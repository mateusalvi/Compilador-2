/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_INT = 258,
    KW_REAL = 259,
    KW_CHAR = 260,
    KW_BOOL = 261,
    KW_IF = 262,
    KW_THEN = 263,
    KW_ELSE = 264,
    KW_LOOP = 265,
    KW_INPUT = 266,
    KW_OUTPUT = 267,
    KW_RETURN = 268,
    OPERATOR_LE = 269,
    OPERATOR_GE = 270,
    OPERATOR_EQ = 271,
    OPERATOR_DIF = 272,
    TK_IDENTIFIER = 273,
    LIT_INT = 274,
    LIT_REAL = 275,
    LIT_CHAR = 276,
    LIT_STRING = 277,
    TOKEN_ERROR = 278
  };
#endif
/* Tokens.  */
#define KW_INT 258
#define KW_REAL 259
#define KW_CHAR 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_LOOP 265
#define KW_INPUT 266
#define KW_OUTPUT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define TK_IDENTIFIER 273
#define LIT_INT 274
#define LIT_REAL 275
#define LIT_CHAR 276
#define LIT_STRING 277
#define TOKEN_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

       AstNode *node;
       HashTableNode *symbol;

#line 108 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
