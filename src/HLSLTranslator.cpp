#include "HLSLTranslator.h"
#include <cassert>

#include "ast.h"
#include "glsl_parser_extras.h"
#include "ir_optimization.h"
#include "program.h"
#include "loop_analysis.h"
#include "standalone_scaffolding.h"

#include "ir_print_glsl_visitor.h"
#include "ir_uniform.h"

extern "C" void
_mesa_error_no_memory(const char *caller)
{
    fprintf(stderr, "Mesa error: out of memory in %s", caller);
    abort();
}

void
linker_error(struct gl_shader_program *prog, const char *fmt, ...)
{
    abort();
}

static void InitializeGLContext(gl_context *ctx, int glslVersion, bool glslES)
{
    initialize_context_to_defaults(ctx, (glslES) ? API_OPENGLES2 : API_OPENGL_CORE);

    /* The standalone compiler needs to claim support for almost
    * everything in order to compile the built-in functions.
    */
   ctx->Const.GLSLVersion = glslVersion;
   ctx->Const.ForceGLSLVersion = glslVersion;
   ctx->Const.GLSLSkipStrictMaxUniformLimitCheck = true;
   ctx->Const.MaxComputeWorkGroupCount[0] = 65535;
   ctx->Const.MaxComputeWorkGroupCount[1] = 65535;
   ctx->Const.MaxComputeWorkGroupCount[2] = 65535;
   ctx->Const.MaxComputeWorkGroupSize[0] = 1024;
   ctx->Const.MaxComputeWorkGroupSize[1] = 1024;
   ctx->Const.MaxComputeWorkGroupSize[2] = 64;
   ctx->Const.MaxComputeWorkGroupInvocations = 1024;
   ctx->Const.Program[MESA_SHADER_COMPUTE].MaxTextureImageUnits = 16;
   ctx->Const.Program[MESA_SHADER_COMPUTE].MaxUniformComponents = 1024;
   ctx->Const.Program[MESA_SHADER_COMPUTE].MaxCombinedUniformComponents = 1024;
   ctx->Const.Program[MESA_SHADER_COMPUTE].MaxInputComponents = 0; /* not used */
   ctx->Const.Program[MESA_SHADER_COMPUTE].MaxOutputComponents = 0; /* not used */

   /* Disable varying packing, this could potentially improve performance later on though.. */
   ctx->Const.DisableVaryingPacking = true;

   // todo: split to es/desktop
   if (!glslES)
   {
       switch (ctx->Const.GLSLVersion) {
       case 110:
       case 120:
           ctx->Const.MaxClipPlanes = 6;
           ctx->Const.MaxCombinedTextureImageUnits = 2;
           ctx->Const.MaxDrawBuffers = 1;
           ctx->Const.MinProgramTexelOffset = 0;
           ctx->Const.MaxProgramTexelOffset = 0;
           ctx->Const.MaxLights = 8;
           ctx->Const.MaxTextureCoordUnits = 2;
           ctx->Const.MaxTextureUnits = 2;

           ctx->Const.Program[MESA_SHADER_VERTEX].MaxAttribs = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits = 0;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformComponents = 512;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxCombinedUniformComponents = 512;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxInputComponents = 0; /* not used */
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents = 32;

           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits =
               ctx->Const.MaxCombinedTextureImageUnits;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformComponents = 64;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxCombinedUniformComponents = 64;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents =
               ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxOutputComponents = 0; /* not used */

           ctx->Const.MaxVarying = ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents / 4;
           break;
       case 130:
       case 140:
           ctx->Const.MaxClipPlanes = 8;
           ctx->Const.MaxCombinedTextureImageUnits = 16;
           ctx->Const.MaxDrawBuffers = 8;
           ctx->Const.MinProgramTexelOffset = -8;
           ctx->Const.MaxProgramTexelOffset = 7;
           ctx->Const.MaxLights = 8;
           ctx->Const.MaxTextureCoordUnits = 8;
           ctx->Const.MaxTextureUnits = 2;

           ctx->Const.Program[MESA_SHADER_VERTEX].MaxAttribs = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxInputComponents = 0; /* not used */
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents = 64;

           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents =
               ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxOutputComponents = 0; /* not used */

           ctx->Const.MaxVarying = ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents / 4;
           break;
       case 150:
       case 330:
       case 400:
       case 410:
       case 420:
       case 430:
       case 440:
       case 450:
           ctx->Const.MaxClipPlanes = 8;
           ctx->Const.MaxDrawBuffers = 8;
           ctx->Const.MinProgramTexelOffset = -8;
           ctx->Const.MaxProgramTexelOffset = 7;
           ctx->Const.MaxLights = 8;
           ctx->Const.MaxTextureCoordUnits = 8;
           ctx->Const.MaxTextureUnits = 2;

           ctx->Const.Program[MESA_SHADER_VERTEX].MaxAttribs = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformBlocks = 64;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxInputComponents = 0; /* not used */
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents = 64;

           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxUniformBlocks = 64;
           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxInputComponents =
               ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents;
           ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxOutputComponents = 128;

           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformBlocks = 64;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents =
               ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxOutputComponents;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxOutputComponents = 0; /* not used */

           ctx->Const.MaxCombinedTextureImageUnits =
               ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits
               + ctx->Const.Program[MESA_SHADER_GEOMETRY].MaxTextureImageUnits
               + ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits;

           ctx->Const.MaxGeometryOutputVertices = 256;
           ctx->Const.MaxGeometryTotalOutputComponents = 1024;
           ctx->Const.MaxCombinedUniformBlocks = 64;
           ctx->Const.MaxUniformBlockSize = 1024;

           //      ctx->Const.MaxGeometryVaryingComponents = 64;

           ctx->Const.MaxVarying = 60 / 4;
           break;
       }
   }
   else
   {
       ctx->Extensions.ARB_ES2_compatibility = true;
       ctx->Extensions.ARB_ES3_compatibility = true;

       switch (ctx->Const.GLSLVersion) {
       case 100:
           ctx->Const.MaxClipPlanes = 0;
           ctx->Const.MaxCombinedTextureImageUnits = 8;
           ctx->Const.MaxDrawBuffers = 2;
           ctx->Const.MinProgramTexelOffset = 0;
           ctx->Const.MaxProgramTexelOffset = 0;
           ctx->Const.MaxLights = 0;
           ctx->Const.MaxTextureCoordUnits = 0;
           ctx->Const.MaxTextureUnits = 8;

           ctx->Const.Program[MESA_SHADER_VERTEX].MaxAttribs = 8;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits = 0;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformComponents = 128 * 4;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxCombinedUniformComponents = 128 * 4;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxInputComponents = 0; /* not used */
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents = 32;

           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits =
               ctx->Const.MaxCombinedTextureImageUnits;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformComponents = 16 * 4;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxCombinedUniformComponents = 16 * 4;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents =
               ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxOutputComponents = 0; /* not used */

           ctx->Const.MaxVarying = ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents / 4;
           break;

       case 300:
           ctx->Const.MaxClipPlanes = 8;
           ctx->Const.MaxCombinedTextureImageUnits = 32;
           ctx->Const.MaxDrawBuffers = 4;
           ctx->Const.MinProgramTexelOffset = -8;
           ctx->Const.MaxProgramTexelOffset = 7;
           ctx->Const.MaxLights = 0;
           ctx->Const.MaxTextureCoordUnits = 0;
           ctx->Const.MaxTextureUnits = 0;

           ctx->Const.Program[MESA_SHADER_VERTEX].MaxAttribs = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxCombinedUniformComponents = 1024;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxUniformBlocks = 64;
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxInputComponents = 0; /* not used */
           ctx->Const.Program[MESA_SHADER_VERTEX].MaxOutputComponents = 16 * 4;

           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxTextureImageUnits = 16;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformComponents = 224;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxCombinedUniformComponents = 224;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxUniformBlocks = 64;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents = 15 * 4;
           ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxOutputComponents = 0; /* not used */

           ctx->Const.MaxCombinedUniformBlocks = 64;
           ctx->Const.MaxUniformBlockSize = 1024;
           ctx->Const.MaxVarying = ctx->Const.Program[MESA_SHADER_FRAGMENT].MaxInputComponents / 4;
           break;
       }
   }

    ctx->Driver.NewShader = _mesa_new_shader;
    //ctx->Driver.DeleteShader = _mesa_delete_shader;
}

static void
set_shader_inout_layout(struct gl_shader *shader,
             struct _mesa_glsl_parse_state *state)
{
   if (shader->Stage != MESA_SHADER_GEOMETRY) {
      /* Should have been prevented by the parser. */
      assert(!state->in_qualifier->flags.i);
      assert(!state->out_qualifier->flags.i);
   }

   if (shader->Stage != MESA_SHADER_COMPUTE) {
      /* Should have been prevented by the parser. */
      assert(!state->cs_input_local_size_specified);
   }

   if (shader->Stage != MESA_SHADER_FRAGMENT) {
      /* Should have been prevented by the parser. */
      assert(!state->fs_uses_gl_fragcoord);
      assert(!state->fs_redeclares_gl_fragcoord);
      assert(!state->fs_pixel_center_integer);
      assert(!state->fs_origin_upper_left);
   }

   switch (shader->Stage) {
   case MESA_SHADER_GEOMETRY:
      shader->Geom.VerticesOut = 0;
      if (state->out_qualifier->flags.q.max_vertices)
         shader->Geom.VerticesOut = state->out_qualifier->max_vertices;

      if (state->gs_input_prim_type_specified) {
         shader->Geom.InputType = state->in_qualifier->prim_type;
      } else {
         shader->Geom.InputType = PRIM_UNKNOWN;
      }

      if (state->out_qualifier->flags.q.prim_type) {
         shader->Geom.OutputType = state->out_qualifier->prim_type;
      } else {
         shader->Geom.OutputType = PRIM_UNKNOWN;
      }

      shader->Geom.Invocations = 0;
      if (state->in_qualifier->flags.q.invocations)
         shader->Geom.Invocations = state->in_qualifier->invocations;
      break;

   case MESA_SHADER_COMPUTE:
      if (state->cs_input_local_size_specified) {
         for (int i = 0; i < 3; i++)
            shader->Comp.LocalSize[i] = state->cs_input_local_size[i];
      } else {
         for (int i = 0; i < 3; i++)
            shader->Comp.LocalSize[i] = 0;
      }
      break;

   case MESA_SHADER_FRAGMENT:
      shader->redeclares_gl_fragcoord = state->fs_redeclares_gl_fragcoord;
      shader->uses_gl_fragcoord = state->fs_uses_gl_fragcoord;
      shader->pixel_center_integer = state->fs_pixel_center_integer;
      shader->origin_upper_left = state->fs_origin_upper_left;
      shader->ARB_fragment_coord_conventions_enable =
         state->ARB_fragment_coord_conventions_enable;
      break;

   default:
      /* Nothing to do. */
      break;
   }
}

static void do_optimization_passes(exec_list* ir, bool linked, const struct gl_shader_compiler_options *options, _mesa_glsl_parse_state* state, void* mem_ctx)
{
    bool progress;
    do {
        progress = false;
        bool progress2;
        if (linked) {
            progress2 = do_function_inlining(ir); progress |= progress2;
            progress2 = do_dead_functions(ir); progress |= progress2;
            progress2 = do_structure_splitting(ir); progress |= progress2;
        }
        progress2 = do_if_simplification(ir); progress |= progress2;
        progress2 = opt_flatten_nested_if_blocks(ir); progress |= progress2;
        //progress2 = propagate_precision(ir); progress |= progress2;
        progress2 = do_copy_propagation(ir); progress |= progress2;
        progress2 = do_copy_propagation_elements(ir); progress |= progress2;
//         if (state->es_shader && linked)
//         {
//             progress2 = optimize_split_vectors(ir, linked, OPT_SPLIT_ONLY_LOOP_INDUCTORS); progress |= progress2;
//         }
        if (linked)
        {
            progress2 = do_vectorize(ir); progress |= progress2;
        }
        if (linked) {
            progress2 = do_dead_code(ir, false); progress |= progress2;
        }
        else {
            progress2 = do_dead_code_unlinked(ir); progress |= progress2;
        }
        progress2 = do_dead_code_local(ir); progress |= progress2;
        //progress2 = propagate_precision(ir); progress |= progress2;
        progress2 = do_tree_grafting(ir); progress |= progress2;
        progress2 = do_constant_propagation(ir); progress |= progress2;
        if (linked) {
            progress2 = do_constant_variable(ir); progress |= progress2;
        }
        else {
            progress2 = do_constant_variable_unlinked(ir); progress |= progress2;
        }
        progress2 = do_constant_folding(ir); progress |= progress2;
        progress2 = do_cse(ir); progress |= progress2;
        progress2 = do_algebraic(ir, true/*FIXME*/, options); progress |= progress2;
        progress2 = do_lower_jumps(ir); progress |= progress2;
        progress2 = do_vec_index_to_swizzle(ir); progress |= progress2;
        progress2 = do_swizzle_swizzle(ir); progress |= progress2;
        progress2 = do_noop_swizzle(ir); progress |= progress2;
        progress2 = optimize_split_arrays(ir, linked); progress |= progress2;
        //progress2 = optimize_split_vectors(ir, linked, OPT_SPLIT_ONLY_UNUSED); progress |= progress2;
        progress2 = optimize_redundant_jumps(ir); progress |= progress2;
        // do loop stuff only when linked; otherwise causes duplicate loop induction variable
        // problems (ast-in.txt test)
        if (linked)
        {
            loop_state *ls = analyze_loop_variables(ir);
            if (ls->loop_found) {
                progress2 = set_loop_controls(ir, ls); progress |= progress2;
                progress2 = unroll_loops(ir, ls, options); progress |= progress2;
            }
            delete ls;
        }
    } while (progress);
}

static void MesaCleanup()
{
    _mesa_glsl_release_types();
    _mesa_glsl_release_builtin_functions();
}

static gl_shader_program *AllocateProgram(void *mem_ctx)
{
    gl_shader_program *pProgram = rzalloc(mem_ctx, gl_shader_program);

    // strings
    pProgram->InfoLog = ralloc_strdup(mem_ctx, "");

    // allocate tables
    pProgram->AttributeBindings = new string_to_uint_map();
    pProgram->FragDataBindings = new string_to_uint_map();
    pProgram->FragDataIndexBindings = new string_to_uint_map();

    return pProgram;
}

static void DeallocateProgram(gl_shader_program *pProgram)
{
    // the info log does not get parented to the program. fix this.
    ralloc_free(pProgram->InfoLog);

    // clean up the string maps
    delete pProgram->UniformHash;
    delete pProgram->FragDataIndexBindings;
    delete pProgram->FragDataBindings;
    delete pProgram->AttributeBindings;
    ralloc_free(pProgram);
}

struct HLSLTranslatorContext
{
    gl_context *pGLContext;
    gl_shader *pGLShader;
    _mesa_glsl_parse_state *pParseState;
};

static char *InternalPreprocessHLSL(void *pMemoryContext, const char *fileName, const char *shaderSource, size_t shaderSourceLength, bool glslES, int glslVersion, const HLSLTranslatorMacro *pMacros, size_t nMacros, HLSLTranslator_IncludeOpenCallback includeOpenCallback, HLSLTranslator_IncludeCloseCallback includeCloseCallback, void *includeContext, char **infoLog)
{
    void *root = ralloc_context(pMemoryContext);

    char *realShaderSource = ralloc_strdup(root, "");
    ralloc_strncat(&realShaderSource, shaderSource, shaderSourceLength);

    // create macro list
    HLSLTranslatorMacro *temp_macros = (HLSLTranslatorMacro *)ralloc_size(root, sizeof(HLSLTranslatorMacro) * (nMacros + 2));
    size_t num_macros = nMacros;
    for (size_t i = 0; i < num_macros; i++)
    {
        temp_macros[i].Name = pMacros[i].Name;
        temp_macros[i].Value = pMacros[i].Value;
    }
    temp_macros[num_macros].Name = (glslES) ? "__OPENGL_ES__" : "__OPENGL__";
    temp_macros[num_macros++].Value = "1";
    temp_macros[num_macros].Name = "GLSL_VERSION";
    temp_macros[num_macros++].Value = ralloc_asprintf(root, "%d", glslVersion);
    
    // preprocess this source
    char *preprocessedSource = realShaderSource;
    int preprocessError = hlslpp_preprocess(root, fileName, &preprocessedSource, infoLog, (hlslpp_macro *)temp_macros, num_macros,
                                            includeOpenCallback, includeCloseCallback, includeContext);

    // handle errors
    if (preprocessError != 0)
    {
        // free the output
        ralloc_free(root);
        return nullptr;
    }

    // done
    ralloc_steal(pMemoryContext, preprocessedSource);
    ralloc_free(root);
    return preprocessedSource;
}

static bool PostShaderCompile(gl_context *pGLContext, gl_shader *shader, _mesa_glsl_parse_state *state, HLSLTranslatorOptimizationLevel optimizationLevel, HLSLTranslatorOutput *pOutput)
{
#if 0
    foreach_list_typed(ast_node, ast, link, &state->translation_unit) {
        ast->print();
    }
    printf("\n\n");
#endif

    // convert ast to ir
    ralloc_free(shader->ir);
    shader->ir = new(shader) exec_list;
    if (!state->translation_unit.is_empty())
        _mesa_ast_to_hir(shader->ir, state);

#if 0
    /* Print out the unoptimized IR. */
    _mesa_print_ir(stdout, shader->ir, state);
#endif

    if (!state->error) 
        validate_ir_tree(shader->ir);

    // handle any errors
    if (state->error)
    {
        ralloc_asprintf_append(&pOutput->InfoLog, "compiling shader failed.\n");
        if (strlen(state->info_log) > 0)
            ralloc_asprintf_append(&pOutput->InfoLog, "%s\n", state->info_log);

        return false;
    }

    // optimizations
    if (!shader->ir->is_empty())
    {
        /* Do some optimization at compile time to reduce shader IR size
        * and reduce later work if the same shader is linked multiple times
        */
        if (optimizationLevel != HLSLTranslatorOptimizationLevelNone)
        {
            // @TODO improve optimization flags
            while (do_common_optimization(shader->ir, (optimizationLevel == HLSLTranslatorOptimizationLevelFull), false, &pGLContext->Const.ShaderCompilerOptions[shader->Stage], pGLContext->Const.NativeIntegers));
        }
        validate_ir_tree(shader->ir);
    }

    // log any warnings
    if (strlen(state->info_log) > 0)
        ralloc_asprintf_append(&pOutput->InfoLog, "%s\n", state->info_log);

    // nuke the shader info log
    assert(shader->InfoLog == nullptr);
    if (shader->InfoLog)
        ralloc_free(shader->InfoLog);

    shader->symbols = new(shader->ir) glsl_symbol_table;
    shader->CompileStatus = !state->error;
    shader->InfoLog = state->info_log;
    shader->Version = state->language_version;
    shader->IsES = state->es_shader;
    shader->uses_builtin_functions = state->uses_builtin_functions;

    if (!state->error)
        set_shader_inout_layout(shader, state);

    /* Retain any live IR, but trash the rest. */
    reparent_ir(shader->ir, shader->ir);

    /* delete the state symbol table, and reallocate it */
    delete state->symbols;
    state->symbols = new (state) glsl_symbol_table();

    /* Destroy the symbol table.  Create a new symbol table that contains only
    * the variables and functions that still exist in the IR.  The symbol
    * table will be used later during linking.
    *
    * There must NOT be any freed objects still referenced by the symbol
    * table.  That could cause the linker to dereference freed memory.
    *
    * We don't have to worry about types or interface-types here because those
    * are fly-weights that are looked up by glsl_type.
    */
    foreach_in_list(ir_instruction, ir, shader->ir) {
        switch (ir->ir_type) {
        case ir_type_function:
            shader->symbols->add_function((ir_function *)ir);
            state->symbols->add_function((ir_function *)ir);
            break;
        case ir_type_variable:
            if (((ir_variable *)ir)->data.mode == ir_var_temporary)
                continue;

            shader->symbols->add_variable((ir_variable *)ir);
            state->symbols->add_variable((ir_variable *)ir);
            break;
        default:
            break;
        }
    }

    return true;
}

void *HLSLTranslator_AllocateMemory(void *memoryContext, size_t length)
{
    return ralloc_size(memoryContext, length);
}

void HLSLTranslator_FreeMemory(void *pMemory)
{
    ralloc_free(pMemory);
}

bool HLSLTranslator_PreprocessHLSL(const char *sourceFileName,
                                   const char *sourceCode,
                                   size_t sourceCodeLength,
                                   HLSLTranslator_IncludeOpenCallback includeOpenCallback,
                                   HLSLTranslator_IncludeCloseCallback includeCloseCallback,
                                   void *includeContext, 
                                   const HLSLTranslatorMacro *pMacros,
                                   size_t nMacros,
                                   HLSLTranslatorOutput **ppOutputGLSL)
{
    // allocate output
    HLSLTranslatorOutput *pOutput = (HLSLTranslatorOutput *)rzalloc(0, HLSLTranslatorOutput);
    pOutput->InfoLog = ralloc_strdup(pOutput, "");
    *ppOutputGLSL = pOutput;

    // preprocess source
    pOutput->OutputSource = InternalPreprocessHLSL(pOutput, sourceFileName, sourceCode, sourceCodeLength, false, 100, pMacros, nMacros, includeOpenCallback, includeCloseCallback, includeContext, &pOutput->InfoLog);

    // set lengths
    pOutput->InfoLogLength = (pOutput->InfoLog != nullptr) ? strlen(pOutput->InfoLog) : 0;
    pOutput->OutputSourceLength = (pOutput->OutputSource != nullptr) ? strlen(pOutput->OutputSource) : 0;
    return (pOutput->OutputSourceLength != 0);
}

bool HLSLTranslator_ConvertHLSLToGLSL(const char *sourceFileName,
                                      const char *sourceCode,
                                      size_t sourceCodeLength,
                                      HLSLTranslator_IncludeOpenCallback includeOpenCallback,
                                      HLSLTranslator_IncludeCloseCallback includeCloseCallback,
                                      void *includeContext, 
                                      const char *entryPoint,
                                      enum HLSLTranslatorShaderStage stage,
                                      enum HLSLTranslatorOptimizationLevel optimizationLevel,
                                      int outputGLSLVersion,
                                      int outputGLSLES,
                                      const HLSLTranslatorMacro *pMacros,
                                      size_t nMacros,
                                      HLSLTranslatorOutput **ppOutputGLSL)
{
    // not threadsafe, but meh!
    static bool firstInstance = false;
    if (!firstInstance)
    {
        firstInstance = true;
        atexit(MesaCleanup);
    }

    // allocate gl context, this is also the ralloc root
    gl_context *pGLContext = (gl_context *)rzalloc(0, gl_context);
    InitializeGLContext(pGLContext, outputGLSLVersion, (outputGLSLES != 0));

    // allocate output
    HLSLTranslatorOutput *pOutput = (HLSLTranslatorOutput *)rzalloc(0, HLSLTranslatorOutput);
    pOutput->InfoLog = ralloc_strdup(pOutput, "");
    *ppOutputGLSL = pOutput;
    
    // allocate shader
    gl_shader *shader;
    _mesa_glsl_parse_state *state;
    bool result = false;
    {
        // select shader stage from mesa list
        GLenum glType = 0;
        gl_shader_stage mesaStage;
        switch (stage)
        {
        case HLSLTranslatorShaderStageVertex:
            glType = GL_VERTEX_SHADER;
            mesaStage = MESA_SHADER_VERTEX;
            break;
        case HLSLTranslatorShaderStageGeometry:
            glType = GL_GEOMETRY_SHADER;
            mesaStage = MESA_SHADER_GEOMETRY;
            break;
        case HLSLTranslatorShaderStagePixel:
            glType = GL_FRAGMENT_SHADER;
            mesaStage = MESA_SHADER_FRAGMENT;
            break;
        default:
            ralloc_asprintf_append(&pOutput->InfoLog, "Unknown shader type: %i\n", (int)stage);
            break;
        }

        if (glType != 0)
        {
            shader = rzalloc(pGLContext, gl_shader);
            shader->Type = glType;
            shader->Stage = mesaStage;
            state = new (shader) _mesa_glsl_parse_state(pGLContext, mesaStage, pGLContext);
        }
        else
        {
            shader = nullptr;
            state = nullptr;
        }
    }
    if (shader != nullptr)
    {
        // preprocess the source
        char *preprocessedSource = InternalPreprocessHLSL(pGLContext, sourceFileName, sourceCode, sourceCodeLength, outputGLSLES != 0, outputGLSLVersion, pMacros, nMacros, includeOpenCallback, includeCloseCallback, includeContext, &pOutput->InfoLog);
        if (preprocessedSource != nullptr)
        {
            // always parse as GLSL 3.3, non-ES.
            state->language_version = 330;
            state->forced_language_version = 330;
            state->es_shader = false;
            state->hlsl_entry_point = entryPoint;

            // construct lexer, and parse the source
            state->current_filename = ralloc_strdup(state, sourceFileName);
            _mesa_hlsl_lexer_ctor(state, preprocessedSource);
            int parseResult = _mesa_hlsl_parse(state);
            _mesa_hlsl_lexer_dtor(state);

            // preprocessed source no longer needed
            ralloc_free(preprocessedSource);

            // check parse result
            if (parseResult == 0)
            {
                // reset state to what is defined
                state->language_version = pGLContext->Const.GLSLVersion;
                state->forced_language_version = pGLContext->Const.GLSLVersion;
                state->es_shader = (pGLContext->API == API_OPENGLES2);

                // post compile stuff
                if (PostShaderCompile(pGLContext, shader, state, optimizationLevel, pOutput))
                {
                    // print the ir
                    pOutput->OutputSource = _mesa_print_ir_glsl(pOutput, shader, shader->ir);
                    result = (pOutput->OutputSource != nullptr);
                }
            }
            else
            {
                ralloc_asprintf_append(&pOutput->InfoLog, "Parsing HLSL shader failed: \n");
                if (strlen(state->info_log) > 0)
                    ralloc_asprintf_append(&pOutput->InfoLog, "%s\n", state->info_log);
            }
        }
        else
        {
            ralloc_asprintf_append(&pOutput->InfoLog, "Preprocessing source failed.\n");
        }   
    }

    // set lengths
    pOutput->InfoLogLength = (pOutput->InfoLog != nullptr) ? strlen(pOutput->InfoLog) : 0;
    pOutput->OutputSourceLength = (pOutput->OutputSource != nullptr) ? strlen(pOutput->OutputSource) : 0;

    // cleanup root
    delete state;
    ralloc_free(pGLContext);
    return result;
}
