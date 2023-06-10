%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/

#include "hash.h"

int yyerror(char *s);

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

%start program

%%

program: declaration program

declaration: type TK_IDENTIFIER '=' literal ';'
           | type TK_IDENTIFIER '(' parameters ')' { block }
           | vectorDeclaration ';'
           |

type: KW_INT
    | KW_REAL
    | KW_CHAR
    | KW_BOOL

vectorDeclaration: KW_INT TK_IDENTIFIER '[' LIT_INT ']' vectorAttibuition
                 | KW_REAL TK_IDENTIFIER '[' LIT_INT ']' vectorAttibuition
                 | KW_CHAR TK_IDENTIFIER '[' LIT_INT ']' vectorAttibuition

vectorAttibuition: literal vectorAttibuition
                 |

literal: LIT_INT
       | LIT_REAL
       | LIT_CHAR
       | LIT_STRING

block: '{' '}'
     | '{' commandList '}'

parameters: type TK_IDENTIFIER ',' parameters
          | type TK_IDENTIFIER
          |

command: atribuition
       | flow
       | KW_RETURN expression
       | KW_OUTPUT expression
       | KW_OUTPUT LIT_STRING
       | ';'
       | block
       | TK_IDENTIFIER OPERATOR_EQ expression
       | TK_IDENTIFIER '[' expression ']' OPERATOR_EQ expression

commandList: command ';' commandList
           | command ';'
           |

expressionList: expression ',' expressionList
              | expression

flow: KW_IF '(' expression ')' command
    | KW_IF '(' expression ')' command KW_ELSE
    | KW_IF '(' expression ')' KW_LOOP command

expression: literal '+' literal

%%

int yyerror(char *error)
{
     fprintf("Syntax error at line %d", getlinenumber());
     exit(3); //Syntax error.
}