#pragma once
#include "HLSLTranslator.h"

typedef struct HLSLTRANSLATOR_GLSL_SHADER_INPUT
{
    const char *VariableName;
    unsigned int VariableType;
    int ExplicitLocation;
} HLSLTranslatorGLSLShaderInput;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_OUTPUT
{
    const char *VariableName;
    unsigned int VariableType;
    int ExplicitLocation;
} HLSLTRANSLATOR_GLSL_SHADER_OUTPUT;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM
{
    const char *VariableName;
    const char *SamplerVariableName;
    unsigned int VariableType;
    unsigned int VariableArraySize;
    int ExplicitLocation;
} HLSLTRANSLATOR_GLSL_SHADER_UNIFORM;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD
{
    const char *VariableName;
    unsigned int VariableType;
    unsigned int VariableArraySize;
    unsigned int OffsetInBuffer;
    unsigned int SizeInBytes;
    unsigned int ArrayStride;
} HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD;

typedef struct HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK
{
    const char *BlockName;
    const char *InstanceName;
    const HLSLTRANSLATOR_GLSL_SHADER_UNIFORM_BLOCK_FIELD *Fields;
    unsigned int FieldCount;
    int ExplicitLocation;
    bool RowMajor;
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
                                                         size_t sourceCodeLength,
                                                         HLSLTRANSLATOR_INCLUDE_OPEN_CALLBACK includeOpenCallback,
                                                         HLSLTRANSLATOR_INCLUDE_CLOSE_CALLBACK includeCloseCallback,
                                                         void *includeContext,
                                                         const char *entryPoint,
                                                         enum HLSLTRANSLATOR_SHADER_STAGE stage,
                                                         unsigned int compileFlags,
                                                         int outputGLSLVersion,
                                                         int outputGLSLES,
                                                         const HLSLTRANSLATOR_MACRO *pMacros,
                                                         size_t nMacros,
                                                         HLSLTRANSLATOR_GLSL_OUTPUT **ppOutputGLSL);

