#include <stdio.h>
#include <stdlib.h> 

//lex.yy.h
int yylex();
extern char *yytext;
extern FILE *yyin;


extern int isRunning(void);
extern void initMe(void);
extern int getLineNumber(void);
extern int yyparse(void);
extern int yydebug;

int main(int argc, char** argv)
{
  //FILE *gold = 0;
  int token = 0;
  //int answar = 0;
  //int nota = 0;
  //int i=1;
  yydebug = 1;

  // fprintf(stderr,"Rodando main do prof. \n");

  if (argc < 2 || argc > 2)
  {
    printf("call: ./etapa1 input.txt\n");
    exit(1);
  }

  if (0==(yyin = fopen(argv[1],"r")))
  {
    printf("Cannot open file %s... \n",argv[1]);
    exit(1);
  }

  initMe();

  yyparse();

  // if (0==(gold = fopen(argv[2],"r")))
  // {
  //   printf("Cannot open file %s... \n",argv[2]);
  //   exit(1);
  // }

  // while (isRunning())
  // {
  //   token = yylex();

  //   if (!isRunning())
  //     break;

  //   //fscanf(gold,"%d",&answar);
  //   //fprintf (stderr, "%d", token);


  //   // if (token == answar)
  //   // {
  //   //   fprintf(stderr,"%d=ok(%s)  ",i,yytext  );
  //   //   ++nota;
  //   // }
  //   // else
  //   //   fprintf(stderr,"\n%d=ERROR(%s,%d,%d) ",i,yytext,token,answar );

  //   // ++i;

  // }

  //printf("NOTA %d\n\n",nota);  
  printf("number of lines %d\n\n", getLineNumber());  
  //fprintf(stderr,"NOTA %d\n\n",nota);  

  return 0;
}