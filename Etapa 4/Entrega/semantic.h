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
bool IsCompatibleForOperation(int type1, int type2);
bool isInt(int type);
bool isReal(int type);
bool isChar(int type);
bool isReal(int type);
bool isArithmetic(int type);
bool isRelational(int type);
bool isLogic(int type);
bool isBool(int type);
void CheckUsage(AstNode *node);

#endif