%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "hashtable.h"
#include "semantic.h"
#include "tacs.h"

int yyerror(char *s);
int yylex();
extern int getLineNumber(void);
extern int yydebug;
extern int SemanticErrors;

AstNode *ASTRoot;

%}

%union{
       AstNode *node;
       HashTableNode *symbol;
}

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
%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INT
%token<symbol> LIT_REAL
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING
%token TOKEN_ERROR

%type<node> program
%type<node> declarations
%type<node> declaration
%type<node> type
%type<node> vectorInicialization
%type<node> literal
%type<node> block
%type<node> parameters
%type<node> parametersTail
%type<node> parameter
%type<node> command
%type<node> outputParameters
%type<node> outputParametersTail
%type<node> commandList
%type<node> functionCall
%type<node> expressionList
%type<node> expressionListTail
%type<node> expression

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '&' '|' '~'
%left '+' '-'
%left '*' '/'

%start program

%%

program: declarations { 
                        ASTRoot = $$;
                        fprintf(stderr, "\n-------------- PRINTING TREE --------------\n"); 
                        PrintTree(0, ASTRoot);
                        fprintf(stderr, "------------ END OF PRINT TREE ------------\n\n\n");
                        fprintf(stderr, "---------- ERRORS (IF APLICABLE) ----------\n");
                        CheckAndSetDeclarations(ASTRoot);
                        CheckUndeclared();
                        //CheckOperands(ASTRoot);
                        //CheckUsage(ASTRoot);
                        fprintf(stderr, "-------------- END OF ERRORS --------------\n\n");
                        TacPrintBackwards(GenerateCode(ASTRoot));
                      }
       ;

declarations: declaration declarations { $$ = CreateNode(AST_DECLIST, 0, $1, $2, 0, 0); }
            | { $$ = 0; }
            ;

declaration: type TK_IDENTIFIER '=' literal ';' { $$ = CreateNode(AST_VARDEC, $2, $1, $4, 0, 0); }
           | type TK_IDENTIFIER '(' parameters ')' block { $$ = CreateNode(AST_FUNCDEC, $2, $1, $4, $6, 0); }
           | type TK_IDENTIFIER '[' expression ']' vectorInicialization ';' { $$ = CreateNode(AST_VECDEC, $2, $1, $4, $6, 0);}
           ;

type: KW_INT  { $$ = CreateNode(AST_TYPE_INT, 0, 0, 0, 0, 0); }
    | KW_REAL { $$ = CreateNode(AST_TYPE_REAL, 0, 0, 0, 0, 0); }
    | KW_CHAR { $$ = CreateNode(AST_TYPE_CHAR, 0, 0, 0, 0, 0); }
    | KW_BOOL { $$ = CreateNode(AST_TYPE_BOOL, 0, 0, 0, 0, 0); }
    ;

vectorInicialization: { $$ = 0; }
                    | literal vectorInicialization { $$ = CreateNode(AST_VECINIT, 0, $1, $2, 0, 0); }
                    ;                  

literal: LIT_INT  { $$ = CreateNode(AST_SYMBOL, $1, 0, 0, 0, 0); }
       | LIT_REAL { $$ = CreateNode(AST_SYMBOL, $1, 0, 0, 0, 0); }
       | LIT_CHAR { $$ = CreateNode(AST_SYMBOL, $1, 0, 0, 0, 0); }
       ;

block: '{' commandList '}' { $$ = CreateNode(AST_BLOCK, 0, $2, 0, 0, 0); }
     ;

parameters: { $$ = 0; }
          | parameter parametersTail { $$ = CreateNode(AST_PARAMS, 0, $1, $2, 0, 0); }
          ;

parametersTail: { $$ = 0; }
              | ',' parameter parametersTail { $$ = CreateNode(AST_PARAMTAIL, 0, $2, $3, 0, 0); }
              ;

parameter: type TK_IDENTIFIER  { $$ = CreateNode(AST_PARAM, $2, $1, 0, 0, 0); }
         ;

command: KW_IF '(' expression ')' command KW_ELSE command { $$ = CreateNode(AST_IFELSE, 0, $3, $5, $7, 0); }
       | KW_IF '(' expression ')' command { $$ = CreateNode(AST_IF, 0, $3, $5, 0, 0); }
       | KW_IF '(' expression ')' KW_LOOP command { $$ = CreateNode(AST_IFLOOP, 0, $3, $6, 0, 0); }
       | KW_RETURN expression ';' { $$ = CreateNode(AST_RETURN, 0, $2, 0, 0, 0); }
       | KW_OUTPUT outputParameters ';' { $$ = CreateNode(AST_OUTPUT, 0, $2, 0, 0, 0); }
       | TK_IDENTIFIER '[' expression ']' '=' expression ';' { $$ = CreateNode(AST_VECATTRIB, $1, $3, $6, 0, 0); }
       | TK_IDENTIFIER '=' expression ';' { $$ = CreateNode(AST_ATTRIB, $1, $3, 0, 0, 0); }
       | block { $$ = $1; } 
       | ';' { $$ = 0; }
       | '{' '}' { $$ = CreateNode(AST_BLANKBLOCK, 0, 0, 0, 0, 0); } //{ $$ = 0; }
       ;

outputParameters: expression outputParametersTail { $$ = CreateNode(AST_OUTPUTLIST, 0, $1, $2, 0, 0); }
                | LIT_STRING outputParametersTail { $$ = CreateNode(AST_OUTPUTLIST, 0, CreateNode(AST_SYMBOL, $1, 0, 0, 0, 0), $2, 0, 0); }
                ;

outputParametersTail: { $$ = 0; }
                    | ',' outputParameters outputParametersTail { $$ = CreateNode(AST_OUTPUTTAIL, 0, $2, $3, 0, 0); }
                    ;

commandList: { $$ = 0; }
           | command commandList { $$ =  CreateNode(AST_CMDLIST, 0, $1, $2, 0, 0); }
           ;

functionCall: TK_IDENTIFIER '(' expressionList ')' { $$ = CreateNode(AST_FUNCALL, $1, $3, 0, 0, 0);}
            ;

expressionList: { $$ = 0; }
              | expression expressionListTail { $$ = CreateNode(AST_EXPLIST, 0, $1, $2, 0, 0); }
              ;

expressionListTail: { $$ = 0; }
                  | ',' expression expressionListTail { $$ = CreateNode(AST_EXPLISTTAIL, 0, $2, $3, 0, 0); }

expression: expression '+' expression { $$ = CreateNode(AST_ADD, 0, $1, $3, 0, 0); }
          | expression '-' expression { $$ = CreateNode(AST_SUB, 0, $1, $3, 0, 0); }
          | expression '/' expression { $$ = CreateNode(AST_DIV, 0, $1, $3, 0, 0); }
          | expression '*' expression { $$ = CreateNode(AST_MULT, 0, $1, $3, 0, 0); }
          | expression '>' expression { $$ = CreateNode(AST_GREATER, 0, $1, $3, 0, 0); }
          | expression '<' expression { $$ = CreateNode(AST_LESS, 0, $1, $3, 0, 0); }
          | expression '&' expression { $$ = CreateNode(AST_AND, 0, $1, $3, 0, 0); }
          | expression '|' expression { $$ = CreateNode(AST_OR, 0, $1, $3, 0, 0); }
          | '~' expression { $$ = CreateNode(AST_NOT, 0, $2, 0, 0, 0); }
          | expression OPERATOR_DIF expression { $$ = CreateNode(AST_DIF, 0, $1, $3, 0, 0); }
          | expression OPERATOR_EQ expression { $$ = CreateNode(AST_EQ, 0, $1, $3, 0, 0); }
          | expression OPERATOR_GE expression { $$ = CreateNode(AST_GE, 0, $1, $3, 0, 0); }
          | expression OPERATOR_LE expression { $$ = CreateNode(AST_LE, 0, $1, $3, 0, 0); }
          | '('expression')' { $$ = CreateNode(AST_PAREN, 0, $2, 0, 0, 0); }
          | functionCall { $$ = $1; }
          | KW_INPUT '(' type ')' { $$ = CreateNode(AST_INPUT, 0, $3, 0, 0, 0); }
          | literal { $$ = $1; }
          | TK_IDENTIFIER '[' expression ']' { $$ = CreateNode(AST_VEC, $1, $3, 0, 0, 0); }
          | TK_IDENTIFIER { $$ = CreateNode(AST_SYMBOL, $1, 0, 0, 0, 0); }
          ;

%%

int yyerror(char *error)
{
       fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
       exit(3); //Syntax error.
}

AstNode* GetAST()
{
       return ASTRoot;
}