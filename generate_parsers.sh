#!/bin/sh

pushd src/glsl

flex -o hlsl_lexer.cpp hlsl_lexer.ll
bison -o hlsl_parser.cpp -p "_mesa_hlsl_" --defines=hlsl_parser.h hlsl_parser.yy

pushd hlslpp
flex -o hlslpp-lex.c hlslpp-lex.l
bison -o hlslpp-parse.c -p "hlslpp_parser_" --defines=hlslpp-parse.h hlslpp-parse.y
popd

# fix stuff that does not compile in vc++
sed -e 's/^__attribute__((__unused__))//' -i hlsl_parser.cpp hlslpp/hlslpp-parse.c
sed -e '/^#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L$/c\#if (defined(__STDC_VERSION__) || defined(_MSC_VER)) && (__STDC_VERSION >= 199901L || _MSC_VER >= 1800)' -i hlsl_lexer.cpp hlslpp/hlslpp-lex.c

popd
