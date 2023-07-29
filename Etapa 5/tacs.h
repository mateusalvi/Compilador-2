#ifndef _TACSH_
#define _TACSH_

#include "hashtable.h"
#include "ast.h"

enum TACTYPES
{
    TAC_SYMBOL,
    TAC_ADD,
    TAC_SUB,
    TAC_MULT,
    TAC_DIV,
    TAC_GREATER,
    TAC_MINOR,
    TAC_GREATEREQ,
    TAC_MINOREQ,
    TAC_DIFFERENCE,
    TAC_EQUAL,
    TAC_NOT,
    TAC_AND,
    TAC_OR,
    TAC_
};

typedef struct tac_node
{
    int type;
    HashTableNode* res;
    HashTableNode* op1;
    HashTableNode* op2;
    struct tac_node* previous;
    struct tac_node* next;
}tac_node;

tac_node* TacCreate(int type, HashTableNode* res, HashTableNode* op1, HashTableNode* op2);
void TacPrint(tac_node* tac);
void TacPrintBackwards(tac_node* tac);
tac_node* GenerateCode(AstNode* node);
tac_node* TacJoin(tac_node* list1, tac_node* list2);


#endif