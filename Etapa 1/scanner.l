%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/

    //#include "hash.h"
    #include "tokens.h"

    int LineNumber = 1;
    int Running = 1;

%}

%x COMMENT
 
%%

"char"    { return KW_CHAR; }
"int"     { return KW_INT; }
"real"    { return KW_REAL; }
"bool"    { return KW_BOOL; }
"if"      { return KW_IF; }
"then"    { return KW_THEN; }
"else"    { return KW_ELSE; }
"loop"    { return KW_LOOP ; }
"input"   { return KW_INPUT; }
"output"  { return KW_OUTPUT; }
"return"  { return KW_RETURN; }

[+-]?(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+".")|([0-9]+"."+[0-9]+([eE][+-]?[0-9]+)?)) { return LIT_REAL; }
[-+]?[0-9]+	          { return LIT_INT; }

\"(\\.|[^"])*\"       { return LIT_STRING; }


"<="                  { return OPERATOR_LE; }
">="                  { return OPERATOR_GE; }
"=="                  { return OPERATOR_EQ; }
"!="                  { return OPERATOR_DIF; }

[-,;()\]\[=+/%<>&|~]  { return yytext[0]; }

[a-zA-Z_.]+           { return TK_IDENTIFIER; }

\n                    { LineNumber++; }
[ \t\s]+              { }

.                     { return TOKEN_ERROR; }


"\\\\\\"   { fprintf(stderr, "COMENT"); BEGIN(COMMENT); }
<COMMENT>"\/\/\/"     { BEGIN(INITIAL); }
<COMMENT>\n        { LineNumber++; }
<COMMENT>.         { }

"\\\\".*              { }
%%

//#include "main.c"

int isRunning(void)
{
	return Running;
}

void main(void)
{
    int tokken;
    yyin = fopen("input.txt", "r");
    int tokkensIgnored = 0;

    while(isRunning())
    {
        tokken = yylex(); 
        
        /*
        if(tokken == IGNORED)
        {
            ++tokkensIgnored;
            continue;
        }
        else
        */

        if(tokken == TOKEN_ERROR)
            printf("\n\nERROR: tokke NOT deffined - %s\n\n", yytext);
        else
            printf("Found TOK %d - %s\n", tokken, yytext);
    } 

    
    fprintf(stderr, "\n\nNumber of lines: %d\nTokkens ignored: %d\n\n", LineNumber, tokkensIgnored-(LineNumber -1));
}

int yywrap()
{
    Running = 0;
    return 1;
}

void initMe()
{
    //TODO: INITIALIZE HASH TABLE
}

int getLineNumber(void)
{
	return LineNumber;
}