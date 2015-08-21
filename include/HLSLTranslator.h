#pragma once
#include <string.h> /* size_t */

#ifdef WIN32
    #ifdef HLSLTRANSLATOR_EXPORTS
        #define HLSLTRANSLATOR_API __declspec(dllexport)
    #else
        #define HLSLTRANSLATOR_API __declspec(dllimport)
    #endif
#else
    #define HLSLTRANSLATOR_API 
#endif

enum HLSLTRANSLATOR_SHADER_STAGE
{
    HLSLTRANSLATOR_SHADER_STAGE_VERTEX,
    HLSLTRANSLATOR_SHADER_STAGE_GEOMETRY,
    HLSLTRANSLATOR_SHADER_STAGE_PIXEL,
    NUM_HLSLTRANSLATOR_SHADER_STAGES
};

enum HLSLTRANSLATOR_COMPILE_FLAGS
{
    HLSLTRANSLATOR_COMPILE_FLAG_OPTIMIZATION_LEVEL_1            = (1 << 0),
    HLSLTRANSLATOR_COMPILE_FLAG_OPTIMIZATION_LEVEL_2            = (1 << 1),
    HLSLTRANSLATOR_COMPILE_FLAG_OPTIMIZATION_LEVEL_3            = (1 << 2),
    HLSLTRANSLATOR_COMPILE_FLAG_GENERATE_REFLECTION             = (1 << 3),
    HLSLTRANSLATOR_COMPILE_FLAG_WARNINGS_ARE_ERRORS             = (1 << 4),
};

typedef struct HLSLTRANSLATOR_MACRO
{
    const char *Name;
    const char *Value;

#ifdef __cplusplus
    HLSLTRANSLATOR_MACRO() {}
    HLSLTRANSLATOR_MACRO(const char *name, const char *value) : Name(name), Value(value) {}
#endif
} HLSLTRANSLATOR_MACRO;

typedef struct HLSLTRANSLATOR_OUTPUT
{
    char *OutputSource;
    unsigned int OutputSourceLength;

    char *InfoLog;
    unsigned int InfoLogLength;
} HLSLTRANSLATOR_OUTPUT;

// Must match that in hlslpp
typedef bool(*HLSLTRANSLATOR_INCLUDE_OPEN_CALLBACK)(void *memoryContext, const char *includeFileName, bool systemInclude, char **outBuffer, unsigned int *outLength, void *context);
typedef void(*HLSLTRANSLATOR_INCLUDE_CLOSE_CALLBACK)(void *memoryContext, char *buffer, void *context);

HLSLTRANSLATOR_API void *HLSLTranslator_AllocateMemory(void *memoryContext, size_t length);
HLSLTRANSLATOR_API void HLSLTranslator_FreeMemory(void *pMemory);

HLSLTRANSLATOR_API bool HLSLTranslator_PreprocessHLSL(const char *sourceFileName,
                                                      const char *sourceCode,
                                                      unsigned int sourceCodeLength,
                                                      HLSLTRANSLATOR_INCLUDE_OPEN_CALLBACK includeOpenCallback,
                                                      HLSLTRANSLATOR_INCLUDE_CLOSE_CALLBACK includeCloseCallback,
                                                      void *includeContext,
                                                      const HLSLTRANSLATOR_MACRO *pMacros,
                                                      unsigned int nMacros,
                                                      HLSLTRANSLATOR_OUTPUT **ppOutputHLSL);
