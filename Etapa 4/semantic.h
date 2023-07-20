#ifndef _SEMANTIC_
#define _SEMANTIC_

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/

#include "hashtable.h"
#include "ast.h"
#include <stdbool.h>
#include <string.h>

void CheckAndSetDeclarations(AstNode *node);
void SetChildDataType(AstNode *node);
void CheckOperands(AstNode *node);
void CheckUndeclared();
bool HasSameDatatype(int type1, int type2);
bool CheckVectorElements(AstNode *node, int dataType);
bool isInt(int type);
bool isReal(int type);
bool isChar(int type);

#endif