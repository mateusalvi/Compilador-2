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

                if(!(HasSameDatatype(node->symbol->dataType, node->children[1]->symbol->dataType) ||
                    (isBool(node->symbol->dataType) && isInt(node->children[1]->symbol->dataType)) ||
                    IsCompatibleForOperation(node->symbol->dataType, node->children[1]->symbol->dataType)
                ))
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
                node->symbol->dataType = DATATYPE_BOOL;
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

void CheckChildTypes(AstNode *node)
{
    if(node == NULL)
        return;
    
    switch (node->type)
    {
    case AST_ATTRIB:
        break;
    
    default:
        break;
    }
}

void CheckOperands(AstNode *node)
{
    if (node == NULL)
        return;

    for(int i = 0; i < 4; i++)
        if(node->children[i])
        {
            CheckOperands(node->children[i]);
        }
    
    if(isArithmetic(node->type))
    {
        //fprintf(stderr, "NODE AND TYPE: %d\n", node->type);
        if (!(isArithmetic(node->children[0]->type)))
        {
            if(node->children[0]->symbol->type) 
                if( isBool(node->children[0]->symbol->type) || isLogic(node->type) || isRelational(node->type) )
                    {
                        fprintf(stderr, "Left arithmetic operand is invalid.\n");
                        SemanticErrors++;
                    }
        }
    }
    //     if(node->children[1] != NULL)
    //     {
    //         if (!(isArithmetic(node->children[1]->type)))
    //         {
    //             if(node->children[1]->symbol->type) 
    //                 if( isBool(node->children[1]->symbol->type) || isLogic(node->type) || isRelational(node->type) )
    //                     {
    //                         fprintf(stderr, "Left arithmetic operand is invalid.\n");
    //                         SemanticErrors++;
    //                     }
    //         }
    //     }
    //     if(node->children[0] != NULL && node->children[1] != NULL)
    //     {
    //         if(!(isArithmetic(node->children[0]->type) && isArithmetic(node->children[1]->type)))
    //         {
    //             if(!IsCompatibleForOperation(node->children[0]->symbol->dataType, node->children[1]->symbol->dataType))
    //             {
    //                 fprintf(stderr, "Arithmetic operation incompatible types.\n");
    //                 SemanticErrors++;
    //             }
    //         }
    //     }   
    // if(isArithmetic(node->type))
    // {
    //     if(!((isArithmetic(node->children[0]->type) && isArithmetic(node->children[1]->type)) && 
    //         IsCompatibleForOperation(node->children[0]->symbol->dataType, node->children[1]->symbol->dataType))
    //         )
    //         {
    //             fprintf(stderr, "Arithmetic operation incompatible types.\n");
    //             SemanticErrors++;
    //         }
    // }
    else if(isRelational(node->type))
    {
        if(node->children[0]->symbol->dataType && node->children[1]->symbol->dataType)
        {
            if(!(
                (
                IsCompatibleForOperation(node->children[0]->symbol->dataType, node->children[1]->symbol->dataType) || 
                ((isRelational(node->children[0]->type) || isRelational(node->children[1]->type)))
                )))
                {
                    fprintf(stderr, "Relational operation incompatible types.");
                    SemanticErrors++;
                }
        }
    }
    else if(isLogic(node->type))
    {
            if(node->type == AST_NOT)
            {
                if(!(isBool(node->children[0]->type)))
                {
                    fprintf(stderr, "Logic operation NOT incompatible argument type.");
                    SemanticErrors++;
                }
            }
            else if(node->children[0]->symbol->dataType && node->children[1]->symbol->dataType)
                {
                    if(!(
                    (
                    IsCompatibleForOperation(node->children[0]->symbol->dataType, node->children[1]->symbol->dataType) || 
                    ((isLogic(node->children[0]->type) || isLogic(node->children[1]->type)))
                    )))
                    {
                        fprintf(stderr, "Logic operation incompatible types.");
                        SemanticErrors++;
                    }
                }
    }

    // switch(node->type)
    // {
    //     case AST_SUM:
    //         if(!(IsCompatibleForOperation(node->children[0]->type, node->children[1]->type) && 
    //             ((isArithmetic(node->children[0]->type) || isArithmetic(node->children[1]->type)))))
    //             {
    //                 fprintf(stderr, )
    //             }
    //         break;
    //     case AST_SUB:
    //         break;
    //     case AST_DIV:
    //         break;
    //     case AST_MULT:
    //         break;
    //     case AST_GREATER:
    //         break;
    //     case AST_LESS:
    //         break;
    //     case AST_AND:
    //         break;
    //     case AST_OR:
    //         break;
    //     case AST_NOT:
    //         break;
    //     case AST_DIF:
    //         break;
    //     case AST_EQ:
    //         break;
    //     case AST_GE:
    //         break;
    //     case AST_LE:
    //         break;                           
    //     default:
    //         //fprintf(stderr, "Unknown datatype read in SetChildDataType function.\n");
    //         break;
    // }
}

void CheckUsage(AstNode *node)
{
    if(node == NULL)
        return;
    

    switch (node->type)
    {
    case AST_SYMBOL:
        if(( node->symbol->dataType == DECLARATION_VAR && node->children[0] != NULL ))
            fprintf(stderr, "Variable %s not called as variable", node->symbol->text);
            SemanticErrors++;
        break;
    case AST_FUNCALL:
        
        break;
    default:
        break;
    }
}

bool HasSameDatatype(int type1, int type2)
{
    return (type1 == type2);
}

bool IsCompatibleForOperation(int type1, int type2)
{
    return (((isChar(type1) || isInt(type1)) && (isChar(type2) || isInt(type2))) || HasSameDatatype(type1, type2));
}

bool isInt(int type)
{
    return (type == DATATYPE_INT);
}

bool isChar(int type)
{
    return (type == DATATYPE_CHAR);
}

bool isBool(int type)
{
    return (type == DATATYPE_BOOL);
}

bool isReal(int type)
{
    return (type == DATATYPE_REAL);
}

bool isArithmetic(int type)
{
    return (type == AST_ADD || type == AST_SUB || type == AST_DIV || type == AST_MULT);
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
        //(NOT)Se os elementos têm o mesmo tipo da declaração ou são compativeis (int, char)
		if(!(HasSameDatatype(node->children[0]->symbol->dataType, dataType) || IsCompatibleForOperation(node->children[0]->symbol->dataType, dataType)))
			return false;
		if(node->children[1] != NULL)
            return CheckVectorElements(node->children[1], dataType);
	}
	return true;
}