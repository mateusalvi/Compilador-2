/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#include "tacs.h"

tac_node* TacCreate(int type, HashTableNode* res, HashTableNode* op1, HashTableNode* op2)
{
    tac_node* newTac = 0;
    newTac = (tac_node*) calloc(1,sizeof(tac_node));
    newTac->type = type;
    newTac->res = res;
    newTac->op1 = op1;
    newTac->op2 = op2;
    newTac->previous = 0;
    newTac->next = 0;
    return newTac;
}

void TacPrint(tac_node* tac)
{
    if(!tac)
        return;
    
    fprintf(stderr, "Tac(");

    switch (tac->type)
    {
    case TAC_SYMBOL:
        fprintf(stderr,"TAC_SYMBOL");
        break;
    case TAC_ADD:
        fprintf(stderr,"TAC_ADD");
        break;
    case TAC_SUB:
        fprintf(stderr,"TAC_SUB");
        break;
    case TAC_MULT:
        fprintf(stderr,"TAC_MULT");
        break;
    case TAC_DIV:
        fprintf(stderr,"TAC_DIV");
        break;
    case TAC_GREATER:
        fprintf(stderr,"TAC_GREATER");
        break;
    case TAC_MINOR:
        fprintf(stderr,"TAC_MINOR");
        break;
    case TAC_GREATEREQ:
        fprintf(stderr,"TAC_GREATEREQ");
        break;
    case TAC_MINOREQ:
        fprintf(stderr,"TAC_MINOREQ");
        break;
    case TAC_DIFFERENCE:
        fprintf(stderr,"TAC_DIFFERENCE");
        break;
    case TAC_EQUAL:
        fprintf(stderr,"TAC_EQUAL");
        break;
    case TAC_NOT:
        fprintf(stderr,"TAC_NOT");
        break;
    case TAC_AND:
        fprintf(stderr,"TAC_AND");
        break;
    case TAC_OR:
        fprintf(stderr,"TAC_OR");
        break;
    default:
        fprintf(stderr,"UNDEFINED TAC PRINT TYPE");
        break;
    }

    fprintf(stderr, ", %s", (tac->res)?  tac->res->text : "");
    fprintf(stderr, ", %s", (tac->op1)?  tac->op1->text : "");
    fprintf(stderr, ", %s", (tac->op2)?  tac->op2->text : "");
    fprintf(stderr, ");\n");
}

void TacPrintBackwards(tac_node* tac)
{
    if(!tac)
        return;
    else
    {
        TacPrintBackwards(tac->previous);
        TacPrint(tac);
    }
}

tac_node* GenerateCode(AstNode* node)
{
    if(!node)
        return 0;
    
    tac_node* result = 0;
    tac_node* code[4];

    for(int i = 0; i < 4; i++)
    {
        GenerateCode(node->children[i]);
    }
    
    switch (node->type)
    {
    case AST_SYMBOL:
        result = TacCreate(TAC_SYMBOL, node->symbol, 0, 0);
        break;
    case AST_ADD:
        result = TacJoin(TacJoin(code[0], code[1]), TacCreate(TAC_ADD, 0, code[0]? code[0]->res : 0, code[1]? code[1]->res : 0));
    default:
        result = TacJoin(code[0], TacJoin(code[1], TacJoin(code[2], code[3])));
        break;
    }
        
    return result;
}

tac_node* TacJoin(tac_node* list1, tac_node* list2)
{
    tac_node* point;

    if(!list1) 
        return list2;
    if(!list2)
        return list1;
    
    for(point = list2; point != NULL; point = point->previous);

    point->previous = list1;

    return list2;
}