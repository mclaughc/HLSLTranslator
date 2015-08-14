/**
 * Based on GLSL optimizer:
 * https://github.com/aras-p/glsl-optimizer 
 */
#include "ir_print_glsl_visitor.h"
#include "ir_visitor.h"
#include "glsl_types.h"
#include "glsl_parser_extras.h"
#include "loop_analysis.h"
#include "program/hash_table.h"
#include "main/macros.h"
#include <math.h>
#include <limits>


class string_buffer
{
public:
	string_buffer(void* mem_ctx)
	{
		m_Capacity = 512;
		m_Ptr = (char*)ralloc_size(mem_ctx, m_Capacity);
		m_Size = 0;
		m_Ptr[0] = 0;
	}

	~string_buffer()
	{
		ralloc_free(m_Ptr);
	}

	const char* c_str() const { return m_Ptr; }

	void asprintf_append(const char *fmt, ...) PRINTFLIKE(2, 3)
	{
		va_list args;
		va_start(args, fmt);
		vasprintf_append(fmt, args);
		va_end(args);
	}

	void vasprintf_append(const char *fmt, va_list args)
	{
		assert (m_Ptr != NULL);
		vasprintf_rewrite_tail (&m_Size, fmt, args);
	}

	void vasprintf_rewrite_tail (size_t *start, const char *fmt, va_list args)
	{
		assert (m_Ptr != NULL);

		//size_t new_length = printf_length(fmt, args);
        va_list argsCopy;
        va_copy(argsCopy, args);
#ifdef _MSC_VER
        size_t new_length = _vscprintf(fmt, argsCopy);
#else
        size_t new_length = vsnprintf(nullptr, 0, fmt, argsCopy);
#endif

		size_t needed_length = m_Size + new_length + 1;

		if (m_Capacity < needed_length)
		{
			m_Capacity = MAX2 (m_Capacity + m_Capacity/2, needed_length);
			m_Ptr = (char*)reralloc_size(ralloc_parent(m_Ptr), m_Ptr, m_Capacity);
		}

		vsnprintf(m_Ptr + m_Size, new_length+1, fmt, args);
		m_Size += new_length;
		assert (m_Capacity >= m_Size);
	}

    void append(const char *str)
    {
        // TODO optimize me
        asprintf_append("%s", str);
    }

    void erase_tail(size_t length)
    {
        if (length > m_Size)
            length = m_Size;

        char *end = m_Ptr + m_Size - length;
        for (size_t i = 0; i < length; i++)
            *(end++) = '\0';
        m_Size -= length;
    }

    void erase_last_line()
    {
        if (m_Size == 0)
            return;

        char *start = m_Ptr + m_Size - 1;
        char *end = start;
        while (start > m_Ptr && *start != '\n')
            start--;

        for (char *cur = start; cur <= end; cur++)
        {
            *cur = '\0';
            m_Size--;
        }
    }

private:
	char* m_Ptr;
	size_t m_Size;
	size_t m_Capacity;
};


static void print_precision(string_buffer& buffer, const glsl_type* type);
static void print_type(string_buffer& buffer, const glsl_type *t, bool arraySize);
static void print_type_post(string_buffer& buffer, const glsl_type *t, bool arraySize);
static void print_struct_declaration(string_buffer& buffer, const glsl_type *type);
static void print_struct_declaration_with_precision(string_buffer& buffer, const glsl_type *type);

struct struct_printer : public ir_hierarchical_visitor
{
    struct_printer(string_buffer &buffer, bool use_precision)
        : buffer(buffer)
        , use_precision(use_precision)
    {
        known_structs = hash_table_ctor(0, hash_table_pointer_hash, hash_table_pointer_compare);
    }

    ~struct_printer()
    {
        hash_table_dtor(known_structs);
    }

    void print_struct(const glsl_type *type)
    {
        // skip already-done structs
        if (hash_table_find(known_structs, type) != NULL)
            return;

        // insert to tracked list
        hash_table_insert(known_structs, (void *)type, type);

        // print nested structs first
        print_nested_structs(type);

        // print the struct
        if (use_precision)
            print_struct_declaration_with_precision(buffer, type);
        else
            print_struct_declaration(buffer, type);
    }

    void print_nested_structs(const glsl_type *type)
    {
        if (type->is_record() || type->is_interface())
        {
            for (unsigned i = 0; i < type->length; i++)
            {
                const glsl_struct_field *field = &type->fields.structure[i];
                if (field->type->is_record())
                    print_struct(field->type);
            }
        }
    }

    virtual ir_visitor_status visit(ir_variable *var) override
    {
        // skip unused variables
        if (var->data.used == 0)
            return visit_continue;

        // skip builtin structures
        if (strncmp(var->name, "gl_", 3) == 0)
            return visit_continue;
        
        // print anything that could use a struct
        const glsl_type *type = var->type;
        if (type->is_record())
            print_struct(type);
        else if (type->is_interface())
            print_nested_structs(type);

        return visit_continue;
    }
  
    string_buffer &buffer;
    hash_table *known_structs;
    bool use_precision;
};

// global assignment locator
static ir_instruction *locate_variable_initializer(ir_variable *var)
{
    // we can get away from starting at the current node since the assignment always comes after the declaration
    for (ir_instruction *ir = static_cast<ir_instruction *>(var->get_next()); !ir->is_tail_sentinel(); ir = static_cast<ir_instruction *>(ir->get_next()))
    {
        // assignment instruction?
        if (ir->ir_type == ir_type_assignment)
        {
            // for our variable?
            ir_assignment *asgn = static_cast<ir_assignment *>(ir);
            if (asgn->lhs->variable_referenced() == var)
                return asgn;
        }
        // call instruction?
        else if (ir->ir_type == ir_type_call)
        {
            // result being set to our variable?
            ir_call *call = static_cast<ir_call *>(ir);
            if (call->return_deref != NULL && call->return_deref->variable_referenced() == var)
                return call;
        }
    }

    // doesn't exist
    return NULL;
}

class ir_print_glsl_visitor : public ir_visitor {
public:
	ir_print_glsl_visitor(void *mem_ctx, string_buffer &buffer, loop_state *loopstate, gl_shader_stage stage, int language_version, bool es_shader, bool use_precision)
		: mem_ctx(mem_ctx)
        , buffer(buffer)
        , indentation(0)
        , expression_depth(0)
		, loopstate(loopstate)
        , stage(stage)
        , language_version(language_version)
        , es_shader(es_shader)
        , use_precision(use_precision)
        , skipped_this_ir(false)
        , previous_skipped(false)
        , current_interface_type(NULL)
        , current_function(NULL)
        , variable_suffix_counter(0)
        , variable_suffixes(hash_table_ctor(0, hash_table_pointer_hash, hash_table_pointer_compare))
	{

	}

	virtual ~ir_print_glsl_visitor()
	{
        hash_table_dtor(variable_suffixes);
	}

	void indent(void);
	void newline_indent();
	void end_statement_line();
	void newline_deindent();
	void print_var_name (ir_variable* v);

	virtual void visit(ir_variable *);
	virtual void visit(ir_function_signature *);
	virtual void visit(ir_function *);
	virtual void visit(ir_expression *);
	virtual void visit(ir_texture *);
	virtual void visit(ir_swizzle *);
	virtual void visit(ir_dereference_variable *);
	virtual void visit(ir_dereference_array *);
	virtual void visit(ir_dereference_record *);
	virtual void visit(ir_assignment *);
	virtual void visit(ir_constant *);
	virtual void visit(ir_call *);
	virtual void visit(ir_return *);
	virtual void visit(ir_discard *);
	virtual void visit(ir_if *);
	virtual void visit(ir_loop *);
	virtual void visit(ir_loop_jump *);
	virtual void visit(ir_emit_vertex *);
	virtual void visit(ir_end_primitive *);
    virtual void visit(ir_barrier *);
	
	void emit_assignment_part(ir_dereference* lhs, ir_rvalue* rhs, unsigned write_mask, ir_rvalue* dstIndex);
    bool can_emit_canonical_for (loop_variable_state *ls);
	bool emit_canonical_for (ir_loop* ir);
	bool try_print_array_assignment (ir_dereference* lhs, ir_rvalue* rhs);
    bool should_print_precision(ir_instruction* ir, const glsl_type* type);

    // utility for initializers
    void print_function_call_rhs(ir_call *ir);

    // @TODO clean this up
    void reset_state()
    {
        skipped_this_ir = false;
        previous_skipped = false;
        current_interface_type = NULL;
        current_function = NULL;
    }

    void *mem_ctx;
	int indentation;
	int expression_depth;
	string_buffer &buffer;
	loop_state *loopstate;
    gl_shader_stage stage;
    int     language_version;
    bool    es_shader;
	bool	use_precision;
	bool	skipped_this_ir;
	bool	previous_skipped;

    // used when writing uniform blocks/members
    const glsl_type *current_interface_type;

    // current function
    const ir_function_signature *current_function;

    // variable suffix tracker
    unsigned int variable_suffix_counter;
    hash_table *variable_suffixes;
};


char *_mesa_print_ir_glsl(void *mem_ctx, struct gl_shader *shader, exec_list *instructions)
{
	string_buffer buffer(mem_ctx);

	// print version & extensions
    buffer.asprintf_append("#version %i", shader->Version);
    if (shader->IsES && shader->Version >= 300)
        buffer.asprintf_append(" es");
    buffer.asprintf_append("\n");

//         if (state->ARB_shader_texture_lod_enable)
// 			str.asprintf_append ("#extension GL_ARB_shader_texture_lod : enable\n");
// 		if (state->EXT_shader_texture_lod_enable)
// 			str.asprintf_append ("#extension GL_EXT_shader_texture_lod : enable\n");
// 		if (state->OES_standard_derivatives_enable)
// 			str.asprintf_append ("#extension GL_OES_standard_derivatives : enable\n");
// 		if (state->EXT_shadow_samplers_enable)
// 			str.asprintf_append ("#extension GL_EXT_shadow_samplers : enable\n");
// 		if (state->EXT_frag_depth_enable)
// 			str.asprintf_append ("#extension GL_EXT_frag_depth : enable\n");
	
    // glsl es header - this is needed because WebGL shading language is GLSL ES,
    // but when running on desktop does not behave like ES, i.e. precision is not
    // recognized, so define them out.
    bool use_precision = false;
    if (shader->IsES && shader->Stage == MESA_SHADER_FRAGMENT)
    {
        static const char gles_fragment_header[] =
            "#ifdef GL_ES\n"
            "   #ifdef GL_FRAGMENT_PRECISION_HIGH\n"
            "        precision highp float;\n"
            "        #define HIGHP highp\n"
            "        #define MEDIUMP mediump\n"
            "        #define LOWP lowp\n"
            "   #else\n"
            "        precision mediump float;\n"
            "        #define HIGHP mediump\n"
            "        #define MEDIUMP mediump\n"
            "        #define LOWP lowp\n"
            "   #endif\n"
            "#else\n"
            "   #define HIGHP \n"
            "   #define MEDIUMP \n"
            "   #define LOWP \n"
            "#endif\n";

        // default precision: fixme!
        buffer.asprintf_append("%s\n", gles_fragment_header);
        use_precision = true;
    }

    // print structs
    {
        struct_printer sprinter(buffer, use_precision);
        sprinter.run(instructions);
    }
    	
	loop_state* loopstate = analyze_loop_variables(instructions);
	if (loopstate->loop_found)
		set_loop_controls(instructions, loopstate);

    // @TODO start at main, find all used functions, recursively, print them, track done functions
    ir_print_glsl_visitor visitor(mem_ctx, buffer, loopstate, shader->Stage, shader->Version, shader->IsES, use_precision);
	foreach_in_list(exec_node, node, instructions)
	{
		ir_instruction *ir = (ir_instruction *)node;
		if (ir->ir_type == ir_type_variable) {
			ir_variable *var = static_cast<ir_variable*>(ir);
			if ((strstr(var->name, "gl_") == var->name)
			  && !var->data.invariant)
				continue;
		}
        
		ir->accept(&visitor);
		if (ir->ir_type != ir_type_function && !visitor.skipped_this_ir)
			buffer.asprintf_append (";\n");

        visitor.reset_state();
	}
	
	delete loopstate;

	return ralloc_strdup(mem_ctx, buffer.c_str());
}

void ir_print_glsl_visitor::indent(void)
{
	if (previous_skipped)
		return;
	previous_skipped = false;
	for (int i = 0; i < indentation; i++)
		buffer.asprintf_append ("  ");
}

void ir_print_glsl_visitor::end_statement_line()
{
	if (!skipped_this_ir)
		buffer.asprintf_append(";\n");
	previous_skipped = skipped_this_ir;
	skipped_this_ir = false;
}

void ir_print_glsl_visitor::newline_indent()
{
	if (expression_depth % 4 == 0)
	{
		++indentation;
		buffer.asprintf_append ("\n");
		indent();
	}
}
void ir_print_glsl_visitor::newline_deindent()
{
	if (expression_depth % 4 == 0)
	{
		--indentation;
		buffer.asprintf_append ("\n");
		indent();
	}
}

static void print_precision(string_buffer& buffer, const glsl_type* type)
{
	if (type &&
		!type->is_float() &&
		!type->is_sampler() &&
		(!type->is_array() || !type->is_float())
	)
	{
		return;
	}

    // @TODO
    buffer.asprintf_append("HIGHP ");
}

static void print_type(string_buffer& buffer, const glsl_type *t, bool arraySize)
{
	if (t->base_type == GLSL_TYPE_ARRAY) 
    {
		print_type(buffer, t->fields.array, true);
		if (arraySize)
			buffer.asprintf_append ("[%u]", t->length);
	}
    //else if ((t->base_type == GLSL_TYPE_STRUCT) && (strncmp("gl_", t->name, 3) != 0)) {
		//buffer.asprintf_append ("%s", t->name);
    else if (t->template_inner_type != NULL)
        buffer.asprintf_append("%s", t->template_base_type->name);
	else
		buffer.asprintf_append("%s", t->name);
}

static void print_type_post(string_buffer& buffer, const glsl_type *t, bool arraySize)
{
	if (t->base_type == GLSL_TYPE_ARRAY) {
		if (!arraySize)
			buffer.asprintf_append ("[%u]", t->length);
	}
}

static void print_struct_declaration(string_buffer& buffer, const glsl_type *type)
{
    assert(type->base_type == GLSL_TYPE_STRUCT);

    buffer.asprintf_append("struct %s {\n", type->name);
    
    for (unsigned i = 0; i < type->length; i++)
    {
        print_type(buffer, type->fields.structure[i].type, false);
        buffer.asprintf_append(" %s", type->fields.structure[i].name);
        print_type_post(buffer, type->fields.structure[i].type, false);
        buffer.asprintf_append(";\n");
    }

    if (type->length == 0)
    {
        // glsl doesn't allow empty structs, we do when 
        // parsing hlsl, so just add a dummy for now
        buffer.asprintf_append("float dummy;\n");
    }

    buffer.asprintf_append("};\n");
}

static void print_struct_declaration_with_precision(string_buffer& buffer, const glsl_type *type)
{
    assert(type->base_type == GLSL_TYPE_STRUCT);

    buffer.asprintf_append("struct %s {\n", type->name);

    for (unsigned i = 0; i < type->length; i++)
    {
        print_precision(buffer, type->fields.structure[i].type);

        print_type(buffer, type->fields.structure[i].type, false);
        buffer.asprintf_append(" %s", type->fields.structure[i].name);
        print_type_post(buffer, type->fields.structure[i].type, false);
        buffer.asprintf_append(";\n");
    }

    if (type->length == 0)
    {
        // glsl doesn't allow empty structs, we do when 
        // parsing hlsl, so just add a dummy for now
        buffer.asprintf_append("LOWP float dummy;\n");
    }

    buffer.asprintf_append("};\n");
}

void ir_print_glsl_visitor::print_var_name (ir_variable* v)
{
    long id = (long)hash_table_find (variable_suffixes, v);
	if (!id && v->data.mode == ir_var_temporary)
	{
        id = ++variable_suffix_counter;
        hash_table_insert (variable_suffixes, (void*)id, v);
	}
    if (id)
    {
        if (v->data.mode == ir_var_temporary)
            buffer.asprintf_append ("tmpvar_%d", (int)id);
        else
            buffer.asprintf_append ("%s_%d", v->name, (int)id);
    }
	else
	{
		buffer.asprintf_append ("%s", v->name);
	}
}

bool ir_print_glsl_visitor::should_print_precision (ir_instruction* ir, const glsl_type* type)
{
    if (!this->use_precision)
		return false;
	if (type &&
		!type->is_float() &&
		!type->is_sampler() &&
		(!type->is_array() || !type->is_float())
	)
	{
		return false;
	}
    if (ir->ir_type != ir_type_function_signature)
        return use_precision;
    else
        return false;
}
    
void ir_print_glsl_visitor::visit(ir_variable *ir)
{
    static const char *const cent = (ir->data.centroid) ? "centroid " : "";
    static const char *const inv = (ir->data.invariant) ? "invariant " : "";
    static const char *const mode[MESA_SHADER_STAGES + 1][ir_var_mode_count] =
	{
		{ "", "uniform ", "attribute ", "varying ", "in ", "out ", "inout ", "", "", "" },      // VERTEX
        { "", "uniform ", "in ",        "out ",     "in ", "out ", "inout ", "", "", "" },      // GEOMETRY
        { "", "uniform ", "varying ",   "out ",     "in ", "out ", "inout ", "", "", "" },      // FRAGMENT
        { "", "uniform ", "in ",        "out ",     "in ", "out ", "inout ", "", "", "" },      // COMPUTE
        { "", "uniform ", "in ",        "out ",     "in ", "out ", "inout ", "", "", "" },      // _General_
    };
	
	static const char *const interp[] = { "", "smooth ", "flat ", "noperspective " };
    static const char *const interfacePackings[3] = { "std140", "shared", "packed" };
    static const char *const matrixLayouts[3] = { "", "column_major", "row_major" };

    // does this variable belong to a uniform block, or is it a uniform block instance?
    if (language_version >= 300 && (ir->is_in_uniform_block() || ir->is_interface_instance()))
    {
        // get the actual interface type
        const glsl_type *interface_type = (ir->is_interface_instance()) ? ir->type : ir->get_interface_type();
        assert(interface_type != nullptr);

        // has this uniform block been printed?
        // also, skip instances that aren't used, and aren't packed
        if (hash_table_find(variable_suffixes, interface_type) != nullptr || ir->data.used == 0 ||
            (ir->is_interface_instance() && interface_type->interface_packing == GLSL_INTERFACE_PACKING_PACKED))
        {
            // skip this variable, already done
            skipped_this_ir = true;
            return;
        }

        // handle any layout parameters
        if (interface_type->interface_packing != GLSL_INTERFACE_PACKING_SHARED ||
            (ir->is_interface_instance() &&
            (ir->data.explicit_location ||
            ir->data.matrix_layout != GLSL_MATRIX_LAYOUT_INHERITED)))
        {
            unsigned layoutParameterCount = 0;
            buffer.asprintf_append("layout(");

            if (interface_type->interface_packing != GLSL_INTERFACE_PACKING_SHARED)
            {
                assert(ir->type->interface_packing < 3);
                buffer.asprintf_append("%s%s", ((layoutParameterCount++) == 0) ? "" : ", ", interfacePackings[ir->type->interface_packing]);
            }

            if (ir->data.matrix_layout != GLSL_MATRIX_LAYOUT_INHERITED)
            {
                assert(ir->data.matrix_layout < 3);
                buffer.asprintf_append("%s%s", ((layoutParameterCount++) == 0) ? "" : ", ", matrixLayouts[ir->data.matrix_layout]);
            }

            if (ir->data.explicit_location && language_version >= 420)
            {
                const int binding_base = (stage == MESA_SHADER_VERTEX ? (int)VERT_ATTRIB_GENERIC0 : (int)FRAG_RESULT_DATA0);
                const int location = ir->data.location - binding_base;
                buffer.asprintf_append("%slocation=%d", ((layoutParameterCount++) == 0) ? "" : ", ", location);
            }

            buffer.asprintf_append(") ");
        }

        // declare the uniform block
        buffer.asprintf_append("uniform %s {\n", interface_type->name);

        // insert the uniform block members
        for (unsigned i = 0; i < interface_type->length; i++)
        {
            if (interface_type->fields.structure[i].type->base_type != GLSL_TYPE_STRUCT)
            {
                // handle layout parameters on the actual field
                if (interface_type->fields.structure[i].matrix_layout != GLSL_MATRIX_LAYOUT_INHERITED)
                {
                    assert(interface_type->fields.structure[i].matrix_layout < 3);
                    buffer.asprintf_append("layout(%s) ", matrixLayouts[interface_type->fields.structure[i].matrix_layout]);
                }

                // print precision
                if (should_print_precision(ir, interface_type->fields.structure[i].type))
                    print_precision(buffer, interface_type->fields.structure[i].type);
            }

            // print type and name
            print_type(buffer, interface_type->fields.structure[i].type, false);
            buffer.asprintf_append(" %s", interface_type->fields.structure[i].name);
            print_type_post(buffer, interface_type->fields.structure[i].type, false);
            end_statement_line();
        }

        // end the uniform block declaration, filling in the variable name if applicable
        if (!ir->is_interface_instance())
        {
            // just end the block definition
            buffer.asprintf_append("};\n");
        }
        else
        {
            // is an instance, so print that name, and array size if applicable
            int arraySize = ir->type->array_size();
            if (arraySize < 0)
                buffer.asprintf_append("} %s;\n", ir->name);
            else if (arraySize == 0)
                buffer.asprintf_append("} %s[];\n", ir->name);
            else
                buffer.asprintf_append("} %s[%i];\n", ir->name, arraySize);
        }

        // insert into global table
        hash_table_insert(variable_suffixes, (void *)interface_type, interface_type);

        // skip this ir
        skipped_this_ir = true;
        return;
    }

	int decormode = (int)stage;
	
    // GLSL 1.30 and up use "in" and "out" for everything, GLSL ES 3 too
	if (language_version >= 130)
		decormode = MESA_SHADER_STAGES;
	
	// give an id to any variable defined in a function that is not an uniform
	if (current_function != NULL && ir->data.mode != ir_var_uniform)
	{
		long id = (long)hash_table_find (variable_suffixes, ir);
		if (id == 0)
		{
			id = ++variable_suffix_counter;
			hash_table_insert (variable_suffixes, (void*)id, ir);
		}
	}

#ifdef FIXME
	// if this is a loop induction variable, do not print it
	// (will be printed inside loop body)
	if (!inside_loop_body)
	{
		loop_variable_state* inductor_state = loopstate->get_for_inductor(ir);
		if (inductor_state && inductor_state->private_induction_variable_count == 1 &&
            can_emit_canonical_for(inductor_state))
		{
			skipped_this_ir = true;
			return;
		}
	}
#endif
	
	// keep invariant declaration for builtin variables
	if (strstr(ir->name, "gl_") == ir->name) {
		buffer.asprintf_append ("%s", inv);
		print_var_name (ir);
		return;
	}

    // skip unused uniforms
    if (ir->data.mode == ir_var_uniform && ir->data.used == 0)
    {
        skipped_this_ir = true;
        return;
    }

    // skip sampler states
    if (ir->type == glsl_type::SamplerState_type)
    {
        skipped_this_ir = true;
        return;
    }

    // handle layout parameters
    if (language_version >= 420)
	{
        // should we specify any layout parameters?
        if (ir->data.explicit_location)
        {
            unsigned layoutParameterCount = 0;
            buffer.asprintf_append("layout(");

            if (ir->data.explicit_location)
            {
                const int binding_base = (stage == MESA_SHADER_VERTEX ? (int)VERT_ATTRIB_GENERIC0 : (int)FRAG_RESULT_DATA0);
                const int location = ir->data.location - binding_base;
                buffer.asprintf_append("%slocation=%d", ((layoutParameterCount++) == 0) ? "" : ", ", location);
            }

            buffer.asprintf_append(") ");
        }
	}

    // constants
    if (ir->data.mode == ir_var_auto && ir->data.read_only)
        buffer.asprintf_append("const ");
	
	
	buffer.asprintf_append ("%s%s%s%s",
							cent, inv, interp[ir->data.interpolation], mode[decormode][ir->data.mode]);

    if (should_print_precision(ir, ir->type))
	    print_precision (buffer, ir->type);

	print_type(buffer, ir->type, false);
	buffer.asprintf_append (" ");

	print_var_name (ir);
	print_type_post(buffer, ir->type, false);

    // print initializer
    if (ir->data.mode != ir_var_shader_in &&
		ir->data.mode != ir_var_shader_out &&
		ir->data.mode != ir_var_function_in &&
		ir->data.mode != ir_var_function_out &&
		ir->data.mode != ir_var_function_inout)
	{
        // constant initializer?
        if (ir->constant_value != NULL)
        {
            buffer.append(" = ");
            visit(ir->constant_value);
        }
        // global variable?
        else if (current_function == NULL)
        {
            ir_instruction *initializer = locate_variable_initializer(ir);
            if (initializer != NULL)
            {
                buffer.asprintf_append("/*&&&%p*/ = ", initializer);
                if (initializer->ir_type == ir_type_assignment)
                {
                    // ensure we have no write mask
                    assert(ir->type->matrix_columns > 1 || ir->type->vector_elements < 1 || static_cast<ir_assignment *>(initializer)->write_mask == ((1 << ir->type->vector_elements) - 1));
                    static_cast<ir_assignment *>(initializer)->rhs->accept(this);
                }
                else if (initializer->ir_type == ir_type_call)
                {
                    print_function_call_rhs(static_cast<ir_call *>(initializer));
                }
            }
        }
	}
}


void ir_print_glsl_visitor::visit(ir_function_signature *ir)
{
    assert(current_function == NULL);
    if (should_print_precision(ir, ir->return_type))
        print_precision (buffer, ir->return_type);

   print_type(buffer, ir->return_type, true);
   buffer.asprintf_append (" %s (", ir->function_name());

   // set current_function before starting so the parameters get tagged with ids
   current_function = ir;

   if (!ir->parameters.is_empty())
   {
	   buffer.asprintf_append ("\n");

	   indentation++; previous_skipped = false;
	   bool first = true;
	   foreach_in_list(ir_variable, inst, &ir->parameters)
       {
		  if (!first)
			  buffer.asprintf_append (",\n");

          bool old_skipped = skipped_this_ir;
          skipped_this_ir = false;

		  indent();
		  inst->accept(this);

          if (!skipped_this_ir && first)
              first = false;
          else if (skipped_this_ir && !first)
          {
              buffer.erase_last_line();
              buffer.erase_tail(1);
          }

          skipped_this_ir = old_skipped;
	   }
	   indentation--;

	   buffer.asprintf_append ("\n");
	   indent();
   }

   if (ir->body.is_empty())
   {
       current_function = NULL;
	   buffer.asprintf_append (");\n");
	   return;
   }

   buffer.asprintf_append (")\n");

   indent();
   buffer.asprintf_append ("{\n");
   indentation++; previous_skipped = false;
	
   foreach_in_list(ir_instruction, inst, &ir->body) {
      indent();
      inst->accept(this);
	   end_statement_line();
   }
   indentation--;
   indent();
   buffer.asprintf_append ("}\n");
   current_function = NULL;
}

void ir_print_glsl_visitor::visit(ir_function *ir)
{
    // print different signatures
    foreach_in_list(ir_function_signature, sig, &ir->signatures) 
    {
        if (sig->is_builtin())// && !sig->is_intrinsic)
            continue;
    
        indent();
        sig->accept(this);
        buffer.asprintf_append ("\n");
    }

   indent();
}


static const char *const operator_glsl_strs[] = {
		"~",
	"!",
	"-",
	"abs",
	"sign",
	"1.0/",
	"inversesqrt",
	"sqrt",
	"exp",
	"log",
	"exp2",
	"log2",
    "int",      // f2i
    "uint",     // f2u
    "float",    // i2f
    "bool",     // f2b
    "float",    // b2f
    "bool",     // i2b
    "int",      // b2i
    "float",    // u2f
    "uint",     // i2u
    "int",      // u2i
    "float",    // d2f
    "double",   // f2d
    "int",      // d2i
    "double",   // i2d
    "uint",     // d2u
    "double",   // u2d
    "bool",     // d2b
	"float",	// bit i2f
	"int",		// bit f2i
	"float",	// bit u2f
	"uint",		// bit f2u
	"any",
	"trunc",
	"ceil",
	"floor",
	"fract",
	"roundEven",
	"sin",
	"cos",
	"dFdx",
    "dFdx_coarse",
    "dFdx_fine",
	"dFdy",
    "dFdy_coarse",
    "dFdy_fine",
	"packSnorm2x16",
	"packSnorm4x8",
	"packUnorm2x16",
	"packUnorm4x8",
	"packHalf2x16",
	"unpackSnorm2x16",
	"unpackSnorm4x8",
	"unpackUnorm2x16",
	"unpackUnorm4x8",
	"unpackHalf2x16",
	"unpackHalf2x16_splitX_TODO",
	"unpackHalf2x16_splitY_TODO",
	"bitfieldReverse",
	"bitCount",
	"findMSB",
	"findLSB",
    "sat",
    "packDouble2x32",
    "unpackDouble2x32",
    "frexp_sig",
    "frexp_exp",
    "noise",
    "interpolate_at_centroid_TODO",
	"+",
	"-",
	"*",
	"*_imul_high_TODO",
	"/",
	"carry_TODO",
	"borrow_TODO",
	"mod",
	"<",
	">",
	"<=",
	">=",
	"equal",
	"notEqual",
	"==",
	"!=",
	"<<",
	">>",
	"&",
	"^",
	"|",
	"&&",
	"^^",
	"||",
	"dot",
	"min",
	"max",
	"pow",
	"packHalf2x16_split_TODO",
	"bfm_TODO",
	"uboloadTODO",
	"ldexp_TODO",
	"vectorExtract_TODO",
    "interpolate_at_offset_TODO",
    "interpolate_at_sample_TODO",
	"fma",
	"mix",
	"csel_TODO",
	"bfi_TODO",
	"bitfield_extract_TODO",
	"vector_insert_TODO",
	"bitfield_insert_TODO",
	"vectorTODO",
};

static const char *const operator_vec_glsl_strs[] = {
	"lessThan",
	"greaterThan",
	"lessThanEqual",
	"greaterThanEqual",
	"equal",
	"notEqual",
};


static bool is_binop_func_like(ir_expression_operation op, const glsl_type* type)
{
	if (op == ir_binop_equal || 
		op == ir_binop_nequal ||
		op == ir_binop_mod ||
		(op >= ir_binop_dot && op <= ir_binop_pow))
		return true;
	if (type->is_vector() && (op >= ir_binop_less && op <= ir_binop_nequal))
	{
		return true;
	}
	return false;
}

void ir_print_glsl_visitor::visit(ir_expression *ir)
{
	++this->expression_depth;
	newline_indent();
	
	if (ir->get_num_operands() == 1) {
		if (ir->operation >= ir_unop_f2i && ir->operation < ir_unop_any) {
			print_type(buffer, ir->type, true);
			buffer.asprintf_append ("(");
        } else if (ir->operation == ir_unop_saturate) {
            buffer.asprintf_append("(clamp((");
		} else if (ir->operation == ir_unop_rcp) {
			buffer.asprintf_append ("(1.0/(");
		} else {
			buffer.asprintf_append ("%s(", operator_glsl_strs[ir->operation]);
		}
		if (ir->operands[0])
			ir->operands[0]->accept(this);
		buffer.asprintf_append (")");
		if (ir->operation == ir_unop_rcp) {
			buffer.asprintf_append (")");
        } else if (ir->operation == ir_unop_saturate) {
            buffer.asprintf_append(", 0.0, 1.0))");
        }
	}
	else if (ir->operation == ir_binop_vector_extract)
	{
		// a[b]
		
		if (ir->operands[0])
			ir->operands[0]->accept(this);
		buffer.asprintf_append ("[");
		if (ir->operands[1])
			ir->operands[1]->accept(this);
		buffer.asprintf_append ("]");
	}
	else if (is_binop_func_like(ir->operation, ir->type))
	{
		if (ir->operation == ir_binop_mod)
		{
			buffer.asprintf_append ("(");
			print_type(buffer, ir->type, true);
			buffer.asprintf_append ("(");
		}
		if (ir->type->is_vector() && (ir->operation >= ir_binop_less && ir->operation <= ir_binop_nequal))
			buffer.asprintf_append ("%s (", operator_vec_glsl_strs[ir->operation-ir_binop_less]);
		else
			buffer.asprintf_append ("%s (", operator_glsl_strs[ir->operation]);
		
		if (ir->operands[0])
			ir->operands[0]->accept(this);
		buffer.asprintf_append (", ");
		if (ir->operands[1])
			ir->operands[1]->accept(this);
		buffer.asprintf_append (")");
		if (ir->operation == ir_binop_mod)
            buffer.asprintf_append ("))");
	}
	else if (ir->get_num_operands() == 2)
	{
		buffer.asprintf_append ("(");
		if (ir->operands[0])
			ir->operands[0]->accept(this);

		buffer.asprintf_append (" %s ", operator_glsl_strs[ir->operation]);

		if (ir->operands[1])
			ir->operands[1]->accept(this);
		buffer.asprintf_append (")");
	}
	else
	{
		// ternary op
		buffer.asprintf_append ("%s (", operator_glsl_strs[ir->operation]);
		if (ir->operands[0])
			ir->operands[0]->accept(this);
		buffer.asprintf_append (", ");
		if (ir->operands[1])
			ir->operands[1]->accept(this);
		buffer.asprintf_append (", ");
		if (ir->operands[2])
			ir->operands[2]->accept(this);
		buffer.asprintf_append (")");
	}
	
	newline_deindent();
	--this->expression_depth;
}

// [glsl_sampler_dim]
static const char* tex_sampler_dim_name[] = {
    "1D", "2D", "3D", "Cube", "Rect", "Buf", "External", "MS"
};
static int tex_sampler_dim_size[] = {
	1, 2, 3, 3, 2, 2, 2, 2
};

void ir_print_glsl_visitor::visit(ir_texture *ir)
{
    // handle textureSize separately
    if (ir->op == ir_txs)
    {
        buffer.asprintf_append("textureSize (");

        // sampler
        ir->sampler->accept(this);

        // lod
        buffer.asprintf_append(", ");
        ir->lod_info.lod->accept(this);

        // done
        buffer.asprintf_append(")");
    }
    else if (ir->op == ir_query_levels)
    {
        buffer.asprintf_append("textureQueryLevels (");
        ir->sampler->accept(this);
        buffer.asprintf_append(")");
    }
    else
    {
	    glsl_sampler_dim sampler_dim = (glsl_sampler_dim)ir->sampler->type->sampler_dimensionality;
	    const bool is_shadow = ir->sampler->type->sampler_shadow;
        const bool is_array = ir->sampler->type->sampler_array;
        const glsl_type* uv_type = ir->coordinate->type;
        const int uv_dim = uv_type->vector_elements;
        int sampler_uv_dim = tex_sampler_dim_size[sampler_dim];
        if (is_shadow)
            sampler_uv_dim += 1;
        if (is_array)
            sampler_uv_dim += 1;
        const bool is_proj = (uv_dim > sampler_uv_dim);
	
        // texture function name
        //ACS: shadow lookups and lookups with dimensionality included in the name were deprecated in 130
        if(language_version<130) 
        {
            buffer.asprintf_append ("%s", is_shadow ? "shadow" : "texture");
            buffer.asprintf_append ("%s", tex_sampler_dim_name[sampler_dim]);
        }
        else 
        {
            if (ir->op == ir_txf)
                buffer.asprintf_append ("texelFetch");
            else
                buffer.asprintf_append ("texture");
        }
	
	    if (is_proj)
		    buffer.asprintf_append ("Proj");
	    if (ir->op == ir_txl)
		    buffer.asprintf_append ("Lod");
	    if (ir->op == ir_txd)
		    buffer.asprintf_append ("Grad");
        if (ir->op == ir_txs)
            buffer.asprintf_append ("Size");
        if (ir->offset != NULL)
            buffer.asprintf_append ("Offset");
	
#if FIXME
	    if (m_state->es_shader)
	    {
		    if ( (is_shadow && m_state->EXT_shadow_samplers_enable) ||
			    (ir->op == ir_txl && m_state->EXT_shader_texture_lod_enable) )
		    {
			    buffer.asprintf_append ("EXT");
		    }
	    }
	
	    if(ir->op == ir_txd)
	    {
		    if(m_state->es_shader && m_state->EXT_shader_texture_lod_enable)
			    buffer.asprintf_append ("EXT");
		    else if(!m_state->es_shader && m_state->ARB_shader_texture_lod_enable)
			    buffer.asprintf_append ("ARB");
	    }
#endif
	
	    buffer.asprintf_append (" (");
	
	    // sampler
	    ir->sampler->accept(this);
	    buffer.asprintf_append (", ");
	
	    // texture coordinate
	    ir->coordinate->accept(this);
	
	    // lod bias
	    if (ir->op == ir_txb)
	    {
		    buffer.asprintf_append (", ");
		    ir->lod_info.bias->accept(this);
	    }
	
	    // lod
	    if (ir->op == ir_txl || ir->op == ir_txf)
	    {
		    buffer.asprintf_append (", ");
		    ir->lod_info.lod->accept(this);
	    }
	
	    // grad
	    if (ir->op == ir_txd)
	    {
		    buffer.asprintf_append (", ");
		    ir->lod_info.grad.dPdx->accept(this);
		    buffer.asprintf_append (", ");
		    ir->lod_info.grad.dPdy->accept(this);
	    }
	
       if (ir->offset != NULL) {
          buffer.asprintf_append (", ");
          ir->offset->accept(this);
       }
    /*
	
	
       if (ir->op != ir_txf) {
          if (ir->projector)
	     ir->projector->accept(this);
          else
	     buffer.asprintf_append ("1");

          if (ir->shadow_comparitor) {
	     buffer.asprintf_append (" ");
	     ir->shadow_comparitor->accept(this);
          } else {
	     buffer.asprintf_append (" ()");
          }
       }

       buffer.asprintf_append (" ");
       switch (ir->op)
       {
       case ir_tex:
          break;
       case ir_txb:
          ir->lod_info.bias->accept(this);
          break;
       case ir_txl:
       case ir_txf:
          ir->lod_info.lod->accept(this);
          break;
       case ir_txd:
          buffer.asprintf_append ("(");
          ir->lod_info.grad.dPdx->accept(this);
          buffer.asprintf_append (" ");
          ir->lod_info.grad.dPdy->accept(this);
          buffer.asprintf_append (")");
          break;
       };
	     */
       buffer.asprintf_append (")");
    }
}


void ir_print_glsl_visitor::visit(ir_swizzle *ir)
{
   const unsigned swiz[4] = {
      ir->mask.x,
      ir->mask.y,
      ir->mask.z,
      ir->mask.w,
   };

   if (ir->val->type == glsl_type::float_type || ir->val->type == glsl_type::int_type || ir->val->type == glsl_type::uint_type)
	{
		if (ir->mask.num_components != 1)
		{
			print_type(buffer, ir->type, true);
			buffer.asprintf_append ("(");
		}
	}

	ir->val->accept(this);
	
	if (ir->val->type == glsl_type::float_type || ir->val->type == glsl_type::int_type || ir->val->type == glsl_type::uint_type)
	{
		if (ir->mask.num_components != 1)
		{
			buffer.asprintf_append (")");
		}
		return;
	}

   buffer.asprintf_append (".");
   for (unsigned i = 0; i < ir->mask.num_components; i++) {
		buffer.asprintf_append ("%c", "xyzw"[swiz[i]]);
   }
}


void ir_print_glsl_visitor::visit(ir_dereference_variable *ir)
{
   ir_variable *var = ir->variable_referenced();
   print_var_name (var);
}


void ir_print_glsl_visitor::visit(ir_dereference_array *ir)
{
   ir->array->accept(this);
   buffer.asprintf_append ("[");
   ir->array_index->accept(this);
   buffer.asprintf_append ("]");
}


void ir_print_glsl_visitor::visit(ir_dereference_record *ir)
{
   ir->record->accept(this);
   buffer.asprintf_append (".%s", ir->field);
}


bool ir_print_glsl_visitor::try_print_array_assignment (ir_dereference* lhs, ir_rvalue* rhs)
{
	if (language_version >= 120)
		return false;
	ir_dereference_variable* rhsarr = rhs->as_dereference_variable();
	if (rhsarr == NULL)
		return false;
	const glsl_type* lhstype = lhs->type;
	const glsl_type* rhstype = rhsarr->type;
	if (!lhstype->is_array() || !rhstype->is_array())
		return false;
	if (lhstype->array_size() != rhstype->array_size())
		return false;
	if (lhstype->base_type != rhstype->base_type)
		return false;
	
	const unsigned size = rhstype->array_size();
	for (unsigned i = 0; i < size; i++)
	{
		lhs->accept(this);
		buffer.asprintf_append ("[%d]=", i);
		rhs->accept(this);
		buffer.asprintf_append ("[%d]", i);
		if (i != size-1)
			buffer.asprintf_append (";");
	}
	return true;
}

void ir_print_glsl_visitor::emit_assignment_part(ir_dereference* lhs, ir_rvalue* rhs, unsigned write_mask, ir_rvalue* dstIndex)
{
    lhs->accept(this);

	if (dstIndex)
	{
		// if dst index is a constant, then emit a swizzle
		ir_constant* dstConst = dstIndex->as_constant();
		if (dstConst)
		{
			const char* comps = "xyzw";
			char comp = comps[dstConst->get_int_component(0)];
			buffer.asprintf_append (".%c", comp);
		}
		else
		{
			buffer.asprintf_append ("[");
			dstIndex->accept(this);
			buffer.asprintf_append ("]");
		}
	}
	
	char mask[5];
	unsigned j = 0;
	const glsl_type* lhsType = lhs->type;
	const glsl_type* rhsType = rhs->type;
	if (!dstIndex && lhsType->matrix_columns <= 1 && lhsType->vector_elements > 1 && write_mask != (1<<lhsType->vector_elements)-1)
	{
		for (unsigned i = 0; i < 4; i++) {
			if ((write_mask & (1 << i)) != 0) {
				mask[j] = "xyzw"[i];
				j++;
			}
		}
		lhsType = glsl_type::get_instance(lhsType->base_type, j, 1);
	}
	mask[j] = '\0';
	bool hasWriteMask = false;
	if (mask[0])
	{
		buffer.asprintf_append (".%s", mask);
		hasWriteMask = true;
	}
	
	buffer.asprintf_append (" = ");
	
	bool typeMismatch = !dstIndex && (lhsType != rhsType);
	const bool addSwizzle = hasWriteMask && typeMismatch;
	if (typeMismatch)
	{
		if (!addSwizzle)
			print_type(buffer, lhsType, true);
		buffer.asprintf_append ("(");
	}
	
	rhs->accept(this);
	
	if (typeMismatch)
	{
		buffer.asprintf_append (")");
		if (addSwizzle)
			buffer.asprintf_append (".%s", mask);
	}
}


// Try to print (X = X + const) as (X += const), mostly to satisfy
// OpenGL ES 2.0 loop syntax restrictions.
static bool try_print_increment (ir_print_glsl_visitor* vis, ir_assignment* ir)
{
	if (ir->condition)
		return false;
	
	// Needs to be + on rhs
	ir_expression* rhsOp = ir->rhs->as_expression();
	if (!rhsOp || rhsOp->operation != ir_binop_add)
		return false;
	
	// Needs to write to whole variable
	ir_variable* lhsVar = ir->whole_variable_written();
	if (lhsVar == NULL)
		return false;
	
	// Types must match
	if (ir->lhs->type != ir->rhs->type)
		return false;
	
	// Type must be scalar
	if (!ir->lhs->type->is_scalar())
		return false;
	
	// rhs0 must be variable deref, same one as lhs
	ir_dereference_variable* rhsDeref = rhsOp->operands[0]->as_dereference_variable();
	if (rhsDeref == NULL)
		return false;
	if (lhsVar != rhsDeref->var)
		return false;
	
	// rhs1 must be a constant
	ir_constant* rhsConst = rhsOp->operands[1]->as_constant();
	if (!rhsConst)
		return false;
	
	// print variable name
	ir->lhs->accept (vis);
	
	// print ++ or +=const
	if (ir->lhs->type->base_type <= GLSL_TYPE_INT && rhsConst->is_one())
	{
		vis->buffer.asprintf_append ("++");
	}
	else
	{
		vis->buffer.asprintf_append(" += ");
		rhsConst->accept (vis);
	}
	
	return true;
}


void ir_print_glsl_visitor::visit(ir_assignment *ir)
{
    // globally scoped variables - initialized elsewhere. assignment cannot happen again at global scope.
    if (current_function == NULL)
    {
        skipped_this_ir = true;
        return;
    }

    // skip assignment to const variables since they're printed with the declaration
    if (ir->lhs->variable_referenced()->constant_value != NULL)
    {
        skipped_this_ir = true;
        return;
    }

#if FIXME
    // if this is a loop induction variable initial assignment, and we aren't inside loop body:
	// do not print it (will be printed when inside loop body)
	if (!inside_loop_body)
	{
		ir_variable* whole_var = ir->whole_variable_written();
		if (!ir->condition && whole_var)
		{
			loop_variable_state* inductor_state = loopstate->get_for_inductor(whole_var);
			if (inductor_state && inductor_state->private_induction_variable_count == 1 &&
                can_emit_canonical_for(inductor_state))
			{
				skipped_this_ir = true;
				return;
			}
		}
	}
#endif
	
// 	// assignments in global scope are postponed to main function
// 	if (current_function == NULL)
// 	{
// 		assert (!this->globals->main_function_done);
// 		this->globals->global_assignments.push_tail (new(this->globals->mem_ctx) ga_entry(ir));
// 		//buffer.asprintf_append ("//"); // for the ; that will follow (ugly, I know)
//         skipped_this_ir = true;
// 		return;
// 	}
	
	// if RHS is ir_triop_vector_insert, then we have to do some special dance. If source expression is:
	//   dst = vector_insert (a, b, idx)
	// then emit it like:
	//   dst = a;
	//   dst.idx = b;
	ir_expression* rhsOp = ir->rhs->as_expression();
	if (rhsOp && rhsOp->operation == ir_triop_vector_insert)
	{
		// skip assignment if lhs and rhs would be the same
		bool skip_assign = false;
		ir_dereference_variable* lhsDeref = ir->lhs->as_dereference_variable();
		ir_dereference_variable* rhsDeref = rhsOp->operands[0]->as_dereference_variable();
		if (lhsDeref && rhsDeref)
		{
			if (lhsDeref->var == rhsDeref->var)
				skip_assign = true;
		}
		
		if (!skip_assign)
		{
			emit_assignment_part(ir->lhs, rhsOp->operands[0], ir->write_mask, NULL);
			buffer.asprintf_append ("; ");
		}
		emit_assignment_part(ir->lhs, rhsOp->operands[1], ir->write_mask, rhsOp->operands[2]);
		return;
	}
	
	if (try_print_increment (this, ir))
		return;
		
	if (try_print_array_assignment (ir->lhs, ir->rhs))
		return;
		
   if (ir->condition)
   {
      ir->condition->accept(this);
	  buffer.asprintf_append (" ");
   }
	
	emit_assignment_part (ir->lhs, ir->rhs, ir->write_mask, NULL);
}

static void print_float (string_buffer& buffer, float f)
{
	// Kind of roundabout way, but this is to satisfy two things:
	// * MSVC and gcc-based compilers differ a bit in how they treat float
	//   widht/precision specifiers. Want to match for tests.
	// * GLSL (early version at least) require floats to have ".0" or
	//   exponential notation.
	char tmp[64];
	snprintf(tmp, 64, "%.6g", f);

	char* posE = NULL;
	posE = strchr(tmp, 'e');
	if (!posE)
		posE = strchr(tmp, 'E');

	// snprintf formats infinity as inf.0 or -inf.0, which isn't useful here.
	// GLSL has no infinity constant so print an equivalent expression instead.
	if (f == std::numeric_limits<float>::infinity())
		strcpy(tmp, "(1.0/0.0)");

	if (f == -std::numeric_limits<float>::infinity())
		strcpy(tmp, "(-1.0/0.0)");
	
	// Do similar thing for NaN
	if (f != f)
		strcpy(tmp, "(0.0/0.0)");

	#if _MSC_VER
	// While gcc would print something like 1.0e+07, MSVC will print 1.0e+007 -
	// only for exponential notation, it seems, will add one extra useless zero. Let's try to remove
	// that so compiler output matches.
	if (posE != NULL)
	{
		if((posE[1] == '+' || posE[1] == '-') && posE[2] == '0')
		{
			char* p = posE+2;
			while (p[0])
			{
				p[0] = p[1];
				++p;
			}
		}
	}
	#endif

	buffer.asprintf_append ("%s", tmp);

	// need to append ".0"?
	if (!strchr(tmp,'.') && (posE == NULL))
		buffer.asprintf_append(".0");
}

void ir_print_glsl_visitor::visit(ir_constant *ir)
{
	const glsl_type* type = ir->type;

	if (type == glsl_type::float_type)
	{
		print_float (buffer, ir->value.f[0]);
		return;
	}
	else if (type == glsl_type::int_type)
	{
		buffer.asprintf_append ("%d", ir->value.i[0]);
		return;
	}
	else if (type == glsl_type::uint_type)
	{
		// ES 2.0 doesn't support uints, neither does GLSL < 130
		if (language_version < 130 || (es_shader && language_version < 300))
			buffer.asprintf_append("%u", ir->value.u[0]);
		else
			buffer.asprintf_append("%uu", ir->value.u[0]);
		return;
	}

   const glsl_type *const base_type = ir->type->get_base_type();

   print_type(buffer, type, true);
   buffer.asprintf_append ("(");

   if (ir->type->is_array()) {
      for (unsigned i = 0; i < ir->type->length; i++)
      {
	 if (i != 0)
	    buffer.asprintf_append (", ");
	 ir->get_array_element(i)->accept(this);
      }
   } else if (ir->type->is_record()) {
      bool first = true;
      foreach_in_list(ir_constant, inst, &ir->components) {
	 if (!first)
	    buffer.asprintf_append (", ");
	 first = false;
	 inst->accept(this);
     } 
   }else {
      bool first = true;
      for (unsigned i = 0; i < ir->type->components(); i++) {
	 if (!first)
	    buffer.asprintf_append (", ");
	 first = false;
	 switch (base_type->base_type) {
	 case GLSL_TYPE_UINT:
	 {
		 // ES 2.0 doesn't support uints, neither does GLSL < 130
         if (language_version < 130 || (es_shader && language_version < 300))
			 buffer.asprintf_append("%u", ir->value.u[i]);
		 else
			 buffer.asprintf_append("%uu", ir->value.u[i]);
		 break;
	 }
	 case GLSL_TYPE_INT:   buffer.asprintf_append ("%d", ir->value.i[i]); break;
	 case GLSL_TYPE_FLOAT: print_float(buffer, ir->value.f[i]); break;
	 case GLSL_TYPE_BOOL:  buffer.asprintf_append ("%d", ir->value.b[i]); break;
	 default: assert(0);
	 }
      }
   }
   buffer.asprintf_append (")");
}


void ir_print_glsl_visitor::visit(ir_call *ir)
{
    // any calls occuring at global scope will be printed with the declaration
    if (current_function == NULL)
    {
        skipped_this_ir = true;
        return;
    }

    if (ir->return_deref)
    {
        visit(ir->return_deref);
        buffer.asprintf_append(" = ");
    }

    print_function_call_rhs(ir);
}

void ir_print_glsl_visitor::print_function_call_rhs(ir_call *ir)
{
    // TODO: Clean up once sampler states are removed
    buffer.asprintf_append("%s (", ir->callee_name());
    bool first = true;
    foreach_in_list(ir_instruction, inst, &ir->actual_parameters)
    {
        if (!first)
            buffer.asprintf_append(", ");

        bool old_skipped = skipped_this_ir;
        skipped_this_ir = false;

        inst->accept(this);

        if (!skipped_this_ir && first)
            first = false;
        else if (skipped_this_ir && !first)
            buffer.erase_tail(2);

        skipped_this_ir = old_skipped;
    }
    buffer.asprintf_append(")");
}


void
ir_print_glsl_visitor::visit(ir_return *ir)
{
   buffer.asprintf_append ("return");

   ir_rvalue *const value = ir->get_value();
   if (value) {
      buffer.asprintf_append (" ");
      value->accept(this);
   }
}


void
ir_print_glsl_visitor::visit(ir_discard *ir)
{
    if (ir->condition != NULL)
    {
        buffer.asprintf_append("if (");
        ir->condition->accept(this);
        buffer.asprintf_append(") { discard; }");
    }
    else
    {
        buffer.asprintf_append("discard");
    }
}


void
ir_print_glsl_visitor::visit(ir_if *ir)
{
   buffer.asprintf_append ("if (");
   ir->condition->accept(this);

   buffer.asprintf_append (") {\n");
	indentation++; previous_skipped = false;


   foreach_in_list(ir_instruction, inst, &ir->then_instructions) {
      indent();
      inst->accept(this);
	   end_statement_line();
   }

   indentation--;
   indent();
   buffer.asprintf_append ("}");

   if (!ir->else_instructions.is_empty())
   {
	   buffer.asprintf_append (" else {\n");
	   indentation++; previous_skipped = false;

	   foreach_in_list(ir_instruction, inst, &ir->else_instructions) {
		  indent();
		  inst->accept(this);
		   end_statement_line();
	   }
	   indentation--;
	   indent();
	   buffer.asprintf_append ("}");
   }
}

bool ir_print_glsl_visitor::can_emit_canonical_for (loop_variable_state *ls)
{
	if (ls == NULL)
		return false;
	
	if (ls->induction_variables.is_empty())
		return false;
	
	if (ls->terminators.is_empty())
		return false;
	
	// only support for loops with one terminator condition
	int terminatorCount = 0;
	foreach_in_list(exec_node, node, &ls->terminators) {
		++terminatorCount;
	}
	if (terminatorCount != 1)
		return false;

    return true;
}

bool ir_print_glsl_visitor::emit_canonical_for (ir_loop* ir)
{
	loop_variable_state* const ls = this->loopstate->get(ir);

    if (!can_emit_canonical_for(ls))
        return false;
	
	hash_table* terminator_hash = hash_table_ctor(0, hash_table_pointer_hash, hash_table_pointer_compare);
	hash_table* induction_hash = hash_table_ctor(0, hash_table_pointer_hash, hash_table_pointer_compare);
	
	buffer.asprintf_append("for (");
	//inside_loop_body = true;
	
#if FIXME
	// emit loop induction variable declarations.
	// only for loops with single induction variable, to avoid cases of different types of them
	if (ls->private_induction_variable_count == 1)
	{
        foreach_in_list(loop_variable, indvar, &ls->induction_variables)
		{
			if (!this->loopstate->get_for_inductor(indvar->var))
				continue;
			
			ir_variable* var = indvar->var;
			print_precision (var, var->type);
			print_type(buffer, var->type, false);
			buffer.asprintf_append (" ");
			print_var_name (var);
			print_type_post(buffer, var->type, false);
			if (indvar->initial_value)
			{
				buffer.asprintf_append (" = ");
				indvar->initial_value->accept(this);
			}
		}
	}
#endif
	buffer.asprintf_append("; ");
	
	// emit loop terminating conditions
	foreach_in_list(loop_terminator, term, &ls->terminators)
	{
		hash_table_insert(terminator_hash, term, term->ir);
		
		// IR has conditions in the form of "if (x) break",
		// whereas for loop needs them negated, in the form
		// if "while (x) continue the loop".
		// See if we can print them using syntax that reads nice.
		bool handled = false;
		ir_expression* term_expr = term->ir->condition->as_expression();
		if (term_expr)
		{
			// Binary comparison conditions
			const char* termOp = NULL;
			switch (term_expr->operation)
			{
				case ir_binop_less: termOp = ">="; break;
				case ir_binop_greater: termOp = "<="; break;
				case ir_binop_lequal: termOp = ">"; break;
				case ir_binop_gequal: termOp = "<"; break;
				case ir_binop_equal: termOp = "!="; break;
				case ir_binop_nequal: termOp = "=="; break;
				default: break;
			}
			if (termOp != NULL)
			{
				term_expr->operands[0]->accept(this);
				buffer.asprintf_append(" %s ", termOp);
				term_expr->operands[1]->accept(this);
				handled = true;
			}
			
			// Unary logic not
			if (!handled && term_expr->operation == ir_unop_logic_not)
			{
				term_expr->operands[0]->accept(this);
				handled = true;
			}
		}
		
		// More complex condition, print as "!(x)"
		if (!handled)
		{
			buffer.asprintf_append("!(");
			term->ir->condition->accept(this);
			buffer.asprintf_append(")");
		}
	}
	buffer.asprintf_append("; ");
	
	// emit loop induction variable updates
	bool first = true;
	foreach_in_list(loop_variable, indvar, &ls->induction_variables)
	{
		hash_table_insert(induction_hash, indvar, indvar->first_assignment);
		if (!first)
			buffer.asprintf_append(", ");
		visit(indvar->first_assignment);
		first = false;
	}
	buffer.asprintf_append(") {\n");
	
	//inside_loop_body = false;
	
	// emit loop body
	indentation++; previous_skipped = false;
	foreach_in_list(ir_instruction, inst, &ir->body_instructions) {
		// skip termination & induction statements,
		// they are part of "for" clause
		if (hash_table_find(terminator_hash, inst))
			continue;
		if (hash_table_find(induction_hash, inst))
			continue;
		
		indent();
		inst->accept(this);
		end_statement_line();
	}
	indentation--;
	
	indent();
	buffer.asprintf_append("}");
	
	hash_table_dtor (terminator_hash);
	hash_table_dtor (induction_hash);
	
	return true;
}

void ir_print_glsl_visitor::visit(ir_loop *ir)
{
	if (emit_canonical_for(ir))
		return;
	
	buffer.asprintf_append ("while (true) {\n");
	indentation++; previous_skipped = false;
	foreach_in_list(ir_instruction, inst, &ir->body_instructions) {
		indent();
		inst->accept(this);
		end_statement_line();
	}
	indentation--;
	indent();
	buffer.asprintf_append ("}");
}

void ir_print_glsl_visitor::visit(ir_loop_jump *ir)
{
   buffer.asprintf_append ("%s", ir->is_break() ? "break" : "continue");
}

void ir_print_glsl_visitor::visit(ir_emit_vertex *ir)
{
	buffer.asprintf_append ("emit-vertex-TODO");
}

void ir_print_glsl_visitor::visit(ir_end_primitive *ir)
{
	buffer.asprintf_append ("end-primitive-TODO");
}

void ir_print_glsl_visitor::visit(ir_barrier *ir)
{
    buffer.asprintf_append("barrier-TODO");
}
