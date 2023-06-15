#ifndef _HASH_
#define _HASH_

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/
#define HASH_TABLE_SIZE 997

enum symbols {
    SYMBOL_KW_INT, // 1
    SYMBOL_KW_REAL, // 2
    SYMBOL_KW_CHAR, // 3
    SYMBOL_KW_BOOL, // 4
    SYMBOL_KW_IF, // 5
    SYMBOL_KW_THEN, // 6
    SYMBOL_KW_ELSE, // 7
    SYMBOL_KW_LOOP, // 8
    SYMBOL_KW_INPUT, // 9
    SYMBOL_KW_OUTPUT, // 10
    SYMBOL_KW_RETURN, // 11
    SYMBOL_OPERATOR_LE, // 12
    SYMBOL_OPERATOR_GE, // 13
    SYMBOL_OPERATOR_EQ, // 14
    SYMBOL_OPERATOR_DIF, // 15
    SYMBOL_TK_IDENTIFIER, // 16
    SYMBOL_LIT_INT, // 17
    SYMBOL_LIT_REAL, // 18
    SYMBOL_LIT_CHAR, // 19
    SYMBOL_LIT_STRING, // 20
    SYMBOL_TOKEN_ERROR // 21
};

typedef struct HashTableNode 
{
    int type;
    char* value;
    struct HashTableNode* NextHashNode;
} HashTableNode;

void InitHashTable(void);
void HashAdress(char *text);
HashTableNode* hashFind(char *text, int address);
HashTableNode* HashInsert(int type, char* text);
void HashPrint(void);

#endif