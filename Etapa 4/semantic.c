/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/

#include "semantic.h"


int SemanticErrors = 0;

AstNode *TreeRoot;

void CheckAndSetDeclarations(AstNode *node)
{
    if (node == NULL)
        return;

    switch(node->type)
    {
        case AST_VARDEC:
            if(node->symbol)
                if (node->symbol->type != SYMBOL_IDENTIFIER)
                {
                    fprintf(stderr, "Variable %s is being redeclared!\n", node->symbol->text);
                    SemanticErrors++;
                }
                else
                {
                    node->symbol->type = DECLARATION_VAR;
                    SetChildDataType(node);
                }

                if(!HasSameDatatype(node->symbol->dataType, node->children[1]->symbol->dataType))
                {
                    fprintf(stderr, "Variable %s initialized with different data type from declared!\n", node->symbol->text);
			        SemanticErrors++;
                }

            break;

        case AST_FUNCDEC:
            if(node->symbol)
                if (node->symbol->type != SYMBOL_IDENTIFIER)
                {
                    fprintf(stderr, "Function %s is being redeclared!\n", node->symbol->text);
                    SemanticErrors++;
                }
                else
                {
                    node->symbol->type = DECLARATION_FUNC;
                    SetChildDataType(node);
                }

            break;

        case AST_VECDEC:
            if(node->symbol)
                if (node->symbol->type != SYMBOL_IDENTIFIER)
                {
                    fprintf(stderr, "Vector %s is being redeclared!\n", node->symbol->text);
                    SemanticErrors++;
                }
                else
                {
                    node->symbol->type = DECLARATION_VEC;
                    SetChildDataType(node);
                }
                if(!CheckVectorElements(node->children[2], node->symbol->dataType))
                {
                    fprintf(stderr, "Vector %s initialized with various data types!\n", node->symbol->text);
			        SemanticErrors++;
                }
            break;

        case AST_PARAM:
            if(node->symbol)
                if (node->symbol->type != SYMBOL_IDENTIFIER)
                {
                    fprintf(stderr, "Function parameter %s is being redeclared!\n", node->symbol->text);
                    SemanticErrors++;
                }
                else
                {
                    node->symbol->type = DECLARATION_PARAM;
                    SetChildDataType(node);
                }
            break;

        default:
            //fprintf(stderr, "Unkown AST Node Type in CheckAndSetDeclarations.\n");
            break;
    }

    for(int i = 0; i < 4; i++)
        CheckAndSetDeclarations(node->children[i]);
}

void SetChildDataType(AstNode *node)
{
    if(node->children[0])
    {
        switch (node->children[0]->type)
        {
            case AST_TYPE_BOOL:
                node->symbol->dataType = DATATYPE_INT;
                break;

            case AST_TYPE_CHAR:
                node->symbol->dataType = DATATYPE_CHAR;
                break;

            case AST_TYPE_INT:
                node->symbol->dataType = DATATYPE_INT;
                break;

            case AST_TYPE_REAL:
                node->symbol->dataType = DATATYPE_REAL;
                break;
            
            case AST_TYPE_STRING:
                node->symbol->dataType = DATATYPE_STRING;
                break;

            default:
                //fprintf(stderr, "Unknown datatype read in SetChildDataType function.\n");
                break;
        }
    }

    return;
}

void CheckUndeclared()
{
    SemanticErrors += HashCheckDeclaration();
}

void CheckOperands(AstNode *node)
{
    if (node == NULL)
        return;

    switch(node->type)
    {
        case AST_SUM:
            if(!(IsCompatibleForOperation(node->children[0]->type, node->children[1]->type) && 
                ((isArithmetic(node->children[0]->type) || isArithmetic(node->children[1]->type)))))
                {
                    fprintf(stderr, )
                }
            break;
        case AST_SUB:
            break;
        case AST_DIV:
            break;
        case AST_MULT:
            break;
        case AST_GREATER:
            break;
        case AST_LESS:
            break;
        case AST_AND:
            break;
        case AST_OR:
            break;
        case AST_NOT:
            break;
        case AST_DIF:
            break;
        case AST_EQ:
            break;
        case AST_GE:
            break;
        case AST_LE:
            break;
                                                           
        default:
            //fprintf(stderr, "Unknown datatype read in SetChildDataType function.\n");
            break;
    }

    for(int i = 0; i < 4; i++)
        CheckAndSetDeclarations(node->children[i]);
}

bool HasSameDatatype(int type1, int type2)
{
    return (type1 == type2);
}

bool IsCompatibleForOperation(int type1, int type2)
{
    return ((isChar(type1) || isInt(type1)) && (isChar(type2) || isInt(type2)));
}

bool isInt(int type)
{
    return (type == DATATYPE_INT);
}

bool isChar(int type)
{
    return (type == DATATYPE_CHAR);
}

bool isReal(int type)
{
    return (type == DATATYPE_REAL);
}

bool isArithmetic(int type)
{
    return (type == AST_SUM || type == AST_SUB || type == AST_DIV || type == AST_MULT);
}

bool isRelational(int type)
{
    return (type == AST_GE || type == AST_GREATER || type == AST_LESS || type == AST_DIF ||  type == AST_LE || type == AST_EQ);
}

bool isLogic(int type)
{
    return (type == AST_AND || type == AST_OR || type == AST_NOT);
}

bool CheckVectorElements(AstNode *node, int dataType)
{
	if(node != NULL)
    {
		if(!HasSameDatatype(node->children[0]->symbol->dataType, dataType))
        {
			return false;
        }
		if(node->children[1] != NULL)
        {
            return CheckVectorElements(node->children[1], dataType);
        }
	}
	return true;
}