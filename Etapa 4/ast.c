/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
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
            fprintf(file, " %s = ", node->symbol->text);
            uncompileAST(node->children[1], file);
            fprintf(file, ";\n");
            break;

        case AST_VECDEC :
            uncompileAST(node->children[0], file);
            fprintf(file, " %s[", node->symbol->text);
            uncompileAST(node->children[1], file);
            fprintf(file, "]");      
            uncompileAST(node->children[2], file);
            fprintf(file, ";\n");
            break;

        case AST_FUNCDEC :
            uncompileAST(node->children[0], file);
            fprintf(file, " %s(", node->symbol->text);
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

        case AST_TYPE_STRING :
            fprintf(file, "string");
            break;

        case AST_SYMBOL :
            fprintf(file, " %s ", node->symbol->text);
            break;

        case AST_VECINIT :
            uncompileAST(node->children[0], file);
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
            fprintf(file, "%s", node->symbol->text);
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
            fprintf(file, "%s = ", node->symbol->text);
            uncompileAST(node->children[0], file);
            fprintf(file, ";\n");
            break;

        case AST_VECATTRIB :
            fprintf(file, "%s[", node->symbol->text);
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
            fprintf(file, ",");
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
            fprintf(file, "%s[", node->symbol->text);
            uncompileAST(node->children[0], file);
            fprintf(file, "]");
            break;

        case AST_FUNCALL :
            fprintf(file, "%s(", node->symbol->text);
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
            fprintf(file, " not ");
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
            fprintf(stderr, "-------- UNCOMPILE ERROR: UNKNOWN NODE --------, %d", node->type);
            break;
    }
}

void PrintTree(int level, AstNode *node)
{
    if(node == NULL)
        return;
  
    fprintf(stderr, "Level %d ", level);
        for(int i = 0; i < level; i++)
            fprintf(stderr, "  ");

    switch(node->type){
        case AST_DECLIST: fprintf(stderr, "AST_DECLIST, %d", node->type);  break;
        case AST_VARDEC: fprintf(stderr, "AST_VARDEC, %d", node->type);  break;
        case AST_VECDEC: fprintf(stderr, "AST_VECDEC, %d", node->type);  break;
        case AST_FUNCDEC: fprintf(stderr, "AST_FUNCDEC, %d", node->type);  break;
        case AST_TYPE_CHAR: fprintf(stderr, "AST_TYPE_CHAR, %d", node->type);  break;
        case AST_TYPE_INT: fprintf(stderr, "AST_TYPE_INT, %d", node->type);  break;
        case AST_TYPE_BOOL: fprintf(stderr, "AST_TYPE_BOOL, %d", node->type);  break;
        case AST_TYPE_REAL: fprintf(stderr, "AST_TYPE_REAL, %d", node->type);  break;
        case AST_TYPE_STRING: fprintf(stderr, "AST_TYPE_STRING, %d", node->type); break;
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, %d", node->type);  break;
        case AST_VECINIT: fprintf(stderr, "AST_VECINIT, %d", node->type);  break;
        case AST_VECELEMENTS: fprintf(stderr, "AST_VECELEMENTS, %d", node->type);  break;
        case AST_PARAMTAIL: fprintf(stderr, "AST_PARAMTAIL, %d", node->type);  break;
        case AST_PARAMS: fprintf(stderr, "AST_PARAMS, %d", node->type);  break;
        case AST_PARAM: fprintf(stderr, "AST_PARAM, %d", node->type);  break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK, %d", node->type);  break;
        case AST_CMDLISTINIT: fprintf(stderr, "AST_CMDLISTINIT, %d", node->type);  break;
        case AST_CMDLIST: fprintf(stderr, "AST_CMDLIST, %d", node->type);  break;
        case AST_ATTRIB: fprintf(stderr, "AST_ATTRIB, %d", node->type);  break;
        case AST_VECATTRIB: fprintf(stderr, "AST_VECATTRIB, %d", node->type);  break;
        case AST_OUTPUT: fprintf(stderr, "AST_OUTPUT, %d", node->type);  break;
        case AST_OUTPUTLIST: fprintf(stderr, "AST_OUTPUTLIST, %d", node->type);  break;
        case AST_OUTPUTTAIL: fprintf(stderr, "AST_OUTPUTTAIL, %d", node->type);  break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN, %d", node->type);  break;
        case AST_IF: fprintf(stderr, "AST_IF, %d", node->type);  break;
        case AST_IFLOOP: fprintf(stderr, "AST_IFLOOP, %d", node->type);  break;
        case AST_LOOP: fprintf(stderr, "AST_LOOP, %d", node->type);  break;
        case AST_IFELSE: fprintf(stderr, "AST_IFELSE, %d", node->type);  break;
        case AST_INPUT: fprintf(stderr, "AST_INPUT, %d", node->type);  break;
        case AST_VEC: fprintf(stderr, "AST_VEC, %d", node->type);  break;
        case AST_FUNCALL: fprintf(stderr, "AST_FUNCALL, %d", node->type);  break;
        case AST_SUM: fprintf(stderr, "AST_SUM, %d", node->type);  break;
        case AST_SUB: fprintf(stderr, "AST_SUB, %d", node->type);  break;
        case AST_MULT: fprintf(stderr, "AST_MULT, %d", node->type);  break;
        case AST_DIV: fprintf(stderr, "AST_DIV, %d", node->type);  break;
        case AST_LESS: fprintf(stderr, "AST_LESS, %d", node->type);  break;
        case AST_GREATER: fprintf(stderr, "AST_GREATER, %d", node->type);  break;
        case AST_EQ: fprintf(stderr, "AST_EQ, %d", node->type);  break;
        case AST_GE: fprintf(stderr, "AST_GE, %d", node->type);  break;
        case AST_LE: fprintf(stderr, "AST_LE, %d", node->type);  break;
        case AST_DIF: fprintf(stderr, "AST_DIF, %d", node->type);  break;
        case AST_AND: fprintf(stderr, "AST_AND, %d", node->type);  break;
        case AST_OR: fprintf(stderr, "AST_OR, %d", node->type);  break;
        case AST_NOT: fprintf(stderr, "AST_NOT, %d", node->type);  break;
        case AST_PAREN: fprintf(stderr, "AST_PAREN, %d", node->type);  break;
        case AST_EXPLIST: fprintf(stderr, "AST_EXPLIST, %d", node->type);  break;
        case AST_EXPLISTTAIL: fprintf(stderr, "AST_EXPLISTTAIL, %d", node->type);  break;
        case AST_BLANKBLOCK: fprintf(stderr, "AST_BLANKBLOCK, %d", node->type); break;
        //case AST_COMMA: fprintf(stderr, "AST_COMMA");  break;
        default : fprintf(stderr, "-------- AST ERROR with type %d -------- ", node->type);  break;
  }

    if(node->symbol != NULL)
        fprintf(stderr, ", %s\n", node->symbol->text);
    else
        fprintf(stderr, "\n");

    for(int i = 0; i < 4; i++)
        PrintTree(level++, node->children[i]);
}