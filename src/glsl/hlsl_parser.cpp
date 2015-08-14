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

#line 152 "hlsl_parser.cpp" /* yacc.c:339  */

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
    SAMPLERBUFFER = 350,
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
    IMAGE1D = 361,
    IMAGE2D = 362,
    IMAGE3D = 363,
    IMAGE2DRECT = 364,
    IMAGECUBE = 365,
    IMAGEBUFFER = 366,
    IMAGE1DARRAY = 367,
    IMAGE2DARRAY = 368,
    IMAGECUBEARRAY = 369,
    IMAGE2DMS = 370,
    IMAGE2DMSARRAY = 371,
    IIMAGE1D = 372,
    IIMAGE2D = 373,
    IIMAGE3D = 374,
    IIMAGE2DRECT = 375,
    IIMAGECUBE = 376,
    IIMAGEBUFFER = 377,
    IIMAGE1DARRAY = 378,
    IIMAGE2DARRAY = 379,
    IIMAGECUBEARRAY = 380,
    IIMAGE2DMS = 381,
    IIMAGE2DMSARRAY = 382,
    UIMAGE1D = 383,
    UIMAGE2D = 384,
    UIMAGE3D = 385,
    UIMAGE2DRECT = 386,
    UIMAGECUBE = 387,
    UIMAGEBUFFER = 388,
    UIMAGE1DARRAY = 389,
    UIMAGE2DARRAY = 390,
    UIMAGECUBEARRAY = 391,
    UIMAGE2DMS = 392,
    UIMAGE2DMSARRAY = 393,
    IMAGE1DSHADOW = 394,
    IMAGE2DSHADOW = 395,
    IMAGE1DARRAYSHADOW = 396,
    IMAGE2DARRAYSHADOW = 397,
    COHERENT = 398,
    VOLATILE = 399,
    RESTRICT = 400,
    READONLY = 401,
    WRITEONLY = 402,
    ATOMIC_UINT = 403,
    STRUCT = 404,
    VOID_TOK = 405,
    WHILE = 406,
    IDENTIFIER = 407,
    TYPE_IDENTIFIER = 408,
    NEW_IDENTIFIER = 409,
    FLOATCONSTANT = 410,
    DOUBLECONSTANT = 411,
    INTCONSTANT = 412,
    UINTCONSTANT = 413,
    BOOLCONSTANT = 414,
    FIELD_SELECTION = 415,
    LEFT_OP = 416,
    RIGHT_OP = 417,
    INC_OP = 418,
    DEC_OP = 419,
    LE_OP = 420,
    GE_OP = 421,
    EQ_OP = 422,
    NE_OP = 423,
    AND_OP = 424,
    OR_OP = 425,
    XOR_OP = 426,
    MUL_ASSIGN = 427,
    DIV_ASSIGN = 428,
    ADD_ASSIGN = 429,
    MOD_ASSIGN = 430,
    LEFT_ASSIGN = 431,
    RIGHT_ASSIGN = 432,
    AND_ASSIGN = 433,
    XOR_ASSIGN = 434,
    OR_ASSIGN = 435,
    SUB_ASSIGN = 436,
    INVARIANT = 437,
    PRECISE = 438,
    LOWP = 439,
    MEDIUMP = 440,
    HIGHP = 441,
    SUPERP = 442,
    PRECISION = 443,
    VERSION_TOK = 444,
    EXTENSION = 445,
    LINE = 446,
    COLON = 447,
    EOL = 448,
    INTERFACE = 449,
    PRAGMA_DEBUG_ON = 450,
    PRAGMA_DEBUG_OFF = 451,
    PRAGMA_OPTIMIZE_ON = 452,
    PRAGMA_OPTIMIZE_OFF = 453,
    PRAGMA_INVARIANT_ALL = 454,
    LAYOUT_TOK = 455,
    ASM = 456,
    CLASS = 457,
    UNION = 458,
    ENUM = 459,
    TYPEDEF = 460,
    TEMPLATE = 461,
    THIS = 462,
    PACKED_TOK = 463,
    GOTO = 464,
    INLINE_TOK = 465,
    NOINLINE = 466,
    PUBLIC_TOK = 467,
    STATIC = 468,
    EXTERN = 469,
    EXTERNAL = 470,
    LONG_TOK = 471,
    SHORT_TOK = 472,
    HALF = 473,
    FIXED_TOK = 474,
    UNSIGNED = 475,
    HVEC2 = 476,
    HVEC3 = 477,
    HVEC4 = 478,
    FVEC2 = 479,
    FVEC3 = 480,
    FVEC4 = 481,
    SAMPLER3DRECT = 482,
    SIZEOF = 483,
    CAST = 484,
    NAMESPACE = 485,
    USING = 486,
    RESOURCE = 487,
    PATCH = 488,
    SUBROUTINE = 489,
    ERROR_TOK = 490,
    COMMON = 491,
    PARTITION = 492,
    ACTIVE = 493,
    FILTER = 494,
    ROW_MAJOR = 495,
    QUOTED_STRING = 496,
    CBUFFER = 497,
    THEN = 498
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 99 "hlsl_parser.yy" /* yacc.c:355  */

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

#line 474 "hlsl_parser.cpp" /* yacc.c:355  */
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

#line 502 "hlsl_parser.cpp" /* yacc.c:358  */

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
#define YYLAST   6271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  268
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  509
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  602

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   498

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   252,     2,     2,     2,   256,   259,     2,
     244,   245,   254,   250,   249,   251,   248,   255,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   263,   265,
     257,   264,   258,   262,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   246,     2,   247,   260,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   266,   261,   267,   253,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   318,   318,   317,   329,   331,   338,   348,   349,   350,
     351,   352,   376,   378,   382,   383,   384,   388,   397,   405,
     413,   424,   425,   429,   436,   443,   450,   457,   464,   471,
     478,   479,   485,   489,   496,   502,   511,   515,   519,   520,
     529,   530,   534,   535,   539,   545,   557,   561,   567,   575,
     586,   587,   591,   592,   596,   602,   614,   626,   627,   633,
     639,   645,   657,   658,   659,   660,   664,   665,   671,   677,
     686,   687,   693,   702,   703,   709,   718,   719,   725,   731,
     737,   746,   747,   753,   762,   763,   772,   773,   782,   783,
     792,   793,   802,   803,   812,   813,   822,   823,   832,   833,
     842,   843,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   856,   860,   876,   880,   885,   889,   894,   898,   905,
     906,   910,   911,   915,   920,   928,   942,   952,   963,   977,
     982,   996,   999,  1007,  1015,  1027,  1038,  1045,  1050,  1055,
    1064,  1068,  1069,  1079,  1089,  1099,  1113,  1120,  1130,  1140,
    1150,  1160,  1172,  1187,  1194,  1205,  1212,  1213,  1223,  1224,
    1228,  1428,  1567,  1593,  1598,  1606,  1611,  1616,  1625,  1630,
    1635,  1636,  1637,  1638,  1639,  1640,  1658,  1666,  1689,  1713,
    1730,  1746,  1766,  1777,  1785,  1790,  1798,  1803,  1808,  1813,
    1818,  1837,  1842,  1850,  1855,  1860,  1866,  1871,  1879,  1885,
    1891,  1905,  1920,  1921,  1929,  1935,  1941,  1947,  1957,  1958,
    1959,  1960,  1961,  1962,  1963,  1964,  1965,  1966,  1967,  1968,
    1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,
    1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,
    1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,  1997,  1998,
    1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,
    2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,  2017,  2018,
    2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,
    2049,  2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,
    2059,  2060,  2061,  2062,  2063,  2064,  2065,  2066,  2067,  2068,
    2069,  2070,  2071,  2075,  2076,  2077,  2078,  2079,  2080,  2081,
    2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,
    2092,  2093,  2094,  2095,  2096,  2097,  2098,  2099,  2100,  2101,
    2102,  2103,  2104,  2105,  2106,  2107,  2108,  2109,  2110,  2111,
    2112,  2113,  2114,  2115,  2116,  2117,  2118,  2119,  2120,  2121,
    2122,  2123,  2124,  2125,  2126,  2127,  2128,  2129,  2130,  2131,
    2132,  2133,  2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,
    2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2176,  2181,
    2186,  2194,  2201,  2209,  2216,  2227,  2232,  2240,  2259,  2264,
    2272,  2278,  2285,  2291,  2301,  2302,  2306,  2313,  2320,  2327,
    2333,  2334,  2338,  2339,  2340,  2341,  2342,  2343,  2347,  2354,
    2353,  2367,  2368,  2372,  2378,  2387,  2397,  2409,  2415,  2424,
    2433,  2438,  2446,  2450,  2468,  2476,  2481,  2489,  2494,  2502,
    2510,  2518,  2526,  2534,  2542,  2550,  2557,  2564,  2574,  2575,
    2579,  2581,  2587,  2592,  2601,  2607,  2613,  2619,  2625,  2634,
    2635,  2636,  2637,  2641,  2654,  2689,  2693,  2716,  2843,  2848,
    2853,  2862,  2866,  2872,  2881,  2886,  2894,  2918,  2926,  2934
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
  "ISAMPLER2DRECT", "USAMPLER2DRECT", "SAMPLER2DRECTSHADOW",
  "SAMPLERBUFFER", "ISAMPLERBUFFER", "USAMPLERBUFFER", "SAMPLER2DMS",
  "ISAMPLER2DMS", "USAMPLER2DMS", "SAMPLER2DMSARRAY", "ISAMPLER2DMSARRAY",
  "USAMPLER2DMSARRAY", "SAMPLEREXTERNALOES", "SAMPLERSTATE", "IMAGE1D",
  "IMAGE2D", "IMAGE3D", "IMAGE2DRECT", "IMAGECUBE", "IMAGEBUFFER",
  "IMAGE1DARRAY", "IMAGE2DARRAY", "IMAGECUBEARRAY", "IMAGE2DMS",
  "IMAGE2DMSARRAY", "IIMAGE1D", "IIMAGE2D", "IIMAGE3D", "IIMAGE2DRECT",
  "IIMAGECUBE", "IIMAGEBUFFER", "IIMAGE1DARRAY", "IIMAGE2DARRAY",
  "IIMAGECUBEARRAY", "IIMAGE2DMS", "IIMAGE2DMSARRAY", "UIMAGE1D",
  "UIMAGE2D", "UIMAGE3D", "UIMAGE2DRECT", "UIMAGECUBE", "UIMAGEBUFFER",
  "UIMAGE1DARRAY", "UIMAGE2DARRAY", "UIMAGECUBEARRAY", "UIMAGE2DMS",
  "UIMAGE2DMSARRAY", "IMAGE1DSHADOW", "IMAGE2DSHADOW",
  "IMAGE1DARRAYSHADOW", "IMAGE2DARRAYSHADOW", "COHERENT", "VOLATILE",
  "RESTRICT", "READONLY", "WRITEONLY", "ATOMIC_UINT", "STRUCT", "VOID_TOK",
  "WHILE", "IDENTIFIER", "TYPE_IDENTIFIER", "NEW_IDENTIFIER",
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
  "ACTIVE", "FILTER", "ROW_MAJOR", "QUOTED_STRING", "CBUFFER", "THEN",
  "'('", "')'", "'['", "']'", "'.'", "','", "'+'", "'-'", "'!'", "'~'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'?'", "':'",
  "'='", "';'", "'{'", "'}'", "$accept", "translation_unit", "$@1",
  "version_statement", "pragma_statement", "extension_statement_list",
  "any_identifier", "extension_statement", "external_declaration_list",
  "variable_identifier", "primary_expression", "postfix_expression",
  "integer_expression", "function_call", "function_call_or_method",
  "function_call_generic", "function_call_header_no_parameters",
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
  "memory_qualifier", "array_specifier", "type_specifier",
  "type_specifier_nonarray", "basic_type_specifier_nonarray",
  "templated_object_type_name", "templated_object_data_type_name",
  "precision_qualifier", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "initializer", "initializer_list", "declaration_statement", "statement",
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
     495,   496,   497,   498,    40,    41,    91,    93,    46,    44,
      43,    45,    33,   126,    42,    47,    37,    60,    62,    38,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -506

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-506)))

#define YYTABLE_NINF -501

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,   -89,   101,  -506,  -118,  -506,   -85,  -506,  -506,  -506,
    -506,   -80,    67,  5558,  -506,  -506,   -69,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
     -29,    18,    39,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,   -47,   -35,   -27,   -22,
     -20,    -1,    20,    28,    35,    49,    50,    51,    52,    53,
      58,    60,    61,    63,    65,    66,    70,    71,    72,    73,
      74,    75,    76,    78,    80,    81,    84,    85,    86,    87,
      91,    98,   100,   102,   103,   104,   105,   108,   110,   111,
     112,   113,   114,   116,   117,   118,   119,   120,   121,   123,
     124,   125,   127,   129,   130,   131,   134,   135,   136,   137,
     139,   141,   142,   143,   144,   145,   151,   152,   153,   154,
     158,  -506,  -506,  -506,  -506,  -506,  -506,  -129,  -506,  -506,
     260,   260,  -506,  -506,  -506,    64,   128,   163,   165,   170,
     173,    22,  -506,   281,  -506,  5355,  -506,  -145,   -17,    44,
      41,  -139,  -506,    99,   309,  5897,  6118,  5897,  5897,  5897,
    -506,   190,  -506,   180,  5897,  -506,  -506,  -506,  -506,  -506,
    -506,   284,  -506,    67,  1368,   174,  -506,  -506,  -506,  -506,
    -506,  5897,  5897,  -506,  5897,  -506,  -506,  -506,  6118,  -506,
    -506,  -506,  -506,  -506,   -97,   175,  -506,  -506,  -506,   587,
    -506,   176,    13,    13,  -506,  -506,  -506,    13,  -506,  6118,
      13,    13,    13,    67,  -506,   203,   204,  -205,   205,  -124,
    -123,  -121,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  4290,
     211,   534,  -506,   184,   258,  -506,    67,  1596,  -506,  1824,
     193,  -506,  -506,   195,  -183,  -506,  -506,  5761,   196,   197,
    2544,   219,   220,   200,  3806,   222,   223,  -506,  -506,  -506,
    -506,  -506,  -506,  4706,  4706,  4706,  -506,  -506,  -506,  -506,
    -506,   201,  -506,   225,  -506,   -57,  -506,  -506,  -506,   227,
    -133,  4914,   230,   -88,  4706,     6,   -68,   109,  -127,   106,
     216,   217,   218,   312,   307,  -144,  -506,  -506,  -130,  -506,
     221,  5922,   239,  -506,  -506,  -506,  -506,   852,  -506,  -506,
    -506,  -506,  -506,    67,  -506,  -506,  -506,  -506,  -506,    67,
    -506,  -506,  -506,  -197,  3557,  -188,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,   237,  -506,  4498,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,   229,  5761,  -506,  -182,
    -116,  -506,  -506,  -506,  -506,  2052,  -506,   122,  -506,   -97,
      67,   231,  5761,  -506,  -506,   334,  3059,  4706,  -506,  -506,
    -103,  4706,  4057,  -506,  -506,  -109,    36,  -506,  2544,  -506,
    -506,  4706,    99,  -506,  -506,  4706,   243,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    4706,  -506,  4706,  4706,  4706,  4706,  4706,  4706,  4706,  4706,
    4706,  4706,  4706,  4706,  4706,  4706,  4706,  4706,  4706,  4706,
    4706,  4706,  4706,  -506,  -506,  -506,  -506,  -148,  3557,  -181,
    3557,  -506,  -506,  3557,  -506,  -506,   242,  -506,   232,    67,
    -146,    67,  -506,  -506,  -506,  -506,  -506,  -506,   -94,  -506,
    -506,   252,  -506,  -506,  4057,   -84,  -506,   -79,   248,    67,
     255,  -506,  4706,  1117,   254,   248,  -506,   259,  -506,   257,
      -7,  5122,  -506,  -506,  -506,  -506,  -506,     6,     6,   -68,
     -68,   109,   109,   109,   109,  -127,  -127,   106,   216,   217,
     218,   312,   307,  -141,  -506,    67,   211,  -506,  3557,  -506,
    -153,  -506,  -506,   350,  -506,    67,  -506,  -506,  4706,  -506,
     240,   261,  2544,   241,   244,  2808,  -506,  -506,  -506,  -506,
    -506,  -506,  4706,   265,  -506,  4706,  -506,  -506,  3308,  -506,
     190,   246,  -506,    -2,  4706,  2808,   499,  -506,   -12,  -506,
    3557,  -506,  -506,  -506,  -506,  -506,  -506,  -506,   211,  -506,
     249,   248,  -506,  2544,  4706,   250,  -506,  -506,  2280,  2544,
      -9,  -506,  -506,  -506,   -96,  -506,  -506,  -506,  -506,  -506,
    2544,  -506
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,    12,     0,     1,     2,    14,    15,    16,
       5,     0,     0,     0,    13,     6,     0,   187,   186,   213,
     209,   211,   212,   210,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   214,   215,   216,   226,   227,   228,   184,
     189,   190,   191,   188,   185,   167,   166,   165,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   250,   251,
     254,   255,   257,   258,   259,   260,   261,   263,   264,   265,
     266,   268,   269,   270,   271,   273,   274,   275,   277,   278,
     279,   280,   282,   249,   267,   276,   256,   262,   272,   281,
     283,   284,   285,   286,   287,   288,   252,   253,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   193,   194,   195,   196,   197,   322,     0,   208,   206,
     168,   169,   420,   419,   418,     0,     0,     0,     0,     0,
       0,     0,   192,     0,   491,     3,   490,     0,     0,   122,
     131,     0,   141,   146,   173,   172,     0,   170,   171,   174,
     153,   202,   204,     0,   175,   205,    18,   489,   117,   118,
     495,     0,   492,     0,     0,     0,   189,   190,   191,    21,
      22,   168,   169,   151,   173,   177,   152,   176,     0,     7,
       8,     9,    10,    11,     0,     0,    20,    19,   114,     0,
     493,   119,   131,   131,   137,   138,   139,   131,   123,     0,
     131,   131,   131,     0,   115,    14,    16,   147,     0,   189,
     190,   191,   179,   496,   178,   154,   180,   181,   183,     0,
     203,     0,   182,     0,     0,   424,     0,     0,   425,     0,
       0,   164,   163,   160,     0,   156,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,    24,
      25,    28,    49,     0,     0,     0,    62,    63,    64,    65,
     457,   449,   453,    23,    30,    57,    32,    37,    38,     0,
       0,    43,     0,    66,     0,    70,    73,    76,    81,    84,
      86,    88,    90,    92,    94,    96,    98,   111,     0,   439,
       0,   173,   153,   442,   455,   441,   440,     0,   443,   444,
     445,   446,   447,     0,   124,   132,   133,   129,   130,   140,
     134,   136,   135,   142,     0,   148,   125,   508,   509,   507,
     198,    66,   113,     0,    47,     0,   402,   398,   400,   401,
     399,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     403,   404,   405,   415,   416,   417,     0,     0,    17,   430,
       0,   428,   423,   426,   422,     0,   116,     0,   155,     0,
       0,     0,   504,   485,   484,     0,     0,     0,   488,   486,
       0,     0,     0,    58,    59,     0,   202,   448,     0,    34,
      35,     0,     0,    41,    40,     0,   208,    44,    46,   101,
     102,   104,   103,   106,   107,   108,   109,   110,   105,   100,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   454,   456,   120,   126,     0,   143,
       0,   434,   150,     0,   199,   200,     0,   207,     0,     0,
     432,     0,   427,   421,   158,   159,   161,   157,     0,   494,
     505,     0,   479,   478,   481,     0,   487,     0,   462,     0,
       0,    29,     0,     0,     0,    36,    33,     0,    39,     0,
       0,    53,    45,    99,    67,    68,    69,    71,    72,    74,
      75,    79,    80,    77,    78,    82,    83,    85,    87,    89,
      91,    93,    95,     0,   112,     0,   128,   145,     0,   437,
       0,   149,   201,   501,   431,     0,   429,   506,     0,   480,
       0,     0,     0,     0,     0,     0,    61,   450,    31,    56,
      51,    50,     0,   208,    54,     0,   127,   144,     0,   435,
     502,     0,   433,     0,   482,     0,   461,   459,     0,   464,
       0,   452,   475,   451,    55,    97,   436,   438,   503,   497,
       0,   483,   477,     0,     0,     0,   465,   469,     0,   473,
       0,   463,   476,   460,     0,   468,   471,   470,   472,   466,
     474,   467
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -506,  -506,  -506,  -506,  -506,  -506,     1,   351,  -506,  -136,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,   -16,  -506,  -152,  -143,  -238,  -154,
      79,    69,    83,    77,    68,    88,  -506,  -221,  -283,  -506,
    -273,   164,     3,     8,  -506,  -506,  -506,  -506,   296,   -18,
    -506,  -506,  -506,  -506,  -185,   -11,  -506,  -506,   132,  -506,
    -506,  -131,  -506,  -506,  -128,  -234,   -13,   235,  -506,  -506,
    -506,     9,  -506,   264,  -235,   138,    56,  -431,  -506,   148,
    -264,  -505,  -506,  -506,   -32,   368,   140,   149,  -506,  -506,
      62,  -506,  -506,   -51,  -506,   -43,  -506,  -506,  -506,  -506,
    -506,  -506,   384,  -506,  -506,  -506,  -170,  -506,  -506,  -323,
    -506,  -506
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,     3,   164,     6,   379,    14,   165,   293,
     294,   295,   494,   296,   297,   298,   299,   300,   301,   302,
     498,   499,   500,   501,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   430,
     318,   353,   319,   320,   168,   169,   170,   337,   228,   229,
     230,   338,   171,   172,   173,   204,   264,   476,   265,   266,
     175,   176,   177,   178,   179,   250,   354,   181,   182,   183,
     376,   184,   185,   257,   258,   380,   381,   462,   530,   323,
     324,   325,   326,   408,   572,   573,   327,   328,   329,   567,
     490,   330,   569,   587,   588,   589,   590,   331,   484,   540,
     541,   332,   186,   187,   188,   189,   190,   191,   561,   391,
     392,   192
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,   400,   174,   345,   243,    11,   395,   584,   585,   256,
     584,   585,   405,    16,   203,   206,   166,   223,   417,   205,
     207,   167,   383,     7,     8,     9,   450,   527,   352,   529,
    -498,  -499,   531,  -500,     7,     8,     9,   238,   439,   440,
     571,   249,   231,   242,   244,   223,   246,   247,   248,   249,
     224,   225,   226,   252,   468,     7,     8,     9,   355,   344,
     571,   461,   388,   455,   249,   355,   389,   458,     4,   480,
     205,   207,   256,   242,   256,    10,   463,     1,   224,   225,
     226,   469,   390,   528,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   231,   231,   558,   557,   249,   231,
     355,     5,   231,   231,   231,    12,   409,   410,   452,   459,
     233,   261,   414,    15,   559,   525,   415,   535,   451,   452,
     218,   219,   555,   193,   485,  -498,   234,   577,   487,   488,
     441,   442,   502,   471,   352,   453,   491,   194,   495,   591,
     452,   347,   348,   262,   349,   470,   452,   503,   195,   472,
     383,   243,   180,   452,   174,   471,   141,   142,   143,   144,
     145,   542,   486,   245,   208,   452,   543,   601,   166,   524,
     452,   537,  -499,   167,   237,   461,   429,   461,   523,   232,
     461,   180,   435,   436,   141,   142,   143,   144,   145,   411,
     242,   412,   390,  -500,   254,   260,   227,   152,   153,   154,
     256,   511,   512,   513,   514,   335,   322,   390,   321,   336,
    -323,   488,   340,   341,   342,   263,   339,   489,   554,     7,
       8,     9,  -324,   526,   227,   152,   153,   154,   221,   455,
    -326,   232,   232,   351,   343,  -327,   232,  -330,   551,   232,
     232,   232,   552,   580,   180,   461,   180,   452,   152,   153,
     154,   235,     8,   236,   180,   586,  -331,   322,   599,   321,
     432,   433,   434,    17,    18,   563,   214,   403,   404,   574,
     437,   438,   575,   443,   444,   461,   497,  -333,   566,   474,
     475,   492,   249,   507,   508,  -334,  -121,   461,   431,   515,
     516,   581,  -335,   222,   509,   510,    39,   196,   197,   489,
     198,    43,    44,    45,    46,    47,  -336,  -337,  -339,  -340,
    -341,   594,    17,    18,   322,  -342,   321,  -344,  -345,   593,
    -346,   209,  -347,  -349,   596,   598,   578,  -350,  -351,  -353,
    -354,  -355,  -356,  -358,   456,  -325,   598,  -343,  -352,   351,
     457,  -332,  -338,  -348,  -357,    39,   239,   240,  -359,   241,
      43,    44,    45,    46,    47,  -360,   210,  -361,   211,  -362,
    -363,  -364,  -328,   212,   180,  -329,   213,  -365,  -366,  -367,
    -368,  -369,   180,  -370,  -371,  -372,  -373,  -374,  -375,   180,
    -376,  -377,  -378,   322,  -379,   321,  -380,  -381,  -382,   322,
     263,  -383,  -384,  -385,  -386,   322,  -387,   321,  -388,  -389,
    -390,  -391,  -392,   141,   142,   143,   144,   145,  -393,  -394,
    -395,  -396,   199,   496,   200,  -397,   504,   505,   506,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   215,   249,   251,   253,   333,
     259,   267,   201,   202,   152,   153,   154,   -21,   -22,   346,
     377,   378,   141,   142,   143,   144,   145,   355,   386,   387,
     161,   393,   394,   396,   397,   398,   401,   402,   407,   -48,
     534,   322,   413,   162,   418,   445,   546,   446,   449,   447,
     322,   448,   321,   -47,   464,   481,   218,   467,   -42,   532,
     544,   201,   202,   152,   153,   154,   538,   452,   479,   533,
     545,   548,   550,   549,   560,   564,   565,   568,   570,   161,
     -52,   579,   583,   595,   592,   518,   216,   521,   334,   466,
     406,   477,   162,   385,   517,   520,   556,   536,   478,   322,
     519,   321,   322,   582,   321,   220,   562,   597,   522,   356,
     357,   358,   359,   360,   482,   483,   539,   600,   493,   217,
       0,     0,   322,     0,   321,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     322,     0,   321,     0,     0,   322,   322,   321,   321,     0,
       0,     0,     0,     0,     0,     0,     0,   322,     0,   321,
      17,    18,    19,    20,    21,    22,    23,   268,   269,   270,
       0,   271,   272,   273,   274,   275,     0,     0,    24,    25,
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
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   276,   199,
     149,   200,   277,   278,   279,   280,   281,   282,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,   154,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,   285,     0,     0,     0,     0,     0,   286,   287,   288,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,   292,    17,    18,    19,    20,    21,
      22,    23,   268,   269,   270,     0,   271,   272,   273,   274,
     275,     0,     0,    24,    25,    26,    27,    28,    29,    30,
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
     140,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   276,   199,   149,   200,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,   285,     0,     0,     0,
       0,     0,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   291,   454,
      17,    18,    19,    20,    21,    22,    23,   268,   269,   270,
       0,   271,   272,   273,   274,   275,     0,     0,    24,    25,
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
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   276,   199,
     149,   200,   277,   278,   279,   280,   281,   282,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,   154,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,   285,     0,     0,     0,     0,     0,   286,   287,   288,
     289,    17,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,   290,   291,   547,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   196,   197,     0,   198,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   202,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,   196,   197,   255,   198,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   196,   197,   382,   198,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   202,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   196,
     197,   384,   198,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
     268,   269,   270,     0,   271,   272,   273,   274,   275,   584,
     585,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   473,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   276,   199,   149,   200,   277,   278,   279,   280,   281,
     282,     0,     0,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,   285,     0,     0,     0,     0,     0,
     286,   287,   288,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   291,    17,    18,    19,
      20,    21,    22,    23,   268,   269,   270,     0,   271,   272,
     273,   274,   275,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   276,   199,   149,   200,   277,
     278,   279,   280,   281,   282,     0,     0,   283,   284,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,   285,     0,
       0,     0,     0,     0,   286,   287,   288,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     291,    17,    18,    19,    20,    21,    22,    23,   268,   269,
     270,     0,   271,   272,   273,   274,   275,     0,     0,    24,
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
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   276,
     199,   149,   200,   277,   278,   279,   280,   281,   282,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,   285,     0,     0,     0,     0,     0,   286,   287,
     288,   289,    17,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,   290,   219,     0,     0,     0,     0,     0,
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
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   199,   149,   200,   277,   278,   279,   280,   281,   282,
       0,     0,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,   153,   154,     0,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,   285,     0,     0,     0,     0,     0,   286,
     287,   288,   289,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,    24,
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
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
     199,   149,   200,   277,   278,   279,   280,   281,   282,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,     0,     0,     0,     0,     0,   286,   287,
     288,   289,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,   460,   576,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,     0,   199,
     149,   200,   277,   278,   279,   280,   281,   282,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,     0,     0,     0,     0,     0,   286,   287,   288,
     289,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,   460,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,   199,   149,
     200,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,     0,     0,     0,     0,     0,   286,   287,   288,   289,
      17,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   196,   197,     0,   198,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   199,
     149,   200,   277,   278,   279,   280,   281,   282,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     202,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    23,
       0,   285,     0,     0,     0,     0,     0,   286,   287,   288,
     289,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,     0,   199,   149,   200,   277,   278,   279,   280,   281,
     282,     0,     0,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   285,     0,     0,   350,     0,     0,
     286,   287,   288,   289,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
     199,   149,   200,   277,   278,   279,   280,   281,   282,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   285,     0,     0,   465,     0,     0,   286,   287,
     288,   289,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,   199,   149,
     200,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     285,     0,     0,     0,     0,     0,   286,   287,   288,   289,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   416,     0,   199,   149,   200,   277,
     278,   279,   280,   281,   282,     0,     0,   283,   284,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   285,     0,
       0,     0,     0,     0,   286,   287,   288,   289,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   553,     0,   199,   149,   200,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,     0,   285,     0,     0,     0,
       0,     0,   286,   287,   288,   289,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,   154,     0,   155,     0,    12,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   163,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,     0,   155,     0,     0,     0,
       0,     0,     0,   156,   157,   158,   159,   160,   161,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   196,   197,
     163,   198,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      17,    18,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,    39,   196,   197,     0,   198,    43,    44,
      45,    46,    47,   201,   202,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,   161,    42,    43,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     202,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,   201,   202,   152,   153,   154,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,    24,
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
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,   149
};

static const yytype_int16 yycheck[] =
{
      13,   274,    13,   237,   174,     4,   270,    19,    20,   194,
      19,    20,   285,    12,   150,   151,    13,     4,   301,   150,
     151,    13,   257,   152,   153,   154,   170,   458,   249,   460,
     154,   154,   463,   154,   152,   153,   154,   173,   165,   166,
     545,   246,   170,   174,   175,     4,   177,   178,   179,   246,
      37,    38,    39,   184,   377,   152,   153,   154,   246,   264,
     565,   344,   245,   327,   246,   246,   249,   264,   157,   392,
     201,   202,   257,   204,   259,   193,   264,   189,    37,    38,
      39,   263,   267,   264,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   222,   223,   249,   528,   246,   227,
     246,     0,   230,   231,   232,   190,   163,   164,   249,   343,
     249,   208,   245,   193,   267,   263,   249,   263,   262,   249,
     265,   266,   263,   192,   397,   154,   265,   558,   401,   402,
     257,   258,   415,   249,   355,   265,   245,   266,   411,   570,
     249,   265,   265,   240,   265,   379,   249,   430,   147,   265,
     385,   321,   165,   249,   165,   249,   143,   144,   145,   146,
     147,   245,   265,   176,   155,   249,   245,   263,   165,   452,
     249,   265,   154,   165,   173,   458,   264,   460,   451,   170,
     463,   194,   250,   251,   143,   144,   145,   146,   147,   246,
     321,   248,   377,   154,   193,   208,   183,   184,   185,   186,
     385,   439,   440,   441,   442,   223,   219,   392,   219,   227,
     257,   484,   230,   231,   232,   214,   229,   402,   501,   152,
     153,   154,   257,   457,   183,   184,   185,   186,   245,   493,
     257,   222,   223,   249,   233,   257,   227,   257,   245,   230,
     231,   232,   249,   245,   257,   528,   259,   249,   184,   185,
     186,   152,   153,   154,   267,   267,   257,   270,   267,   270,
     254,   255,   256,     3,     4,   538,   244,   283,   284,   552,
     161,   162,   555,   167,   168,   558,   412,   257,   542,   157,
     158,   245,   246,   435,   436,   257,   245,   570,   304,   443,
     444,   564,   257,   249,   437,   438,    36,    37,    38,   484,
      40,    41,    42,    43,    44,    45,   257,   257,   257,   257,
     257,   584,     3,     4,   327,   257,   327,   257,   257,   583,
     257,   193,   257,   257,   588,   589,   560,   257,   257,   257,
     257,   257,   257,   257,   333,   257,   600,   257,   257,   355,
     339,   257,   257,   257,   257,    36,    37,    38,   257,    40,
      41,    42,    43,    44,    45,   257,   193,   257,   193,   257,
     257,   257,   257,   193,   377,   257,   193,   257,   257,   257,
     257,   257,   385,   257,   257,   257,   257,   257,   257,   392,
     257,   257,   257,   396,   257,   396,   257,   257,   257,   402,
     389,   257,   257,   257,   257,   408,   257,   408,   257,   257,
     257,   257,   257,   143,   144,   145,   146,   147,   257,   257,
     257,   257,   152,   412,   154,   257,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   154,   246,   257,   154,   263,
     266,   266,   182,   183,   184,   185,   186,   244,   244,   244,
     266,   193,   143,   144,   145,   146,   147,   246,   265,   264,
     200,   265,   265,   244,   244,   265,   244,   244,   267,   244,
     469,   484,   245,   213,   244,   259,   492,   260,   171,   261,
     493,   169,   493,   244,   247,   151,   265,   258,   245,   247,
     489,   182,   183,   184,   185,   186,   244,   249,   267,   267,
     245,   247,   245,   244,   154,   265,   245,   266,   264,   200,
     245,   265,    13,   263,   265,   446,   165,   449,   222,   355,
     285,   389,   213,   259,   445,   448,   525,   471,   390,   542,
     447,   542,   545,   565,   545,   167,   535,   588,   450,     5,
       6,     7,     8,     9,   396,   396,   484,   590,   408,   165,
      -1,    -1,   565,    -1,   565,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     583,    -1,   583,    -1,    -1,   588,   589,   588,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,    -1,   600,
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
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,   185,   186,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,   266,   267,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
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
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,   185,   186,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,   244,    -1,    -1,    -1,
      -1,    -1,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   266,   267,
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
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,   185,   186,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,   265,   266,   267,    -1,    -1,    -1,    -1,    21,
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
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   267,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,   267,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   267,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   267,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,   185,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,   266,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,   185,
     186,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,   244,    -1,
      -1,    -1,    -1,    -1,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
     266,     3,     4,     5,     6,     7,     8,     9,    10,    11,
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
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,   185,   186,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,
     252,   253,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,   265,   266,    -1,    -1,    -1,    -1,    -1,
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
     131,   132,   133,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,   185,   186,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,   250,
     251,   252,   253,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    21,
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
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,
     252,   253,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   267,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,   253,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
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
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   244,    -1,    -1,   247,    -1,    -1,
     250,   251,   252,   253,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   244,    -1,    -1,   247,    -1,    -1,   250,   251,
     252,   253,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,   253,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   244,    -1,
      -1,    -1,    -1,    -1,   250,   251,   252,   253,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,   244,    -1,    -1,    -1,
      -1,    -1,   250,   251,   252,   253,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
     185,   186,    -1,   188,    -1,   190,    -1,    -1,    -1,    -1,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   242,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,   185,   186,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     242,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       3,     4,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,   200,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,   185,   186,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    21,
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
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
      -1,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   189,   269,   271,   157,     0,   273,   152,   153,   154,
     193,   274,   190,   270,   275,   193,   274,     3,     4,     5,
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
     138,   143,   144,   145,   146,   147,   148,   149,   150,   153,
     182,   183,   184,   185,   186,   188,   195,   196,   197,   198,
     199,   200,   213,   242,   272,   276,   310,   311,   312,   313,
     314,   320,   321,   322,   323,   328,   329,   330,   331,   332,
     334,   335,   336,   337,   339,   340,   370,   371,   372,   373,
     374,   375,   379,   192,   266,   274,    37,    38,    40,   152,
     154,   182,   183,   277,   323,   329,   277,   329,   339,   193,
     193,   193,   193,   193,   244,   154,   275,   370,   265,   266,
     353,   245,   249,     4,    37,    38,    39,   183,   316,   317,
     318,   332,   339,   249,   265,   152,   154,   274,   277,    37,
      38,    40,   329,   374,   329,   334,   329,   329,   329,   246,
     333,   257,   329,   154,   274,   267,   322,   341,   342,   266,
     334,   208,   240,   274,   324,   326,   327,   266,    10,    11,
      12,    14,    15,    16,    17,    18,   151,   155,   156,   157,
     158,   159,   160,   163,   164,   244,   250,   251,   252,   253,
     265,   266,   267,   277,   278,   279,   281,   282,   283,   284,
     285,   286,   287,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   308,   310,
     311,   323,   334,   347,   348,   349,   350,   354,   355,   356,
     359,   365,   369,   263,   316,   317,   317,   315,   319,   334,
     317,   317,   317,   274,   264,   333,   244,   265,   265,   265,
     247,   292,   305,   309,   334,   246,     5,     6,     7,     8,
       9,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   338,   266,   193,   274,
     343,   344,   267,   342,   267,   341,   265,   264,   245,   249,
     322,   377,   378,   265,   265,   348,   244,   244,   265,   265,
     308,   244,   244,   292,   292,   308,   335,   267,   351,   163,
     164,   246,   248,   245,   245,   249,   150,   306,   244,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   264,
     307,   292,   254,   255,   256,   250,   251,   161,   162,   165,
     166,   257,   258,   167,   168,   259,   260,   261,   169,   171,
     170,   262,   249,   265,   267,   348,   274,   274,   264,   333,
     266,   306,   345,   264,   247,   247,   309,   258,   377,   263,
     333,   249,   265,   267,   157,   158,   325,   326,   343,   267,
     377,   151,   347,   355,   366,   308,   265,   308,   308,   322,
     358,   245,   245,   354,   280,   308,   274,   277,   288,   289,
     290,   291,   306,   306,   292,   292,   292,   294,   294,   295,
     295,   296,   296,   296,   296,   297,   297,   298,   299,   300,
     301,   302,   303,   308,   306,   263,   333,   345,   264,   345,
     346,   345,   247,   267,   274,   263,   344,   265,   244,   358,
     367,   368,   245,   245,   274,   245,   292,   267,   247,   244,
     245,   245,   249,   150,   306,   263,   274,   345,   249,   267,
     154,   376,   274,   308,   265,   245,   348,   357,   266,   360,
     264,   349,   352,   353,   306,   306,   267,   345,   333,   265,
     245,   308,   352,    13,    19,    20,   267,   361,   362,   363,
     364,   345,   265,   348,   308,   263,   348,   361,   348,   267,
     363,   263
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   268,   270,   269,   271,   271,   271,   272,   272,   272,
     272,   272,   273,   273,   274,   274,   274,   275,   276,   276,
     276,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     279,   279,   279,   279,   279,   279,   280,   281,   282,   282,
     283,   283,   284,   284,   285,   285,   286,   287,   287,   287,
     288,   288,   289,   289,   290,   290,   291,   292,   292,   292,
     292,   292,   293,   293,   293,   293,   294,   294,   294,   294,
     295,   295,   295,   296,   296,   296,   297,   297,   297,   297,
     297,   298,   298,   298,   299,   299,   300,   300,   301,   301,
     302,   302,   303,   303,   304,   304,   305,   305,   306,   306,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   308,   308,   309,   310,   310,   310,   310,   310,   311,
     311,   312,   312,   313,   313,   314,   315,   315,   315,   316,
     316,   317,   317,   317,   317,   317,   317,   318,   318,   318,
     319,   320,   320,   320,   320,   320,   321,   321,   321,   321,
     321,   321,   321,   322,   322,   323,   324,   324,   325,   325,
     326,   326,   326,   327,   327,   328,   328,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   330,   330,   331,   331,   331,   331,
     331,   331,   331,   332,   332,   332,   332,   332,   333,   333,
     333,   333,   334,   334,   335,   335,   335,   335,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   339,
     339,   340,   340,   340,   340,   341,   341,   342,   343,   343,
     344,   344,   344,   344,   345,   345,   345,   346,   346,   347,
     348,   348,   349,   349,   349,   349,   349,   349,   350,   351,
     350,   352,   352,   353,   353,   354,   354,   355,   355,   356,
     357,   357,   358,   358,   359,   360,   360,   361,   361,   362,
     362,   363,   363,   364,   364,   365,   365,   365,   366,   366,
     367,   367,   368,   368,   369,   369,   369,   369,   369,   370,
     370,   370,   370,   371,   372,   373,   373,   374,   375,   375,
     375,   376,   376,   376,   377,   377,   378,   379,   379,   379
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     4,     1,     2,     1,     1,     1,     4,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     4,     3,     1,     2,     3,     1,     3,
       1,     3,     2,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     1,     1,     2,     3,     1,     2,     1,     2,     5,
       3,     1,     1,     4,     5,     2,     3,     3,     2,     1,
       2,     2,     2,     1,     2,     5,     7,     6,     1,     1,
       1,     0,     2,     3,     2,     2,     2,     3,     2,     1,
       1,     1,     1,     2,     5,     1,     2,     7,     1,     1,
       1,     0,     1,     2,     1,     2,     3,     3,     3,     3
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
#line 87 "hlsl_parser.yy" /* yacc.c:1429  */
{
   yylloc.first_line = 1;
   yylloc.first_column = 1;
   yylloc.last_line = 1;
   yylloc.last_column = 1;
   yylloc.source = 0;
   yylloc.filename = state->current_filename;
}

#line 3240 "hlsl_parser.cpp" /* yacc.c:1429  */
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
#line 318 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      _mesa_glsl_initialize_types(state);
   }
#line 3431 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 322 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      delete state->symbols;
      state->symbols = new(ralloc_parent(state)) glsl_symbol_table;
      _mesa_glsl_initialize_types(state);
   }
#line 3441 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 332 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->process_version_directive(&(yylsp[-1]), (yyvsp[-1].n), NULL);
      if (state->error) {
         YYERROR;
      }
   }
#line 3452 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 339 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->process_version_directive(&(yylsp[-2]), (yyvsp[-2].n), (yyvsp[-1].identifier));
      if (state->error) {
         YYERROR;
      }
   }
#line 3463 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 353 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 3489 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 389 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!_mesa_glsl_process_extension((yyvsp[-3].identifier), & (yylsp[-3]), (yyvsp[-1].identifier), & (yylsp[-1]), state)) {
         YYERROR;
      }
   }
#line 3499 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 398 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* FINISHME: The NULL test is required because pragmas are set to
       * FINISHME: NULL. (See production rule for external_declaration.)
       */
      if ((yyvsp[0].node) != NULL)
         state->translation_unit.push_tail(& (yyvsp[0].node)->link);
   }
#line 3511 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 406 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* FINISHME: The NULL test is required because pragmas are set to
       * FINISHME: NULL. (See production rule for external_declaration.)
       */
      if ((yyvsp[0].node) != NULL)
         state->translation_unit.push_tail(& (yyvsp[0].node)->link);
   }
#line 3523 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 413 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!state->allow_extension_directive_midshader) {
         _mesa_glsl_error(& (yylsp[0]), state,
                          "#extension directive is not allowed "
                          "in the middle of a shader");
         YYERROR;
      }
   }
#line 3536 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 430 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_identifier, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.identifier = (yyvsp[0].identifier);
   }
#line 3547 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 437 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_int_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.int_constant = (yyvsp[0].n);
   }
#line 3558 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 444 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_uint_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.uint_constant = (yyvsp[0].n);
   }
#line 3569 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 451 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_float_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.float_constant = (yyvsp[0].real);
   }
#line 3580 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 458 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_double_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.double_constant = (yyvsp[0].dreal);
   }
#line 3591 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 465 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_bool_constant, NULL, NULL, NULL);
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->primary_expression.bool_constant = (yyvsp[0].n);
   }
#line 3602 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 472 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
   }
#line 3610 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 480 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_array_index, (yyvsp[-3].expression), (yyvsp[-1].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-3]), (yylsp[0]));
   }
#line 3620 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 486 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[0].expression);
   }
#line 3628 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 490 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_field_selection, (yyvsp[-2].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
      (yyval.expression)->primary_expression.identifier = (yyvsp[0].identifier);
   }
#line 3639 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 497 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_post_inc, (yyvsp[-1].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3649 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 503 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_post_dec, (yyvsp[-1].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3659 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 521 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_field_selection, (yyvsp[-2].expression), (yyvsp[0].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3669 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 540 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_location((yylsp[-1]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3679 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 546 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
      (yyval.expression)->set_location((yylsp[-2]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3689 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 562 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_function_expression((yyvsp[0].type_specifier));
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3699 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 568 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[0].identifier));
      callee->set_location((yylsp[0]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3711 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 576 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[0].identifier));
      callee->set_location((yylsp[0]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[0]));
      }
#line 3723 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 597 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_location((yylsp[-1]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3733 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 603 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
      (yyval.expression)->set_location((yylsp[-2]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 3743 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 615 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_expression *callee = new(ctx) ast_expression((yyvsp[-1].identifier));
      callee->set_location((yylsp[-1]));
      (yyval.expression) = new(ctx) ast_function_expression(callee);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3755 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 628 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_pre_inc, (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3765 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 634 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_pre_dec, (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location((yylsp[-1]));
   }
#line 3775 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 640 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression((yyvsp[-1].n), (yyvsp[0].expression), NULL, NULL);
      (yyval.expression)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 3785 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 646 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      //$$ = new (ctx) ast_hlsl_prefix_cast($2, $4);
      (yyval.expression) = new (ctx) ast_function_expression((yyvsp[-2].type_specifier));
      (yyval.expression)->expressions.push_tail(&(yyvsp[0].expression)->link);
      (yyval.expression)->set_location_range((yylsp[-3]), (yylsp[-2]));
   }
#line 3797 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 657 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_plus; }
#line 3803 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 658 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_neg; }
#line 3809 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 659 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_logic_not; }
#line 3815 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 660 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_bit_not; }
#line 3821 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 666 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_mul, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3831 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 672 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_div, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3841 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 678 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_mod, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3851 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 688 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_add, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3861 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 694 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_sub, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3871 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 704 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_lshift, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3881 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 710 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_rshift, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3891 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 720 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_less, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3901 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 726 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_greater, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3911 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 732 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_lequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3921 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 738 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_gequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3931 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 748 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_equal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3941 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 754 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_nequal, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3951 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 764 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_and, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3961 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 774 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_xor, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3971 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 784 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_bit_or, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3981 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 794 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_and, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 3991 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 804 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_xor, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4001 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 814 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression_bin(ast_logic_or, (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4011 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 824 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression(ast_conditional, (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.expression)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 4021 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 834 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_expression((yyvsp[-1].n), (yyvsp[-2].expression), (yyvsp[0].expression), NULL);
      (yyval.expression)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 4031 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 842 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_assign; }
#line 4037 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 843 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_mul_assign; }
#line 4043 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 844 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_div_assign; }
#line 4049 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 845 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_mod_assign; }
#line 4055 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 846 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_add_assign; }
#line 4061 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 847 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_sub_assign; }
#line 4067 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 848 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_ls_assign; }
#line 4073 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 849 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_rs_assign; }
#line 4079 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 850 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_and_assign; }
#line 4085 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 851 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_xor_assign; }
#line 4091 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 852 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = ast_or_assign; }
#line 4097 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 857 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[0].expression);
   }
#line 4105 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 861 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4122 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 881 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->symbols->pop_scope();
      (yyval.node) = (yyvsp[-1].function);
   }
#line 4131 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 886 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-1].declarator_list);
   }
#line 4139 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 890 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyvsp[-1].type_specifier)->default_precision = (yyvsp[-2].n);
      (yyval.node) = (yyvsp[-1].type_specifier);
   }
#line 4148 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 895 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
   }
#line 4156 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 899 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
   }
#line 4164 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 906 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.function)->return_semantic = (yyvsp[0].identifier); }
#line 4170 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 916 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.function) = (yyvsp[-1].function);
      (yyval.function)->parameters.push_tail(& (yyvsp[0].parameter_declarator)->link);
   }
#line 4179 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 921 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.function) = (yyvsp[-2].function);
      (yyval.function)->parameters.push_tail(& (yyvsp[0].parameter_declarator)->link);
   }
#line 4188 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 929 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.function) = new(ctx) ast_function();
      (yyval.function)->set_location((yylsp[-1]));
      (yyval.function)->return_type = (yyvsp[-2].fully_specified_type);
      (yyval.function)->identifier = (yyvsp[-1].identifier);

      state->symbols->add_function(new(state) ir_function((yyvsp[-1].identifier)));
      state->symbols->push_scope();
   }
#line 4203 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 943 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location((yylsp[-1]));
      (yyval.parameter_declarator)->type->specifier = (yyvsp[-1].type_specifier);
      (yyval.parameter_declarator)->identifier = (yyvsp[0].identifier);
   }
#line 4217 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 953 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4232 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 964 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4247 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 978 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.parameter_declarator) = (yyvsp[0].parameter_declarator);
      (yyval.parameter_declarator)->type->qualifier = (yyvsp[-1].type_qualifier);
   }
#line 4256 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 983 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.parameter_declarator) = new(ctx) ast_parameter_declarator();
      (yyval.parameter_declarator)->set_location((yylsp[0]));
      (yyval.parameter_declarator)->type = new(ctx) ast_fully_specified_type();
      (yyval.parameter_declarator)->type->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.parameter_declarator)->type->qualifier = (yyvsp[-1].type_qualifier);
      (yyval.parameter_declarator)->type->specifier = (yyvsp[0].type_specifier);
   }
#line 4270 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 996 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
   }
#line 4278 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1000 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.constant)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate const qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.constant = 1;
   }
#line 4290 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1008 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.precise)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precise qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 4302 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1016 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (((yyvsp[-1].type_qualifier).flags.q.in || (yyvsp[-1].type_qualifier).flags.q.out) && ((yyvsp[0].type_qualifier).flags.q.in || (yyvsp[0].type_qualifier).flags.q.out))
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate in/out/inout qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.q.constant)
         _mesa_glsl_error(&(yylsp[-1]), state, "in/out/inout must come after const "
                                      "or precise");

      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 4318 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1028 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).precision != ast_precision_none)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precision qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.i != 0)
         _mesa_glsl_error(&(yylsp[-1]), state, "precision qualifiers must come last");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).precision = (yyvsp[-1].n);
   }
#line 4333 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1039 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 4342 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1046 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 4351 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1051 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 4360 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1056 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 4370 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1070 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = (yyvsp[-2].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[0].identifier), ir_var_auto));
   }
#line 4384 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1080 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      decl->set_location_range((yylsp[-1]), (yylsp[0]));

      (yyval.declarator_list) = (yyvsp[-3].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-1].identifier), ir_var_auto));
   }
#line 4398 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1090 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), (yyvsp[0].expression));
      decl->set_location_range((yylsp[-3]), (yylsp[-2]));

      (yyval.declarator_list) = (yyvsp[-5].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-3].identifier), ir_var_auto));
   }
#line 4412 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1100 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      decl->set_location((yylsp[-2]));

      (yyval.declarator_list) = (yyvsp[-4].declarator_list);
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
      state->symbols->add_variable(new(state) ir_variable(NULL, (yyvsp[-2].identifier), ir_var_auto));
   }
#line 4426 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1114 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      /* Empty declaration list is valid. */
      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[0].fully_specified_type));
      (yyval.declarator_list)->set_location((yylsp[0]));
   }
#line 4437 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1121 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-1].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4451 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1131 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      decl->set_location_range((yylsp[-1]), (yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-2].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-2]), (yylsp[0]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4465 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1141 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), (yyvsp[0].expression));
      decl->set_location_range((yylsp[-3]), (yylsp[-2]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-4].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-4]), (yylsp[-2]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4479 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1151 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      decl->set_location((yylsp[-2]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list((yyvsp[-3].fully_specified_type));
      (yyval.declarator_list)->set_location_range((yylsp[-3]), (yylsp[-2]));
      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4493 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1161 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list(NULL);
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->invariant = true;

      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4509 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1173 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      decl->set_location((yylsp[0]));

      (yyval.declarator_list) = new(ctx) ast_declarator_list(NULL);
      (yyval.declarator_list)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.declarator_list)->precise = true;

      (yyval.declarator_list)->declarations.push_tail(&decl->link);
   }
#line 4525 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1188 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.fully_specified_type) = new(ctx) ast_fully_specified_type();
      (yyval.fully_specified_type)->set_location((yylsp[0]));
      (yyval.fully_specified_type)->specifier = (yyvsp[0].type_specifier);
   }
#line 4536 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1195 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.fully_specified_type) = new(ctx) ast_fully_specified_type();
      (yyval.fully_specified_type)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.fully_specified_type)->qualifier = (yyvsp[-1].type_qualifier);
      (yyval.fully_specified_type)->specifier = (yyvsp[0].type_specifier);
   }
#line 4548 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1206 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
   }
#line 4556 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1214 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-2].type_qualifier);
      if (!(yyval.type_qualifier).merge_qualifier(& (yylsp[0]), state, (yyvsp[0].type_qualifier))) {
         YYERROR;
      }
   }
#line 4567 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1223 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4573 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1224 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4579 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1229 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4783 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1429 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4926 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1568 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 4944 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1594 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.row_major = 1;
   }
#line 4953 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1599 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.packed = 1;
   }
#line 4962 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1607 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.smooth = 1;
   }
#line 4971 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1612 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.flat = 1;
   }
#line 4980 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1617 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.noperspective = 1;
   }
#line 4989 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1626 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.invariant = 1;
   }
#line 4998 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1631 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 5007 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1641 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(&(yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).precision = (yyvsp[0].n);
   }
#line 5016 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1659 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).flags.q.precise)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate \"precise\" qualifier");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).flags.q.precise = 1;
   }
#line 5028 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1667 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5055 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1690 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5083 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1714 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5104 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1731 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5124 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1747 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5148 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1767 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].type_qualifier).precision != ast_precision_none)
         _mesa_glsl_error(&(yylsp[-1]), state, "duplicate precision qualifier");

      if (!state->ARB_shading_language_420pack_enable && (yyvsp[0].type_qualifier).flags.i != 0)
         _mesa_glsl_error(&(yylsp[-1]), state, "precision qualifiers must come last");

      (yyval.type_qualifier) = (yyvsp[0].type_qualifier);
      (yyval.type_qualifier).precision = (yyvsp[-1].n);
   }
#line 5163 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1778 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_qualifier) = (yyvsp[-1].type_qualifier);
      (yyval.type_qualifier).merge_qualifier(&(yylsp[-1]), state, (yyvsp[0].type_qualifier));
   }
#line 5172 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1786 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.centroid = 1;
   }
#line 5181 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1791 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.sample = 1;
   }
#line 5190 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1799 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.constant = 1;
   }
#line 5199 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1804 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.attribute = 1;
   }
#line 5208 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1809 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.varying = 1;
   }
#line 5217 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1814 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 5226 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1819 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5249 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1838 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.uniform = 1;
   }
#line 5258 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1843 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.static_ = 1;
   }
#line 5267 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1851 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.coherent = 1;
   }
#line 5276 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1856 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q._volatile = 1;
   }
#line 5285 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1861 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      STATIC_ASSERT(sizeof((yyval.type_qualifier).flags.q) <= sizeof((yyval.type_qualifier).flags.i));
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.restrict_flag = 1;
   }
#line 5295 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1867 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.read_only = 1;
   }
#line 5304 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1872 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.write_only = 1;
   }
#line 5313 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1880 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.array_specifier) = new(ctx) ast_array_specifier((yylsp[-1]));
      (yyval.array_specifier)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 5323 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1886 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.array_specifier) = new(ctx) ast_array_specifier((yylsp[-2]), (yyvsp[-1].expression));
      (yyval.array_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 5333 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1892 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 5351 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1906 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.array_specifier) = (yyvsp[-3].array_specifier);

      if (!state->ARB_arrays_of_arrays_enable) {
         _mesa_glsl_error(& (yylsp[-3]), state,
                          "GL_ARB_arrays_of_arrays "
                          "required for defining arrays of arrays");
      }

      (yyval.array_specifier)->add_dimension((yyvsp[-1].expression));
   }
#line 5367 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1922 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.type_specifier) = (yyvsp[-1].type_specifier);
      (yyval.type_specifier)->array_specifier = (yyvsp[0].array_specifier);
   }
#line 5376 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1930 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].identifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5386 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1936 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].struct_specifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5396 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1942 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.type_specifier) = new(ctx) ast_type_specifier((yyvsp[0].identifier));
      (yyval.type_specifier)->set_location((yylsp[0]));
   }
#line 5406 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1948 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       void *ctx = state;
       (yyval.type_specifier) = new(ctx)ast_type_specifier((yyvsp[-3].identifier));
       (yyval.type_specifier)->template_data_type_name = (yyvsp[-1].identifier);
       (yyval.type_specifier)->set_location((yylsp[-3]));
   }
#line 5417 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1957 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "void"; }
#line 5423 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1958 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "float"; }
#line 5429 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1959 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "double"; }
#line 5435 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1960 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "int"; }
#line 5441 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1961 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uint"; }
#line 5447 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1962 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bool"; }
#line 5453 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1963 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec2"; }
#line 5459 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1964 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec3"; }
#line 5465 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1965 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec4"; }
#line 5471 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1966 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec2"; }
#line 5477 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1967 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec3"; }
#line 5483 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1968 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec4"; }
#line 5489 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1969 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec2"; }
#line 5495 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1970 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec3"; }
#line 5501 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1971 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec4"; }
#line 5507 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1972 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec2"; }
#line 5513 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1973 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec3"; }
#line 5519 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1974 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec4"; }
#line 5525 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1975 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec2"; }
#line 5531 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1976 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec3"; }
#line 5537 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1977 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec4"; }
#line 5543 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1978 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2"; }
#line 5549 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1979 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2x3"; }
#line 5555 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1980 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat2x4"; }
#line 5561 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1981 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3x2"; }
#line 5567 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1982 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3"; }
#line 5573 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1983 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat3x4"; }
#line 5579 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1984 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4x2"; }
#line 5585 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1985 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4x3"; }
#line 5591 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1986 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "mat4"; }
#line 5597 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1987 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2"; }
#line 5603 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1988 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2x3"; }
#line 5609 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1989 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat2x4"; }
#line 5615 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1990 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3x2"; }
#line 5621 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1991 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3"; }
#line 5627 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1992 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat3x4"; }
#line 5633 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1993 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4x2"; }
#line 5639 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1994 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4x3"; }
#line 5645 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1995 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dmat4"; }
#line 5651 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1996 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1D"; }
#line 5657 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1997 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2D"; }
#line 5663 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1998 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRect"; }
#line 5669 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1999 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler3D"; }
#line 5675 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 2000 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCube"; }
#line 5681 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 2001 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerExternalOES"; }
#line 5687 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 2002 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerState"; }
#line 5693 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 2003 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DShadow"; }
#line 5699 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 2004 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DShadow"; }
#line 5705 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 2005 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRectShadow"; }
#line 5711 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 2006 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeShadow"; }
#line 5717 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 2007 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArray"; }
#line 5723 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 2008 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArray"; }
#line 5729 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 2009 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArrayShadow"; }
#line 5735 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 2010 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArrayShadow"; }
#line 5741 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 2011 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerBuffer"; }
#line 5747 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 2012 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArray"; }
#line 5753 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 2013 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArrayShadow"; }
#line 5759 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 2014 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1D"; }
#line 5765 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 2015 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2D"; }
#line 5771 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 2016 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DRect"; }
#line 5777 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 2017 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler3D"; }
#line 5783 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 2018 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCube"; }
#line 5789 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 2019 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1DArray"; }
#line 5795 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 2020 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DArray"; }
#line 5801 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 2021 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerBuffer"; }
#line 5807 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 2022 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCubeArray"; }
#line 5813 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 2023 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1D"; }
#line 5819 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 2024 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2D"; }
#line 5825 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 2025 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DRect"; }
#line 5831 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 2026 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler3D"; }
#line 5837 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 2027 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCube"; }
#line 5843 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 2028 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1DArray"; }
#line 5849 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 2029 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DArray"; }
#line 5855 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 2030 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerBuffer"; }
#line 5861 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 2031 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCubeArray"; }
#line 5867 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 2032 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMS"; }
#line 5873 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 2033 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMS"; }
#line 5879 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 2034 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMS"; }
#line 5885 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 2035 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMSArray"; }
#line 5891 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 2036 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMSArray"; }
#line 5897 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 2037 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMSArray"; }
#line 5903 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 2038 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1D"; }
#line 5909 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 2039 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2D"; }
#line 5915 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 2040 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image3D"; }
#line 5921 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 2041 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DRect"; }
#line 5927 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 2042 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCube"; }
#line 5933 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 2043 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageBuffer"; }
#line 5939 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 2044 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1DArray"; }
#line 5945 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 2045 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DArray"; }
#line 5951 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 2046 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCubeArray"; }
#line 5957 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 2047 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMS"; }
#line 5963 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 2048 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMSArray"; }
#line 5969 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2049 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1D"; }
#line 5975 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2050 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2D"; }
#line 5981 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2051 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage3D"; }
#line 5987 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2052 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DRect"; }
#line 5993 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2053 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCube"; }
#line 5999 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2054 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageBuffer"; }
#line 6005 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2055 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1DArray"; }
#line 6011 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 2056 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DArray"; }
#line 6017 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2057 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCubeArray"; }
#line 6023 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2058 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMS"; }
#line 6029 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2059 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMSArray"; }
#line 6035 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2060 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1D"; }
#line 6041 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2061 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2D"; }
#line 6047 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 2062 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage3D"; }
#line 6053 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2063 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DRect"; }
#line 6059 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2064 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCube"; }
#line 6065 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2065 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageBuffer"; }
#line 6071 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2066 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1DArray"; }
#line 6077 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2067 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DArray"; }
#line 6083 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2068 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCubeArray"; }
#line 6089 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2069 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMS"; }
#line 6095 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2070 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMSArray"; }
#line 6101 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2071 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "atomic_uint"; }
#line 6107 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2075 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1D"; }
#line 6113 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2076 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2D"; }
#line 6119 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2077 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRect"; }
#line 6125 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2078 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler3D"; }
#line 6131 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2079 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCube"; }
#line 6137 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2080 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerExternalOES"; }
#line 6143 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2081 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "SamplerState"; }
#line 6149 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2082 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DShadow"; }
#line 6155 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2083 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DShadow"; }
#line 6161 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2084 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DRectShadow"; }
#line 6167 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2085 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeShadow"; }
#line 6173 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2086 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArray"; }
#line 6179 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2087 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArray"; }
#line 6185 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2088 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler1DArrayShadow"; }
#line 6191 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2089 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DArrayShadow"; }
#line 6197 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 2090 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerBuffer"; }
#line 6203 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2091 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArray"; }
#line 6209 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2092 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "samplerCubeArrayShadow"; }
#line 6215 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 2093 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1D"; }
#line 6221 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 2094 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2D"; }
#line 6227 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2095 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DRect"; }
#line 6233 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2096 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler3D"; }
#line 6239 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2097 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCube"; }
#line 6245 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2098 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler1DArray"; }
#line 6251 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2099 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DArray"; }
#line 6257 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2100 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerBuffer"; }
#line 6263 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2101 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isamplerCubeArray"; }
#line 6269 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2102 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1D"; }
#line 6275 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2103 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2D"; }
#line 6281 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2104 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DRect"; }
#line 6287 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2105 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler3D"; }
#line 6293 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2106 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCube"; }
#line 6299 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2107 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler1DArray"; }
#line 6305 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 2108 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DArray"; }
#line 6311 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2109 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerBuffer"; }
#line 6317 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2110 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usamplerCubeArray"; }
#line 6323 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2111 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMS"; }
#line 6329 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2112 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMS"; }
#line 6335 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2113 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMS"; }
#line 6341 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2114 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "sampler2DMSArray"; }
#line 6347 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2115 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "isampler2DMSArray"; }
#line 6353 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2116 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "usampler2DMSArray"; }
#line 6359 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2117 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1D"; }
#line 6365 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2118 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2D"; }
#line 6371 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2119 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image3D"; }
#line 6377 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2120 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DRect"; }
#line 6383 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2121 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCube"; }
#line 6389 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2122 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageBuffer"; }
#line 6395 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2123 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image1DArray"; }
#line 6401 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2124 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DArray"; }
#line 6407 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2125 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "imageCubeArray"; }
#line 6413 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2126 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMS"; }
#line 6419 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2127 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "image2DMSArray"; }
#line 6425 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2128 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1D"; }
#line 6431 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2129 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2D"; }
#line 6437 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2130 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage3D"; }
#line 6443 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2131 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DRect"; }
#line 6449 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2132 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCube"; }
#line 6455 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2133 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageBuffer"; }
#line 6461 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2134 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage1DArray"; }
#line 6467 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2135 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DArray"; }
#line 6473 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2136 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimageCubeArray"; }
#line 6479 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2137 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMS"; }
#line 6485 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2138 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "iimage2DMSArray"; }
#line 6491 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2139 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1D"; }
#line 6497 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2140 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2D"; }
#line 6503 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2141 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage3D"; }
#line 6509 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2142 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DRect"; }
#line 6515 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2143 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCube"; }
#line 6521 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2144 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageBuffer"; }
#line 6527 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2145 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage1DArray"; }
#line 6533 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2146 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DArray"; }
#line 6539 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2147 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimageCubeArray"; }
#line 6545 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2148 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMS"; }
#line 6551 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2149 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uimage2DMSArray"; }
#line 6557 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2153 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "float"; }
#line 6563 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2154 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "double"; }
#line 6569 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2155 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "int"; }
#line 6575 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2156 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uint"; }
#line 6581 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2157 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bool"; }
#line 6587 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2158 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec2"; }
#line 6593 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2159 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec3"; }
#line 6599 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2160 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "vec4"; }
#line 6605 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2161 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec2"; }
#line 6611 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2162 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec3"; }
#line 6617 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2163 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "bvec4"; }
#line 6623 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2164 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec2"; }
#line 6629 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2165 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec3"; }
#line 6635 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2166 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "ivec4"; }
#line 6641 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2167 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec2"; }
#line 6647 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2168 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec3"; }
#line 6653 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2169 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "uvec4"; }
#line 6659 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2170 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec2"; }
#line 6665 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2171 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec3"; }
#line 6671 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2172 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.identifier) = "dvec4"; }
#line 6677 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2177 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_high;
   }
#line 6686 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2182 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_medium;
   }
#line 6695 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2187 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->check_precision_qualifiers_allowed(&(yylsp[0]));
      (yyval.n) = ast_precision_low;
   }
#line 6704 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2195 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier((yyvsp[-3].identifier), (yyvsp[-1].declarator_list));
      (yyval.struct_specifier)->set_location_range((yylsp[-3]), (yylsp[0]));
      state->symbols->add_type((yyvsp[-3].identifier), glsl_type::void_type);
   }
#line 6715 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2202 "hlsl_parser.yy" /* yacc.c:1646  */
    {
       /* HLSL: Empty struct declarations are permitted */
       void *ctx = state;
       (yyval.struct_specifier) = new(ctx) ast_struct_specifier((yyvsp[-2].identifier), NULL);
       (yyval.struct_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
       state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6727 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2210 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier(state->anonymous_struct_counter++, (yyvsp[-1].declarator_list));
      (yyval.struct_specifier)->set_location_range((yylsp[-2]), (yylsp[0]));
      state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6738 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2217 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      /* HLSL: Empty struct declarations are permitted */
      void *ctx = state;
      (yyval.struct_specifier) = new(ctx) ast_struct_specifier(state->anonymous_struct_counter++, NULL);
      (yyval.struct_specifier)->set_location_range((yylsp[-1]), (yylsp[0]));
      state->symbols->add_type((yyval.struct_specifier)->name, glsl_type::void_type);
   }
#line 6750 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2228 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[0].declarator_list);
      (yyvsp[0].declarator_list)->link.self_link();
   }
#line 6759 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2233 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[-1].declarator_list);
      (yyval.declarator_list)->link.insert_before(& (yyvsp[0].declarator_list)->link);
   }
#line 6768 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2241 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 6788 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2260 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declaration) = (yyvsp[0].declaration);
      (yyvsp[0].declaration)->link.self_link();
   }
#line 6797 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2265 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declaration) = (yyvsp[-2].declaration);
      (yyval.declaration)->link.insert_before(& (yyvsp[0].declaration)->link);
   }
#line 6806 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2273 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[0].identifier), NULL, NULL);
      (yyval.declaration)->set_location((yylsp[0]));
   }
#line 6816 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2279 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, NULL);
      (yyval.declaration)->set_location((yylsp[-2]));
      (yyval.declaration)->semantic = (yyvsp[0].identifier);
   }
#line 6827 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2286 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-1].identifier), (yyvsp[0].array_specifier), NULL);
      (yyval.declaration)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 6837 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2292 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.declaration) = new(ctx) ast_declaration((yyvsp[-3].identifier), (yyvsp[-2].array_specifier), NULL);
      (yyval.declaration)->set_location_range((yylsp[-3]), (yylsp[-2]));
      (yyval.declaration)->semantic = (yyvsp[0].identifier);
   }
#line 6848 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2303 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-1].expression);
   }
#line 6856 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2307 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.expression) = (yyvsp[-2].expression);
   }
#line 6864 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2314 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.expression) = new(ctx) ast_aggregate_initializer();
      (yyval.expression)->set_location((yylsp[0]));
      (yyval.expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 6875 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2321 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyvsp[-2].expression)->expressions.push_tail(& (yyvsp[0].expression)->link);
   }
#line 6883 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2333 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (ast_node *) (yyvsp[0].compound_statement); }
#line 6889 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2348 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(true, NULL);
      (yyval.compound_statement)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 6899 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 2354 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      state->symbols->push_scope();
   }
#line 6907 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2358 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(true, (yyvsp[-1].node));
      (yyval.compound_statement)->set_location_range((yylsp[-3]), (yylsp[0]));
      state->symbols->pop_scope();
   }
#line 6918 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2367 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (ast_node *) (yyvsp[0].compound_statement); }
#line 6924 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2373 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(false, NULL);
      (yyval.compound_statement)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 6934 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 2379 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.compound_statement) = new(ctx) ast_compound_statement(false, (yyvsp[-1].node));
      (yyval.compound_statement)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 6944 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2388 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == NULL) {
         _mesa_glsl_error(& (yylsp[0]), state, "<nil> statement");
         assert((yyvsp[0].node) != NULL);
      }

      (yyval.node) = (yyvsp[0].node);
      (yyval.node)->link.self_link();
   }
#line 6958 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2398 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == NULL) {
         _mesa_glsl_error(& (yylsp[0]), state, "<nil> statement");
         assert((yyvsp[0].node) != NULL);
      }
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->link.insert_before(& (yyvsp[0].node)->link);
   }
#line 6971 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2410 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_expression_statement(NULL);
      (yyval.node)->set_location((yylsp[0]));
   }
#line 6981 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2416 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_expression_statement((yyvsp[-1].expression));
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 6991 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2425 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = new(state) ast_selection_statement((yyvsp[-2].expression), (yyvsp[0].selection_rest_statement).then_statement,
                                              (yyvsp[0].selection_rest_statement).else_statement);
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 7001 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2434 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.selection_rest_statement).then_statement = (yyvsp[-2].node);
      (yyval.selection_rest_statement).else_statement = (yyvsp[0].node);
   }
#line 7010 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2439 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.selection_rest_statement).then_statement = (yyvsp[0].node);
      (yyval.selection_rest_statement).else_statement = NULL;
   }
#line 7019 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2447 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (ast_node *) (yyvsp[0].expression);
   }
#line 7027 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2451 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      ast_declaration *decl = new(ctx) ast_declaration((yyvsp[-2].identifier), NULL, (yyvsp[0].expression));
      ast_declarator_list *declarator = new(ctx) ast_declarator_list((yyvsp[-3].fully_specified_type));
      decl->set_location_range((yylsp[-2]), (yylsp[0]));
      declarator->set_location((yylsp[-3]));

      declarator->declarations.push_tail(&decl->link);
      (yyval.node) = declarator;
   }
#line 7042 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2469 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = new(state) ast_switch_statement((yyvsp[-2].expression), (yyvsp[0].switch_body));
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[0]));
   }
#line 7051 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2477 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.switch_body) = new(state) ast_switch_body(NULL);
      (yyval.switch_body)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7060 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2482 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.switch_body) = new(state) ast_switch_body((yyvsp[-1].case_statement_list));
      (yyval.switch_body)->set_location_range((yylsp[-2]), (yylsp[0]));
   }
#line 7069 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2490 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label) = new(state) ast_case_label((yyvsp[-1].expression));
      (yyval.case_label)->set_location((yylsp[-1]));
   }
#line 7078 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2495 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label) = new(state) ast_case_label(NULL);
      (yyval.case_label)->set_location((yylsp[0]));
   }
#line 7087 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2503 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_label_list *labels = new(state) ast_case_label_list();

      labels->labels.push_tail(& (yyvsp[0].case_label)->link);
      (yyval.case_label_list) = labels;
      (yyval.case_label_list)->set_location((yylsp[0]));
   }
#line 7099 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2511 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_label_list) = (yyvsp[-1].case_label_list);
      (yyval.case_label_list)->labels.push_tail(& (yyvsp[0].case_label)->link);
   }
#line 7108 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2519 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_statement *stmts = new(state) ast_case_statement((yyvsp[-1].case_label_list));
      stmts->set_location((yylsp[0]));

      stmts->stmts.push_tail(& (yyvsp[0].node)->link);
      (yyval.case_statement) = stmts;
   }
#line 7120 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2527 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_statement) = (yyvsp[-1].case_statement);
      (yyval.case_statement)->stmts.push_tail(& (yyvsp[0].node)->link);
   }
#line 7129 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2535 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      ast_case_statement_list *cases= new(state) ast_case_statement_list();
      cases->set_location((yylsp[0]));

      cases->cases.push_tail(& (yyvsp[0].case_statement)->link);
      (yyval.case_statement_list) = cases;
   }
#line 7141 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2543 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.case_statement_list) = (yyvsp[-1].case_statement_list);
      (yyval.case_statement_list)->cases.push_tail(& (yyvsp[0].case_statement)->link);
   }
#line 7150 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2551 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_while,
                                            NULL, (yyvsp[-2].node), NULL, (yyvsp[0].node));
      (yyval.node)->set_location_range((yylsp[-4]), (yylsp[-1]));
   }
#line 7161 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2558 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_do_while,
                                            NULL, (yyvsp[-2].expression), NULL, (yyvsp[-5].node));
      (yyval.node)->set_location_range((yylsp[-6]), (yylsp[-1]));
   }
#line 7172 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2565 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_iteration_statement(ast_iteration_statement::ast_for,
                                            (yyvsp[-3].node), (yyvsp[-2].for_rest_statement).cond, (yyvsp[-2].for_rest_statement).rest, (yyvsp[0].node));
      (yyval.node)->set_location_range((yylsp[-5]), (yylsp[0]));
   }
#line 7183 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2581 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
   }
#line 7191 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2588 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.for_rest_statement).cond = (yyvsp[-1].node);
      (yyval.for_rest_statement).rest = NULL;
   }
#line 7200 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2593 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.for_rest_statement).cond = (yyvsp[-2].node);
      (yyval.for_rest_statement).rest = (yyvsp[0].expression);
   }
#line 7209 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2602 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_continue, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7219 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2608 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_break, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7229 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2614 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_return, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7239 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2620 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_return, (yyvsp[-1].expression));
      (yyval.node)->set_location_range((yylsp[-2]), (yylsp[-1]));
   }
#line 7249 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2626 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.node) = new(ctx) ast_jump_statement(ast_jump_statement::ast_discard, NULL);
      (yyval.node)->set_location((yylsp[-1]));
   }
#line 7259 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2634 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].function_definition); }
#line 7265 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2635 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7271 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2636 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 7277 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2637 "hlsl_parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7283 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2642 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      void *ctx = state;
      (yyval.function_definition) = new(ctx) ast_function_definition();
      (yyval.function_definition)->set_location_range((yylsp[-1]), (yylsp[0]));
      (yyval.function_definition)->prototype = (yyvsp[-1].function);
      (yyval.function_definition)->body = (yyvsp[0].compound_statement);

      state->symbols->pop_scope();
   }
#line 7297 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2655 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 7319 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2690 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].interface_block);
   }
#line 7327 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2694 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 7351 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2717 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 7479 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2844 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.in = 1;
   }
#line 7488 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2849 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.out = 1;
   }
#line 7497 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2854 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      memset(& (yyval.type_qualifier), 0, sizeof((yyval.type_qualifier)));
      (yyval.type_qualifier).flags.q.uniform = 1;
   }
#line 7506 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2862 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          NULL, NULL);
   }
#line 7515 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2867 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          (yyvsp[0].identifier), NULL);
      (yyval.interface_block)->set_location((yylsp[0]));
   }
#line 7525 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 2873 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.interface_block) = new(state) ast_interface_block(*state->default_uniform_qualifier,
                                          (yyvsp[-1].identifier), (yyvsp[0].array_specifier));
      (yyval.interface_block)->set_location_range((yylsp[-1]), (yylsp[0]));
   }
#line 7535 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2882 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[0].declarator_list);
      (yyvsp[0].declarator_list)->link.self_link();
   }
#line 7544 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2887 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.declarator_list) = (yyvsp[-1].declarator_list);
      (yyvsp[0].declarator_list)->link.insert_before(& (yyval.declarator_list)->link);
   }
#line 7553 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2895 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 7578 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2919 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      if (!state->default_uniform_qualifier->merge_qualifier(& (yylsp[-2]), state, (yyvsp[-2].type_qualifier))) {
         YYERROR;
      }
      (yyval.node) = NULL;
   }
#line 7589 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2927 "hlsl_parser.yy" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
      if (!state->in_qualifier->merge_in_qualifier(& (yylsp[-2]), state, (yyvsp[-2].type_qualifier), (yyval.node))) {
         YYERROR;
      }
   }
#line 7600 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2935 "hlsl_parser.yy" /* yacc.c:1646  */
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
#line 7632 "hlsl_parser.cpp" /* yacc.c:1646  */
    break;


#line 7636 "hlsl_parser.cpp" /* yacc.c:1646  */
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
