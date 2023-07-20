/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/
#include "ast.h"

AstNode* CreateNode(int type, HashTableNode* symbol, AstNode* firstChild, AstNode* secondChild, AstNode* thirdChild, AstNode* fourthChild)
{
    AstNode *node = calloc(1, sizeof(AstNode));
    node->type = type;
    node->symbol = symbol;
    node->children[0] = firstChild;
    node->children[1] = secondChild;
    node->children[2] = thirdChild;
    node->children[3] = fourthChild;
    return node;
}

void uncompileAST(AstNode *node, FILE *file)
{
    if(node == NULL)
        return;

    switch(node->type)
    {
        case AST_DECLIST :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_VARDEC :
            uncompileAST(node->children[0], file);
            fprintf(file, " %s = ", node->symbol->value);
            uncompileAST(node->children[1], file);
            fprintf(file, ";\n");
            break;

        case AST_VECDEC :
            uncompileAST(node->children[0], file);
            fprintf(file, " %s[", node->symbol->value);
            uncompileAST(node->children[1], file);
            fprintf(file, "]");      
            uncompileAST(node->children[2], file);
            fprintf(file, ";\n");
            break;

        case AST_FUNCDEC :
            uncompileAST(node->children[0], file);
            fprintf(file, " %s(", node->symbol->value);
            uncompileAST(node->children[1], file);
            fprintf(file, ")");      
            uncompileAST(node->children[2], file);
            fprintf(file, "\n");
            break;

        case AST_BLANKBLOCK :
            fprintf(file, "{}");
            break;

        case AST_TYPE_CHAR :
            fprintf(file, "char");
            break;

        case AST_TYPE_INT :
            fprintf(file, "int");
            break;

        case AST_TYPE_BOOL :
            fprintf(file, "bool");
            break;

        case AST_TYPE_REAL :
            fprintf(file, "real");
            break;

        case AST_SYMBOL :
            fprintf(file, " %s ", node->symbol->value);
            break;

        case AST_VECINIT :
            uncompileAST(node->children[0], file);
            //fprintf(file, " ");
            uncompileAST(node->children[1], file);
            break;

        case AST_VECELEMENTS :
            uncompileAST(node->children[0], file);
            fprintf(file, " ");
            uncompileAST(node->children[1], file);
            break;

        case AST_PARAMS :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_PARAMTAIL :
            fprintf(file, ", ");
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_PARAM :
            uncompileAST(node->children[0], file);
            fprintf(file, " ");
            fprintf(file, "%s", node->symbol->value);
            break;

        case AST_BLOCK :
            fprintf(file, "\n{\n");
            uncompileAST(node->children[0], file);
            fprintf(file, "}\n");
            break;

        case AST_CMDLIST :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_CMDLISTINIT :
            fprintf(file, ";\n");
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_ATTRIB :
            fprintf(file, "%s = ", node->symbol->value);
            uncompileAST(node->children[0], file);
            fprintf(file, ";\n");
            break;

        case AST_VECATTRIB :
            fprintf(file, "%s[", node->symbol->value);
            uncompileAST(node->children[0], file);
            fprintf(file, "] = ");
            uncompileAST(node->children[1], file);
            fprintf(file, ";\n");
            break;
        
        case AST_OUTPUT :
            fprintf(file, "output ");
            uncompileAST(node->children[0], file);
            fprintf(file, ";\n");
            uncompileAST(node->children[1], file);
            break;

        case AST_OUTPUTLIST :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_OUTPUTTAIL :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_INPUT :
            fprintf(file, "input(");
            uncompileAST(node->children[0], file);
            fprintf(file, ")");
            break;

        case AST_RETURN :
            fprintf(file, "return ");
            uncompileAST(node->children[0], file);
            fprintf(file, ";\n");
            break;

        case AST_IF :
            fprintf(file, "if(");
            uncompileAST(node->children[0], file);
            fprintf(file, ") \n");
            uncompileAST(node->children[1], file);
            break;

        case AST_IFLOOP :
            fprintf(file, "if(");
            uncompileAST(node->children[0], file);
            fprintf(file, ") loop");
            uncompileAST(node->children[1], file);
            break;

        case AST_IFELSE :
            fprintf(file, "if(");
            uncompileAST(node->children[0], file);
            fprintf(file, ")");
            uncompileAST(node->children[1], file);
            fprintf(file, "else\n");
            uncompileAST(node->children[2], file);
            break;

        case AST_VEC :
            fprintf(file, "%s[", node->symbol->value);
            uncompileAST(node->children[0], file);
            fprintf(file, "]");
            break;

        case AST_FUNCALL :
            fprintf(file, "%s(", node->symbol->value);
            uncompileAST(node->children[0], file);
            fprintf(file, ")");
            break;

        case AST_SUM :
            uncompileAST(node->children[0], file);
            fprintf(file, " + ");
            uncompileAST(node->children[1], file);
            break;

        case AST_SUB :
            uncompileAST(node->children[0], file);
            fprintf(file, " - ");
            uncompileAST(node->children[1], file);
            break;

        case AST_MULT :
            uncompileAST(node->children[0], file);
            fprintf(file, " * ");
            uncompileAST(node->children[1], file);
            break;

        case AST_DIV :
            uncompileAST(node->children[0], file);
            fprintf(file, " / ");
            uncompileAST(node->children[1], file);
            break;

        case AST_LESS :
            uncompileAST(node->children[0], file);
            fprintf(file, " < ");
            uncompileAST(node->children[1], file);
            break;

        case AST_GREATER :
            uncompileAST(node->children[0], file);
            fprintf(file, " > ");
            uncompileAST(node->children[1], file);
            break;

        case AST_EQ :
            uncompileAST(node->children[0], file);
            fprintf(file, " == ");
            uncompileAST(node->children[1], file);
            break;

        case AST_GE :
            uncompileAST(node->children[0], file);
            fprintf(file, " >= ");
            uncompileAST(node->children[1], file);
            break;

        case AST_LE :
            uncompileAST(node->children[0], file);
            fprintf(file, " <= ");
            uncompileAST(node->children[1], file);
            break;

        case AST_DIF :
            uncompileAST(node->children[0], file);
            fprintf(file, " != ");
            uncompileAST(node->children[1], file);
            break;

        case AST_AND :
            uncompileAST(node->children[0], file);
            fprintf(file, " and ");
            uncompileAST(node->children[1], file);
            break;

        case AST_OR :
            uncompileAST(node->children[0], file);
            fprintf(file, " or ");
            uncompileAST(node->children[1], file);
            break;

        case AST_NOT :
            fprintf(file, "not ");
            uncompileAST(node->children[0], file);
            break;

        case AST_PAREN :
            fprintf(file, "(");
            uncompileAST(node->children[0], file);
            fprintf(file, ")");
            break;

        case AST_EXPLIST :
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        case AST_EXPLISTTAIL :
            fprintf(file, ", ");
            uncompileAST(node->children[0], file);
            uncompileAST(node->children[1], file);
            break;

        default:
            fprintf(stderr, "UNCOMPILE ERROR, %d", node->type);
            break;
    }
}

void PrintTree(int level, AstNode *node)
{
    int i;

    if(node == NULL)
        return;
  
    fprintf(stderr, "Level %d ", level);
        for(i = 0; i < level; i++)
        fprintf(stderr, "  ");

    switch(node->type){
        case AST_DECLIST: fprintf(stderr, "AST_DECLIST");  break;
        case AST_VARDEC: fprintf(stderr, "AST_VARDEC");  break;
        case AST_VECDEC: fprintf(stderr, "AST_VECDEC");  break;
        case AST_FUNCDEC: fprintf(stderr, "AST_FUNCDEC");  break;
        case AST_TYPE_CHAR: fprintf(stderr, "AST_TYPE_CHAR");  break;
        case AST_TYPE_INT: fprintf(stderr, "AST_TYPE_INT");  break;
        case AST_TYPE_BOOL: fprintf(stderr, "AST_TYPE_BOOL");  break;
        case AST_TYPE_REAL: fprintf(stderr, "AST_TYPE_REAL");  break;
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL");  break;
        case AST_VECINIT: fprintf(stderr, "AST_VECINIT");  break;
        case AST_VECELEMENTS: fprintf(stderr, "AST_VECELEMENTS");  break;
        case AST_PARAMTAIL: fprintf(stderr, "AST_PARAMTAIL");  break;
        case AST_PARAMS: fprintf(stderr, "AST_PARAMS");  break;
        case AST_PARAM: fprintf(stderr, "AST_PARAM");  break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK");  break;
        case AST_CMDLISTINIT: fprintf(stderr, "AST_CMDLISTINIT");  break;
        case AST_CMDLIST: fprintf(stderr, "AST_CMDLIST");  break;
        case AST_ATTRIB: fprintf(stderr, "AST_ATTRIB");  break;
        case AST_VECATTRIB: fprintf(stderr, "AST_VECATTRIB");  break;
        case AST_OUTPUT: fprintf(stderr, "AST_OUTPUT");  break;
        case AST_OUTPUTLIST: fprintf(stderr, "AST_OUTPUTLIST");  break;
        case AST_OUTPUTTAIL: fprintf(stderr, "AST_OUTPUTTAIL");  break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN");  break;
        case AST_IF: fprintf(stderr, "AST_IF");  break;
        case AST_IFLOOP: fprintf(stderr, "AST_IFLOOP");  break;
        case AST_LOOP: fprintf(stderr, "AST_LOOP");  break;
        case AST_IFELSE: fprintf(stderr, "AST_IFELSE");  break;
        case AST_INPUT: fprintf(stderr, "AST_INPUT");  break;
        case AST_VEC: fprintf(stderr, "AST_VEC");  break;
        case AST_FUNCALL: fprintf(stderr, "AST_FUNCALL");  break;
        case AST_SUM: fprintf(stderr, "AST_SUM");  break;
        case AST_SUB: fprintf(stderr, "AST_SUB");  break;
        case AST_MULT: fprintf(stderr, "AST_MULT");  break;
        case AST_DIV: fprintf(stderr, "AST_DIV");  break;
        case AST_LESS: fprintf(stderr, "AST_LESS");  break;
        case AST_GREATER: fprintf(stderr, "AST_GREATER");  break;
        case AST_EQ: fprintf(stderr, "AST_EQ");  break;
        case AST_GE: fprintf(stderr, "AST_GE");  break;
        case AST_LE: fprintf(stderr, "AST_LE");  break;
        case AST_DIF: fprintf(stderr, "AST_DIF");  break;
        case AST_AND: fprintf(stderr, "AST_AND");  break;
        case AST_OR: fprintf(stderr, "AST_OR");  break;
        case AST_NOT: fprintf(stderr, "AST_NOT");  break;
        case AST_PAREN: fprintf(stderr, "AST_PAREN");  break;
        case AST_EXPLIST: fprintf(stderr, "AST_EXPLIST");  break;
        case AST_EXPLISTTAIL: fprintf(stderr, "AST_EXPLISTTAIL");  break;
        case AST_BLANKBLOCK: fprintf(stderr, "AST_BLANKBLOCK"); break;
        //case AST_COMMA: fprintf(stderr, "AST_COMMA");  break;
        default : fprintf(stderr, "-------AST ERROR with type %d-------- ", node->type);  break;
  }

    if(node->symbol != NULL)
        fprintf(stderr, ", %s\n", node->symbol->value);
    else
        fprintf(stderr, "\n");

    for(i = 0; i < 4; i++)
        PrintTree(level++, node->children[i]);
}