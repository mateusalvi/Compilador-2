#ifndef _AST_
#define _AST_
/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

enum AST_TYPES
{
    AST_DECLIST,
    AST_VARDEC,
    AST_VECDEC,
    AST_FUNCDEC,
    AST_TYPE_CHAR,
    AST_TYPE_INT,
    AST_TYPE_BOOL,
    AST_TYPE_REAL,
    AST_SYMBOL,
    AST_VECINIT,
    AST_VECELEMENTS,
    AST_PARAMTAIL,
    AST_PARAMS,
    AST_PARAM,
    AST_BLOCK,
    AST_CMDLISTINIT,
    AST_CMDLIST,
    AST_ATTRIB,
    AST_VECATTRIB,
    AST_OUTPUT,
    AST_OUTPUTLIST,
    AST_OUTPUTTAIL,
    AST_RETURN,
    AST_IF,
    AST_IFLOOP,
    AST_LOOP,
    AST_IFELSE,
    AST_INPUT,
    AST_VEC,
    AST_FUNCALL,
    AST_SUM,
    AST_SUB,
    AST_MULT,
    AST_DIV,
    AST_LESS,
    AST_GREATER,
    AST_EQ,
    AST_GE,
    AST_LE,
    AST_DIF,
    AST_AND,
    AST_OR,
    AST_NOT,
    AST_PAREN,
    AST_EXPLIST,
    AST_BLANKBLOCK,
    AST_EXPLISTTAIL
    //AST_COMMA
};

typedef struct AstNode
{
    int type;
    HashTableNode *symbol;
    struct AstNode *children[4];
} AstNode;

AstNode* CreateNode(int type, HashTableNode* symbol, AstNode* firstChild, AstNode* secondChild, AstNode* thirdChild, AstNode* fourthChild);
void PrintTree(int level, AstNode *node);
void uncompileAST(AstNode *node, FILE *file);

#endif