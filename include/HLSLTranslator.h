#pragma once
#include <cstring>              // for size_t

#ifdef WIN32
    #ifdef HLSLTRANSLATOR_EXPORTS
        #define HLSLTRANSLATOR_API __declspec(dllexport)
    #else
        #define HLSLTRANSLATOR_API __declspec(dllimport)
    #endif
#else
    #define HLSLTRANSLATOR_API 
#endif

enum HLSLTranslatorShaderStage
{
    HLSLTranslatorShaderStageVertex,
    HLSLTranslatorShaderStageGeometry,
    HLSLTranslatorShaderStagePixel,
    HLSLTranslatorShaderStageCount
};

enum HLSLTranslatorOptimizationLevel
{
    HLSLTranslatorOptimizationLevelNone = 0,
    HLSLTranslatorOptimizationLevelBasic = 1,
    HLSLTranslatorOptimizationLevelFull = 2,
    HLSLTranslatorOptimizationLevelDefault = HLSLTranslatorOptimizationLevelFull
};

typedef struct HLSLTranslatorMacro
{
    const char *Name;
    const char *Value;

#ifdef __cplusplus
    HLSLTranslatorMacro() {}
    HLSLTranslatorMacro(const char *name, const char *value) : Name(name), Value(value) {}
#endif
} HLSLTranslatorMacro;

typedef struct HLSLTranslatorOutput
{
    char *OutputSource;
    size_t OutputSourceLength;

    char *InfoLog;
    size_t InfoLogLength;
} HLSLTranslatorOutput;

// Must match that in hlslpp
typedef bool(*HLSLTranslator_IncludeOpenCallback)(void *memoryContext, const char *includeFileName, bool systemInclude, char **outBuffer, unsigned int *outLength, void *context);
typedef void(*HLSLTranslator_IncludeCloseCallback)(void *memoryContext, char *buffer, void *context);

HLSLTRANSLATOR_API void *HLSLTranslator_AllocateMemory(void *memoryContext, size_t length);
HLSLTRANSLATOR_API void HLSLTranslator_FreeMemory(void *pMemory);

HLSLTRANSLATOR_API bool HLSLTranslator_PreprocessHLSL(const char *sourceFileName,
                                                      const char *sourceCode,
                                                      size_t sourceCodeLength,
                                                      HLSLTranslator_IncludeOpenCallback includeOpenCallback,
                                                      HLSLTranslator_IncludeCloseCallback includeCloseCallback,
                                                      void *includeContext,
                                                      const HLSLTranslatorMacro *pMacros,
                                                      size_t nMacros,
                                                      HLSLTranslatorOutput **ppOutputGLSL);

HLSLTRANSLATOR_API bool HLSLTranslator_ConvertHLSLToGLSL(const char *sourceFileName,
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
                                                         HLSLTranslatorOutput **ppOutputGLSL);

