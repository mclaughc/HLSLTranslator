/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         _mesa_hlsl_parse
#define yylex           _mesa_hlsl_lex
#define yyerror         _mesa_hlsl_error
#define yydebug         _mesa_hlsl_debug
#define yynerrs         _mesa_hlsl_nerrs


/* Copy the first part of user declarations.  */
#line 1 "hlsl_parser.yy" /* yacc.c:339  */

/*
 * Copyright © 2008, 2009 Intel Corporation
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _MSC_VER
#include <strings.h>
#endif
#include <assert.h>

#include "ast.h"
#include "glsl_parser_extras.h"
#include "glsl_types.h"
#include "main/context.h"

#ifdef _MSC_VER
#pragma warning( disable : 4065 ) // switch statement contains 'default' but no 'case' labels
#endif

#undef yyerror

static void yyerror(YYLTYPE *loc, _mesa_glsl_parse_state *st, const char *msg)
{
   _mesa_glsl_error(loc, st, "%s", msg);
}

static int
_mesa_hlsl_lex(YYSTYPE *val, YYLTYPE *loc, _mesa_glsl_parse_state *state)
{
   return _mesa_hlsl_lexer_lex(val, loc, state->scanner);
}

static bool match_layout_qualifier(const char *s1, const char *s2,
                                   _mesa_glsl_parse_state *state)
{
   /* From the GLSL 1.50 spec, section 4.3.8 (Layout Qualifiers):
    *
    *     "The tokens in any layout-qualifier-id-list ... are not case
    *     sensitive, unless explicitly noted otherwise."
    *
    * The text "unless explicitly noted otherwise" appears to be
    * vacuous--no desktop GLSL spec (up through GLSL 4.40) notes
    * otherwise.
    *
    * However, the GLSL ES 3.00 spec says, in section 4.3.8 (Layout
    * Qualifiers):
    *
    *     "As for other identifiers, they are case sensitive."
    *
    * So we need to do a case-sensitive or a case-insensitive match,
    * depending on whether we are compiling for GLSL ES.
    */
   if (state->es_shader)
      return strcmp(s1, s2);
   else
      return strcasecmp(s1, s2);
}

static bool parse_register_location(YYLTYPE *loc, ast_type_qualifier *out, const char *var, _mesa_glsl_parse_state *state)
{
    if (var[0] != 'b' && var[1] != 't' && var[2] != 's' && var[3] != 'u')
    {
        state->add_error_at(loc, "invalid register class: %c", var[0]);
        return false;
    }

    out->flags.q.explicit_location = 1;
    out->location = atoi(var + 1);
    return true;
}


#line 166 "hlsl_parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "hlsl_parser.h".  */
#ifndef YY__MESA_HLSL_HLSL_PARSER_H_INCLUDED
# define YY__MESA_HLSL_HLSL_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int _mesa_hlsl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ATTRIBUTE = 258,
    CONST_TOK = 259,
    BOOL_TOK = 260,
    FLOAT_TOK = 261,
    INT_TOK = 262,
    UINT_TOK = 263,
    DOUBLE_TOK = 264,
    BREAK = 265,
    CONTINUE = 266,
    DO = 267,
    ELSE = 268,
    FOR = 269,
    IF = 270,
    DISCARD = 271,
    RETURN = 272,
    SWITCH = 273,
    CASE = 274,
    DEFAULT = 275,
    BVEC2 = 276,
    BVEC3 = 277,
    BVEC4 = 278,
    IVEC2 = 279,
    IVEC3 = 280,
    IVEC4 = 281,
    UVEC2 = 282,
    UVEC3 = 283,
    UVEC4 = 284,
    VEC2 = 285,
    VEC3 = 286,
    VEC4 = 287,
    DVEC2 = 288,
    DVEC3 = 289,
    DVEC4 = 290,
    CENTROID = 291,
    IN_TOK = 292,
    OUT_TOK = 293,
    INOUT_TOK = 294,
    UNIFORM = 295,
    VARYING = 296,
    SAMPLE = 297,
    NOPERSPECTIVE = 298,
    FLAT = 299,
    SMOOTH = 300,
    MAT2X2 = 301,
    MAT2X3 = 302,
    MAT2X4 = 303,
    MAT3X2 = 304,
    MAT3X3 = 305,
    MAT3X4 = 306,
    MAT4X2 = 307,
    MAT4X3 = 308,
    MAT4X4 = 309,
    DMAT2X2 = 310,
    DMAT2X3 = 311,
    DMAT2X4 = 312,
    DMAT3X2 = 313,
    DMAT3X3 = 314,
    DMAT3X4 = 315,
    DMAT4X2 = 316,
    DMAT4X3 = 317,
    DMAT4X4 = 318,
    SAMPLER1D = 319,
    SAMPLER2D = 320,
    SAMPLER3D = 321,
    SAMPLERCUBE = 322,
    SAMPLER1DSHADOW = 323,
    SAMPLER2DSHADOW = 324,
    SAMPLERCUBESHADOW = 325,
    SAMPLER1DARRAY = 326,
    SAMPLER2DARRAY = 327,
    SAMPLER1DARRAYSHADOW = 328,
    SAMPLER2DARRAYSHADOW = 329,
    SAMPLERCUBEARRAY = 330,
    SAMPLERCUBEARRAYSHADOW = 331,
    ISAMPLER1D = 332,
    ISAMPLER2D = 333,
    ISAMPLER3D = 334,
    ISAMPLERCUBE = 335,
    ISAMPLER1DARRAY = 336,
    ISAMPLER2DARRAY = 337,
    ISAMPLERCUBEARRAY = 338,
    USAMPLER1D = 339,
    USAMPLER2D = 340,
    USAMPLER3D = 341,
    USAMPLERCUBE = 342,
    USAMPLER1DARRAY = 343,
    USAMPLER2DARRAY = 344,
    USAMPLERCUBEARRAY = 345,
    SAMPLER2DRECT = 346,
    ISAMPLER2DRECT = 347,
    USAMPLER2DRECT = 348,
    SAMPLER2DRECTSHADOW = 349,
    BUFFER = 350,
    ISAMPLERBUFFER = 351,
    USAMPLERBUFFER = 352,
    SAMPLER2DMS = 353,
    ISAMPLER2DMS = 354,
    USAMPLER2DMS = 355,
    SAMPLER2DMSARRAY = 356,
    ISAMPLER2DMSARRAY = 357,
    USAMPLER2DMSARRAY = 358,
    SAMPLEREXTERNALOES = 359,
    SAMPLERSTATE = 360,
    SAMPLERCOMPARISONSTATE = 361,
    IMAGE1D = 362,
    IMAGE2D = 363,
    IMAGE3D = 364,
    IMAGE2DRECT = 365,
    IMAGECUBE = 366,
    IMAGEBUFFER = 367,
    IMAGE1DARRAY = 368,
    IMAGE2DARRAY = 369,
    IMAGECUBEARRAY = 370,
    IMAGE2DMS = 371,
    IMAGE2DMSARRAY = 372,
    IIMAGE1D = 373,
    IIMAGE2D = 374,
    IIMAGE3D = 375,
    IIMAGE2DRECT = 376,
    IIMAGECUBE = 377,
    IIMAGEBUFFER = 378,
    IIMAGE1DARRAY = 379,
    IIMAGE2DARRAY = 380,
    IIMAGECUBEARRAY = 381,
    IIMAGE2DMS = 382,
    IIMAGE2DMSARRAY = 383,
    UIMAGE1D = 384,
    UIMAGE2D = 385,
    UIMAGE3D = 386,
    UIMAGE2DRECT = 387,
    UIMAGECUBE = 388,
    UIMAGEBUFFER = 389,
    UIMAGE1DARRAY = 390,
    UIMAGE2DARRAY = 391,
    UIMAGECUBEARRAY = 392,
    UIMAGE2DMS = 393,
    UIMAGE2DMSARRAY = 394,
    IMAGE1DSHADOW = 395,
    IMAGE2DSHADOW = 396,
    IMAGE1DARRAYSHADOW = 397,
    IMAGE2DARRAYSHADOW = 398,
    COHERENT = 399,
    VOLATILE = 400,
    RESTRICT = 401,
    READONLY = 402,
    WRITEONLY = 403,
    ATOMIC_UINT = 404,
    STRUCT = 405,
    VOID_TOK = 406,
    WHILE = 407,
    IDENTIFIER = 408,
    TYPE_IDENTIFIER = 409,
    NEW_IDENTIFIER = 410,
    FLOATCONSTANT = 411,
    DOUBLECONSTANT = 412,
    INTCONSTANT = 413,
    UINTCONSTANT = 414,
    BOOLCONSTANT = 415,
    FIELD_SELECTION = 416,
    LEFT_OP = 417,
    RIGHT_OP = 418,
    INC_OP = 419,
    DEC_OP = 420,
    LE_OP = 421,
    GE_OP = 422,
    EQ_OP = 423,
    NE_OP = 424,
    AND_OP = 425,
    OR_OP = 426,
    XOR_OP = 427,
    MUL_ASSIGN = 428,
    DIV_ASSIGN = 429,
    ADD_ASSIGN = 430,
    MOD_ASSIGN = 431,
    LEFT_ASSIGN = 432,
    RIGHT_ASSIGN = 433,
    AND_ASSIGN = 434,
    XOR_ASSIGN = 435,
    OR_ASSIGN = 436,
    SUB_ASSIGN = 437,
    INVARIANT = 438,
    PRECISE = 439,
    LOWP = 440,
    MEDIUMP = 441,
    HIGHP = 442,
    SUPERP = 443,
    PRECISION = 444,
    VERSION_TOK = 445,
    EXTENSION = 446,
    LINE = 447,
    COLON = 448,
    EOL = 449,
    INTERFACE = 450,
    PRAGMA_DEBUG_ON = 451,
    PRAGMA_DEBUG_OFF = 452,
    PRAGMA_OPTIMIZE_ON = 453,
    PRAGMA_OPTIMIZE_OFF = 454,
    PRAGMA_INVARIANT_ALL = 455,
    LAYOUT_TOK = 456,
    ASM = 457,
    CLASS = 458,
    UNION = 459,
    ENUM = 460,
    TYPEDEF = 461,
    TEMPLATE = 462,
    THIS = 463,
    PACKED_TOK = 464,
    GOTO = 465,
    INLINE_TOK = 466,
    NOINLINE = 467,
    PUBLIC_TOK = 468,
    STATIC = 469,
    EXTERN = 470,
    EXTERNAL = 471,
    LONG_TOK = 472,
    SHORT_TOK = 473,
    HALF = 474,
    FIXED_TOK = 475,
    UNSIGNED = 476,
    HVEC2 = 477,
    HVEC3 = 478,
    HVEC4 = 479,
    FVEC2 = 480,
    FVEC3 = 481,
    FVEC4 = 482,
    SAMPLER3DRECT = 483,
    SIZEOF = 484,
    CAST = 485,
    NAMESPACE = 486,
    USING = 487,
    RESOURCE = 488,
    PATCH = 489,
    SUBROUTINE = 490,
    ERROR_TOK = 491,
    COMMON = 492,
    PARTITION = 493,
    ACTIVE = 494,
    FILTER = 495,
    ROW_MAJOR = 496,
    QUOTED_STRING = 497,
    CBUFFER = 498,
    TBUFFER = 499,
    REGISTER = 500,
    PACKOFFSET = 501,
    THEN = 502
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 113 "hlsl_parser.yy" /* yacc.c:355  */

   int n;
   float real;
   double dreal;
   const char *identifier;

   struct ast_type_qualifier type_qualifier;

   ast_node *node;
   ast_type_specifier *type_specifier;
   ast_array_specifier *array_specifier;
   ast_fully_specified_type *fully_specified_type;
   ast_function *function;
   ast_parameter_declarator *parameter_declarator;
   ast_function_definition *function_definition;
   ast_compound_statement *compound_statement;
   ast_expression *expression;
   ast_declarator_list *declarator_list;
   ast_struct_specifier *struct_specifier;
   ast_declaration *declaration;
   ast_switch_body *switch_body;
   ast_case_label *case_label;
   ast_case_label_list *case_label_list;
   ast_case_statement *case_statement;
   ast_case_statement_list *case_statement_list;
   ast_interface_block *interface_block;

   struct {
      ast_node *cond;
      ast_expression *rest;
   } for_rest_statement;

   struct {
      ast_node *then_statement;
      ast_node *else_statement;
   } selection_rest_statement;

#line 492 "hlsl_parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int _mesa_hlsl_parse (struct _mesa_glsl_parse_state *state);

#endif /* !YY__MESA_HLSL_HLSL_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 520 "hlsl_parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  272
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  622

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   502

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   256,     2,     2,     2,   260,   263,     2,
     248,   249,   258,   254,   253,   255,   252,   259,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   267,   269,
     261,   268,   262,   266,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   250,     2,   251,   264,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   270,   265,   271,   257,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   333,   333,   332,   344,   346,   353,   363,   364,   365,
     366,   367,   391,   393,   397,   398,   399,   403,   412,   420,
     428,   439,   440,   444,   451,   458,   465,   472,   479,   486,
     493,   494,   500,   504,   511,   517,   526,   530,   534,   535,
     544,   545,   549,   550,   554,   560,   572,   576,   582,   590,
     601,   602,   606,   607,   611,   617,   629,   641,   642,   648,
     654,   660,   673,   674,   675,   676,   680,   681,   687,   693,
     702,   703,   709,   718,   719,   725,   734,   735,   741,   747,
     753,   762,   763,   769,   778,   779,   788,   789,   798,   799,
     808,   809,   818,   819,   828,   829,   838,   839,   848,   849,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   872,   876,   892,   896,   901,   905,   910,   914,   921,
     922,   926,   927,   931,   936,   944,   958,   968,   979,   993,
     998,  1012,  1015,  1023,  1031,  1043,  1054,  1061,  1066,  1071,
    1080,  1084,  1085,  1095,  1105,  1115,  1129,  1136,  1146,  1156,
    1166,  1176,  1188,  1203,  1210,  1221,  1228,  1229,  1239,  1240,
    1244,  1444,  1583,  1609,  1614,  1622,  1627,  1632,  1641,  1646,
    1651,  1652,  1653,  1654,  1655,  1656,  1674,  1682,  1705,  1729,
    1746,  1762,  1782,  1793,  1801,  1806,  1814,  1819,  1824,  1829,
    1834,  1853,  1858,  1866,  1871,  1876,  1882,  1887,  1895,  1903,
    1912,  1918,  1926,  1927,  1937,  1943,  1949,  1963,  1978,  1979,
    1987,  1993,  1999,  2005,  2015,  2016,  2017,  2018,  2019,  2020,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
    2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,
    2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,
    2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,  2060,
    2061,  2062,  2063,  2064,  2065,  2066,  2067,  2068,  2069,  2070,
    2071,  2072,  2073,  2074,  2075,  2076,  2077,  2078,  2079,  2080,
    2081,  2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2090,
    2091,  2092,  2093,  2094,  2095,  2096,  2097,  2098,  2099,  2100,
    2101,  2102,  2103,  2104,  2105,  2106,  2107,  2108,  2109,  2110,
    2111,  2112,  2113,  2114,  2115,  2116,  2117,  2118,  2119,  2120,
    2121,  2122,  2123,  2124,  2125,  2126,  2127,  2128,  2129,  2130,
    2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,
    2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,
    2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,
    2204,  2205,  2206,  2207,  2208,  2209,  2213,  2214,  2215,  2216,
    2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,  2226,
    2227,  2228,  2229,  2230,  2231,  2232,  2236,  2241,  2246,  2254,
    2261,  2269,  2276,  2287,  2292,  2300,  2319,  2324,  2332,  2338,
    2345,  2351,  2361,  2362,  2366,  2373,  2380,  2387,  2393,  2394,
    2398,  2399,  2400,  2401,  2402,  2403,  2407,  2414,  2413,  2427,
    2428,  2432,  2438,  2447,  2457,  2469,  2475,  2484,  2493,  2498,
    2506,  2510,  2528,  2536,  2541,  2549,  2554,  2562,  2570,  2578,
    2586,  2594,  2602,  2610,  2617,  2624,  2634,  2635,  2639,  2641,
    2647,  2652,  2661,  2667,  2673,  2679,  2685,  2694,  2695,  2696,
    2697,  2701,  2714,  2733,  2768,  2772,  2795,  2922,  2927,  2932,
    2941,  2945,  2951,  2960,  2965,  2973,  2997,  3005,  3013
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTE", "CONST_TOK", "BOOL_TOK",
  "FLOAT_TOK", "INT_TOK", "UINT_TOK", "DOUBLE_TOK", "BREAK", "CONTINUE",
  "DO", "ELSE", "FOR", "IF", "DISCARD", "RETURN", "SWITCH", "CASE",
  "DEFAULT", "BVEC2", "BVEC3", "BVEC4", "IVEC2", "IVEC3", "IVEC4", "UVEC2",
  "UVEC3", "UVEC4", "VEC2", "VEC3", "VEC4", "DVEC2", "DVEC3", "DVEC4",
  "CENTROID", "IN_TOK", "OUT_TOK", "INOUT_TOK", "UNIFORM", "VARYING",
  "SAMPLE", "NOPERSPECTIVE", "FLAT", "SMOOTH", "MAT2X2", "MAT2X3",
  "MAT2X4", "MAT3X2", "MAT3X3", "MAT3X4", "MAT4X2", "MAT4X3", "MAT4X4",
  "DMAT2X2", "DMAT2X3", "DMAT2X4", "DMAT3X2", "DMAT3X3", "DMAT3X4",
  "DMAT4X2", "DMAT4X3", "DMAT4X4", "SAMPLER1D", "SAMPLER2D", "SAMPLER3D",
  "SAMPLERCUBE", "SAMPLER1DSHADOW", "SAMPLER2DSHADOW", "SAMPLERCUBESHADOW",
  "SAMPLER1DARRAY", "SAMPLER2DARRAY", "SAMPLER1DARRAYSHADOW",
  "SAMPLER2DARRAYSHADOW", "SAMPLERCUBEARRAY", "SAMPLERCUBEARRAYSHADOW",
  "ISAMPLER1D", "ISAMPLER2D", "ISAMPLER3D", "ISAMPLERCUBE",
  "ISAMPLER1DARRAY", "ISAMPLER2DARRAY", "ISAMPLERCUBEARRAY", "USAMPLER1D",
  "USAMPLER2D", "USAMPLER3D", "USAMPLERCUBE", "USAMPLER1DARRAY",
  "USAMPLER2DARRAY", "USAMPLERCUBEARRAY", "SAMPLER2DRECT",
  "ISAMPLER2DRECT", "USAMPLER2DRECT", "SAMPLER2DRECTSHADOW", "BUFFER",
  "ISAMPLERBUFFER", "USAMPLERBUFFER", "SAMPLER2DMS", "ISAMPLER2DMS",
  "USAMPLER2DMS", "SAMPLER2DMSARRAY", "ISAMPLER2DMSARRAY",
  "USAMPLER2DMSARRAY", "SAMPLEREXTERNALOES", "SAMPLERSTATE",
  "SAMPLERCOMPARISONSTATE", "IMAGE1D", "IMAGE2D", "IMAGE3D", "IMAGE2DRECT",
  "IMAGECUBE", "IMAGEBUFFER", "IMAGE1DARRAY", "IMAGE2DARRAY",
  "IMAGECUBEARRAY", "IMAGE2DMS", "IMAGE2DMSARRAY", "IIMAGE1D", "IIMAGE2D",
  "IIMAGE3D", "IIMAGE2DRECT", "IIMAGECUBE", "IIMAGEBUFFER",
  "IIMAGE1DARRAY", "IIMAGE2DARRAY", "IIMAGECUBEARRAY", "IIMAGE2DMS",
  "IIMAGE2DMSARRAY", "UIMAGE1D", "UIMAGE2D", "UIMAGE3D", "UIMAGE2DRECT",
  "UIMAGECUBE", "UIMAGEBUFFER", "UIMAGE1DARRAY", "UIMAGE2DARRAY",
  "UIMAGECUBEARRAY", "UIMAGE2DMS", "UIMAGE2DMSARRAY", "IMAGE1DSHADOW",
  "IMAGE2DSHADOW", "IMAGE1DARRAYSHADOW", "IMAGE2DARRAYSHADOW", "COHERENT",
  "VOLATILE", "RESTRICT", "READONLY", "WRITEONLY", "ATOMIC_UINT", "STRUCT",
  "VOID_TOK", "WHILE", "IDENTIFIER", "TYPE_IDENTIFIER", "NEW_IDENTIFIER",
  "FLOATCONSTANT", "DOUBLECONSTANT", "INTCONSTANT", "UINTCONSTANT",
  "BOOLCONSTANT", "FIELD_SELECTION", "LEFT_OP", "RIGHT_OP", "INC_OP",
  "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "XOR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "ADD_ASSIGN", "MOD_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "SUB_ASSIGN", "INVARIANT", "PRECISE", "LOWP", "MEDIUMP", "HIGHP",
  "SUPERP", "PRECISION", "VERSION_TOK", "EXTENSION", "LINE", "COLON",
  "EOL", "INTERFACE", "PRAGMA_DEBUG_ON", "PRAGMA_DEBUG_OFF",
  "PRAGMA_OPTIMIZE_ON", "PRAGMA_OPTIMIZE_OFF", "PRAGMA_INVARIANT_ALL",
  "LAYOUT_TOK", "ASM", "CLASS", "UNION", "ENUM", "TYPEDEF", "TEMPLATE",
  "THIS", "PACKED_TOK", "GOTO", "INLINE_TOK", "NOINLINE", "PUBLIC_TOK",
  "STATIC", "EXTERN", "EXTERNAL", "LONG_TOK", "SHORT_TOK", "HALF",
  "FIXED_TOK", "UNSIGNED", "HVEC2", "HVEC3", "HVEC4", "FVEC2", "FVEC3",
  "FVEC4", "SAMPLER3DRECT", "SIZEOF", "CAST", "NAMESPACE", "USING",
  "RESOURCE", "PATCH", "SUBROUTINE", "ERROR_TOK", "COMMON", "PARTITION",
  "ACTIVE", "FILTER", "ROW_MAJOR", "QUOTED_STRING", "CBUFFER", "TBUFFER",
  "REGISTER", "PACKOFFSET", "THEN", "'('", "')'", "'['", "']'", "'.'",
  "','", "'+'", "'-'", "'!'", "'~'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "'&'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "translation_unit", "$@1", "version_statement", "pragma_statement",
  "extension_statement_list", "any_identifier", "extension_statement",
  "external_declaration_list", "variable_identifier", "primary_expression",
  "postfix_expression", "integer_expression", "function_call",
  "function_call_or_method", "function_call_generic",
  "function_call_header_no_parameters",
  "function_call_header_with_parameters", "function_call_header",
  "function_identifier", "method_call_generic",
  "method_call_header_no_parameters", "method_call_header_with_parameters",
  "method_call_header", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_xor_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "function_prototype",
  "function_declarator", "function_header_with_parameters",
  "function_header", "parameter_declarator", "parameter_declaration",
  "parameter_qualifier", "parameter_direction_qualifier",
  "parameter_type_specifier", "init_declarator_list", "single_declaration",
  "fully_specified_type", "layout_qualifier", "layout_qualifier_id_list",
  "integer_constant", "layout_qualifier_id",
  "interface_block_layout_qualifier", "interpolation_qualifier",
  "type_qualifier", "auxiliary_storage_qualifier", "storage_qualifier",
  "memory_qualifier", "location_qualifier_id", "location_qualifier",
  "array_specifier", "type_specifier", "type_specifier_nonarray",
  "basic_type_specifier_nonarray", "templated_object_type_name",
  "templated_object_data_type_name", "precision_qualifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "initializer",
  "initializer_list", "declaration_statement", "statement",
  "simple_statement", "compound_statement", "$@2",
  "statement_no_new_scope", "compound_statement_no_new_scope",
  "statement_list", "expression_statement", "selection_statement",
  "selection_rest_statement", "condition", "switch_statement",
  "switch_body", "case_label", "case_label_list", "case_statement",
  "case_statement_list", "iteration_statement", "for_init_statement",
  "conditionopt", "for_rest_statement", "jump_statement",
  "external_declaration", "function_definition", "cbuffer_block",
  "interface_block", "basic_interface_block", "interface_qualifier",
  "instance_name_opt", "member_list", "member_declaration",
  "layout_defaults", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,    40,    41,
      91,    93,    46,    44,    43,    45,    33,   126,    42,    47,
      37,    60,    62,    38,    94,   124,    63,    58,    61,    59,
     123,   125
};
# endif

#define YYPACT_NINF -509

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-509)))

#define YYTABLE_NINF -510

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,  -120,    43,  -509,   -94,  -509,  -124,  -509,  -509,  -509,
    -509,   -92,    10,  5637,  -509,  -509,   -80,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
     -30,   -24,    21,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,   -79,   -65,   -43,   -38,
     -20,   -15,   -13,    -5,     0,    19,    22,    28,    29,    30,
      33,    34,    36,    38,    39,    40,    41,    42,    44,    45,
      47,    48,    51,    52,    53,    54,    55,    59,    62,    63,
      64,    65,    73,    74,    76,    78,    79,    92,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     107,   108,   109,   110,   111,   112,   113,   115,   116,   117,
     118,   119,   120,   122,   123,   124,   127,   128,   130,   132,
     133,   134,  -509,  -509,  -509,  -509,  -509,  -509,  -128,  -509,
    -509,   307,   307,  -509,  -509,  -509,    35,   -46,   125,   152,
     163,   202,     4,  -509,   137,  -509,  5433,  -509,  -229,    24,
     144,    58,  -161,  -509,    85,  5978,  6003,  6223,  6003,  6003,
    6003,  -509,    46,  -509,   138,  6003,  -509,  -509,  -509,  -509,
    -509,  -509,   149,  -509,    10,  1403,   131,  -509,  -509,  -509,
    -509,  -509,  6003,  6003,  -509,  6003,  -509,  -509,  -509,  6223,
    -509,  -509,  -509,  -509,  -509,  -103,   135,  -509,  -509,  -509,
     610,  -509,   136,   294,   294,  -509,  -509,  -509,   294,  -509,
    6223,   294,   294,   294,    10,  -509,   156,   158,  -204,   159,
    -139,  -136,  -133,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    4348,   150,   520,  -509,   140,   214,  -509,    10,  1635,  -509,
    1867,   142,  -509,  -509,   145,  -184,  -509,  -509,  5841,   143,
     165,  2599,   166,   187,   167,  3881,   189,   195,  -509,  -509,
    -509,  -509,  -509,  -509,  4772,  4772,  4772,  -509,  -509,  -509,
    -509,  -509,   173,  -509,   197,  -509,  -109,  -509,  -509,  -509,
     198,   -91,  4984,   200,   -95,  4772,    12,  -132,    66,  -135,
      82,   183,   185,   191,   280,   285,  -134,  -509,  -509,  -148,
    -509,   190,  6026,   210,  -509,  -509,  -509,  -509,   879,  -509,
    -509,  -509,  -509,  -509,    10,  -509,  -509,  -509,  -509,  -509,
      10,  -509,  -509,  -509,  -180,  3628,  -177,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,   212,  -509,  4560,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,   199,  5841,  -509,
    -173,  -141,  -509,  -509,  -509,  -509,  2099,  -509,    96,  -509,
    -103,    10,   193,  5841,  -509,  -509,   313,  3122,  4772,  -509,
    -509,  -116,  4772,  4136,  -509,  -509,   -72,     9,  -509,  2599,
    -509,  -509,  4772,    85,  -509,  -509,  4772,   218,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  4772,  -509,  4772,  4772,  4772,  4772,  4772,  4772,  4772,
    4772,  4772,  4772,  4772,  4772,  4772,  4772,  4772,  4772,  4772,
    4772,  4772,  4772,  4772,  -509,  -509,  -509,  -509,  -151,  3628,
    -175,  3628,  -509,  -509,  3628,  -509,  -509,   219,  -509,   201,
      10,  -147,    10,  -509,  -509,  -509,  -509,  -509,  -509,  -113,
     204,  -509,   221,  -509,  -509,  4136,   -66,  -509,   -64,   220,
      10,   227,  -509,  4772,  1148,   226,   220,  -509,   234,  -509,
     235,   -61,  5196,  -509,  -509,  -509,  -509,  -509,    12,    12,
    -132,  -132,    66,    66,    66,    66,  -135,  -135,    82,   183,
     185,   191,   280,   285,  -163,  -509,    10,   150,  -509,  3628,
    -509,  -164,  -509,  -509,   330,  -509,    10,  -509,  -509,    31,
    4772,  -509,   228,   239,  2599,   225,   230,  2867,  -509,  -509,
    -509,  -509,  -509,  -509,  4772,   240,  -509,  4772,  -509,  -509,
    3375,  -509,    46,   231,  -509,   248,   251,  -509,   249,   -56,
    4772,  2867,   488,  -509,    -8,  -509,  3628,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,   150,  -509,    10,    10,  -103,   236,
     220,  -509,  2599,  4772,   237,  -509,  -509,  2331,  2599,    -2,
    -509,   -54,   -41,  -509,  -509,  -509,  -152,  -509,  -509,  -509,
    -509,  -509,  2599,  -509,    10,  -509,    10,  -509,   254,   257,
    -509,  -509
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,    12,     0,     1,     2,    14,    15,    16,
       5,     0,     0,     0,    13,     6,     0,   187,   186,   219,
     215,   217,   218,   216,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   220,   221,   222,   232,   233,   234,   184,
     189,   190,   191,   188,   185,   167,   166,   165,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   256,   257,
     261,   262,   264,   265,   266,   267,   268,   270,   271,   272,
     273,   275,   276,   277,   278,   280,   281,   282,   284,   285,
     286,   287,   289,   255,   274,   283,   263,   269,   279,   288,
     290,   291,   292,   293,   294,   295,   258,   259,   260,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   193,   194,   195,   196,   197,   329,     0,   214,
     212,   168,   169,   428,   427,   426,     0,     0,     0,     0,
       0,     0,     0,   192,     0,   499,     3,   498,     0,     0,
     122,   131,     0,   141,   146,   173,   172,     0,   170,   171,
     174,   153,   208,   210,     0,   175,   211,    18,   497,   117,
     118,   504,     0,   500,     0,     0,     0,   189,   190,   191,
      21,    22,   168,   169,   151,   173,   177,   152,   176,     0,
       7,     8,     9,    10,    11,     0,     0,    20,    19,   114,
       0,   501,   119,   131,   131,   137,   138,   139,   131,   123,
       0,   131,   131,   131,     0,   115,    14,    16,   147,     0,
     189,   190,   191,   179,   505,   178,   154,   180,   181,   183,
       0,   209,     0,   182,     0,     0,   432,     0,     0,   433,
       0,     0,   164,   163,   160,     0,   156,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      24,    25,    28,    49,     0,     0,     0,    62,    63,    64,
      65,   465,   457,   461,    23,    30,    57,    32,    37,    38,
       0,     0,    43,     0,    66,     0,    70,    73,    76,    81,
      84,    86,    88,    90,    92,    94,    96,    98,   111,     0,
     447,     0,   173,   153,   450,   463,   449,   448,     0,   451,
     452,   453,   454,   455,     0,   124,   132,   133,   129,   130,
     140,   134,   136,   135,   142,     0,   148,   125,   517,   518,
     516,   204,    66,   113,     0,    47,     0,   410,   406,   408,
     409,   407,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   411,   412,   413,   423,   424,   425,     0,     0,    17,
     438,     0,   436,   431,   434,   430,     0,   116,     0,   155,
       0,     0,     0,   513,   493,   492,     0,     0,     0,   496,
     494,     0,     0,     0,    58,    59,     0,   208,   456,     0,
      34,    35,     0,     0,    41,    40,     0,   214,    44,    46,
     101,   102,   104,   103,   106,   107,   108,   109,   110,   105,
     100,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   466,   462,   464,   120,   126,     0,
     143,     0,   442,   150,     0,   205,   206,     0,   213,     0,
       0,   440,     0,   435,   429,   158,   159,   161,   157,     0,
     502,   514,     0,   487,   486,   489,     0,   495,     0,   470,
       0,     0,    29,     0,     0,     0,    36,    33,     0,    39,
       0,     0,    53,    45,    99,    67,    68,    69,    71,    72,
      74,    75,    79,    80,    77,    78,    82,    83,    85,    87,
      89,    91,    93,    95,     0,   112,     0,   128,   145,     0,
     445,     0,   149,   207,   510,   439,     0,   437,   515,     0,
       0,   488,     0,     0,     0,     0,     0,     0,    61,   458,
      31,    56,    51,    50,     0,   214,    54,     0,   127,   144,
       0,   443,   511,     0,   441,     0,     0,   202,   503,     0,
     490,     0,   469,   467,     0,   472,     0,   460,   483,   459,
      55,    97,   444,   446,   512,   506,     0,     0,     0,     0,
     491,   485,     0,     0,     0,   473,   477,     0,   481,     0,
     471,     0,     0,   203,   484,   468,     0,   476,   479,   478,
     480,   474,   482,   198,     0,   200,     0,   475,     0,     0,
     199,   201
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -509,  -509,  -509,  -509,  -509,  -509,    -4,   341,  -509,  -138,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,   -18,  -509,  -158,  -157,  -226,  -159,
      67,    68,    61,    69,    60,    72,  -509,  -221,  -292,  -509,
    -252,   155,    -9,     2,  -509,  -509,  -509,  -509,   289,   -53,
    -509,  -509,  -509,  -509,  -192,    -7,  -509,  -509,  -381,  -509,
    -509,  -131,  -509,  -509,     3,  -509,  -509,  -233,   -11,   233,
    -509,  -509,  -509,  -114,  -509,   256,  -234,   126,    84,  -431,
    -509,   141,  -270,  -508,  -509,  -509,   -57,   352,   121,   160,
    -509,  -509,    49,  -509,  -509,   -73,  -509,   -68,  -509,  -509,
    -509,  -509,  -509,  -509,   369,  -509,  -509,  -509,  -168,  -509,
    -509,  -244,  -509,  -509
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,     3,   165,     6,   264,    14,   166,   294,
     295,   296,   495,   297,   298,   299,   300,   301,   302,   303,
     499,   500,   501,   502,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   431,
     319,   354,   320,   321,   169,   170,   171,   338,   229,   230,
     231,   339,   172,   173,   174,   205,   265,   477,   266,   267,
     176,   177,   178,   179,   180,   567,   568,   251,   355,   182,
     183,   184,   377,   185,   186,   258,   259,   381,   382,   463,
     531,   324,   325,   326,   327,   409,   578,   579,   328,   329,
     330,   573,   491,   331,   575,   596,   597,   598,   599,   332,
     485,   542,   543,   333,   187,   188,   189,   190,   191,   192,
     563,   392,   393,   193
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   396,   181,   257,   167,   346,   175,   244,    16,   478,
     418,   593,   594,   204,   207,   168,  -507,   593,   594,  -508,
     206,   208,  -509,   401,   384,     7,     8,     9,   528,   353,
     530,   440,   441,   532,   406,     1,   239,   451,     4,   577,
     219,   220,   209,     5,   243,   245,   250,   247,   248,   249,
       7,     8,     9,   462,   253,   410,   411,   233,   456,     7,
       8,     9,   224,   577,   345,   389,   257,    12,   257,   390,
     250,   206,   208,   356,   243,   356,   391,   250,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   459,   560,
     453,   464,   234,   529,   470,   225,   226,   227,   559,   250,
      10,   453,    15,   356,   557,   453,   262,   561,   235,   233,
     233,   460,   472,   194,   233,   617,   526,   233,   233,   233,
     536,   454,   436,   437,   503,  -507,   442,   443,   473,   583,
     348,  -508,   452,   349,   469,   353,   350,   453,   263,   504,
     472,   412,   195,   413,   196,   600,   486,   471,   210,   481,
     488,   489,   384,   487,   244,   181,   538,   167,   415,   175,
     496,   525,   416,     7,     8,     9,   246,   462,   168,   462,
     238,   336,   462,   430,   232,   337,  -509,   492,   341,   342,
     343,   453,  -330,   544,   181,   545,   391,   453,   553,   453,
     255,   243,   554,   589,   257,   613,  -331,   453,   261,   614,
     524,   391,   142,   143,   144,   145,   146,   603,   615,   323,
     556,   490,   616,   322,   512,   513,   514,   515,  -333,   340,
     153,   154,   155,  -334,   456,   527,   232,   232,   438,   439,
     344,   232,   352,   489,   232,   232,   232,   462,   236,     8,
     237,  -338,   228,   153,   154,   155,  -339,   181,  -341,   181,
     444,   445,   215,   380,   475,   476,  -342,   181,   493,   250,
     323,  -343,   580,   595,   322,   581,   404,   405,   462,   611,
     433,   434,   435,   222,   572,   498,   565,   566,   508,   509,
    -344,   510,   511,  -345,   462,   516,   517,   432,   569,  -347,
    -348,  -349,   216,   490,  -350,  -352,   250,  -353,   224,  -354,
    -355,  -357,  -358,  -359,   254,  -361,  -362,  -121,  -363,  -364,
      17,    18,  -366,  -332,  -351,  -360,  -340,   323,   590,   211,
    -346,   322,   605,  -356,  -365,  -367,  -368,   608,   610,   584,
     457,   225,   226,   227,  -369,  -370,   458,  -371,   352,  -372,
    -335,   606,   610,    39,   197,   198,   212,   199,    43,    44,
      45,    46,    47,  -336,  -337,  -373,  -374,   213,  -375,  -376,
    -377,  -378,  -379,  -380,  -381,  -382,  -383,   181,  -384,  -385,
    -386,  -387,  -388,  -389,  -390,   181,  -391,  -392,  -393,  -394,
    -395,  -396,   181,  -397,  -398,  -399,   323,   380,  -400,  -401,
     322,  -402,   323,  -403,  -404,  -405,   214,   223,   323,   252,
     356,   260,   322,   334,   -21,   268,   -22,   347,   379,   497,
     378,   387,   394,   388,   397,   505,   506,   507,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   395,   398,   399,   402,   142,   143,
     144,   145,   146,   403,   408,   -48,   446,   414,   419,   447,
     449,   142,   143,   144,   145,   146,   448,   450,   -47,   219,
     200,   468,   201,   465,   480,   482,   535,   -42,   380,   540,
     533,   539,   534,   453,   323,   548,   547,   550,   228,   153,
     154,   155,   551,   323,   552,   562,   546,   322,   571,   -52,
     202,   203,   153,   154,   155,   574,   586,   570,   576,   587,
     585,   592,   588,   620,   607,   604,   621,   217,   162,   520,
     522,   467,   335,   518,   591,   519,   386,   479,   521,   407,
     221,   163,   558,   523,   609,   357,   358,   359,   360,   361,
     494,   612,   564,   323,   541,   218,   323,   322,   483,     0,
     322,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   537,   484,     0,     0,
     323,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,   601,   602,     0,   322,   323,   323,     0,     0,
     322,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,   322,     0,     0,     0,     0,
     618,     0,   619,    17,    18,    19,    20,    21,    22,    23,
     269,   270,   271,     0,   272,   273,   274,   275,   276,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   277,   200,   150,   201,   278,   279,   280,   281,
     282,   283,     0,     0,   284,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,   286,     0,
       0,     0,     0,     0,   287,   288,   289,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
     292,   293,    17,    18,    19,    20,    21,    22,    23,   269,
     270,   271,     0,   272,   273,   274,   275,   276,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   277,   200,   150,   201,   278,   279,   280,   281,   282,
     283,     0,     0,   284,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,   286,     0,     0,
       0,     0,     0,   287,   288,   289,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   292,
     455,    17,    18,    19,    20,    21,    22,    23,   269,   270,
     271,     0,   272,   273,   274,   275,   276,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     277,   200,   150,   201,   278,   279,   280,   281,   282,   283,
       0,     0,   284,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,   287,   288,   289,   290,    17,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,   291,   292,   549,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     197,   198,     0,   199,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   197,   198,   256,   199,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,     0,     0,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   197,   198,   383,   199,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   203,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,   197,   198,   385,   199,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,   269,   270,   271,     0,   272,   273,   274,   275,   276,
     593,   594,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     474,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   277,   200,   150,   201,   278,   279,   280,
     281,   282,   283,     0,     0,   284,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,   287,   288,   289,   290,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,    17,    18,    19,    20,    21,    22,    23,   269,
     270,   271,     0,   272,   273,   274,   275,   276,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   277,   200,   150,   201,   278,   279,   280,   281,   282,
     283,     0,     0,   284,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,   286,     0,     0,
       0,     0,     0,   287,   288,   289,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   292,
      17,    18,    19,    20,    21,    22,    23,   269,   270,   271,
       0,   272,   273,   274,   275,   276,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   277,
     200,   150,   201,   278,   279,   280,   281,   282,   283,     0,
       0,   284,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,     0,   286,     0,     0,     0,     0,
       0,   287,   288,   289,   290,    17,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,   291,   220,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   200,   150,   201,   278,   279,
     280,   281,   282,   283,     0,     0,   284,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
     286,     0,     0,     0,     0,     0,   287,   288,   289,   290,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,   200,   150,
     201,   278,   279,   280,   281,   282,   283,     0,     0,   284,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,   287,
     288,   289,   290,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,   461,   582,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,   200,   150,   201,   278,   279,   280,   281,   282,   283,
       0,     0,   284,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,   287,   288,   289,   290,    19,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,     0,   461,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,     0,   200,   150,   201,   278,   279,   280,
     281,   282,   283,     0,     0,   284,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,   287,   288,   289,   290,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,   197,   198,     0,   199,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   200,
     150,   201,   278,   279,   280,   281,   282,   283,     0,     0,
     284,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   286,     0,     0,     0,     0,     0,
     287,   288,   289,   290,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,   200,   150,   201,   278,   279,   280,   281,   282,   283,
       0,     0,   284,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,   286,     0,     0,   351,
       0,     0,   287,   288,   289,   290,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,   200,   150,   201,   278,   279,   280,   281,
     282,   283,     0,     0,   284,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   286,     0,
       0,   466,     0,     0,   287,   288,   289,   290,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,   200,   150,   201,   278,   279,
     280,   281,   282,   283,     0,     0,   284,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     286,     0,     0,     0,     0,     0,   287,   288,   289,   290,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   417,     0,   200,   150,   201,
     278,   279,   280,   281,   282,   283,     0,     0,   284,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   286,     0,     0,     0,     0,     0,   287,   288,
     289,   290,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   555,     0,   200,
     150,   201,   278,   279,   280,   281,   282,   283,     0,     0,
     284,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,     0,   286,     0,     0,     0,     0,     0,
     287,   288,   289,   290,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,     0,   156,     0,    12,     0,     0,     0,     0,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   164,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,   156,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,   161,   162,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   197,   198,
     164,   199,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    17,    18,     0,     0,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,    39,   240,   241,     0,   242,    43,
      44,    45,    46,    47,   202,   203,   153,   154,   155,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,    39,
     197,   198,   162,   199,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,   153,   154,   155,     0,     0,     0,     0,
     142,   143,   144,   145,   146,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,   202,   203,   153,   154,
     155,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,   202,
     203,   153,   154,   155,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,   150
};

static const yytype_int16 yycheck[] =
{
       4,   271,    13,   195,    13,   238,    13,   175,    12,   390,
     302,    19,    20,   151,   152,    13,   155,    19,    20,   155,
     151,   152,   155,   275,   258,   153,   154,   155,   459,   250,
     461,   166,   167,   464,   286,   190,   174,   171,   158,   547,
     269,   270,   156,     0,   175,   176,   250,   178,   179,   180,
     153,   154,   155,   345,   185,   164,   165,   171,   328,   153,
     154,   155,     4,   571,   268,   249,   258,   191,   260,   253,
     250,   202,   203,   250,   205,   250,   268,   250,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   268,   253,
     253,   268,   253,   268,   267,    37,    38,    39,   529,   250,
     194,   253,   194,   250,   267,   253,   209,   271,   269,   223,
     224,   344,   253,   193,   228,   267,   267,   231,   232,   233,
     267,   269,   254,   255,   416,   155,   261,   262,   269,   560,
     269,   155,   266,   269,   378,   356,   269,   253,   241,   431,
     253,   250,   270,   252,   148,   576,   398,   380,   194,   393,
     402,   403,   386,   269,   322,   166,   269,   166,   249,   166,
     412,   453,   253,   153,   154,   155,   177,   459,   166,   461,
     174,   224,   464,   268,   171,   228,   155,   249,   231,   232,
     233,   253,   261,   249,   195,   249,   378,   253,   249,   253,
     194,   322,   253,   249,   386,   249,   261,   253,   209,   253,
     452,   393,   144,   145,   146,   147,   148,   588,   249,   220,
     502,   403,   253,   220,   440,   441,   442,   443,   261,   230,
     185,   186,   187,   261,   494,   458,   223,   224,   162,   163,
     234,   228,   250,   485,   231,   232,   233,   529,   153,   154,
     155,   261,   184,   185,   186,   187,   261,   258,   261,   260,
     168,   169,   248,   257,   158,   159,   261,   268,   249,   250,
     271,   261,   554,   271,   271,   557,   284,   285,   560,   271,
     258,   259,   260,   249,   544,   413,   245,   246,   436,   437,
     261,   438,   439,   261,   576,   444,   445,   305,   540,   261,
     261,   261,   155,   485,   261,   261,   250,   261,     4,   261,
     261,   261,   261,   261,   155,   261,   261,   249,   261,   261,
       3,     4,   261,   261,   261,   261,   261,   328,   570,   194,
     261,   328,   592,   261,   261,   261,   261,   597,   598,   562,
     334,    37,    38,    39,   261,   261,   340,   261,   356,   261,
     261,   593,   612,    36,    37,    38,   194,    40,    41,    42,
      43,    44,    45,   261,   261,   261,   261,   194,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   378,   261,   261,
     261,   261,   261,   261,   261,   386,   261,   261,   261,   261,
     261,   261,   393,   261,   261,   261,   397,   391,   261,   261,
     397,   261,   403,   261,   261,   261,   194,   253,   409,   261,
     250,   270,   409,   267,   248,   270,   248,   248,   194,   413,
     270,   269,   269,   268,   248,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   269,   248,   269,   248,   144,   145,
     146,   147,   148,   248,   271,   248,   263,   249,   248,   264,
     170,   144,   145,   146,   147,   148,   265,   172,   248,   269,
     153,   262,   155,   251,   271,   152,   470,   249,   472,   248,
     251,   267,   271,   253,   485,   493,   249,   251,   184,   185,
     186,   187,   248,   494,   249,   155,   490,   494,   249,   249,
     183,   184,   185,   186,   187,   270,   248,   269,   268,   248,
     269,    13,   253,   249,   267,   269,   249,   166,   201,   448,
     450,   356,   223,   446,   571,   447,   260,   391,   449,   286,
     168,   214,   526,   451,   597,     5,     6,     7,     8,     9,
     409,   599,   536,   544,   485,   166,   547,   544,   397,    -1,
     547,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   472,   397,    -1,    -1,
     571,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592,   586,   587,    -1,   592,   597,   598,    -1,    -1,
     597,   598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   612,    -1,    -1,    -1,   612,    -1,    -1,    -1,    -1,
     614,    -1,   616,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,   186,   187,    -1,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,   271,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,   186,   187,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,
     271,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,   186,   187,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,   269,   270,   271,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   271,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,   271,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   271,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     271,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,   186,   187,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,   270,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,   186,   187,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,   186,   187,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,   186,   187,
      -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   271,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   248,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   248,    -1,    -1,   251,
      -1,    -1,   254,   255,   256,   257,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   248,    -1,
      -1,   251,    -1,    -1,   254,   255,   256,   257,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     248,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,   164,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,   186,
     187,    -1,   189,    -1,   191,    -1,    -1,    -1,    -1,   196,
     197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,   243,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,   186,   187,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     243,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     3,     4,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,   183,   184,   185,   186,   187,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,   201,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,   186,
     187,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   183,
     184,   185,   186,   187,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,    -1,   154
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   190,   273,   275,   158,     0,   277,   153,   154,   155,
     194,   278,   191,   274,   279,   194,   278,     3,     4,     5,
       6,     7,     8,     9,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   144,   145,   146,   147,   148,   149,   150,   151,
     154,   183,   184,   185,   186,   187,   189,   196,   197,   198,
     199,   200,   201,   214,   243,   276,   280,   314,   315,   316,
     317,   318,   324,   325,   326,   327,   332,   333,   334,   335,
     336,   340,   341,   342,   343,   345,   346,   376,   377,   378,
     379,   380,   381,   385,   193,   270,   278,    37,    38,    40,
     153,   155,   183,   184,   281,   327,   333,   281,   333,   345,
     194,   194,   194,   194,   194,   248,   155,   279,   376,   269,
     270,   359,   249,   253,     4,    37,    38,    39,   184,   320,
     321,   322,   336,   345,   253,   269,   153,   155,   278,   281,
      37,    38,    40,   333,   380,   333,   340,   333,   333,   333,
     250,   339,   261,   333,   155,   278,   271,   326,   347,   348,
     270,   340,   209,   241,   278,   328,   330,   331,   270,    10,
      11,    12,    14,    15,    16,    17,    18,   152,   156,   157,
     158,   159,   160,   161,   164,   165,   248,   254,   255,   256,
     257,   269,   270,   271,   281,   282,   283,   285,   286,   287,
     288,   289,   290,   291,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   312,
     314,   315,   327,   340,   353,   354,   355,   356,   360,   361,
     362,   365,   371,   375,   267,   320,   321,   321,   319,   323,
     340,   321,   321,   321,   278,   268,   339,   248,   269,   269,
     269,   251,   296,   309,   313,   340,   250,     5,     6,     7,
       8,     9,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   344,   270,   194,
     278,   349,   350,   271,   348,   271,   347,   269,   268,   249,
     253,   326,   383,   384,   269,   269,   354,   248,   248,   269,
     269,   312,   248,   248,   296,   296,   312,   341,   271,   357,
     164,   165,   250,   252,   249,   249,   253,   151,   310,   248,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     268,   311,   296,   258,   259,   260,   254,   255,   162,   163,
     166,   167,   261,   262,   168,   169,   263,   264,   265,   170,
     172,   171,   266,   253,   269,   271,   354,   278,   278,   268,
     339,   270,   310,   351,   268,   251,   251,   313,   262,   383,
     267,   339,   253,   269,   271,   158,   159,   329,   330,   349,
     271,   383,   152,   353,   361,   372,   312,   269,   312,   312,
     326,   364,   249,   249,   360,   284,   312,   278,   281,   292,
     293,   294,   295,   310,   310,   296,   296,   296,   298,   298,
     299,   299,   300,   300,   300,   300,   301,   301,   302,   303,
     304,   305,   306,   307,   312,   310,   267,   339,   351,   268,
     351,   352,   351,   251,   271,   278,   267,   350,   269,   267,
     248,   364,   373,   374,   249,   249,   278,   249,   296,   271,
     251,   248,   249,   249,   253,   151,   310,   267,   278,   351,
     253,   271,   155,   382,   278,   245,   246,   337,   338,   312,
     269,   249,   354,   363,   270,   366,   268,   355,   358,   359,
     310,   310,   271,   351,   339,   269,   248,   248,   253,   249,
     312,   358,    13,    19,    20,   271,   367,   368,   369,   370,
     351,   278,   278,   330,   269,   354,   312,   267,   354,   367,
     354,   271,   369,   249,   253,   249,   253,   267,   278,   278,
     249,   249
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   272,   274,   273,   275,   275,   275,   276,   276,   276,
     276,   276,   277,   277,   278,   278,   278,   279,   280,   280,
     280,   281,   281,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   283,   283,   283,   283,   284,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   291,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   296,   296,   296,
     296,   296,   297,   297,   297,   297,   298,   298,   298,   298,
     299,   299,   299,   300,   300,   300,   301,   301,   301,   301,
     301,   302,   302,   302,   303,   303,   304,   304,   305,   305,
     306,   306,   307,   307,   308,   308,   309,   309,   310,   310,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   312,   313,   314,   314,   314,   314,   314,   315,
     315,   316,   316,   317,   317,   318,   319,   319,   319,   320,
     320,   321,   321,   321,   321,   321,   321,   322,   322,   322,
     323,   324,   324,   324,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   326,   326,   327,   328,   328,   329,   329,
     330,   330,   330,   331,   331,   332,   332,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   334,   334,   335,   335,   335,   335,
     335,   335,   335,   336,   336,   336,   336,   336,   337,   337,
     337,   337,   338,   338,   339,   339,   339,   339,   340,   340,
     341,   341,   341,   341,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   345,   345,   345,   346,
     346,   346,   346,   347,   347,   348,   349,   349,   350,   350,
     350,   350,   351,   351,   351,   352,   352,   353,   354,   354,
     355,   355,   355,   355,   355,   355,   356,   357,   356,   358,
     358,   359,   359,   360,   360,   361,   361,   362,   363,   363,
     364,   364,   365,   366,   366,   367,   367,   368,   368,   369,
     369,   370,   370,   371,   371,   371,   372,   372,   373,   373,
     374,   374,   375,   375,   375,   375,   375,   376,   376,   376,
     376,   377,   378,   378,   379,   379,   380,   381,   381,   381,
     382,   382,   382,   383,   383,   384,   385,   385,   385
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     4,     2,     2,     2,
       2,     2,     0,     2,     1,     1,     1,     5,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     3,     2,     2,     1,     1,     1,     3,
       2,     2,     2,     1,     2,     3,     2,     1,     1,     1,
       2,     2,     2,     1,     2,     3,     2,     1,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     4,     1,     1,     2,
       4,     1,     1,     2,     3,     3,     2,     4,     3,     2,
       2,     0,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     4,     6,     5,     1,     2,     3,     5,
       4,     2,     2,     1,     2,     4,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     6,
       4,     6,     1,     3,     2,     3,     3,     4,     1,     2,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     4,     3,     1,     2,     3,     1,     3,     1,     3,
       2,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       1,     2,     3,     1,     2,     1,     2,     5,     3,     1,
       1,     4,     5,     2,     3,     3,     2,     1,     2,     2,
       2,     1,     2,     5,     7,     6,     1,     1,     1,     0,
       2,     3,     2,     2,     2,     3,     2,     1,     1,     1,
       1,     2,     5,     7,     1,     2,     7,     1,     1,     1,
       0,     1,     2,     1,     2,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, state, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct _mesa_glsl_parse_state *state)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (state);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct _mesa_glsl_parse_state *state)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, struct _mesa_glsl_parse_state *state)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, state); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct _mesa_glsl_parse_state *state)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct _mesa_glsl_parse_state *state)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 101 "hlsl_parser.yy" /* yacc.c:1429  */
{
   yylloc.first_line = 1;
   yylloc.first_column = 1;
   yylloc.last_line = 1;
   yylloc.last_column = 1;
   yylloc.source = 0;
   yylloc.filename = state->current_filename;
}

#line 3291 "hlsl_parser.cpp" /* yacc.c:1429  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, state);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 333 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      _mesa_glsl_initialize_types(state);
   }
#line 3482 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 337 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      delete state->symbols;
      state->symbols = new(ralloc_parent(state)) glsl_symbol_table;
      _mesa_glsl_initialize_types(state);
   }
#line 3492 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 347 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->process_version_directive(&(yylsp[-1]), (yyvsp[-1].n), NULL);
      if (state->error) {
         YYERROR;
      }
   }
#line 3503 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 354 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->process_version_directive(&(yylsp[-2]), (yyvsp[-2].n), (yyvsp[-1].identifier));
      if (state->error) {
         YYERROR;
      }
   }
#line 3514 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 368 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* Pragma invariant(all) cannot be used in a fragment shader.
       *
       * Page 27 of the GLSL 1.20 spec, Page 53 of the GLSL ES 3.00 spec:
       *
       *     "It is an error to use this pragma in a fragment shader."
       */
      if (state->is_version(120, 300) &&
          state->stage == MESA_SHADER_FRAGMENT) {
         _mesa_glsl_error(& (yylsp[-1]), state,
                          "pragma `invariant(all)' cannot be used "
                          "in a fragment shader.");
      } else if (!state->is_version(120, 100)) {
         _mesa_glsl_warning(& (yylsp[-1]), state,
                            "pragma `invariant(all)' not supported in %s "
                            "(GLSL ES 1.00 or GLSL 1.20 required)",
                            state->get_version_string());
      } else {
         state->all_invariant = true;
      }
   }
#line 3540 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 404 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!_mesa_glsl_process_extension((yyvsp[-3].identifier), & (yylsp[-3]), (yyvsp[-1].identifier), & (yylsp[-1]), state)) {
         YYERROR;
      }
   }
#line 3550 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 413 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* FINISHME: The NULL test is required because pragmas are set to
       * FINISHME: NULL. (See production rule for external_declaration.)
       */
      if ((yyvsp[0].node) != NULL)
         state->translation_unit.push_tail(& (yyvsp[0].node)->link);
   }
#line 3562 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 421 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* FINISHME: The NULL test is required because pragmas are set to
       * FINISHME: NULL. (See production rule for external_declaration.)
       */
      if ((yyvsp[0].node) != NULL)
         state->translation_unit.push_tail(& (yyvsp[0].node)->link);
   }
#line 3574 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 428 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!state->allow_extension_directive_midshader) {
         _mesa_glsl_error(& (yylsp[0]), state,
                          "#extension directive is not allowed "
                          "in the middle of a shader");
         YYERROR;
      }
   }
#line 3587 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 445 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_identifier, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.identifier = (yyvsp[0].identifier);
   }
#line 3598 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 452 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_int_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.int_constant = (yyvsp[0].n);
   }
#line 3609 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 459 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_uint_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.uint_constant = (yyvsp[0].n);
   }
#line 3620 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 466 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_float_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.float_constant = (yyvsp[0].real);
   }
#line 3631 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 473 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_double_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.double_constant = (yyvsp[0].dreal);
   }
#line 3642 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 480 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_bool_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.bool_constant = (yyvsp[0].n);
   }
#line 3653 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 487 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
   }
#line 3661 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 495 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_array_index, (yyvsp[-3].expression), (yyvsp[-1].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-3]), (yylsp[0]));
   }
#line 3671 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 501 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[0].expression);
   }
#line 3679 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 505 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_field_selection, (yyvsp[-2].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
      (yyval.expression)->primary_expression.identifier = (yyvsp[0].identifier);
   }
#line 3690 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 512 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_post_inc, (yyvsp[-1].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3700 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 518 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_post_dec, (yyvsp[-1].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3710 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 536 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_field_selection, (yyvsp[-2].expression), (yyvsp[0].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3720 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 555 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_location((yylsp[-1]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3730 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 561 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
      (yyval.expression)->set_location((yylsp[-2]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3740 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 577 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_function_expression((yyvsp[0].type_specifier));
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3750 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 583 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[0].identifier));
      callee->set_location((yylsp[0]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3762 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 591 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[0].identifier));
      callee->set_location((yylsp[0]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3774 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 612 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_location((yylsp[-1]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3784 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 618 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
      (yyval.expression)->set_location((yylsp[-2]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3794 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 630 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[-1].identifier));
      callee->set_location((yylsp[-1]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3806 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 643 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_pre_inc, (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3816 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 649 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_pre_dec, (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3826 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 655 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression((yyvsp[-1].n), (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3836 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 661 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      // @TODO use this instead of function_expression, ugh
      //$$ = new (ctx) ast_hlsl_prefix_cast($2, $4);
      (yyval.expression) = new (ctx) ast_function_expression((yyvsp[-2].type_specifier));
      (yyval.expression)->expressions.push_tail(&(yyvsp[0].expression)->link);
      (yyval.expression)->set_location_range((yylsp[-3]), (yylsp[-2]));
   }
#line 3849 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 673 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_plus; }
#line 3855 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 674 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_neg; }
#line 3861 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 675 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_logic_not; }
#line 3867 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 676 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_bit_not; }
#line 3873 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 682 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_mul, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3883 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 688 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_div, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3893 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 694 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_mod, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3903 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 704 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_add, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3913 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 710 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_sub, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3923 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 720 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_lshift, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3933 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 726 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_rshift, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3943 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 736 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_less, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3953 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 742 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_greater, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3963 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 748 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_lequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3973 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 754 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_gequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3983 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 764 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_equal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3993 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 770 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_nequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4003 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 780 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_and, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4013 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 790 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_xor, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4023 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 800 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_or, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4033 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 810 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_and, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4043 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 820 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_xor, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4053 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 830 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_or, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4063 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 840 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_conditional, (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 4073 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 850 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression((yyvsp[-1].n), (yyvsp[-2].expression), (yyvsp[0].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4083 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 858 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_assign; }
#line 4089 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 859 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_mul_assign; }
#line 4095 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 860 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_div_assign; }
#line 4101 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 861 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_mod_assign; }
#line 4107 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 862 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_add_assign; }
#line 4113 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 863 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_sub_assign; }
#line 4119 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 864 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_ls_assign; }
#line 4125 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 865 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_rs_assign; }
#line 4131 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 866 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_and_assign; }
#line 4137 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 867 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_xor_assign; }
#line 4143 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 868 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_or_assign; }
#line 4149 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 873 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[0].expression);
   }
#line 4157 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 877 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      if ((yyvsp[-2].expression)->oper != ast_sequence) {
         (yyval.expression) = new(ctx) ast_expression(ast_sequence, NULL, NULL, NULL);
         (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
         (yyval.expression)->expressions.push_tail(& (yyvsp[-2].expression)->link);
      } else {
         (yyval.expression) = (yyvsp[-2].expression);
      }

      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 4174 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 897 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->symbols->pop_scope();
      (yyval.node) = (yyvsp[-1].function);
   }
#line 4183 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 902 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-1].declarator_list);
   }
#line 4191 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 906 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyvsp[-1].type_specifier)->default_precision = (yyvsp[-2].n);
      (yyval.node) = (yyvsp[-1].type_specifier);
   }
#line 4200 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 911 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
   }
#line 4208 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 915 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
   }
#line 4216 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 922 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.function)->return_semantic = (yyvsp[0].identifier); }
#line 4222 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 932 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.function) = (yyvsp[-1].function);
      (yyval.function)->parameters.push_tail(& (yyvsp[0].parameter_declarator)->link);
   }
#line 4231 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 937 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.function) = (yyvsp[-2].function);
      (yyval.function)->parameters.push_tail(& (yyvsp[0].parameter_declarator)->link);
   }
#line 4240 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 945 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.function) = new(ctx) ast_function();
      (yyval.function)->set_location((yylsp[-1]));
      (yyval.function)->return_type = (yyvsp[-2].fully_specified_type);
      (yyval.function)->identifier = (yyvsp[-1].identifier);

      state->symbols->add_function(new(state) ir_function((yyvsp[-1].identifier)));
      state->symbols->push_scope();
   }
#line 4255 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 959 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location((yylsp[-1]));
      (yyval.parameter_declarator)->type->specifier = (yyvsp[-1].type_specifier);
      (yyval.parameter_declarator)->identifier = (yyvsp[0].identifier);
   }
#line 4269 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 969 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location_range((yylsp[-3]), (yylsp[-2]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location((yylsp[-3]));
      (yyval.parameter_declarator)->type->specifier = (yyvsp[-3].type_specifier);
      (yyval.parameter_declarator)->identifier = (yyvsp[-2].identifier);
      (yyval.parameter_declarator)->semantic = (yyvsp[0].identifier);
   }
#line 4284 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 980 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location_range((yylsp[-2]), (yylsp[0]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location((yylsp[-2]));
      (yyval.parameter_declarator)->type->specifier = (yyvsp[-2].type_specifier);
      (yyval.parameter_declarator)->identifier = (yyvsp[-1].identifier);
      (yyval.parameter_declarator)->array_specifier = (yyvsp[0].array_specifier);
   }
#line 4299 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 994 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.parameter_declarator) = (yyvsp[0].parameter_declarator);
      (yyval.parameter_declarator)->type->qualifier = (yyvsp[-1].type_qualifier);
   }
#line 4308 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 999 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location((yylsp[0]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.parameter_declarator)->type->qualifier = (yyvsp[-1].type_qualifier);
      (yyval.parameter_declarator)->type->specifier = (yyvsp[0].type_specifier);
   }
#line 4322 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1012 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
   }
#line 4330 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1016 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.constant)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate const qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.constant = 1;
   }
#line 4342 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1024 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.precise)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precise qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 4354 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1032 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (((yyvsp[-1].type_qualifier).flags.q.in || (yyvsp[-1].type_qualifier).flags.q.out) && ((yyvsp[0].type_qualifier).flags.q.in || (yyvsp[0].type_qualifier).flags.q.out))
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate in/out/inout qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.q.constant)
         _mesa_glsl_error(&(yylsp[-1]), state, "in/out/inout must come after const "
                                      "or precise");

      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 4370 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1044 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).precision != ast_precision_none)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precision qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.i != 0)
         _mesa_glsl_error(&(yylsp[-1]), state, "precision qualifiers must come last");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).precision = (yyvsp[-1].n);
   }
#line 4385 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1055 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 4394 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1062 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 4403 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1067 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 4412 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1072 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 4422 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1086 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = (yyvsp[-2].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[0].identifier), ir_var_auto));
   }
#line 4436 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1096 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      decl->set_location_range((yylsp[-1]), (yylsp[0]));

      (yyval.declarator_list) = (yyvsp[-3].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-1].identifier), ir_var_auto));
   }
#line 4450 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1106 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), (yyvsp[0].expression));
      decl->set_location_range((yylsp[-3]), (yylsp[-2]));

      (yyval.declarator_list) = (yyvsp[-5].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-3].identifier), ir_var_auto));
   }
#line 4464 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1116 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      decl->set_location((yylsp[-2]));

      (yyval.declarator_list) = (yyvsp[-4].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-2].identifier), ir_var_auto));
   }
#line 4478 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1130 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      /* Empty declaration list is valid. */
      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[0].fully_specified_type));
      (yyval.declarator_list)->set_location((yylsp[0]));
   }
#line 4489 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1137 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-1].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4503 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1147 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      decl->set_location_range((yylsp[-1]), (yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-2].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-2]), (yylsp[0]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4517 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1157 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), (yyvsp[0].expression));
      decl->set_location_range((yylsp[-3]), (yylsp[-2]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-4].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-4]), (yylsp[-2]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4531 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1167 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      decl->set_location((yylsp[-2]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-3].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-3]), (yylsp[-2]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4545 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1177 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list(NULL);
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->invariant = true;

      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4561 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1189 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list(NULL);
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->precise = true;

      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4577 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1204 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.fully_specified_type) = new(ctx) ast_fully_specified_type();
      (yyval.fully_specified_type)->set_location((yylsp[0]));
      (yyval.fully_specified_type)->specifier = (yyvsp[0].type_specifier);
   }
#line 4588 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1211 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.fully_specified_type) = new(ctx) ast_fully_specified_type();
      (yyval.fully_specified_type)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.fully_specified_type)->qualifier = (yyvsp[-1].type_qualifier);
      (yyval.fully_specified_type)->specifier = (yyvsp[0].type_specifier);
   }
#line 4600 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1222 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
   }
#line 4608 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1230 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-2].type_qualifier);
      if (!(yyval.type_qualifier).merge_qualifier(& (yylsp[0]), state, (yyvsp[0].type_qualifier))) {
         YYERROR;
      }
   }
#line 4619 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1239 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4625 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1240 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4631 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1245 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));

      /* Layout qualifiers for ARB_fragment_coord_conventions. */
      if (!(yyval.type_qualifier).flags.i && (state->ARB_fragment_coord_conventions_enable ||
                          state->is_version(150, 0))) {
         if (match_layout_qualifier((yyvsp[0].identifier), "origin_upper_left", state) == 0) {
            (yyval.type_qualifier).flags.q.origin_upper_left = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "pixel_center_integer",
                                           state) == 0) {
            (yyval.type_qualifier).flags.q.pixel_center_integer = 1;
         }

         if ((yyval.type_qualifier).flags.i && state->ARB_fragment_coord_conventions_warn) {
            _mesa_glsl_warning(& (yylsp[0]), state,
                               "GL_ARB_fragment_coord_conventions layout "
                               "identifier `%s' used", (yyvsp[0].identifier));
         }
      }

      /* Layout qualifiers for AMD/ARB_conservative_depth. */
      if (!(yyval.type_qualifier).flags.i &&
          (state->AMD_conservative_depth_enable ||
           state->ARB_conservative_depth_enable)) {
         if (match_layout_qualifier((yyvsp[0].identifier), "depth_any", state) == 0) {
            (yyval.type_qualifier).flags.q.depth_any = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "depth_greater", state) == 0) {
            (yyval.type_qualifier).flags.q.depth_greater = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "depth_less", state) == 0) {
            (yyval.type_qualifier).flags.q.depth_less = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "depth_unchanged",
                                           state) == 0) {
            (yyval.type_qualifier).flags.q.depth_unchanged = 1;
         }

         if ((yyval.type_qualifier).flags.i && state->AMD_conservative_depth_warn) {
            _mesa_glsl_warning(& (yylsp[0]), state,
                               "GL_AMD_conservative_depth "
                               "layout qualifier `%s' is used", (yyvsp[0].identifier));
         }
         if ((yyval.type_qualifier).flags.i && state->ARB_conservative_depth_warn) {
            _mesa_glsl_warning(& (yylsp[0]), state,
                               "GL_ARB_conservative_depth "
                               "layout qualifier `%s' is used", (yyvsp[0].identifier));
         }
      }

      /* See also interface_block_layout_qualifier. */
      if (!(yyval.type_qualifier).flags.i && state->has_uniform_buffer_objects()) {
         if (match_layout_qualifier((yyvsp[0].identifier), "std140", state) == 0) {
            (yyval.type_qualifier).flags.q.std140 = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "shared", state) == 0) {
            (yyval.type_qualifier).flags.q.shared = 1;
         } else if (match_layout_qualifier((yyvsp[0].identifier), "column_major", state) == 0) {
            (yyval.type_qualifier).flags.q.column_major = 1;
         /* "row_major" is a reserved word in GLSL 1.30+. Its token is parsed
          * below in the interface_block_layout_qualifier rule.
          *
          * It is not a reserved word in GLSL ES 3.00, so it's handled here as
          * an identifier.
          *
          * Also, this takes care of alternate capitalizations of
          * "row_major" (which is necessary because layout qualifiers
          * are case-insensitive in desktop GLSL).
          */
         } else if (match_layout_qualifier((yyvsp[0].identifier), "row_major", state) == 0) {
            (yyval.type_qualifier).flags.q.row_major = 1;
         /* "packed" is a reserved word in GLSL, and its token is
          * parsed below in the interface_block_layout_qualifier rule.
          * However, we must take care of alternate capitalizations of
          * "packed", because layout qualifiers are case-insensitive
          * in desktop GLSL.
          */
         } else if (match_layout_qualifier((yyvsp[0].identifier), "packed", state) == 0) {
           (yyval.type_qualifier).flags.q.packed = 1;
         }

         if ((yyval.type_qualifier).flags.i && state->ARB_uniform_buffer_object_warn) {
            _mesa_glsl_warning(& (yylsp[0]), state,
                               "#version 140 / GL_ARB_uniform_buffer_object "
                               "layout qualifier `%s' is used", (yyvsp[0].identifier));
         }
      }

      /* Layout qualifiers for GLSL 1.50 geometry shaders. */
      if (!(yyval.type_qualifier).flags.i) {
         static const struct {
            const char *s;
            GLenum e;
         } map[] = {
                 { "points", GL_POINTS },
                 { "lines", GL_LINES },
                 { "lines_adjacency", GL_LINES_ADJACENCY },
                 { "line_strip", GL_LINE_STRIP },
                 { "triangles", GL_TRIANGLES },
                 { "triangles_adjacency", GL_TRIANGLES_ADJACENCY },
                 { "triangle_strip", GL_TRIANGLE_STRIP },
         };
         for (unsigned i = 0; i < ARRAY_SIZE(map); i++) {
            if (match_layout_qualifier((yyvsp[0].identifier), map[i].s, state) == 0) {
               (yyval.type_qualifier).flags.q.prim_type = 1;
               (yyval.type_qualifier).prim_type = map[i].e;
               break;
            }
         }

         if ((yyval.type_qualifier).flags.i && !state->is_version(150, 0)) {
            _mesa_glsl_error(& (yylsp[0]), state, "#version 150 layout "
                             "qualifier `%s' used", (yyvsp[0].identifier));
         }
      }

      /* Layout qualifiers for ARB_shader_image_load_store. */
      if (state->ARB_shader_image_load_store_enable ||
          state->is_version(420, 0)) {
         if (!(yyval.type_qualifier).flags.i) {
            static const struct {
               const char *name;
               GLenum format;
               glsl_base_type base_type;
            } map[] = {
               { "rgba32f", GL_RGBA32F, GLSL_TYPE_FLOAT },
               { "rgba16f", GL_RGBA16F, GLSL_TYPE_FLOAT },
               { "rg32f", GL_RG32F, GLSL_TYPE_FLOAT },
               { "rg16f", GL_RG16F, GLSL_TYPE_FLOAT },
               { "r11f_g11f_b10f", GL_R11F_G11F_B10F, GLSL_TYPE_FLOAT },
               { "r32f", GL_R32F, GLSL_TYPE_FLOAT },
               { "r16f", GL_R16F, GLSL_TYPE_FLOAT },
               { "rgba32ui", GL_RGBA32UI, GLSL_TYPE_UINT },
               { "rgba16ui", GL_RGBA16UI, GLSL_TYPE_UINT },
               { "rgb10_a2ui", GL_RGB10_A2UI, GLSL_TYPE_UINT },
               { "rgba8ui", GL_RGBA8UI, GLSL_TYPE_UINT },
               { "rg32ui", GL_RG32UI, GLSL_TYPE_UINT },
               { "rg16ui", GL_RG16UI, GLSL_TYPE_UINT },
               { "rg8ui", GL_RG8UI, GLSL_TYPE_UINT },
               { "r32ui", GL_R32UI, GLSL_TYPE_UINT },
               { "r16ui", GL_R16UI, GLSL_TYPE_UINT },
               { "r8ui", GL_R8UI, GLSL_TYPE_UINT },
               { "rgba32i", GL_RGBA32I, GLSL_TYPE_INT },
               { "rgba16i", GL_RGBA16I, GLSL_TYPE_INT },
               { "rgba8i", GL_RGBA8I, GLSL_TYPE_INT },
               { "rg32i", GL_RG32I, GLSL_TYPE_INT },
               { "rg16i", GL_RG16I, GLSL_TYPE_INT },
               { "rg8i", GL_RG8I, GLSL_TYPE_INT },
               { "r32i", GL_R32I, GLSL_TYPE_INT },
               { "r16i", GL_R16I, GLSL_TYPE_INT },
               { "r8i", GL_R8I, GLSL_TYPE_INT },
               { "rgba16", GL_RGBA16, GLSL_TYPE_FLOAT },
               { "rgb10_a2", GL_RGB10_A2, GLSL_TYPE_FLOAT },
               { "rgba8", GL_RGBA8, GLSL_TYPE_FLOAT },
               { "rg16", GL_RG16, GLSL_TYPE_FLOAT },
               { "rg8", GL_RG8, GLSL_TYPE_FLOAT },
               { "r16", GL_R16, GLSL_TYPE_FLOAT },
               { "r8", GL_R8, GLSL_TYPE_FLOAT },
               { "rgba16_snorm", GL_RGBA16_SNORM, GLSL_TYPE_FLOAT },
               { "rgba8_snorm", GL_RGBA8_SNORM, GLSL_TYPE_FLOAT },
               { "rg16_snorm", GL_RG16_SNORM, GLSL_TYPE_FLOAT },
               { "rg8_snorm", GL_RG8_SNORM, GLSL_TYPE_FLOAT },
               { "r16_snorm", GL_R16_SNORM, GLSL_TYPE_FLOAT },
               { "r8_snorm", GL_R8_SNORM, GLSL_TYPE_FLOAT }
            };

            for (unsigned i = 0; i < ARRAY_SIZE(map); i++) {
               if (match_layout_qualifier((yyvsp[0].identifier), map[i].name, state) == 0) {
                  (yyval.type_qualifier).flags.q.explicit_image_format = 1;
                  (yyval.type_qualifier).image_format = map[i].format;
                  (yyval.type_qualifier).image_base_type = map[i].base_type;
                  break;
               }
            }
         }

         if (!(yyval.type_qualifier).flags.i &&
             match_layout_qualifier((yyvsp[0].identifier), "early_fragment_tests", state) == 0) {
            /* From section 4.4.1.3 of the GLSL 4.50 specification
             * (Fragment Shader Inputs):
             *
             *  "Fragment shaders also allow the following layout
             *   qualifier on in only (not with variable declarations)
             *     layout-qualifier-id
             *        early_fragment_tests
             *   [...]"
             */
            if (state->stage != MESA_SHADER_FRAGMENT) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "early_fragment_tests layout qualifier only "
                                "valid in fragment shaders");
            }

            (yyval.type_qualifier).flags.q.early_fragment_tests = 1;
         }
      }

      if (!(yyval.type_qualifier).flags.i) {
         _mesa_glsl_error(& (yylsp[0]), state, "unrecognized layout identifier "
                          "`%s'", (yyvsp[0].identifier));
         YYERROR;
      }
   }
#line 4835 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1445 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));

      if (match_layout_qualifier("location", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.explicit_location = 1;

         if ((yyval.type_qualifier).flags.q.attribute == 1 &&
             state->ARB_explicit_attrib_location_warn) {
            _mesa_glsl_warning(& (yylsp[-2]), state,
                               "GL_ARB_explicit_attrib_location layout "
                               "identifier `%s' used", (yyvsp[-2].identifier));
         }

         if ((yyvsp[0].n) >= 0) {
            (yyval.type_qualifier).location = (yyvsp[0].n);
         } else {
             _mesa_glsl_error(& (yylsp[0]), state, "invalid location %d specified", (yyvsp[0].n));
             YYERROR;
         }
      }

      if (match_layout_qualifier("index", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.explicit_index = 1;

         if ((yyvsp[0].n) >= 0) {
            (yyval.type_qualifier).index = (yyvsp[0].n);
         } else {
            _mesa_glsl_error(& (yylsp[0]), state, "invalid index %d specified", (yyvsp[0].n));
            YYERROR;
         }
      }

      if ((state->ARB_shading_language_420pack_enable ||
           state->has_atomic_counters()) &&
          match_layout_qualifier("binding", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.explicit_binding = 1;
         (yyval.type_qualifier).binding = (yyvsp[0].n);
      }

      if (state->has_atomic_counters() &&
          match_layout_qualifier("offset", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.explicit_offset = 1;
         (yyval.type_qualifier).offset = (yyvsp[0].n);
      }

      if (match_layout_qualifier("max_vertices", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.max_vertices = 1;

         if ((yyvsp[0].n) < 0) {
            _mesa_glsl_error(& (yylsp[0]), state,
                             "invalid max_vertices %d specified", (yyvsp[0].n));
            YYERROR;
         } else {
            (yyval.type_qualifier).max_vertices = (yyvsp[0].n);
            if (!state->is_version(150, 0)) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "#version 150 max_vertices qualifier "
                                "specified", (yyvsp[0].n));
            }
         }
      }

      if (state->stage == MESA_SHADER_GEOMETRY) {
         if (match_layout_qualifier("stream", (yyvsp[-2].identifier), state) == 0 &&
             state->check_explicit_attrib_stream_allowed(& (yylsp[0]))) {
            (yyval.type_qualifier).flags.q.stream = 1;

            if ((yyvsp[0].n) < 0) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "invalid stream %d specified", (yyvsp[0].n));
               YYERROR;
            } else {
               (yyval.type_qualifier).flags.q.explicit_stream = 1;
               (yyval.type_qualifier).stream = (yyvsp[0].n);
            }
         }
      }

      static const char * const local_size_qualifiers[3] = {
         "local_size_x",
         "local_size_y",
         "local_size_z",
      };
      for (int i = 0; i < 3; i++) {
         if (match_layout_qualifier(local_size_qualifiers[i], (yyvsp[-2].identifier),
                                    state) == 0) {
            if ((yyvsp[0].n) <= 0) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "invalid %s of %d specified",
                                local_size_qualifiers[i], (yyvsp[0].n));
               YYERROR;
            } else if (!state->is_version(430, 0) &&
                       !state->ARB_compute_shader_enable) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "%s qualifier requires GLSL 4.30 or "
                                "ARB_compute_shader",
                                local_size_qualifiers[i]);
               YYERROR;
            } else {
               (yyval.type_qualifier).flags.q.local_size |= (1 << i);
               (yyval.type_qualifier).local_size[i] = (yyvsp[0].n);
            }
            break;
         }
      }

      if (match_layout_qualifier("invocations", (yyvsp[-2].identifier), state) == 0) {
         (yyval.type_qualifier).flags.q.invocations = 1;

         if ((yyvsp[0].n) <= 0) {
            _mesa_glsl_error(& (yylsp[0]), state,
                             "invalid invocations %d specified", (yyvsp[0].n));
            YYERROR;
         } else if ((yyvsp[0].n) > MAX_GEOMETRY_SHADER_INVOCATIONS) {
            _mesa_glsl_error(& (yylsp[0]), state,
                             "invocations (%d) exceeds "
                             "GL_MAX_GEOMETRY_SHADER_INVOCATIONS", (yyvsp[0].n));
            YYERROR;
         } else {
            (yyval.type_qualifier).invocations = (yyvsp[0].n);
            if (!state->is_version(400, 0) &&
                !state->ARB_gpu_shader5_enable) {
               _mesa_glsl_error(& (yylsp[0]), state,
                                "GL_ARB_gpu_shader5 invocations "
                                "qualifier specified", (yyvsp[0].n));
            }
         }
      }

      /* If the identifier didn't match any known layout identifiers,
       * emit an error.
       */
      if (!(yyval.type_qualifier).flags.i) {
         _mesa_glsl_error(& (yylsp[-2]), state, "unrecognized layout identifier "
                          "`%s'", (yyvsp[-2].identifier));
         YYERROR;
      }
   }
#line 4978 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1584 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      /* Layout qualifiers for ARB_uniform_buffer_object. */
      if ((yyval.type_qualifier).flags.q.uniform && !state->has_uniform_buffer_objects()) {
         _mesa_glsl_error(& (yylsp[0]), state,
                          "#version 140 / GL_ARB_uniform_buffer_object "
                          "layout qualifier `%s' is used", (yyvsp[0].type_qualifier));
      } else if ((yyval.type_qualifier).flags.q.uniform && state->ARB_uniform_buffer_object_warn) {
         _mesa_glsl_warning(& (yylsp[0]), state,
                            "#version 140 / GL_ARB_uniform_buffer_object "
                            "layout qualifier `%s' is used", (yyvsp[0].type_qualifier));
      }
   }
#line 4996 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1610 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.row_major = 1;
   }
#line 5005 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1615 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.packed = 1;
   }
#line 5014 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1623 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.smooth = 1;
   }
#line 5023 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1628 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.flat = 1;
   }
#line 5032 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1633 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.noperspective = 1;
   }
#line 5041 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1642 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.invariant = 1;
   }
#line 5050 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1647 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 5059 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1657 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).precision = (yyvsp[0].n);
   }
#line 5068 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1675 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.precise)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate \"precise\" qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 5080 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1683 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.invariant)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate \"invariant\" qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.q.precise)
         _mesa_glsl_error(&(yylsp[-1]), state,
                          "\"invariant\" must come after \"precise\"");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.invariant = 1;

      /* GLSL ES 3.00 spec, section 4.6.1 "The Invariant Qualifier":
       *
       * "Only variables output from a shader can be candidates for invariance.
       * This includes user-defined output variables and the built-in output
       * variables. As only outputs can be declared as invariant, an invariant
       * output from one shader stage will still match an input of a subsequent
       * stage without the input being declared as invariant."
       */
      if (state->es_shader && state->language_version >= 300 && (yyval.type_qualifier).flags.q.in)
         _mesa_glsl_error(&(yylsp[-1]), state, "invariant qualifiers cannot be used with shader inputs");
   }
#line 5107 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1706 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* Section 4.3 of the GLSL 1.40 specification states:
       * "...qualified with one of these interpolation qualifiers"
       *
       * GLSL 1.30 claims to allow "one or more", but insists that:
       * "These interpolation qualifiers may only precede the qualifiers in,
       *  centroid in, out, or centroid out in a declaration."
       *
       * ...which means that e.g. smooth can't precede smooth, so there can be
       * only one after all, and the 1.40 text is a clarification, not a change.
       */
      if ((yyvsp[0].type_qualifier).has_interpolation())
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate interpolation qualifier");

      if (!state->ARB_shading_language_420pack_enable &&
          ((yyvsp[0].type_qualifier).flags.q.precise || (yyvsp[0].type_qualifier).flags.q.invariant)) {
         _mesa_glsl_error(&(yylsp[-1]), state, "interpolation qualifiers must come "
                          "after \"precise\" or \"invariant\"");
      }

      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5135 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1730 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* In the absence of ARB_shading_language_420pack, layout qualifiers may
       * appear no later than auxiliary storage qualifiers. There is no
       * particularly clear spec language mandating this, but in all examples
       * the layout qualifier precedes the storage qualifier.
       *
       * We allow combinations of layout with interpolation, invariant or
       * precise qualifiers since these are useful in ARB_separate_shader_objects.
       * There is no clear spec guidance on this either.
       */
      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).has_layout())
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate layout(...) qualifiers");

      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5156 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1747 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).has_auxiliary_storage()) {
         _mesa_glsl_error(&(yylsp[-1]), state,
                          "duplicate auxiliary storage qualifier (centroid or sample)");
      }

      if (!state->ARB_shading_language_420pack_enable &&
          ((yyvsp[0].type_qualifier).flags.q.precise || (yyvsp[0].type_qualifier).flags.q.invariant ||
           (yyvsp[0].type_qualifier).has_interpolation() || (yyvsp[0].type_qualifier).has_layout())) {
         _mesa_glsl_error(&(yylsp[-1]), state, "auxiliary storage qualifiers must come "
                          "just before storage qualifiers");
      }
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5176 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1763 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* Section 4.3 of the GLSL 1.20 specification states:
       * "Variable declarations may have a storage qualifier specified..."
       *  1.30 clarifies this to "may have one storage qualifier".
       */
      if ((yyvsp[-1].type_qualifier).has_storage() && (yyvsp[0].type_qualifier).has_storage())
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate storage qualifier");

      if (!state->ARB_shading_language_420pack_enable &&
          ((yyvsp[0].type_qualifier).flags.q.precise || (yyvsp[0].type_qualifier).flags.q.invariant || (yyvsp[0].type_qualifier).has_interpolation() ||
           (yyvsp[0].type_qualifier).has_layout() || (yyvsp[0].type_qualifier).has_auxiliary_storage())) {
         _mesa_glsl_error(&(yylsp[-1]), state, "storage qualifiers must come after "
                          "precise, invariant, interpolation, layout and auxiliary "
                          "storage qualifiers");
      }

      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5200 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1783 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).precision != ast_precision_none)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precision qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.i != 0)
         _mesa_glsl_error(&(yylsp[-1]), state, "precision qualifiers must come last");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).precision = (yyvsp[-1].n);
   }
#line 5215 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1794 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5224 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1802 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.centroid = 1;
   }
#line 5233 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1807 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.sample = 1;
   }
#line 5242 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1815 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.constant = 1;
   }
#line 5251 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1820 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.attribute = 1;
   }
#line 5260 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1825 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.varying = 1;
   }
#line 5269 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1830 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 5278 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1835 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.out = 1;

      if (state->stage == MESA_SHADER_GEOMETRY &&
          state->has_explicit_attrib_stream()) {
         /* Section 4.3.8.2 (Output Layout Qualifiers) of the GLSL 4.00
          * spec says:
          *
          *     "If the block or variable is declared with the stream
          *     identifier, it is associated with the specified stream;
          *     otherwise, it is associated with the current default stream."
          */
          (yyval.type_qualifier).flags.q.stream = 1;
          (yyval.type_qualifier).flags.q.explicit_stream = 0;
          (yyval.type_qualifier).stream = state->out_qualifier->stream;
      }
   }
#line 5301 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1854 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.uniform = 1;
   }
#line 5310 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1859 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.static_ = 1;
   }
#line 5319 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1867 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.coherent = 1;
   }
#line 5328 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1872 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q._volatile = 1;
   }
#line 5337 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1877 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      STATIC_ASSERT(sizeof((yyval.type_qualifier).flags.q) <= sizeof((yyval.type_qualifier).flags.i));
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.restrict_flag = 1;
   }
#line 5347 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1883 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.read_only = 1;
   }
#line 5356 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1888 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.write_only = 1;
   }
#line 5365 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1896 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
       if (!parse_register_location(&(yylsp[-1]), &(yyval.type_qualifier), (yyvsp[-1].identifier), state)) {
           YYERROR;
       }
   }
#line 5376 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1904 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       // space, etc ignored for now
       memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
       if (!parse_register_location(&(yylsp[-3]), &(yyval.type_qualifier), (yyvsp[-3].identifier), state)) {
           YYERROR;
       }
   }
#line 5388 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1913 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       // packoffset ignored for now
       memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
   }
#line 5397 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1919 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       // packoffset ignored for now
       memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
   }
#line 5406 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1928 "hlsl_parser.yy" /* yacc.c:1646  */
    {
        (yyval.type_qualifier) = (yyvsp[-2].type_qualifier);
        if (!(yyval.type_qualifier).merge_qualifier(&(yylsp[0]), state, (yyvsp[0].type_qualifier))) {
            YYERROR;
        }
    }
#line 5417 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1938 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.array_specifier) = new(ctx) ast_array_specifier((yylsp[-1]));
      (yyval.array_specifier)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 5427 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1944 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.array_specifier) = new(ctx) ast_array_specifier((yylsp[-2]), (yyvsp[-1].expression));
      (yyval.array_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 5437 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1950 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.array_specifier) = (yyvsp[-2].array_specifier);

      if (!state->ARB_arrays_of_arrays_enable) {
         _mesa_glsl_error(& (yylsp[-2]), state,
                          "GL_ARB_arrays_of_arrays "
                          "required for defining arrays of arrays");
      } else {
         _mesa_glsl_error(& (yylsp[-2]), state,
                          "only the outermost array dimension can "
                          "be unsized");
      }
   }
#line 5455 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1964 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.array_specifier) = (yyvsp[-3].array_specifier);

      if (!state->ARB_arrays_of_arrays_enable) {
         _mesa_glsl_error(& (yylsp[-3]), state,
                          "GL_ARB_arrays_of_arrays "
                          "required for defining arrays of arrays");
      }

      (yyval.array_specifier)->add_dimension((yyvsp[-1].expression));
   }
#line 5471 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1980 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_specifier) = (yyvsp[-1].type_specifier);
      (yyval.type_specifier)->array_specifier = (yyvsp[0].array_specifier);
   }
#line 5480 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1988 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].identifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5490 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1994 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].struct_specifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5500 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2000 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].identifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5510 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2006 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       void *ctx = state;
       (yyval.type_specifier) = new(ctx)ast_type_specifier((yyvsp[-3].identifier));
       (yyval.type_specifier)->template_data_type_name = (yyvsp[-1].identifier);
       (yyval.type_specifier)->set_location((yylsp[-3]));
   }
#line 5521 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2015 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "void"; }
#line 5527 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2016 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "float"; }
#line 5533 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2017 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "double"; }
#line 5539 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2018 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "int"; }
#line 5545 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2019 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uint"; }
#line 5551 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2020 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bool"; }
#line 5557 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2021 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec2"; }
#line 5563 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2022 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec3"; }
#line 5569 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2023 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec4"; }
#line 5575 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2024 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec2"; }
#line 5581 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2025 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec3"; }
#line 5587 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2026 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec4"; }
#line 5593 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2027 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec2"; }
#line 5599 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2028 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec3"; }
#line 5605 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2029 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec4"; }
#line 5611 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2030 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec2"; }
#line 5617 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 2031 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec3"; }
#line 5623 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 2032 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec4"; }
#line 5629 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 2033 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec2"; }
#line 5635 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 2034 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec3"; }
#line 5641 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 2035 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec4"; }
#line 5647 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 2036 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2"; }
#line 5653 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 2037 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2x3"; }
#line 5659 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 2038 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2x4"; }
#line 5665 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 2039 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3x2"; }
#line 5671 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 2040 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3"; }
#line 5677 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 2041 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3x4"; }
#line 5683 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 2042 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4x2"; }
#line 5689 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 2043 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4x3"; }
#line 5695 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 2044 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4"; }
#line 5701 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 2045 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2"; }
#line 5707 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 2046 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2x3"; }
#line 5713 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 2047 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2x4"; }
#line 5719 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 2048 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3x2"; }
#line 5725 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 2049 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3"; }
#line 5731 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 2050 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3x4"; }
#line 5737 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 2051 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4x2"; }
#line 5743 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 2052 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4x3"; }
#line 5749 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 2053 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4"; }
#line 5755 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 2054 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1D"; }
#line 5761 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 2055 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2D"; }
#line 5767 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 2056 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRect"; }
#line 5773 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 2057 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler3D"; }
#line 5779 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 2058 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCube"; }
#line 5785 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 2059 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerExternalOES"; }
#line 5791 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 2060 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerState"; }
#line 5797 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 2061 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerComparisonState"; }
#line 5803 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 2062 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DShadow"; }
#line 5809 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 2063 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DShadow"; }
#line 5815 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 2064 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRectShadow"; }
#line 5821 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 2065 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeShadow"; }
#line 5827 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 2066 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArray"; }
#line 5833 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 2067 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArray"; }
#line 5839 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 2068 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArrayShadow"; }
#line 5845 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 2069 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArrayShadow"; }
#line 5851 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 2070 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerBuffer"; }
#line 5857 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 2071 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArray"; }
#line 5863 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 2072 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArrayShadow"; }
#line 5869 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 2073 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1D"; }
#line 5875 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 2074 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2D"; }
#line 5881 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 2075 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DRect"; }
#line 5887 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 2076 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler3D"; }
#line 5893 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 2077 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCube"; }
#line 5899 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 2078 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1DArray"; }
#line 5905 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 2079 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DArray"; }
#line 5911 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 2080 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerBuffer"; }
#line 5917 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 2081 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCubeArray"; }
#line 5923 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 2082 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1D"; }
#line 5929 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 2083 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2D"; }
#line 5935 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 2084 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DRect"; }
#line 5941 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 2085 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler3D"; }
#line 5947 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 2086 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCube"; }
#line 5953 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 2087 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1DArray"; }
#line 5959 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 2088 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DArray"; }
#line 5965 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 2089 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerBuffer"; }
#line 5971 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 2090 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCubeArray"; }
#line 5977 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 2091 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMS"; }
#line 5983 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 2092 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMS"; }
#line 5989 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 2093 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMS"; }
#line 5995 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 2094 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMSArray"; }
#line 6001 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 2095 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMSArray"; }
#line 6007 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 2096 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMSArray"; }
#line 6013 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 2097 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1D"; }
#line 6019 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 2098 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2D"; }
#line 6025 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 2099 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image3D"; }
#line 6031 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 2100 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DRect"; }
#line 6037 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2101 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCube"; }
#line 6043 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2102 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageBuffer"; }
#line 6049 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2103 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1DArray"; }
#line 6055 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2104 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DArray"; }
#line 6061 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2105 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCubeArray"; }
#line 6067 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2106 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMS"; }
#line 6073 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2107 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMSArray"; }
#line 6079 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 2108 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1D"; }
#line 6085 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2109 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2D"; }
#line 6091 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2110 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage3D"; }
#line 6097 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2111 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DRect"; }
#line 6103 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2112 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCube"; }
#line 6109 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2113 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageBuffer"; }
#line 6115 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 2114 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1DArray"; }
#line 6121 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2115 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DArray"; }
#line 6127 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2116 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCubeArray"; }
#line 6133 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2117 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMS"; }
#line 6139 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2118 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMSArray"; }
#line 6145 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2119 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1D"; }
#line 6151 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2120 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2D"; }
#line 6157 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2121 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage3D"; }
#line 6163 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2122 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DRect"; }
#line 6169 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2123 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCube"; }
#line 6175 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2124 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageBuffer"; }
#line 6181 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2125 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1DArray"; }
#line 6187 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2126 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DArray"; }
#line 6193 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2127 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCubeArray"; }
#line 6199 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2128 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMS"; }
#line 6205 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2129 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMSArray"; }
#line 6211 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2130 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "atomic_uint"; }
#line 6217 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2134 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1D"; }
#line 6223 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2135 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2D"; }
#line 6229 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2136 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRect"; }
#line 6235 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2137 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler3D"; }
#line 6241 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2138 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCube"; }
#line 6247 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2139 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerExternalOES"; }
#line 6253 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2140 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerState"; }
#line 6259 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2141 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerComparisonState"; }
#line 6265 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 2142 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DShadow"; }
#line 6271 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2143 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DShadow"; }
#line 6277 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2144 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRectShadow"; }
#line 6283 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 2145 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeShadow"; }
#line 6289 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 2146 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArray"; }
#line 6295 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2147 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArray"; }
#line 6301 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2148 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArrayShadow"; }
#line 6307 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2149 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArrayShadow"; }
#line 6313 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2150 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerBuffer"; }
#line 6319 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2151 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArray"; }
#line 6325 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2152 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArrayShadow"; }
#line 6331 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2153 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1D"; }
#line 6337 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2154 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2D"; }
#line 6343 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2155 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DRect"; }
#line 6349 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2156 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler3D"; }
#line 6355 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2157 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCube"; }
#line 6361 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2158 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1DArray"; }
#line 6367 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2159 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DArray"; }
#line 6373 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 2160 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerBuffer"; }
#line 6379 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2161 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCubeArray"; }
#line 6385 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2162 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1D"; }
#line 6391 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2163 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2D"; }
#line 6397 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2164 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DRect"; }
#line 6403 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2165 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler3D"; }
#line 6409 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2166 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCube"; }
#line 6415 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2167 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1DArray"; }
#line 6421 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2168 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DArray"; }
#line 6427 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2169 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerBuffer"; }
#line 6433 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2170 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCubeArray"; }
#line 6439 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2171 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMS"; }
#line 6445 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2172 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMS"; }
#line 6451 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2173 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMS"; }
#line 6457 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2174 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMSArray"; }
#line 6463 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2175 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMSArray"; }
#line 6469 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2176 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMSArray"; }
#line 6475 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2177 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1D"; }
#line 6481 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2178 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2D"; }
#line 6487 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2179 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image3D"; }
#line 6493 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2180 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DRect"; }
#line 6499 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2181 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCube"; }
#line 6505 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2182 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageBuffer"; }
#line 6511 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2183 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1DArray"; }
#line 6517 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2184 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DArray"; }
#line 6523 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2185 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCubeArray"; }
#line 6529 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2186 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMS"; }
#line 6535 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2187 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMSArray"; }
#line 6541 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2188 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1D"; }
#line 6547 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2189 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2D"; }
#line 6553 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2190 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage3D"; }
#line 6559 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2191 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DRect"; }
#line 6565 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2192 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCube"; }
#line 6571 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2193 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageBuffer"; }
#line 6577 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2194 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1DArray"; }
#line 6583 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2195 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DArray"; }
#line 6589 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2196 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCubeArray"; }
#line 6595 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2197 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMS"; }
#line 6601 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2198 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMSArray"; }
#line 6607 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2199 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1D"; }
#line 6613 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2200 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2D"; }
#line 6619 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2201 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage3D"; }
#line 6625 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2202 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DRect"; }
#line 6631 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2203 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCube"; }
#line 6637 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2204 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageBuffer"; }
#line 6643 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2205 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1DArray"; }
#line 6649 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2206 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DArray"; }
#line 6655 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2207 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCubeArray"; }
#line 6661 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2208 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMS"; }
#line 6667 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2209 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMSArray"; }
#line 6673 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2213 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "float"; }
#line 6679 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2214 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "double"; }
#line 6685 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2215 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "int"; }
#line 6691 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2216 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uint"; }
#line 6697 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2217 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bool"; }
#line 6703 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2218 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec2"; }
#line 6709 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2219 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec3"; }
#line 6715 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2220 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec4"; }
#line 6721 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2221 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec2"; }
#line 6727 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2222 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec3"; }
#line 6733 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2223 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec4"; }
#line 6739 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2224 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec2"; }
#line 6745 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2225 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec3"; }
#line 6751 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2226 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec4"; }
#line 6757 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2227 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec2"; }
#line 6763 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2228 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec3"; }
#line 6769 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2229 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec4"; }
#line 6775 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2230 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec2"; }
#line 6781 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2231 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec3"; }
#line 6787 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2232 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec4"; }
#line 6793 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2237 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_high;
   }
#line 6802 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2242 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_medium;
   }
#line 6811 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2247 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_low;
   }
#line 6820 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2255 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier((yyvsp[-3].identifier), (yyvsp[-1].declarator_list));
      (yyval.struct_specifier)->set_location_range((yylsp[-3]), (yylsp[0]));
      state->symbols->add_type((yyvsp[-3].identifier), glsl_type::void_type);
   }
#line 6831 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2262 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       /* HLSL: Empty struct declarations are permitted */
       void *ctx = state;
       (yyval.struct_specifier) = new(ctx) ast_struct_specifier((yyvsp[-2].identifier), NULL);
       (yyval.struct_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
       state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6843 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2270 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier(state->anonymous_struct_counter++, (yyvsp[-1].declarator_list));
      (yyval.struct_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
      state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6854 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2277 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* HLSL: Empty struct declarations are permitted */
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier(state->anonymous_struct_counter++, NULL);
      (yyval.struct_specifier)->set_location_range((yylsp[-1]), (yylsp[0]));
      state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6866 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2288 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[0].declarator_list);
      (yyvsp[0].declarator_list)->link.self_link();
   }
#line 6875 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2293 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[-1].declarator_list);
      (yyval.declarator_list)->link.insert_before(& (yyvsp[0].declarator_list)->link);
   }
#line 6884 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2301 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_fully_specified_type *const type = (yyvsp[-2].fully_specified_type);
      type->set_location((yylsp[-2]));

      if (type->qualifier.flags.i != 0)
         _mesa_glsl_error(&(yylsp[-2]), state,
			  "only precision qualifiers may be applied to "
			  "structure members");

      (yyval.declarator_list) = new(ctx) ast_declarator_list(type);
      (yyval.declarator_list)->set_location((yylsp[-1]));

      (yyval.declarator_list)->declarations.push_degenerate_list_at_head(& (yyvsp[-1].declaration)->link);
   }
#line 6904 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2320 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declaration) = (yyvsp[0].declaration);
      (yyvsp[0].declaration)->link.self_link();
   }
#line 6913 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2325 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declaration) = (yyvsp[-2].declaration);
      (yyval.declaration)->link.insert_before(& (yyvsp[0].declaration)->link);
   }
#line 6922 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2333 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      (yyval.declaration)->set_location((yylsp[0]));
   }
#line 6932 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2339 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, NULL);
      (yyval.declaration)->set_location((yylsp[-2]));
      (yyval.declaration)->semantic = (yyvsp[0].identifier);
   }
#line 6943 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2346 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      (yyval.declaration)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 6953 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 2352 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), NULL);
      (yyval.declaration)->set_location_range((yylsp[-3]), (yylsp[-2]));
      (yyval.declaration)->semantic = (yyvsp[0].identifier);
   }
#line 6964 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2363 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
   }
#line 6972 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 2367 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
   }
#line 6980 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 2374 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_aggregate_initializer();
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 6991 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 2381 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyvsp[-2].expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 6999 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2393 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (ast_node *) (yyvsp[0].compound_statement); }
#line 7005 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2408 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(true, NULL);
      (yyval.compound_statement)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7015 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2414 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->symbols->push_scope();
   }
#line 7023 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2418 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(true, (yyvsp[-1].node));
      (yyval.compound_statement)->set_location_range((yylsp[-3]), (yylsp[0]));
      state->symbols->pop_scope();
   }
#line 7034 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2427 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (ast_node *) (yyvsp[0].compound_statement); }
#line 7040 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2433 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(false, NULL);
      (yyval.compound_statement)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7050 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2439 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(false, (yyvsp[-1].node));
      (yyval.compound_statement)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 7060 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2448 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == NULL) {
         _mesa_glsl_error(& (yylsp[0]), state, "<nil> statement");
         assert((yyvsp[0].node) != NULL);
      }

      (yyval.node) = (yyvsp[0].node);
      (yyval.node)->link.self_link();
   }
#line 7074 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2458 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == NULL) {
         _mesa_glsl_error(& (yylsp[0]), state, "<nil> statement");
         assert((yyvsp[0].node) != NULL);
      }
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->link.insert_before(& (yyvsp[0].node)->link);
   }
#line 7087 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2470 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_expression_statement(NULL);
      (yyval.node)->set_location((yylsp[0]));
   }
#line 7097 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2476 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_expression_statement((yyvsp[-1].expression));
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7107 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2485 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = new(state) ast_selection_statement((yyvsp[-2].expression), (yyvsp[0].selection_rest_statement).then_statement,
                                              (yyvsp[0].selection_rest_statement).else_statement);
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 7117 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2494 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.selection_rest_statement).then_statement = (yyvsp[-2].node);
      (yyval.selection_rest_statement).else_statement = (yyvsp[0].node);
   }
#line 7126 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2499 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.selection_rest_statement).then_statement = (yyvsp[0].node);
      (yyval.selection_rest_statement).else_statement = NULL;
   }
#line 7135 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2507 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (ast_node *) (yyvsp[0].expression);
   }
#line 7143 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2511 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      ast_declarator_list *declarator = new(ctx) ast_declarator_list((yyvsp[-3].fully_specified_type));
      decl->set_location_range((yylsp[-2]), (yylsp[0]));
      declarator->set_location((yylsp[-3]));

      declarator->declarations.push_tail(&decl->link);
      (yyval.node) = declarator;
   }
#line 7158 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2529 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = new(state) ast_switch_statement((yyvsp[-2].expression), (yyvsp[0].switch_body));
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 7167 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2537 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.switch_body) = new(state) ast_switch_body(NULL);
      (yyval.switch_body)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7176 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2542 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.switch_body) = new(state) ast_switch_body((yyvsp[-1].case_statement_list));
      (yyval.switch_body)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 7185 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2550 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label) = new(state) ast_case_label((yyvsp[-1].expression));
      (yyval.case_label)->set_location((yylsp[-1]));
   }
#line 7194 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2555 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label) = new(state) ast_case_label(NULL);
      (yyval.case_label)->set_location((yylsp[0]));
   }
#line 7203 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2563 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_label_list *labels = new(state) ast_case_label_list();

      labels->labels.push_tail(& (yyvsp[0].case_label)->link);
      (yyval.case_label_list) = labels;
      (yyval.case_label_list)->set_location((yylsp[0]));
   }
#line 7215 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2571 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label_list) = (yyvsp[-1].case_label_list);
      (yyval.case_label_list)->labels.push_tail(& (yyvsp[0].case_label)->link);
   }
#line 7224 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2579 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_statement *stmts = new(state) ast_case_statement((yyvsp[-1].case_label_list));
      stmts->set_location((yylsp[0]));

      stmts->stmts.push_tail(& (yyvsp[0].node)->link);
      (yyval.case_statement) = stmts;
   }
#line 7236 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2587 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_statement) = (yyvsp[-1].case_statement);
      (yyval.case_statement)->stmts.push_tail(& (yyvsp[0].node)->link);
   }
#line 7245 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2595 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_statement_list *cases= new(state) ast_case_statement_list();
      cases->set_location((yylsp[0]));

      cases->cases.push_tail(& (yyvsp[0].case_statement)->link);
      (yyval.case_statement_list) = cases;
   }
#line 7257 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2603 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_statement_list) = (yyvsp[-1].case_statement_list);
      (yyval.case_statement_list)->cases.push_tail(& (yyvsp[0].case_statement)->link);
   }
#line 7266 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2611 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_while,
                                            NULL, (yyvsp[-2].node), NULL, (yyvsp[0].node));
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[-1]));
   }
#line 7277 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2618 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_do_while,
                                            NULL, (yyvsp[-2].expression), NULL, (yyvsp[-5].node));
      (yyval.node)->set_location_range((yylsp[-6]), (yylsp[-1]));
   }
#line 7288 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2625 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_for,
                                            (yyvsp[-3].node), (yyvsp[-2].for_rest_statement).cond, (yyvsp[-2].for_rest_statement).rest, (yyvsp[0].node));
      (yyval.node)->set_location_range((yylsp[-5]), (yylsp[0]));
   }
#line 7299 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2641 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
   }
#line 7307 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2648 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.for_rest_statement).cond = (yyvsp[-1].node);
      (yyval.for_rest_statement).rest = NULL;
   }
#line 7316 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2653 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.for_rest_statement).cond = (yyvsp[-2].node);
      (yyval.for_rest_statement).rest = (yyvsp[0].expression);
   }
#line 7325 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2662 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_continue, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7335 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2668 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_break, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7345 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2674 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_return, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7355 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2680 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_return, (yyvsp[-1].expression));
      (yyval.node)->set_location_range((yylsp[-2]), (yylsp[-1]));
   }
#line 7365 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2686 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_discard, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7375 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2694 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].function_definition); }
#line 7381 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2695 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7387 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2696 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 7393 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2697 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7399 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2702 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.function_definition) = new(ctx) ast_function_definition();
      (yyval.function_definition)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.function_definition)->prototype = (yyvsp[-1].function);
      (yyval.function_definition)->body = (yyvsp[0].compound_statement);

      state->symbols->pop_scope();
   }
#line 7413 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2715 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       ast_type_qualifier block_qualifier;
       memset(&block_qualifier, 0, sizeof(block_qualifier));
       block_qualifier.flags.q.uniform = 1;

       /* HLSL default uniform packing */
       block_qualifier.flags.q.row_major = 1;
       block_qualifier.flags.q.std140 = 1;

       /* Instantiate block */
       ast_interface_block *block = new(state) ast_interface_block(block_qualifier, NULL, NULL);
       block->block_name = (yyvsp[-3].identifier);
       block->declarations.push_degenerate_list_at_head(&(yyvsp[-1].declarator_list)->link);

       /* Done? */
       (yyval.node) = block;
   }
#line 7435 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 2734 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       ast_type_qualifier block_qualifier;
       memcpy(&block_qualifier, &(yyvsp[0].type_qualifier), sizeof(block_qualifier));
       block_qualifier.flags.q.uniform = 1;

       /* HLSL default uniform packing */
       block_qualifier.flags.q.row_major = 1;
       block_qualifier.flags.q.std140 = 1;

       /* Instantiate block */
       ast_interface_block *block = new(state) ast_interface_block(block_qualifier, NULL, NULL);
       block->block_name = (yyvsp[-5].identifier);
       block->declarations.push_degenerate_list_at_head(&(yyvsp[-3].declarator_list)->link);

       /* Done? */
       (yyval.node) = block;
   }
#line 7457 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2769 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].interface_block);
   }
#line 7465 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2773 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_interface_block *block = (yyvsp[0].interface_block);
      if (!block->layout.merge_qualifier(& (yylsp[-1]), state, (yyvsp[-1].type_qualifier))) {
         YYERROR;
      }

      foreach_list_typed (ast_declarator_list, member, link, &block->declarations) {
         ast_type_qualifier& qualifier = member->type->qualifier;
         if (qualifier.flags.q.stream && qualifier.stream != block->layout.stream) {
               _mesa_glsl_error(& (yylsp[-1]), state,
                             "stream layout qualifier on "
                             "interface block member does not match "
                             "the interface block (%d vs %d)",
                             qualifier.stream, block->layout.stream);
               YYERROR;
         }
      }
      (yyval.node) = block;
   }
#line 7489 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2796 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_interface_block *const block = (yyvsp[-1].interface_block);

      block->block_name = (yyvsp[-5].identifier);
      block->declarations.push_degenerate_list_at_head(& (yyvsp[-3].declarator_list)->link);

      if ((yyvsp[-6].type_qualifier).flags.q.uniform) {
         if (!state->has_uniform_buffer_objects()) {
            _mesa_glsl_error(& (yylsp[-6]), state,
                             "#version 140 / GL_ARB_uniform_buffer_object "
                             "required for defining uniform blocks");
         } else if (state->ARB_uniform_buffer_object_warn) {
            _mesa_glsl_warning(& (yylsp[-6]), state,
                               "#version 140 / GL_ARB_uniform_buffer_object "
                               "required for defining uniform blocks");
         }
      } else {
         if (state->es_shader || state->language_version < 150) {
            _mesa_glsl_error(& (yylsp[-6]), state,
                             "#version 150 required for using "
                             "interface blocks");
         }
      }

      /* From the GLSL 1.50.11 spec, section 4.3.7 ("Interface Blocks"):
       * "It is illegal to have an input block in a vertex shader
       *  or an output block in a fragment shader"
       */
      if ((state->stage == MESA_SHADER_VERTEX) && (yyvsp[-6].type_qualifier).flags.q.in) {
         _mesa_glsl_error(& (yylsp[-6]), state,
                          "`in' interface block is not allowed for "
                          "a vertex shader");
      } else if ((state->stage == MESA_SHADER_FRAGMENT) && (yyvsp[-6].type_qualifier).flags.q.out) {
         _mesa_glsl_error(& (yylsp[-6]), state,
                          "`out' interface block is not allowed for "
                          "a fragment shader");
      }

      /* Since block arrays require names, and both features are added in
       * the same language versions, we don't have to explicitly
       * version-check both things.
       */
      if (block->instance_name != NULL) {
         state->check_version(150, 300, & (yylsp[-6]), "interface blocks with "
                               "an instance name are not allowed");
      }

      uint64_t interface_type_mask;
      struct ast_type_qualifier temp_type_qualifier;

      /* Get a bitmask containing only the in/out/uniform flags, allowing us
       * to ignore other irrelevant flags like interpolation qualifiers.
       */
      temp_type_qualifier.flags.i = 0;
      temp_type_qualifier.flags.q.uniform = true;
      temp_type_qualifier.flags.q.in = true;
      temp_type_qualifier.flags.q.out = true;
      interface_type_mask = temp_type_qualifier.flags.i;

      /* Get the block's interface qualifier.  The interface_qualifier
       * production rule guarantees that only one bit will be set (and
       * it will be in/out/uniform).
       */
      uint64_t block_interface_qualifier = (yyvsp[-6].type_qualifier).flags.i;

      block->layout.flags.i |= block_interface_qualifier;

      if (state->stage == MESA_SHADER_GEOMETRY &&
          state->has_explicit_attrib_stream()) {
         /* Assign global layout's stream value. */
         block->layout.flags.q.stream = 1;
         block->layout.flags.q.explicit_stream = 0;
         block->layout.stream = state->out_qualifier->stream;
      }

      foreach_list_typed (ast_declarator_list, member, link, &block->declarations) {
         ast_type_qualifier& qualifier = member->type->qualifier;
         if ((qualifier.flags.i & interface_type_mask) == 0) {
            /* GLSLangSpec.1.50.11, 4.3.7 (Interface Blocks):
             * "If no optional qualifier is used in a member declaration, the
             *  qualifier of the variable is just in, out, or uniform as declared
             *  by interface-qualifier."
             */
            qualifier.flags.i |= block_interface_qualifier;
         } else if ((qualifier.flags.i & interface_type_mask) !=
                    block_interface_qualifier) {
            /* GLSLangSpec.1.50.11, 4.3.7 (Interface Blocks):
             * "If optional qualifiers are used, they can include interpolation
             *  and storage qualifiers and they must declare an input, output,
             *  or uniform variable consistent with the interface qualifier of
             *  the block."
             */
            _mesa_glsl_error(& (yylsp[-6]), state,
                             "uniform/in/out qualifier on "
                             "interface block member does not match "
                             "the interface block");
         }

         /* From GLSL ES 3.0, chapter 4.3.7 "Interface Blocks":
          *
          * "GLSL ES 3.0 does not support interface blocks for shader inputs or
          * outputs."
          *
          * And from GLSL ES 3.0, chapter 4.6.1 "The invariant qualifier":.
          *
          * "Only variables output from a shader can be candidates for
          * invariance."
          *
          * From GLSL 4.40 and GLSL 1.50, section "Interface Blocks":
          *
          * "If optional qualifiers are used, they can include interpolation
          * qualifiers, auxiliary storage qualifiers, and storage qualifiers
          * and they must declare an input, output, or uniform member
          * consistent with the interface qualifier of the block"
          */
         if (qualifier.flags.q.invariant)
            _mesa_glsl_error(&(yylsp[-6]), state,
                             "invariant qualifiers cannot be used "
                             "with interface blocks members");
      }

      (yyval.interface_block) = block;
   }
#line 7617 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2923 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 7626 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2928 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 7635 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2933 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.uniform = 1;
   }
#line 7644 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 2941 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          NULL, NULL);
   }
#line 7653 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 2946 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          (yyvsp[0].identifier), NULL);
      (yyval.interface_block)->set_location((yylsp[0]));
   }
#line 7663 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 2952 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          (yyvsp[-1].identifier), (yyvsp[0].array_specifier));
      (yyval.interface_block)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7673 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 2961 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[0].declarator_list);
      (yyvsp[0].declarator_list)->link.self_link();
   }
#line 7682 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 2966 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[-1].declarator_list);
      (yyvsp[0].declarator_list)->link.insert_before(& (yyval.declarator_list)->link);
   }
#line 7691 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 2974 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_fully_specified_type *type = (yyvsp[-2].fully_specified_type);
      type->set_location((yylsp[-2]));

      if (type->qualifier.flags.q.attribute) {
         _mesa_glsl_error(& (yylsp[-2]), state,
                          "keyword 'attribute' cannot be used with "
                          "interface block member");
      } else if (type->qualifier.flags.q.varying) {
         _mesa_glsl_error(& (yylsp[-2]), state,
                          "keyword 'varying' cannot be used with "
                          "interface block member");
      }

      (yyval.declarator_list) = new(ctx) ast_declarator_list(type);
      (yyval.declarator_list)->set_location((yylsp[-1]));

      (yyval.declarator_list)->declarations.push_degenerate_list_at_head(& (yyvsp[-1].declaration)->link);
   }
#line 7716 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 2998 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!state->default_uniform_qualifier->merge_qualifier(& (yylsp[-2]), state, (yyvsp[-2].type_qualifier))) {
         YYERROR;
      }
      (yyval.node) = NULL;
   }
#line 7727 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 3006 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
      if (!state->in_qualifier->merge_in_qualifier(& (yylsp[-2]), state, (yyvsp[-2].type_qualifier), (yyval.node))) {
         YYERROR;
      }
   }
#line 7738 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 3014 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (state->stage != MESA_SHADER_GEOMETRY) {
         _mesa_glsl_error(& (yylsp[-2]), state,
                          "out layout qualifiers only valid in "
                          "geometry shaders");
      } else {
         if ((yyvsp[-2].type_qualifier).flags.q.prim_type) {
            /* Make sure this is a valid output primitive type. */
            switch ((yyvsp[-2].type_qualifier).prim_type) {
            case GL_POINTS:
            case GL_LINE_STRIP:
            case GL_TRIANGLE_STRIP:
               break;
            default:
               _mesa_glsl_error(&(yylsp[-2]), state, "invalid geometry shader output "
                                "primitive type");
               break;
            }
         }
         if (!state->out_qualifier->merge_qualifier(& (yylsp[-2]), state, (yyvsp[-2].type_qualifier)))
            YYERROR;

         /* Allow future assigments of global out's stream id value */
         state->out_qualifier->flags.q.explicit_stream = 0;
      }
      (yyval.node) = NULL;
   }
#line 7770 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;


#line 7774 "hlsl_parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, state, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, state, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, state);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
