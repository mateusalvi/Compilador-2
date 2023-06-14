%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int yyerror(char *s);
int yylex();
extern int getLineNumber(void);

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
            | { printf("Current terminal: \n"); fprintf(stderr, "Char: %c, Int: %d\n", $$, $$); }
            ;

declaration: type TK_IDENTIFIER '=' literal ';' { printf("Current terminal: \n"); fprintf(stderr, "Char: %c, Int: %d\n", $$, $$); }
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
       | LIT_STRING
       ;

block: '{' commandList '}'
     ;

parameters:
          | parameter parameters 
          ;

parameter: type TK_IDENTIFIER
         ;

command: 
       | flow
       | KW_RETURN expression 
       | KW_OUTPUT LIT_STRING
       | block
       | TK_IDENTIFIER '[' expression ']' '=' expression
       | TK_IDENTIFIER '=' expression 
       ;

commandList: command commandListEnd
           ;

commandListEnd: 
              | ';' command commandListEnd

functionCall: TK_IDENTIFIER '(' expressionList ')'
            ;

expressionList: expression ',' expressionList
              | expression
              ;

flow: KW_IF '(' expression ')' command else
    | KW_IF '(' expression ')' KW_LOOP command
    ;

else: 
    | KW_ELSE command
    ;

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