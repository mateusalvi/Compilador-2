/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int yylex();
extern char *yytext;
extern FILE *yyin;

extern int isRunning(void);
extern void initMe(void);
extern int getLineNumber(void);
extern int yyparse(void);
extern int yydebug;
extern AstNode* GetAST();

int main(int argc, char** argv)
{
  FILE *out = 0;
  int token = 0;
  yydebug = 0;

  if (argc < 3 || argc > 3)
  {
    printf("Call: ./etapa1 input.txt output.txt\n");
    exit(1);
  }

  if (0==(yyin = fopen(argv[1], "r")))
  {
    printf("Cannot open file %s... \n", argv[1]);
    exit(1);
  }

  if(0==(out = fopen(argv[2], "w+"))){
		printf("Cannot open file %s... \n", argv[2]);
		exit(1);
	}

  // while(isRunning())
  // {
  //   token = yylex();      
  //   printf("Token: %d - %s\n", token, yytext);
  // }

  initMe();

  yyparse();

  HashPrint();

  uncompileAST(GetAST(), out);

	fclose(out);

  printf("\nCOMPLETED WITH SUCCESS!\n"); 

  return 0;
}