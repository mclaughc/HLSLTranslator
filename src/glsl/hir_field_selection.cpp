/*
 * Copyright © 2010 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "ir.h"
#include "glsl_parser_extras.h"
#include "ast.h"
#include "glsl_types.h"

static ir_rvalue *handle_texture_object_methods(ir_rvalue *op, YYLTYPE *loc, ast_expression *call, const char *method, exec_list *instructions, struct _mesa_glsl_parse_state *state);

ir_rvalue *
_mesa_ast_field_selection_to_hir(const ast_expression *expr,
				 exec_list *instructions,
				 struct _mesa_glsl_parse_state *state)
{
   void *ctx = state;
   ir_rvalue *result = NULL;
   ir_rvalue *op;

   op = expr->subexpressions[0]->hir(instructions, state);

   /* There are two kinds of field selection.  There is the selection of a
    * specific field from a structure, and there is the selection of a
    * swizzle / mask from a vector.  Which is which is determined entirely
    * by the base type of the thing to which the field selection operator is
    * being applied.
    */
   YYLTYPE loc = expr->get_location();
   if (op->type->is_error()) {
      /* silently propagate the error */
   } else if (op->type->base_type == GLSL_TYPE_STRUCT
              || op->type->base_type == GLSL_TYPE_INTERFACE) {
      result = new(ctx) ir_dereference_record(op,
					      expr->primary_expression.identifier);

      if (result->type->is_error()) {
	 _mesa_glsl_error(& loc, state, "cannot access field `%s' of "
			  "structure",
			  expr->primary_expression.identifier);
      }
   } else if (expr->subexpressions[1] != NULL) {
      /* Handle "method calls" in GLSL 1.20 - namely, array.length() */
      if (!state->in_hlsl_mode())
         state->check_version(120, 300, &loc, "methods not supported");

      ast_expression *call = expr->subexpressions[1];
      assert(call->oper == ast_function_call);

      const char *method;
      method = call->subexpressions[0]->primary_expression.identifier;

      /* handle hlsl objects */
      if (state->in_hlsl_mode())
      {
          /* texture methods */
          if (op->type->base_type == GLSL_TYPE_SAMPLER)
              return handle_texture_object_methods(op, &loc, call, method, instructions, state);
      }
      else
      {
          if (strcmp(method, "length") == 0) {
             if (!call->expressions.is_empty())
                _mesa_glsl_error(&loc, state, "length method takes no arguments");

             if (op->type->is_array()) {
                if (op->type->is_unsized_array())
                   _mesa_glsl_error(&loc, state, "length called on unsized array");

                result = new(ctx) ir_constant(op->type->array_size());
             } else if (op->type->is_vector()) {
                if (state->ARB_shading_language_420pack_enable) {
                   /* .length() returns int. */
                   result = new(ctx) ir_constant((int) op->type->vector_elements);
                } else {
                   _mesa_glsl_error(&loc, state, "length method on matrix only available"
                                                 "with ARB_shading_language_420pack");
                }
             } else if (op->type->is_matrix()) {
                if (state->ARB_shading_language_420pack_enable) {
                   /* .length() returns int. */
                   result = new(ctx) ir_constant((int) op->type->matrix_columns);
                } else {
                   _mesa_glsl_error(&loc, state, "length method on matrix only available"
                                                 "with ARB_shading_language_420pack");
                }
             }
          } else {
	     _mesa_glsl_error(&loc, state, "unknown method: `%s'", method);
          }
      }
   } else if (op->type->is_vector() ||
              ((state->ARB_shading_language_420pack_enable || state->in_hlsl_mode()) &&
               op->type->is_scalar())) {
      ir_swizzle *swiz = ir_swizzle::create(op,
					    expr->primary_expression.identifier,
					    op->type->vector_elements);
      if (swiz != NULL) {
	 result = swiz;
      } else {
	 /* FINISHME: Logging of error messages should be moved into
	  * FINISHME: ir_swizzle::create.  This allows the generation of more
	  * FINISHME: specific error messages.
	  */
	 _mesa_glsl_error(& loc, state, "invalid swizzle / mask `%s'",
			  expr->primary_expression.identifier);
      }
   } else {
      _mesa_glsl_error(& loc, state, "cannot access field `%s' of "
		       "non-structure / non-vector",
		       expr->primary_expression.identifier);
   }

   return result ? result : ir_rvalue::error_value(ctx);
}

static ir_rvalue *handle_texture_object_methods(ir_rvalue *op, YYLTYPE *loc, ast_expression *call, const char *method, exec_list *instructions, struct _mesa_glsl_parse_state *state)
{
    void *ctx = ralloc_parent(op);

    // @TODO remove hlsl_sampler_state, do the split here
    // @TODO consider generating calls to the texture instrinsics here

    // get offset type
    const glsl_type *coordinate_offset_type = glsl_type::get_instance(GLSL_TYPE_INT, op->type->coordinate_components(), 1);
   
    // methods
    if (strcmp(method, "Sample") == 0)
    {
        if (call->expressions.length() < 2 || call->expressions.length() > 3)
        {
            state->add_error_at(loc, "Sample method takes 2-3 arguments.");
            return ir_rvalue::error_value(ctx);
        }
        else
        {
            ir_texture *tex = new (ctx)ir_texture(ir_tex);
            tex->set_sampler(op->as_dereference(), op->type->sampler_data_type());
            tex->hlsl_sampler_state = exec_node_data(ast_expression, call->expressions.node_at_index(0), link)->hir(instructions, state);
            tex->coordinate = exec_node_data(ast_expression, call->expressions.node_at_index(1), link)->hir(instructions, state);
            if (call->expressions.length() > 2)
                tex->offset = exec_node_data(ast_expression, call->expressions.node_at_index(2), link)->hir(instructions, state);

            // check sampler state return type
            if (tex->hlsl_sampler_state != NULL && tex->hlsl_sampler_state->type != glsl_type::SamplerState_type)
            {
                state->add_error_at(loc, "expected SamplerState sampler, got %s", tex->hlsl_sampler_state->type->name);
                return ir_rvalue::error_value(ctx);
            }

            // handle typed textures, ie Texture2D<float> return types
            if (op->type->template_inner_type != NULL)
            {
                // convert to the template type
                return convert_vector_type(op->type->template_inner_type, tex, state);
            }
            else
            {
                // no conversion
                return tex;
            }
        }
    }
    else if (strcmp(method, "SampleLevel") == 0)
    {
        if (call->expressions.length() < 3 || call->expressions.length() > 4)
        {
            state->add_error_at(loc, "Sample method takes 3-4 arguments.");
            return ir_rvalue::error_value(ctx);
        }
        else
        {
            ir_texture *tex = new (ctx) ir_texture (ir_txl);
            tex->set_sampler(op->as_dereference(), op->type->sampler_data_type());
            tex->hlsl_sampler_state = exec_node_data(ast_expression, call->expressions.node_at_index(0), link)->hir(instructions, state);
            tex->coordinate = exec_node_data(ast_expression, call->expressions.node_at_index(1), link)->hir(instructions, state);
            tex->lod_info.lod = exec_node_data(ast_expression, call->expressions.node_at_index(2), link)->hir(instructions, state);
            apply_implicit_conversion(glsl_type::float_type, tex->lod_info.lod, state);
            if (call->expressions.length() > 3)
            {
                apply_implicit_conversion(coordinate_offset_type, tex->offset, state);
                tex->offset = exec_node_data(ast_expression, call->expressions.node_at_index(3), link)->hir(instructions, state);
            }

            // check sampler state return type
            if (tex->hlsl_sampler_state != NULL && tex->hlsl_sampler_state->type != glsl_type::SamplerState_type)
            {
                state->add_error_at(loc, "expected SamplerState sampler, got %s", tex->hlsl_sampler_state->type->name);
                return ir_rvalue::error_value(ctx);
            }

            // handle typed textures, ie Texture2D<float> return types
            if (op->type->template_inner_type != NULL)
            {
                // convert to the template type
                return convert_vector_type(op->type->template_inner_type, tex, state);
            }
            else
            {
                // no conversion
                return tex;
            }
        }
    }
    else if (strcmp(method, "SampleCmp") == 0 || strcmp(method, "SampleCmpLevelZero") == 0)
    {
        // the sampler will be converted to a shadow type later
        // NOTE: annoyingly GLSL doesn't have textureLod for shadow types with dimensions >1D :S
        bool use_level_zero = (strcmp(method, "SampleCmpLevelZero") == 0 && op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_1D);
        ir_texture *tex = new (ctx) ir_texture (use_level_zero ? ir_txl : ir_tex);
        tex->sampler = op->as_dereference();
        tex->type = glsl_type::float_type;
        tex->hlsl_sampler_state = exec_node_data(ast_expression, call->expressions.node_at_index(0), link)->hir(instructions, state);
        tex->coordinate = exec_node_data(ast_expression, call->expressions.node_at_index(1), link)->hir(instructions, state);
        if (use_level_zero)
            tex->lod_info.lod = new (ctx) ir_constant(0.0f, 1);
        tex->shadow_comparitor = exec_node_data(ast_expression, call->expressions.node_at_index(2), link)->hir(instructions, state);
        if (call->expressions.length() > 3)
        {
            apply_implicit_conversion(coordinate_offset_type, tex->offset, state);
            tex->offset = exec_node_data(ast_expression, call->expressions.node_at_index(3), link)->hir(instructions, state);
        }

        // check sampler state return type
        if (tex->hlsl_sampler_state != NULL && tex->hlsl_sampler_state->type != glsl_type::SamplerComparisonState_type)
        {
            state->add_error_at(loc, "expected SamplerComparisonState sampler, got %s", tex->hlsl_sampler_state->type->name);
            return ir_rvalue::error_value(ctx);
        }

        return tex;
    }
    else if (strcmp(method, "Load") == 0)
    {
        // split packed vector to coords+lod
        ir_rvalue *coords = exec_node_data(ast_expression, call->expressions.node_at_index(0), link)->hir(instructions, state);
        if (coords == NULL || coords->type->base_type != GLSL_TYPE_INT || coords->type->vector_elements != (op->type->coordinate_components() + 1))
        {
            state->add_error_at(loc, "Texture Load call must have integer coordinates of components + 1");
            return ir_rvalue::error_value(ctx);
        }
        else
        {
            // emit texel fetch op, @TODO Handle texture buffers, @TODO Multisample
            ir_texture *tex = new (ctx) ir_texture(ir_txf);
            tex->set_sampler(op->as_dereference(), op->type->sampler_data_type());
            tex->coordinate = new (ctx) ir_swizzle(coords, 0, 1, 2, 3, op->type->coordinate_components());
            tex->lod_info.lod = new (ctx) ir_swizzle(coords, op->type->coordinate_components(), 0, 0, 0, 1);
            if (call->expressions.length() > 1)
            {
                apply_implicit_conversion(coordinate_offset_type, tex->offset, state);
                tex->offset = exec_node_data(ast_expression, call->expressions.node_at_index(1), link)->hir(instructions, state);
            }

            // handle typed textures, ie Texture2D<float> return types
            if (op->type->template_inner_type != NULL)
            {
                // convert to the template type
                return convert_vector_type(op->type->template_inner_type, tex, state);
            }
            else
            {
                // no conversion
                return tex;
            }
        }
    }
    else if (strcmp(method, "GetDimensions") == 0)
    {
        // find number of components
        unsigned int num_indices = UINT32_MAX - 10;
        if (op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_1D)
            num_indices = 1;
        else if (op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_2D || op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_CUBE || op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_RECT || op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_MS)
            num_indices = 2;
        else if (op->type->sampler_dimensionality == GLSL_SAMPLER_DIM_3D)
            num_indices = 3;

        // check argument count
        if (call->expressions.length() < num_indices)
        {
            state->add_error_at(loc, "GetDimensions method takes at least %u arguments.", num_indices);
            return ir_rvalue::error_value(ctx);
        }
        else
        {
            ir_texture *tex = new (ctx)ir_texture(ir_txs);
            tex->sampler = op->as_dereference();
            tex->type = glsl_type::ivec(num_indices);

            // has mipmap?
            unsigned int base = 0;
            if (call->expressions.length() <= num_indices)
            {
                tex->lod_info.lod = new (ctx)ir_constant((int)0, 1);
            }
            else
            {
                if (call->expressions.length() < (num_indices + 2))
                {
                    state->add_error_at(loc, "GetDimensions method with mip level requires numberOfLevels specified.");
                    return ir_rvalue::error_value(ctx);
                }

                ir_rvalue *lod_expr = exec_node_data(ast_expression, call->expressions.node_at_index(0), link)->hir(instructions, state);
                if (lod_expr != NULL)
                {
                    apply_implicit_conversion(glsl_type::int_type, lod_expr, state);
                    tex->lod_info.lod = lod_expr;
                }

                ir_rvalue *levels_expr = exec_node_data(ast_expression, call->expressions.node_at_index(1 + num_indices), link)->hir(instructions, state);
                if (levels_expr != NULL)
                {
                    ir_texture *levels = new (ctx)ir_texture(ir_query_levels);
                    levels->sampler = op->as_dereference();
                    levels->type = glsl_type::int_type;

                    ir_rvalue *levels_value = levels;
                    apply_implicit_conversion(levels_expr->type, levels_value, state);
                    ir_assignment *asgn = new (ctx) ir_assignment(levels_expr, levels_value);
                    instructions->push_tail(asgn);
                }

                base = 1;
            }

            // assign to the parameters
            ir_rvalue *out_loc;
            ir_rvalue *swizzle;

            // width
            out_loc = exec_node_data(ast_expression, call->expressions.node_at_index(base + 0), link)->hir(instructions, state);
            swizzle = (out_loc != NULL) ? ir_swizzle::create(tex, "x", num_indices) : NULL;
            if (swizzle != NULL)
            {
                apply_implicit_conversion(out_loc->type, swizzle, state);
                instructions->push_tail(new (ctx)ir_assignment(out_loc, swizzle));

                // height
                if (num_indices > 1)
                {
                    out_loc = exec_node_data(ast_expression, call->expressions.node_at_index(base + 1), link)->hir(instructions, state);
                    swizzle = (out_loc != NULL) ? ir_swizzle::create(tex, "y", num_indices) : NULL;
                    if (swizzle != NULL)
                    {
                        apply_implicit_conversion(out_loc->type, swizzle, state);
                        instructions->push_tail(new (ctx)ir_assignment(out_loc, swizzle));

                        // depth
                        if (num_indices > 2)
                        {
                            out_loc = exec_node_data(ast_expression, call->expressions.node_at_index(base + 2), link)->hir(instructions, state);
                            swizzle = (out_loc != NULL) ? ir_swizzle::create(tex, "z", num_indices) : NULL;
                            if (swizzle != NULL)
                            {
                                apply_implicit_conversion(out_loc->type, swizzle, state);
                                instructions->push_tail(new (ctx)ir_assignment(out_loc, swizzle));
                            }
                        }
                    }
                }
            }
        }

        // we're not returning anything
        return NULL;
    }
    else
    {
        state->add_error_at(loc, "unknown texture object method: '%s'", method);
        return ir_rvalue::error_value(ctx);
    }
}
