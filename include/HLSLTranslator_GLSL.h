#pragma once
#include "HLSLTranslator.h"

typedef struct HLSLTRANSLATOR_GLSL_SHADER_INPUT
{
    const char *VariableName;
    const char *SemanticName;
    unsigned int SemanticIndex;
    unsigned int Type;
    int ExplicitLocation;
} HLSLTranslatorGLSLShaderInput;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_OUTPUT
{
    const char *VariableName;
    const char *SemanticName;
    unsigned int SemanticIndex;
    unsigned int Type;
    int ExplicitLocation;
} HLSLTRANSLATOR_GLSL_SHADER_OUTPUT;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM
{
    const char *VariableName;
    const char *SamplerVariableName;
    unsigned int Type;
    int ArraySize;
    int ExplicitLocation;
} HLSLTRANSLATOR_GLSL_SHADER_UNIFORM;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD
{
    const char *VariableName;
    unsigned int Type;
    int ArraySize;
    unsigned int OffsetInBuffer;
    unsigned int SizeInBytes;
    unsigned int ArrayStride;
    bool RowMajor;
} HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK
{
    const char *BlockName;
    const char *InstanceName;
    const HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD *Fields;
    unsigned int FieldCount;
    unsigned int TotalSize;
    int ExplicitLocation;
} HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_REFLECTION
{
    const HLSLTRANSLATOR_GLSL_SHADER_INPUT *Inputs;
    const HLSLTRANSLATOR_GLSL_SHADER_OUTPUT *Outputs;
    const HLSLTRANSLATOR_GLSL_SHADER_UNIFORM *Uniforms;
    const HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK *UniformBlocks;
    unsigned int InputCount;
    unsigned int OutputCount;
    unsigned int UniformCount;
    unsigned int UniformBlockCount;
} HLSLTRANSLATOR_GLSL_SHADER_REFLECTION;

typedef struct HLSLTRANSLATOR_GLSL_OUTPUT
{
    char *OutputSource;
    unsigned int OutputSourceLength;

    char *InfoLog;
    unsigned int InfoLogLength;

    const HLSLTRANSLATOR_GLSL_SHADER_REFLECTION *Reflection;
} HLSLTRANSLATOR_GLSL_OUTPUT;

HLSLTRANSLATOR_API bool HLSLTranslator_ConvertHLSLToGLSL(const char *sourceFileName,
                                                         const char *sourceCode,
                                                         unsigned int sourceCodeLength,
                                                         HLSLTRANSLATOR_INCLUDE_OPEN_CALLBACK includeOpenCallback,
                                                         HLSLTRANSLATOR_INCLUDE_CLOSE_CALLBACK includeCloseCallback,
                                                         void *includeContext,
                                                         const char *entryPoint,
                                                         enum HLSLTRANSLATOR_SHADER_STAGE stage,
                                                         unsigned int compileFlags,
                                                         int outputGLSLVersion,
                                                         int outputGLSLES,
                                                         const HLSLTRANSLATOR_MACRO *pMacros,
                                                         unsigned int nMacros,
                                                         HLSLTRANSLATOR_GLSL_OUTPUT **ppOutputGLSL);

