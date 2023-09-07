/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#include "asm.h"

FILE* out;

tac_node* GenerateCode(AstNode* node)
{

}

tac_node* tacReverse(tac_node* tac)
{
    tac_node* t = tac;
    for(t = tac; t->previous; t = t->previous)
        t->previous->next = t;
    return t;
}

void GenerateAsm(tac_node* first)
{
    //FIXED HEADER
    fprintf(out, ".text\n .data\n");
}