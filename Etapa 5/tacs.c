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
    case TAC_LESS:
        fprintf(stderr,"TAC_MINOR");
        break;
    case TAC_GE:
        fprintf(stderr,"TAC_GE");
        break;
    case TAC_LE:
        fprintf(stderr,"TAC_LE");
        break;
    case TAC_DIFFERENCE:
        fprintf(stderr,"TAC_DIFFERENCE");
        break;
    case TAC_EQ:
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
    case TAC_MOVE:
        fprintf(stderr,"TAC_MOVE");
        break;
    case TAC_BEGINFUNC:
        fprintf(stderr,"TAC_BEGINFUNC");
        break;
    case TAC_ENDFUNC:
        fprintf(stderr,"TAC_ENDFUNC");
        break;
    case TAC_VECATTRIB:
        fprintf(stderr,"TAC_VECATTRIB");
        break;
    case TAC_JUMPFALSE:
        fprintf(stderr,"TAC_JUMPFALSE");
        break;
    case TAC_LABEL:
        fprintf(stderr,"TAC_LABEL");
        break;   
    case TAC_IF:
        fprintf(stderr,"TAC_IF");
        break;
    case TAC_IFELSE:
        fprintf(stderr,"TAC_IFELSE");
        break; 
    case TAC_IFLOOP:
        fprintf(stderr,"TAC_IFLOOP");
        break;   
    case TAC_JUMPELSE:
        fprintf(stderr,"TAC_JUMPELSE");
        break;
    case TAC_FUNCALL:
        fprintf(stderr,"TAC_FUNCALL");
        break;
    default:
        fprintf(stderr,"\nUNDEFINED TAC PRINT TYPE %d\n\n", tac->type);
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

tac_node* TacCreateBinaryOperationNode(int type, tac_node* code[]);
tac_node* MakeIfThen(tac_node* code0, tac_node* code1);
tac_node* MakeIfElse(tac_node* code0, tac_node* code1, tac_node* code2);
tac_node* CreateFunction(tac_node* symbol, tac_node* params, tac_node* code);

tac_node* GenerateCode(AstNode* node)
{
    if(!node)
        return 0;

    tac_node* result = 0;
    tac_node* code[4];

    for(int i = 0; i < 4; i++)
    {
        code[i] = GenerateCode(node->children[i]);
    }

    switch (node->type)
    {
    //BINARY OPERATIONS
    case AST_ADD:
        result = TacCreateBinaryOperationNode(TAC_ADD, code);
        //result = TacJoin(TacJoin(code[0], code[1]), TacCreate(TAC_ADD, MakeTemp(), code[0]? code[0]->res : 0, code[1]? code[1]->res : 0));
        break;
    case AST_SUB:
        result = TacCreateBinaryOperationNode(TAC_SUB, code);
        break;
    case AST_MULT:
        result = TacCreateBinaryOperationNode(TAC_MULT, code);
        break;
    case AST_DIV:
        result = TacCreateBinaryOperationNode(TAC_DIV, code);
        break;
    case AST_GREATER:
        result = TacCreateBinaryOperationNode(TAC_GREATER, code);
        break;
    case AST_GE:
        result = TacCreateBinaryOperationNode(TAC_GE, code);
        break;
    case AST_LESS:
        result = TacCreateBinaryOperationNode(TAC_LESS, code);
        break;
    case AST_LE:
        result = TacCreateBinaryOperationNode(TAC_LE, code);
        break;
    case AST_DIF:
        result = TacCreateBinaryOperationNode(TAC_DIF, code);
        break;
    case AST_EQ:
        result = TacCreateBinaryOperationNode(TAC_EQ, code);
        break;
    case AST_OR:
        result = TacCreateBinaryOperationNode(TAC_OR, code);
        break;
    case AST_AND:
        result = TacCreateBinaryOperationNode(TAC_AND, code);
        break;
    //FLOW, VARIABLES, DECLARATIONS AND FUNCTIONS
    case AST_SYMBOL:
        result = TacCreate(TAC_SYMBOL, node->symbol, 0, 0);
        break;
    case AST_ATTRIB:
        result = TacJoin(code[0], TacCreate(TAC_MOVE, node->symbol, code[0]? code[0]->res : 0, 0));
        break;
    case AST_FUNCDEC:
        result = CreateFunction(TacCreate(TAC_SYMBOL, node->symbol, 0, 0), code[1], code[2]);
        break;
    case AST_VECATTRIB:
        result = TacJoin(code[0], TacCreate(TAC_VECATTRIB, node->symbol, code[0]? code[0]->res : 0, code[1]? code[1]->res : 0));
        break;
    case AST_IFELSE:
        result = MakeIfElse(code[0], code[1], code[2]);
        break;
    case AST_IFLOOP:
    case AST_IF:
        result = MakeIfThen(code[0], code[1]);
        break;
    case AST_FUNCALL:
        result = TacJoin(code[0], TacCreate(TAC_FUNCALL, MakeTemp(), node->symbol, 0));
        break;
    //DEFAULT
    default:
        result = TacJoin(TacJoin(TacJoin(code[0], code[1]), code[2]), code[3]);
        break;
    }

    return result;
}

tac_node* CreateFunction(tac_node* symbol, tac_node* params, tac_node* code)
{
	return TacJoin(TacJoin(TacJoin(TacCreate(TAC_BEGINFUNC, symbol->res, 0, 0), params), code), TacCreate(TAC_ENDFUNC, symbol->res, 0, 0));
}

tac_node* TacCreateBinaryOperationNode(int type, tac_node* code[])
{
    return TacJoin(TacJoin(code[0], code[1]), TacCreate(type, MakeTemp(), code[0]? code[0]->res : 0, code[1]? code[1]->res : 0));
}

tac_node* MakeIfElse(tac_node* code0, tac_node* code1, tac_node* code2)
{
    tac_node* jumpTac = 0;
    tac_node* labelTac = 0;
    tac_node* jumpElseTac = 0;
    HashTableNode* newLabel = 0;
    HashTableNode* elseLabel = 0;

    newLabel = MakeLabel();
    elseLabel = MakeLabel();
    jumpTac = TacCreate(TAC_JUMPFALSE, newLabel, code0? code0->res : 0, 0);
    jumpTac->previous = code0;
    labelTac = TacCreate(TAC_LABEL, newLabel, 0, 0);
    labelTac->previous = code1;
    jumpElseTac = TacCreate(TAC_JUMPELSE, elseLabel, code2? code2->res : 0, 0);
    jumpElseTac->previous = code2;
    return TacJoin(jumpTac, TacJoin(labelTac, jumpElseTac));
}

tac_node* MakeIfThen(tac_node* code0, tac_node* code1)
{
    tac_node* jumpTac = 0;
    tac_node* labelTac = 0;
    HashTableNode* newLabel = MakeLabel();

    jumpTac = TacCreate(TAC_JUMPFALSE, newLabel, code0? code0->res : 0, 0);
    jumpTac->previous = code0;
    labelTac = TacCreate(TAC_LABEL, newLabel, 0, 0);
    labelTac->previous = code1;
    return TacJoin(jumpTac, labelTac);
}

tac_node* TacJoin(tac_node* list1, tac_node* list2)
{
    tac_node* tac = list2;

    if(!list1) return list2;
    if(!list2) return list1;

    while(tac->previous)
    {
        tac = tac->previous;
    }
    tac->previous = list1;
    return list2;
}