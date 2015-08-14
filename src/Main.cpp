#include "HLSLTranslator.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#ifndef _MSC_VER
    #define stricmp strcasecmp
#endif

static bool IncludeOpenCallback(void *mem_ctx, const char *filename, bool is_system_include, char **out_buffer, unsigned int *out_buffer_size, void *context)
{
    fprintf(stderr, "<<<INCLUDE FILE '%s'>>>\n", filename);

    FILE *file = fopen(filename, "rb");
    if (file == nullptr)
        return false;

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    *out_buffer_size = length;
    *out_buffer = (char *)HLSLTranslator_AllocateMemory(mem_ctx, length);
    fread(*out_buffer, 1, length, file);
    fclose(file);
    return true;
}

static void IncludeCloseCallback(void *mem_ctx, char *buffer, void *context)
{
    HLSLTranslator_FreeMemory(buffer);
}

static void usage(const char *programName)
{
    printf("%s: -t (vertex|geometry|pixel) -E <entrypoint> [-Ddefine_name=define_value] [-P] [-O] [-T version|versionES] source_file_name...\n", programName);
}

int main(int argc, char *argv[])
{
    std::vector<HLSLTranslatorMacro> macros;
    std::vector<char> shader_code;
    const char *filename;
    const char *hlsl_entry_point = "main";
    HLSLTranslatorShaderStage stage = HLSLTranslatorShaderStageVertex;
    HLSLTranslatorOptimizationLevel optimizationLevel = HLSLTranslatorOptimizationLevelFull;
    bool preprocess_only = false;
    int version = 330;
    bool es = false;

    for (int i = 1; i < argc; i++)
    {
        printf("arg: %s\n", argv[i]);
        if (strcmp(argv[i], "-h") == 0)
        {
            usage(argv[0]);
            return 0;
        }
        else if (strcmp(argv[i], "-P") == 0)
        {
            preprocess_only = true;
        }
        else if (strcmp(argv[i], "-T") == 0)
        {
            i++;
            if (i == argc)
            {
                usage(argv[0]);
                return -1;
            }

            version = atoi(argv[i]);
            if (strlen(argv[i]) > 2 && stricmp(argv[i] + strlen(argv[i]) - 2, "es") == 0)
                es = true;
        }
        else if (strcmp(argv[i], "-E") == 0)
        {
            i++;
            if (i == argc)
            {
                usage(argv[0]);
                return -1;
            }

            hlsl_entry_point = argv[i];
        }
        else if (strncmp(argv[i], "-D", 2) == 0)
        {
            // handle defines
            char *defineString = strdup(argv[i] + 2);
            char *value = strchr(defineString, '=');
            if (value != nullptr)
            {
                *value = '\0';
                value++;
            }

            HLSLTranslatorMacro macro;
            macro.Name = defineString;
            macro.Value = value;
            macros.push_back(macro);
        }
        else if (strcmp(argv[i], "-t") == 0)
        {
            i++;
            if (i == argc)
            {
                usage(argv[0]);
                return -1;
            }

            if (stricmp(argv[i], "vertex") == 0)
                stage = HLSLTranslatorShaderStageVertex;
            else if (stricmp(argv[i], "geometry") == 0)
                stage = HLSLTranslatorShaderStageGeometry;
            else if (stricmp(argv[i], "pixel") == 0)
                stage = HLSLTranslatorShaderStagePixel;
            else
            {
                fprintf(stderr, "unknown shader type: %s\n", argv[i]);
                return -1;
            }
        }
        else if (strcmp(argv[i], "-O") == 0)
        {
            i++;
            if (i == argc)
            {
                usage(argv[0]);
                return -1;
            }

            int level = atoi(argv[i]);
            if (level < 0 || level > HLSLTranslatorOptimizationLevelFull)
            {
                fprintf(stderr, "invalid optimization level: %d", level);
                return -1;
            }

            optimizationLevel = (HLSLTranslatorOptimizationLevel)level;
        }
        else if (argv[i][0] == '-')
        {
            usage(argv[0]);
            return -1;
        }
        else
        {
            // assume a filename
            FILE *file = fopen(argv[i], "rb");
            if (file == nullptr)
            {
                printf("failed to open file '%s'\n", argv[i]);
                return -1;
            }

            fseek(file, 0, SEEK_END);
            size_t length = ftell(file);
            fseek(file, 0, SEEK_SET);

            size_t orig_pos = shader_code.size();
            shader_code.resize(shader_code.size() + length);
            fread(shader_code.data() + orig_pos, 1, length, file);
            fclose(file);

            fprintf(stderr, "added %u bytes from %s\n", (unsigned int)length, argv[i]);
            filename = argv[i];
        }
    }

    if (shader_code.size() == 0)
    {
        fprintf(stderr, "no code provided.\n");
        usage(argv[0]);
        return -1;
    }

    if (preprocess_only)
    {
        fprintf(stderr, "preprocessing...\n");

        HLSLTranslatorOutput *pOutput;
        if (HLSLTranslator_PreprocessHLSL(filename, shader_code.data(), shader_code.size(), IncludeOpenCallback, IncludeCloseCallback, nullptr, (macros.size() > 0) ? macros.data() : nullptr, macros.size(), &pOutput))
        {
            fprintf(stderr, "shader preprocessed.\n");

            if (pOutput->InfoLogLength > 0)
            {
                fprintf(stderr, "preprocess may have had warnings:\n");
                fputs(pOutput->InfoLog, stderr);
            }

            fprintf(stderr, "output hlsl:\n");
            if (pOutput->OutputSourceLength > 0)
                fputs(pOutput->OutputSource, stdout);
        }
        else
        {
            fprintf(stderr, "preprocess failed.\n");
            if (pOutput->InfoLogLength > 0)
                fputs(pOutput->InfoLog, stderr);
        }

        HLSLTranslator_FreeMemory(pOutput);
    }
    else
    {
        fprintf(stderr, "translating...\n");

        HLSLTranslatorOutput *pOutput;
        if (HLSLTranslator_ConvertHLSLToGLSL(filename, shader_code.data(), shader_code.size(), IncludeOpenCallback, IncludeCloseCallback, nullptr, hlsl_entry_point, stage, optimizationLevel, version, es, (macros.size() > 0) ? macros.data() : nullptr, macros.size(), &pOutput))
        {
            fprintf(stderr, "shader compiled.\n");

            if (pOutput->InfoLogLength > 0)
            {
                fprintf(stderr, "compile may have had warnings:\n");
                fputs(pOutput->InfoLog, stderr);
            }

            fprintf(stderr, "output glsl:\n");
            if (pOutput->OutputSourceLength > 0)
                fputs(pOutput->OutputSource, stdout);
        }
        else
        {
            fprintf(stderr, "compile failed.\n");
            if (pOutput->InfoLogLength > 0)
                fputs(pOutput->InfoLog, stderr);
        }

        HLSLTranslator_FreeMemory(pOutput);
    }

    return 0;
}

