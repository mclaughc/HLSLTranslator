#include "glsl_symbol_table.h"
#include "glsl_parser_extras.h"
#include "ir.h"
#include "ir_optimization.h"
#include "ir_rvalue_visitor.h"
#include "glsl_types.h"
#include "main/imports.h"
#include "ast.h"

static char *create_semantic_variable_name(void *mem_ctx, const char *prefix, const char *input_semantic_name)
{
    // extract the semantic name part of the text
    const char *name_end = input_semantic_name;
    while (*name_end != '\0' && isalpha(*name_end))
        name_end++;

    // extract the semantic index part of the text
    int index = 0;
    if (*name_end != '\0')
        index = (int)strtol(name_end, NULL, 10);

    // create the variable name
    char *str = ralloc_strdup(mem_ctx, prefix);
    ralloc_strncat(&str, input_semantic_name, name_end - input_semantic_name);
    ralloc_asprintf_append(&str, "%d", index);
    return str;
}

static ir_rvalue *resolve_input_semantic(void *mem_ctx, _mesa_glsl_parse_state *parse_state, exec_list *instructions, const glsl_type *type, const char *semantic_name)
{
    char *new_variable_name = NULL;
    ir_variable *source_variable = NULL;

    if (parse_state->stage == MESA_SHADER_VERTEX)
    {
        // Builtins
        if (strcasecmp(semantic_name, "SV_VertexID") == 0)
            source_variable = parse_state->symbols->get_variable("gl_VertexID");
        else if (strcasecmp(semantic_name, "SV_InstanceID") == 0)
            source_variable = parse_state->symbols->get_variable("gl_InstanceID");
        //else if (strcasecmp(semantic_name, "SV_ClipDistance"))

        // VS inputs are vertex attributes, we name them attribute_X where X is the semantic name
        new_variable_name = create_semantic_variable_name(mem_ctx, "attribute_", semantic_name);
    }
    else if (parse_state->stage == MESA_SHADER_FRAGMENT)
    {
        // Builtins
        if (strcasecmp(semantic_name, "SV_Position") == 0)
            source_variable = parse_state->symbols->get_variable("gl_FragCoord");
        else if (strcasecmp(semantic_name, "SV_IsFrontFace") == 0)
            source_variable = parse_state->symbols->get_variable("gl_FrontFacing");

        // fragment shader inputs are varyings, we have to do some work to construct the name
        new_variable_name = create_semantic_variable_name(mem_ctx, "varying_", semantic_name);
    }

    if (new_variable_name != NULL)
    {
        // look up if this has already been specified
        source_variable = parse_state->symbols->get_variable(new_variable_name);
        if (source_variable == NULL)
        {
            // construct the variable
            source_variable = new (mem_ctx)ir_variable(type, new_variable_name, ir_var_shader_in);

            // add to IR, we'll just throw it at the top for now
            instructions->push_head(source_variable);

            // add to symbol table
            parse_state->symbols->add_variable(source_variable);
        }

        // free name
        ralloc_free(new_variable_name);
    }

    if (source_variable != NULL)
        return new (mem_ctx) ir_dereference_variable(source_variable);

    parse_state->add_error("unable to resolve HLSL input semantic : '%s'\n", semantic_name);
    return NULL;
}

static ir_variable *resolve_output_semantic(void *mem_ctx, _mesa_glsl_parse_state *parse_state, exec_list *instructions, const glsl_type *type, const char *semantic_name)
{
    char *output_variable_name = NULL;
    int output_variable_location = -1;
    ir_variable *output_variable = NULL;

    if (parse_state->stage == MESA_SHADER_VERTEX)
    {
        // VS outputs
        if (strcasecmp(semantic_name, "SV_Position") == 0)
        {
            // map to gl_Position. this seems to return null if something doesn't reference it.. wtf?
            output_variable = parse_state->symbols->get_variable("gl_Position");
        }
        else
        {
            // Varyings
            output_variable_name = create_semantic_variable_name(mem_ctx, "varying_", semantic_name);
        }
    }
    else if (parse_state->stage == MESA_SHADER_FRAGMENT)
    {
        // FS outputs
        if (strcasecmp(semantic_name, "SV_Depth") == 0)
            output_variable = parse_state->symbols->get_variable("gl_FragDepth");

        // target colour.. crude but effective
        else if (strcasecmp(semantic_name, "SV_Target") == 0 || strcasecmp(semantic_name, "SV_Target0") == 0 || strcasecmp(semantic_name, "SV_Target1") == 0 ||
                 strcasecmp(semantic_name, "SV_Target2") == 0 || strcasecmp(semantic_name, "SV_Target3") == 0 || strcasecmp(semantic_name, "SV_Target4") == 0 ||
                 strcasecmp(semantic_name, "SV_Target5") == 0 || strcasecmp(semantic_name, "SV_Target6") == 0 || strcasecmp(semantic_name, "SV_Target7") == 0)
        {
            // get render target index
            output_variable_location = (strlen(semantic_name) < 10) ? 0 : (semantic_name[9] - '0');

            // if we're using opengl es 2.0, we have have only one target
            if (parse_state->es_shader && parse_state->language_version == 100)
            {
                // has to be zero
                if (output_variable_location != 0)
                {
                    ralloc_asprintf_append(&parse_state->info_log, "render target indexes unsupported in GLSL ES 1.0, must be SV_Target or SV_Target0.\n");
                    return nullptr;
                }

                // use gl_FragColor
                output_variable_name = ralloc_strdup(mem_ctx, "gl_FragColor");
                output_variable_location = -1;
            }
            else
            {
                // construct the output variable name
                output_variable_name = ralloc_asprintf(mem_ctx, "out_Target%d", output_variable_location);
            }
        }
    }

    // automatic variable creation
    if (output_variable_name != NULL)
    {
        // look up if this has already been specified
        output_variable = parse_state->symbols->get_variable(output_variable_name);
        if (output_variable == NULL)
        {
            // construct the variable
            output_variable = new (mem_ctx)ir_variable(type, output_variable_name, ir_var_shader_out);

            // apply implicit location
            if (output_variable_location >= 0)
            {
                output_variable->data.explicit_location = 1;
                output_variable->data.location = (parse_state->stage == MESA_SHADER_VERTEX ? (int)VARYING_SLOT_VAR0 : (int)FRAG_RESULT_DATA0) + output_variable_location;
            }

            // add to IR, we'll just throw it at the top for now
            instructions->push_head(output_variable);

            // add to symbol table
            parse_state->symbols->add_variable(output_variable);
        }

        // free name
        ralloc_free(output_variable_name);
    }   

    // write out
    if (output_variable != NULL)
        return output_variable;

    parse_state->add_error("unable to resolve HLSL output semantic: '%s'\n", semantic_name);
    return NULL;
}

static bool create_main_signature(exec_list *instructions, _mesa_glsl_parse_state *state)
{
    // get memory context
    void *mem_ctx = ralloc_parent(instructions);

    // temporary: we need to rename a main() in the shader to something else.. fix this properly at some point
    if (state->symbols->get_function("main") != NULL)
    {
        state->add_error("main already defined, cannot proceed, this will be fixed in a later release");
        return false;
    }

    // find our entry point
    ir_function *entry_point_fn = state->symbols->get_function(state->hlsl_entry_point);
    if (entry_point_fn == NULL)
    {
        state->add_error("could not resolve entry point '%s'", state->hlsl_entry_point);
        return false;
    }

    // check overloads
    if (entry_point_fn->signatures.length() != 1)
    {
        state->add_error("entry point '%s' has %u signatures, it should not be overloaded", entry_point_fn->signatures.length());
        return false;
    }

    // get signature
    ir_function_signature *entry_point_sig = static_cast<ir_function_signature *>(entry_point_fn->signatures.get_head());

    // create main method
    ir_function *main_fn = new (mem_ctx) ir_function("main");
    ir_function_signature *main_sig = new (mem_ctx) ir_function_signature(glsl_type::void_type);
    main_fn->add_signature(main_sig);
    emit_function(state, main_fn);
    if (!state->symbols->add_function(main_fn))
    {
        state->add_error("internal error: main function already defined");
        return false;
    }

    // setup parameters
    exec_list entrypoint_call_parameters;
    exec_list declaration_statements;
    exec_list before_call_statements;
    exec_list after_call_statements;
    foreach_in_list(ir_variable, param, &entry_point_sig->parameters)
    {
        // check in/out
        if (param->data.mode == ir_var_function_in)
        {
            // shader input - map to an attribute/varying, check for struct
            if (param->type->is_record())
            {
                // create an instance of the struct
                ir_variable *temp_var = new (mem_ctx) ir_variable(param->type, param->name, ir_var_temporary);
                declaration_statements.push_tail(temp_var);

                // map each of the struct's semantics to the temporary
                for (unsigned i = 0; i < param->type->length; i++)
                {
                    const glsl_struct_field *field = &param->type->fields.structure[i];
                    if (field->semantic_name == NULL)
                    {
                        state->add_error("entry point function has struct parameter '%s' with record '%s' missing semantic", param->name, field->name);
                        return false;
                    }

                    // resolve the semantic
                    ir_rvalue *source_expr = resolve_input_semantic(mem_ctx, state, instructions, field->type, field->semantic_name);
                    if (source_expr == NULL)
                        return false;

                    // store to the temporary struct
                    ir_dereference_record *temp_record_deref = new (mem_ctx) ir_dereference_record(temp_var, field->name);
                    ir_assignment *asgn = new (mem_ctx) ir_assignment(temp_record_deref, source_expr);
                    before_call_statements.push_tail(asgn);
                }

                // push the temporary struct to the parameter list
                ir_dereference_variable *entrypoint_param = new (mem_ctx) ir_dereference_variable(temp_var);
                entrypoint_call_parameters.push_tail(entrypoint_param);
            }
            else
            {
                // all entry point parameters must have semantics
                if (param->semantic_name == NULL)
                {
                    state->add_error("entry point function has parameter '%s' without semantic", param->name);
                    return false;
                }

                // single variable
                ir_rvalue *source_expr = resolve_input_semantic(mem_ctx, state, instructions, param->type, param->semantic_name);
                if (source_expr == NULL)
                    return false;
                
                // for inputs, we don't need a temporary, can just pass the expression right through.
                entrypoint_call_parameters.push_tail(source_expr);
            }
        }
        else if (param->data.mode == ir_var_function_out)
        {
            // shader output - map to output/varying, check for struct
            if (param->type->is_record())
            {
                // create a temporary instance of the struct
                ir_variable *temp_var = new (mem_ctx) ir_variable(param->type, param->name, ir_var_temporary);
                declaration_statements.push_tail(temp_var);

                // post-call - map each of the temporary struct's records to the semantic variables
                for (unsigned i = 0; i < param->type->length; i++)
                {
                    const glsl_struct_field *field = &param->type->fields.structure[i];
                    if (field->semantic_name == NULL)
                    {
                        state->add_error("entry point function has struct parameter '%s' with record '%s' missing semantic", param->name, field->name);
                        return false;
                    }

                    // resolve the semantic
                    ir_variable *dest_variable = resolve_output_semantic(mem_ctx, state, instructions, field->type, field->semantic_name);
                    if (dest_variable == NULL)
                        return false;

                    // store to the output variable struct
                    ir_dereference_variable *dest_variable_deref = new (mem_ctx) ir_dereference_variable(dest_variable);
                    ir_dereference_record *temp_record_deref = new (mem_ctx) ir_dereference_record(temp_var, field->name);
                    ir_assignment *asgn = new (mem_ctx) ir_assignment(dest_variable_deref, temp_record_deref);
                    after_call_statements.push_tail(asgn);
                }

                // push the temporary struct to the parameter list
                ir_dereference_variable *entrypoint_param = new (mem_ctx) ir_dereference_variable(temp_var);
                entrypoint_call_parameters.push_tail(entrypoint_param);
            }
            else
            {
                // all entry point parameters must have semantics
                if (param->semantic_name == NULL)
                {
                    state->add_error("entry point function has parameter '%s' without semantic", param->name);
                    return false;
                }

                // single variable
                ir_variable *dest_var = resolve_output_semantic(mem_ctx, state, instructions, param->type, param->semantic_name);
                if (dest_var == NULL)
                    return false;

                // create a temporary in the main method, and after the function call copy to the destination
                ir_variable *temp_var = new (mem_ctx) ir_variable(dest_var->type, param->name, ir_var_temporary);
                ir_dereference_variable *dest_var_deref = new (mem_ctx) ir_dereference_variable(dest_var);
                ir_dereference_variable *temp_deref = new (mem_ctx) ir_dereference_variable(temp_var);
                ir_assignment *temp_assignment = new (mem_ctx) ir_assignment(dest_var_deref, temp_deref);
                declaration_statements.push_tail(temp_var);
                after_call_statements.push_tail(temp_assignment);

                // push to parameter list
                ir_dereference_variable *entrypoint_param = new (mem_ctx) ir_dereference_variable(temp_var);
                entrypoint_call_parameters.push_tail(entrypoint_param);
            }
        }
        else
        {
            // hmm?
            abort();
        }
    }

    // for entry points that return a struct, these have to be handled here
    ir_variable *entry_point_return_value = NULL;
    if (entry_point_sig->return_type->is_record())
    {
        // create a temporary of the return value, we'll deal with it later
        entry_point_return_value = new (mem_ctx) ir_variable(entry_point_sig->return_type, entry_point_sig->function_name(), ir_var_temporary);
        declaration_statements.push_tail(entry_point_return_value);
    }

    // append the declarations and pre-call statements to the main body
    main_sig->body.append_list(&declaration_statements);
    main_sig->body.append_list(&before_call_statements);

    // generate the call to the entry point
    ir_rvalue *call_return = generate_call(&main_sig->body, entry_point_sig, &entrypoint_call_parameters, state);
    if (state->error)
        return false;

    // copy the return value of the entry point to the temporary
    if (call_return != NULL)
    {
        assert(call_return->type == entry_point_sig->return_type);
        if (call_return->type->is_record())
        {
            assert(entry_point_return_value != NULL);

            // use the temporary we created earlier as a destination of the call return
            ir_dereference_variable *temp_deref = new (mem_ctx) ir_dereference_variable(entry_point_return_value);
            ir_assignment *temp_asgn = new (mem_ctx) ir_assignment(temp_deref, call_return);
            main_sig->body.push_tail(temp_asgn);

            // post-call - map each of the temporary struct's records to the semantic variables
            for (unsigned i = 0; i < call_return->type->length; i++)
            {
                const glsl_struct_field *field = &call_return->type->fields.structure[i];
                if (field->semantic_name == NULL)
                {
                    state->add_error("entry point function has return struct with record '%s' missing semantic", field->name);
                    return false;
                }

                // resolve the semantic
                ir_variable *dest_variable = resolve_output_semantic(mem_ctx, state, instructions, field->type, field->semantic_name);
                if (dest_variable == NULL)
                    return false;

                // store to the output variable
                ir_dereference_variable *dest_variable_deref = new (mem_ctx) ir_dereference_variable(dest_variable);
                ir_dereference_record *temp_record_deref = new (mem_ctx) ir_dereference_record(entry_point_return_value, field->name);
                ir_assignment *asgn = new (mem_ctx) ir_assignment(dest_variable_deref, temp_record_deref);
                after_call_statements.push_tail(asgn);
            }
        }
        else
        {
            // singular value should have semantic
            assert(entry_point_return_value == NULL);
            if (entry_point_sig->return_semantic_name == NULL)
            {
                state->add_error("entry point '%s' has return type but no semantic", entry_point_sig->function_name());
                return false;
            }

            // can simply write straight from the call to the output for singular values
            ir_variable *dest_var = resolve_output_semantic(mem_ctx, state, instructions, call_return->type, entry_point_sig->return_semantic_name);
            if (dest_var == NULL)
                return false;

            // create assignment
            ir_dereference_variable *dest_var_deref = new (mem_ctx) ir_dereference_variable(dest_var);
            ir_assignment *asgn = new (mem_ctx) ir_assignment(dest_var_deref, call_return);
            main_sig->body.push_tail(asgn);
        }
    }

    // copy post-call statements
    main_sig->body.append_list(&after_call_statements);
    main_sig->is_defined = 1;
    return true;
}

struct inline_hlsl_intrinsics_visitor : public ir_hierarchical_visitor
{
    virtual ir_visitor_status visit_enter(ir_call *ir) override final
    {
        if (ir->callee->is_builtin() && ir->callee->is_hlsl_intrinsic)
        {
            // should be a prototype
            assert(ir->callee->body.length() == 0 && ir->callee->get_origin() != ir->callee);

            // replace prototype call with actual function body
            ir->callee = const_cast<ir_function_signature *>(ir->callee->get_origin());

            // inline it
            ir->generate_inline(ir);
            ir->remove();
        }

        return visit_continue;
    }
};

static void inline_hlsl_intrinsics(exec_list *instructions)
{
    inline_hlsl_intrinsics_visitor visitor;
    visitor.run(instructions);
}

struct inline_missing_glsles_10_intrinsics_visitor : public ir_hierarchical_visitor
{
    virtual ir_visitor_status visit_enter(ir_call *ir) override final
    {
        if (ir->callee->is_builtin())
        {
            if (strcmp(ir->callee_name(), "transpose") == 0 ||
                strcmp(ir->callee_name(), "inverse") == 0)
            {
                const ir_function_signature *origin = ir->callee->get_origin();
                if (origin != ir->callee)
                    ir->callee = const_cast<ir_function_signature *>(origin);

                ir->generate_inline(ir);
                ir->remove();
            }
        }

        return visit_continue;
    }
};

static void inline_missing_glsles_10_intrinsics(exec_list *instructions)
{
    inline_missing_glsles_10_intrinsics_visitor visitor;
    visitor.run(instructions);
}

struct remove_discards_visitor : ir_hierarchical_visitor
{
    virtual ir_visitor_status visit_enter(ir_discard *ir) override final
    {
        // remove it
        ir->remove();
        return visit_continue;
    }
};

static void remove_discards(exec_list *instructions)
{
    remove_discards_visitor visitor;
    visitor.run(instructions);
}

// TODO:
// convert_sampler_states_to_samplers

struct remove_sampler_states_visitor : ir_hierarchical_visitor
{
    static inline bool is_removable_type(const glsl_type *type)
    {
        return (type == glsl_type::SamplerState_type || type == glsl_type::SamplerComparisonState_type);
    }

    virtual ir_visitor_status visit_enter(ir_function_signature *ir) override final
    {
        // remove from parameter lists
        foreach_in_list_safe(ir_rvalue, param, &ir->parameters)
        {
            if (is_removable_type(param->type))
                param->remove();
        }

        // remove sampler return types
        if (is_removable_type(ir->return_type))
            ir->return_type = glsl_type::void_type;

        // visit body
        return visit_continue;
    }

    virtual ir_visitor_status visit_enter(ir_call *ir) override final
    {
        // remove return type
        if (ir->return_deref != NULL && is_removable_type(ir->return_deref->type))
            ir->return_deref = NULL;

        // remove from parameter lists
        foreach_in_list_safe(ir_rvalue, param, &ir->actual_parameters)
        {
            if (is_removable_type(param->type))
                param->remove();
        }

        // no need to visit the parameters, since we've already done it
        return visit_continue_with_parent;
    }

    virtual ir_visitor_status visit_enter(ir_assignment *ir) override final
    {
        // remove assignments to/from sampler types
        if (is_removable_type(ir->lhs->type))
            ir->remove();

        return visit_continue_with_parent;
    }

    virtual ir_visitor_status visit(ir_variable *ir) override final
    {
        // remove variable declarations
        if (is_removable_type(ir->type))
            ir->remove();

        return visit_continue;
    }
};

static void remove_sampler_states(exec_list *instructions)
{
    remove_sampler_states_visitor visitor;
    visitor.run(instructions);
}

// struct 
// 
// struct expand_sampler_function_parameters_visitor : public ir_visitor
// {
//     expand_sampler_function_parameters_visitor(exec_list *instructions, _mesa_glsl_parse_state *state)
//         : instructions(instructions), state(state), current_function(NULL), found_tex(NULL)
//     {
// 
//     }
// 
//     virtual void visit(ir_function_signature *ir) override
//     {
//         // skip prototypes
//         if (ir->is_prototype())
//             return;
// 
//         // for each parameter, if it is a sampler parameter, search for usage
//         // bug: this won't catch cases where the sampler is copied to a local, then used
//         foreach_in_list(ir_variable, var, &ir->parameters)
//         {
//             if (var->type->base_type == GLSL_TYPE_SAMPLER)
//             {
//                 ir_texture *last_tex = NULL;
//                 ir_rvalue *last_sampler = NULL;
// 
//                 // search for texture instructions
//                 foreach_in_list(ir_instruction, inst, &ir->body)
//                 {
//                     if (inst->ir_type != ir_type_texture)
//                         continue;
// 
//                     ir_texture *tex = inst->as_texture();
//                     if (last_tex != NULL)
//                     {
//                         // second+ usage
//                         if (last_sampler != tex->hlsl_sampler_state)
//                         {
//                             // texture used with >1 sampler state
//                             state->add_error("in function %s, sampler parameter %s used with >1 sampler state, this is not supported", ir->function_name(), var->name);
//                             return;
//                         }
//                     }
//                     else
//                     {
//                         // first usage
//                         last_tex = tex;
//                         last_sampler = tex->hlsl_sampler_state;
//                     }
//                 }
// 
//                 // needs conversion to shadow type?
//                 if (last_sampler != NULL && last_sampler->type == glsl_type::SamplerComparisonState_type)
//                 {
//                     // convert the type of the parameter
//                     const glsl_type *new_type = glsl_type::get_sampler_instance((glsl_sampler_dim)var->type->sampler_dimensionality, true, var->type->sampler_array, (glsl_base_type)var->type->sampler_type);
//                     if (new_type == NULL)
//                         var->type = new_type;
//                 }
//             }
//         }
//     }
// 
//     virtual void visit(ir_variable *) override {}
//     virtual void visit(ir_function *) override {}
//     virtual void visit(ir_expression *) override {}
//     virtual void visit(ir_texture *) override {}
//     virtual void visit(ir_swizzle *) override {}
//     virtual void visit(ir_dereference_variable *) override {}
//     virtual void visit(ir_dereference_array *) override {}
//     virtual void visit(ir_dereference_record *) override {}
//     virtual void visit(ir_assignment *) override {}
//     virtual void visit(ir_constant *) override {}
//     virtual void visit(ir_call *) override {}
//     virtual void visit(ir_return *) override {}
//     virtual void visit(ir_discard *) override {}
//     virtual void visit(ir_if *) override {}
//     virtual void visit(ir_loop *) override {}
//     virtual void visit(ir_loop_jump *) override {}
//     virtual void visit(ir_emit_vertex *) override {}
//     virtual void visit(ir_end_primitive *) override {}
//     virtual void visit(ir_barrier *) override {}
// 
// private:
//     exec_list *instructions;
//     _mesa_glsl_parse_state *state;
//     ir_function_signature *current_function;
//     ir_texture *found_tex;
// };
// 
// static void expand_samplers(exec_list *instructions)
// {
// 
// }

// convert functions that take samplers as parameters to use shadow types
// bug: this won't catch cases where the sampler is copied to a local, then used
// but of optimization is done prior to this pass it shouldn't be an issue
static bool convert_function_parameters_to_shadow_types(exec_list *instructions, _mesa_glsl_parse_state *state)
{
    foreach_in_list(ir_instruction, ir, instructions)
    {
        // only handle function signatures
        if (ir->ir_type != ir_type_function_signature)
            continue;

        // skip prototypes
        ir_function_signature *sig = (ir_function_signature *)ir;
        if (sig->is_prototype())
            continue;

        // for each parameter, if it is a sampler parameter, search for usage
        foreach_in_list(ir_variable, var, &sig->parameters)
        {
            if (var->type->base_type == GLSL_TYPE_SAMPLER)
            {
                ir_texture *last_tex = NULL;
                ir_rvalue *last_sampler = NULL;

                // search for texture instructions
                foreach_in_list(ir_instruction, inst, &sig->body)
                {
                    if (inst->ir_type != ir_type_texture)
                        continue;

                    ir_texture *tex = inst->as_texture();
                    if (last_tex != NULL)
                    {
                        // second+ usage
                        if (last_sampler != tex->hlsl_sampler_state)
                        {
                            // texture used with >1 sampler state
                            state->add_error("in function %s, sampler parameter %s used with >1 sampler state, this is not supported", sig->function_name(), var->name);
                            return false;
                        }
                    }
                    else
                    {
                        // first usage
                        last_tex = tex;
                        last_sampler = tex->hlsl_sampler_state;
                    }
                }

                // needs conversion to shadow type?
                if (last_sampler != NULL && last_sampler->type == glsl_type::SamplerComparisonState_type)
                {
                    // convert the type of the parameter
                    const glsl_type *new_type = glsl_type::get_sampler_instance((glsl_sampler_dim)var->type->sampler_dimensionality, true, var->type->sampler_array, (glsl_base_type)var->type->sampler_type);
                    if (new_type == NULL)
                        var->type = new_type;
                }
            }
        }
    }

    return true;
}

// convert direct usage of samplers in shadow mode to shadow types, cloning the uniforms as necessary
struct expand_sampler_visitor : public ir_hierarchical_visitor
{
    expand_sampler_visitor(void *mem_ctx) 
        : mem_ctx(mem_ctx), generic_sampler_rvalue(NULL), generic_shadow_sampler_rvalue(NULL)
    {

    }
    ~expand_sampler_visitor()
    {
        foreach_in_list(cloned_texture, ctex, &cloned_textures)
            delete ctex;
    }

    // bit of a hack, but needed due to function calls
    ir_rvalue *get_generic_sampler_rvalue()
    {
        if (generic_sampler_rvalue != NULL)
            return generic_sampler_rvalue;

        ir_variable *var = new (mem_ctx) ir_variable(glsl_type::SamplerState_type, "__generic_SamplerState", ir_var_temporary);
        generic_sampler_rvalue = new (mem_ctx) ir_dereference_variable(var);
        return generic_sampler_rvalue;
    }
    ir_rvalue *get_generic_shadow_sampler_rvalue()
    {
        if (generic_shadow_sampler_rvalue != NULL)
            return generic_shadow_sampler_rvalue;

        ir_variable *var = new (mem_ctx) ir_variable(glsl_type::SamplerComparisonState_type, "__generic_SamplerComparisonState", ir_var_temporary);
        generic_shadow_sampler_rvalue = new (mem_ctx) ir_dereference_variable(var);
        return generic_shadow_sampler_rvalue;
    }

    ir_variable *clone_texture(ir_variable *texture, ir_rvalue *sampler_state)
    {
        ir_variable *clone = texture->clone(ralloc_parent(texture), NULL);
        clone->merged_sampler_var = (sampler_state != NULL) ? sampler_state->variable_referenced() : NULL;
        if (clone->merged_sampler_var != NULL)
            clone->name = ralloc_asprintf("%s_%s", clone->name, clone->merged_sampler_var->name);

        // convert samplers to shadow samplers
        bool texture_is_shadow = (texture->type->sampler_shadow);
        bool sampler_is_shadow = (clone->merged_sampler_var != NULL && clone->merged_sampler_var->type == glsl_type::SamplerComparisonState_type);
        if (texture_is_shadow != sampler_is_shadow)
        {
            const glsl_type *new_type = glsl_type::get_sampler_instance((glsl_sampler_dim)texture->type->sampler_dimensionality, sampler_is_shadow, texture->type->sampler_array, (glsl_base_type)texture->type->sampler_type);
            if (new_type != NULL)
                clone->type = new_type;
        }

        cloned_texture *ctex = new (mem_ctx) cloned_texture;
        ctex->orig_texture = texture;
        ctex->new_texture = clone;
        ctex->sampler_state = sampler_state;
        cloned_textures.push_tail(ctex);

        // add after the initial declaration
        texture->insert_after(clone);

        return clone;
    }

    ir_variable *get_cloned_texture(ir_variable *texture, ir_rvalue *sampler_state)
    {
        foreach_in_list(cloned_texture, ctex, &cloned_textures)
        {
            if (ctex->orig_texture == texture && ctex->sampler_state == sampler_state)
                return ctex->new_texture;
        }

        return clone_texture(texture, sampler_state);
    }

    ir_variable *bind_texture_to_sampler(ir_variable *texture, ir_rvalue *sampler_state)
    {
        if (texture->merged_sampler_var == sampler_state->variable_referenced())
            return texture;

        // TODO: rename if behaviour is ALWAYS RENAME
        if (texture->merged_sampler_var != NULL)
            return get_cloned_texture(texture, sampler_state);

        // convert samplers to shadow samplers
        bool texture_is_shadow = (texture->type->sampler_shadow);
        bool sampler_is_shadow = (sampler_state != NULL && sampler_state->type == glsl_type::SamplerComparisonState_type);
        if (texture_is_shadow != sampler_is_shadow)
        {
            const glsl_type *new_type = glsl_type::get_sampler_instance((glsl_sampler_dim)texture->type->sampler_dimensionality, sampler_is_shadow, texture->type->sampler_array, (glsl_base_type)texture->type->sampler_type);
            if (new_type != NULL)
                texture->type = new_type;
        }

        texture->merged_sampler_var = sampler_state->variable_referenced();
        return texture;
    }

    virtual ir_visitor_status visit_enter(ir_texture *ir) override final
    {
        // texture load instructions can be left as-is
        if (ir->hlsl_sampler_state == NULL)
            return visit_continue_with_parent;

        // can only handle uniforms
        ir_dereference_variable *tex_deref = ir->sampler->as_dereference_variable();
        if (tex_deref == NULL || tex_deref->var->data.mode != ir_var_uniform)
            return visit_continue_with_parent;

        // bind each texture call to their sampler state
        tex_deref->var = bind_texture_to_sampler(tex_deref->var, ir->hlsl_sampler_state);
        tex_deref->type = tex_deref->var->type;

        // done with the texture call
        return visit_continue_with_parent;
    }

    virtual ir_visitor_status visit_enter(ir_call *ir) override final
    {
        ir_function_signature *sig = ir->callee;
        unsigned int param_index = 0;

        // is the function call taking a shadow type, and we are a generic type?
        foreach_in_list(ir_rvalue, param, &ir->actual_parameters)
        {
            // skip non-sampler parameters, not even worth the time
            if (param->ir_type != ir_type_dereference_variable || param->type->base_type != GLSL_TYPE_SAMPLER)
            {
                param_index++;
                continue;
            }

            // can only handle uniforms
            ir_dereference_variable *param_deref = param->as_dereference_variable();
            if (param_deref->var->data.mode != ir_var_uniform)
            {
                param_index++;
                continue;
            }

            // compare against the prototype
            ir_variable *c_param = (ir_variable *)ir->callee->parameters.node_at_index(param_index);
            if (c_param != NULL)
            {
                // bind to a generic sampler state
                ir_rvalue *sampler_state = (c_param->type == glsl_type::SamplerComparisonState_type) ? get_generic_shadow_sampler_rvalue() : get_generic_sampler_rvalue();
                param_deref->var = bind_texture_to_sampler(param_deref->var, sampler_state);
                param_deref->type = param_deref->var->type;
            }

            // next param
            param_index++;
        }

        // no need to look at params/return
        return visit_continue_with_parent;
    }

private:
    struct cloned_texture : public exec_node
    {
        DECLARE_RALLOC_CXX_OPERATORS(cloned_texture)

        ir_variable *orig_texture;
        ir_variable *new_texture;
        ir_rvalue *sampler_state;
    };

    void *mem_ctx;
    exec_list cloned_textures;
    ir_rvalue *generic_sampler_rvalue;
    ir_rvalue *generic_shadow_sampler_rvalue;
};

static void expand_samplers(exec_list *instructions, _mesa_glsl_parse_state *state)
{
    expand_sampler_visitor visitor(state);
    visitor.run(instructions);
}

bool _mesa_hlsl_post_convert(exec_list *instructions, _mesa_glsl_parse_state *state)
{       
    // don't do anything if there's errors
    if (state->error)
        return false;

    // GLSL ES 1.0 fixups, ugh.
    if (state->es_shader && state->language_version < 300)
    {
        // doesn't support constant arrays, lower them to uniforms
        lower_const_arrays_to_uniforms(instructions);

        // has no transpose function, so inline the builtin functions
        inline_missing_glsles_10_intrinsics(instructions);
    }

    // Desktop GL doesn't allow overloading of built-in functions, so we have to inline them.
    inline_hlsl_intrinsics(instructions);

    // discard is a syntax error in GLSL non-fragment shaders, but not in HLSL
    if (state->stage != MESA_SHADER_FRAGMENT)
        remove_discards(instructions);

    // Create main function
    if (!create_main_signature(instructions, state))
        return false;

    // expand samplers
    expand_samplers(instructions, state);

    // remove sampler state types
    remove_sampler_states(instructions);
        
    return !state->error;
}
