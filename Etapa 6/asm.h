#ifndef _ASM_
#define _ASM_
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#include "tacs.h"
#include "ast.h"

tac_node* GenerateCode(AstNode* node);

tac_node* tacReverse(tac_node* tac);
void GenerateAsm(tac_node* first);

#endif