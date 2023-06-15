%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int yyerror(char *s);
int yylex();
extern int getLineNumber(void);
extern int yydebug;

%}

%token KW_INT
%token KW_REAL
%token KW_CHAR
%token KW_BOOL
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_LOOP
%token KW_INPUT
%token KW_OUTPUT
%token KW_RETURN
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF
%token TK_IDENTIFIER
%token LIT_INT
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '&' '|' '~'
%left '+' '-'
%left '*' '/'

%start program

%%

program: declarations
       ;

declarations: declaration declarations 
            | 
            ;

declaration: type TK_IDENTIFIER '=' literal ';'
           | type TK_IDENTIFIER '(' parameters ')' block
           | type TK_IDENTIFIER '[' LIT_INT ']' vectorInicialization ';'
           ;

type: KW_INT
    | KW_REAL
    | KW_CHAR
    | KW_BOOL
    ;

vectorInicialization:
                    | literal vectorInicialization
                    ;

literal: LIT_INT  
       | LIT_REAL
       | LIT_CHAR 
       ;

block: '{' commandList '}'
     ;

parameters:
          | parameter parametersTail
          ;

parametersTail:
              | ',' parameter parametersTail
              ;

parameter: type TK_IDENTIFIER
         ;

command: KW_IF '(' expression ')' command KW_ELSE command
       | KW_IF '(' expression ')' command
       | KW_IF '(' expression ')' KW_LOOP command
       | KW_RETURN expression ';'
       | KW_OUTPUT outputParameters ';'
       | block
       | ';'
       | TK_IDENTIFIER '[' expression ']' '=' expression ';'
       | TK_IDENTIFIER '=' expression ';'
       ;

outputParameters: expression outputParametersTail
                | LIT_STRING outputParametersTail
                ;

outputParametersTail:
                    | ',' outputParameters outputParametersTail
                    ;

commandList:
           | command commandList
           ;

functionCall: TK_IDENTIFIER '(' expressionList ')'
            ;

expressionList: 
              | expression expressionListTail
              ;

expressionListTail: 
                  | ',' expression expressionListTail

expression: expression '+' expression
          | expression '-' expression
          | expression '/' expression
          | expression '*' expression
          | expression '>' expression
          | expression '<' expression
          | expression '&' expression
          | expression '|' expression
          | expression '~' expression
          | expression OPERATOR_DIF expression
          | expression OPERATOR_EQ expression
          | expression OPERATOR_GE expression
          | expression OPERATOR_LE expression
          | '('expression')'
          | functionCall
          | KW_INPUT '(' type ')'
          | literal
          | TK_IDENTIFIER
          ;

%%

int yyerror(char *error)
{
     fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
     exit(3); //Syntax error.
}