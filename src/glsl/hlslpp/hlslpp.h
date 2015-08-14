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

#ifndef HLSLPP_H
#define HLSLPP_H

#include <stdint.h>
#include <stdbool.h>

#include "main/mtypes.h"

#include "util/ralloc.h"

#include "program/hash_table.h"

#define yyscan_t void*

/* Some data types used for parser values. */

typedef struct expression_value {
	intmax_t value;
	char *undefined_macro;
} expression_value_t;
   

typedef struct string_node {
	const char *str;
	struct string_node *next;
} string_node_t;

typedef struct string_list {
	string_node_t *head;
	string_node_t *tail;
} string_list_t;

typedef struct token token_t;
typedef struct token_list token_list_t;

typedef union YYSTYPE
{
	intmax_t ival;
	expression_value_t expression_value;
	char *str;
	string_list_t *string_list;
	token_t *token;
	token_list_t *token_list;
} YYSTYPE;

# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1

typedef struct YYLTYPE {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
   unsigned source;
   const char *filename;
} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1

# define YYLLOC_DEFAULT(Current, Rhs, N)			\
do {								\
   if (N)							\
   {								\
      (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;	\
      (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
      (Current).last_line    = YYRHSLOC(Rhs, N).last_line;	\
      (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
   }								\
   else								\
   {								\
      (Current).first_line   = (Current).last_line =		\
	 YYRHSLOC(Rhs, 0).last_line;				\
      (Current).first_column = (Current).last_column =		\
	 YYRHSLOC(Rhs, 0).last_column;				\
   }								\
   (Current).source = 0;					\
   (Current).filename = 0; \
} while (0)

struct token {
	int type;
	YYSTYPE value;
	YYLTYPE location;
};

typedef struct token_node {
	token_t *token;
	struct token_node *next;
} token_node_t;

struct token_list {
	token_node_t *head;
	token_node_t *tail;
	token_node_t *non_space_tail;
};

typedef struct argument_node {
	token_list_t *argument;
	struct argument_node *next;
} argument_node_t;

typedef struct argument_list {
	argument_node_t *head;
	argument_node_t *tail;
} argument_list_t;

typedef struct hlslpp_parser hlslpp_parser_t;

typedef enum {
	TOKEN_CLASS_IDENTIFIER,
	TOKEN_CLASS_IDENTIFIER_FINALIZED,
	TOKEN_CLASS_FUNC_MACRO,
	TOKEN_CLASS_OBJ_MACRO
} token_class_t;

typedef struct {
	int is_function;
	string_list_t *parameters;
	const char *identifier;
	token_list_t *replacements;
} macro_t;

typedef struct expansion_node {
	macro_t *macro;
	token_node_t *replacements;
	struct expansion_node *next;
} expansion_node_t;

typedef enum skip_type {
	SKIP_NO_SKIP,
	SKIP_TO_ELSE,
	SKIP_TO_ENDIF
} skip_type_t;

typedef struct skip_node {
	skip_type_t type;
	bool has_else;
	YYLTYPE loc; /* location of the initial #if/#elif/... */
	struct skip_node *next;
} skip_node_t;

typedef struct active_list {
	const char *identifier;
	token_node_t *marker;
	struct active_list *next;
} active_list_t;

/* --- GLSLCompiler Begin */
typedef bool(*hlslpp_include_callback_open)(void *mem_ctx, const char *filename, bool is_system_include, char **out_buffer, unsigned int *out_buffer_size, void *context);
typedef void(*hlslpp_include_callback_close)(void *mem_ctx, char *buffer, void *context);
/* --- GLSLCompiler End */

struct hlslpp_macro
{
    const char *define;
    const char *value;
};

struct hlslpp_include_stack
{
    struct yy_buffer_state *buffer_state;
    YYLTYPE old_location;
};

#define HLSLPP_MAX_INCLUDE_DEPTH (10)

struct hlslpp_parser {
	yyscan_t scanner;
	struct hash_table *defines;
	active_list_t *active;
	int lexing_directive;
	int space_tokens;
	int last_token_was_newline;
	int last_token_was_space;
	int first_non_space_token_this_line;
	int newline_as_space;
	int in_control_line;
	int paren_count;
	int commented_newlines;
	skip_node_t *skip_stack;
	int skipping;
	token_list_t *lex_from_list;
	token_node_t *lex_from_node;
	char *output;
	char *info_log;
	size_t output_length;
	size_t info_log_length;
	int error;
	bool has_new_line_number;
	int new_line_number;
	bool has_new_source_number;
	int new_source_number;
    bool has_new_source_filename;
    const char *new_source_filename;

    struct hlslpp_include_stack include_stack[HLSLPP_MAX_INCLUDE_DEPTH];
    unsigned int include_stack_size;

    
    hlslpp_include_callback_open include_callback_open;
    hlslpp_include_callback_close include_callback_close;
    void *include_user_data;
    /* --- GLSLCompiler End */
};

#ifdef __cplusplus
    extern "C" {
#endif

token_class_t
hlslpp_parser_classify_token (hlslpp_parser_t *parser,
			     const char *identifier,
			     int *parameter_index);

hlslpp_parser_t *
hlslpp_parser_create(const char *filename, struct hlslpp_macro *macros, unsigned int num_macros, hlslpp_include_callback_open include_callback_open, hlslpp_include_callback_close include_callback_close, void *include_user_data);

int
hlslpp_parser_parse (hlslpp_parser_t *parser);

void
hlslpp_parser_destroy (hlslpp_parser_t *parser);

int
hlslpp_preprocess(void *ralloc_ctx, const char *filename, char **shader, char **info_log,
	   struct hlslpp_macro *macros, unsigned int num_macros,
       hlslpp_include_callback_open include_callback_open, hlslpp_include_callback_close include_callback_close, void *include_user_data);

/* Functions for writing to the info log */

void
hlslpp_error (YYLTYPE *locp, hlslpp_parser_t *parser, const char *fmt, ...);

void
hlslpp_warning (YYLTYPE *locp, hlslpp_parser_t *parser, const char *fmt, ...);

/* Generated by hlslpp-lex.l to hlslpp-lex.c */

int
hlslpp_lex_init_extra (hlslpp_parser_t *parser, yyscan_t* scanner);

void
hlslpp_lex_set_source_string(hlslpp_parser_t *parser, char *shader);

int
hlslpp_lex (YYSTYPE *lvalp, YYLTYPE *llocp, yyscan_t scanner);

int
hlslpp_lex_destroy (yyscan_t scanner);

/* Generated by hlslpp-parse.y to hlslpp-parse.c */

int
yyparse (hlslpp_parser_t *parser);

#ifdef __cplusplus
    }
#endif

#endif
