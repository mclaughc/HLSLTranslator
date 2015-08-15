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

bool _mesa_hlsl_post_convert(exec_list *instructions, _mesa_glsl_parse_state *state)
{       
    //if (!convert_and_rename_entrypoint(instructions, state))
        //return false;

    //if (!check_functions_for_semantics(instructions, state))
        //return false;

    //if (!convert_intrinsic_calls_to_inline(instructions, state))
        //return false;

    // remove sampler state types
    remove_sampler_states(instructions);

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
        
    return !state->error;
}
