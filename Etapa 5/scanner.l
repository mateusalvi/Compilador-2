%{
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/

    #include "hashtable.h"
    #include "ast.h"
    #include "y.tab.h"

    int LineNumber = 1;
    int Running = 1;

%}

%x COMMENT

%x ONELINECOMMENT
 
%%

char                  { return KW_CHAR; }
int                   { return KW_INT;  }
real                  { return KW_REAL; }
bool                  { return KW_BOOL; }
if                    { return KW_IF;   }
then                  { return KW_THEN; }
else                  { return KW_ELSE; }
loop                  { return KW_LOOP ; }
input                 { return KW_INPUT; }
output                { return KW_OUTPUT; }
return                { return KW_RETURN; }

[0-9]+"."[0-9]+       { yylval.symbol = HashInsert(SYMBOL_REAL, yytext); return LIT_REAL; }
[0-9]+	              { yylval.symbol = HashInsert(SYMBOL_INT, yytext); return LIT_INT; }
[a-zA-Z_\.]+          { yylval.symbol = HashInsert(SYMBOL_IDENTIFIER, yytext); return TK_IDENTIFIER; }
\"(\\.|[^"])+\"       { yylval.symbol = HashInsert(SYMBOL_STRING, yytext); return LIT_STRING; }
\'(\\.|[^'])+\'       { yylval.symbol = HashInsert(SYMBOL_CHAR, yytext); return LIT_CHAR; }

"<="                  { return OPERATOR_LE; }
">="                  { return OPERATOR_GE; }
"=="                  { return OPERATOR_EQ; }
"!="                  { return OPERATOR_DIF; }

[-,;()\]\[=+/%<>&|~\*}{] { return yytext[0]; }

\n                    { LineNumber++; }
[ \t\s]+              { }

"\\\\\\"              { BEGIN(COMMENT); }
<COMMENT>"///"        { BEGIN(INITIAL); }
<COMMENT>\n           { LineNumber++; }
<COMMENT>.            { }

"\\\\"                { BEGIN(ONELINECOMMENT); }
<ONELINECOMMENT>\n    { LineNumber++; BEGIN(INITIAL); }
<ONELINECOMMENT>.     { }


.                     { return TOKEN_ERROR; }

%%

//#include "main.c"

int isRunning(void)
{
	return Running;
}

// void main(void)
// {
//     int token;
//     yyin = fopen("input.txt", "r");
//     int last = 0;
    
//     while(isRunning())
//     {
//         token = yylex(); 
        
//         printf("Token: %d - %s\n", token, yytext);

//     }

// }

int yywrap()
{
    Running = 0;
    return 1;
}

void initMe()
{
    InitHashTable();
}

int getLineNumber(void)
{
	return LineNumber;
}