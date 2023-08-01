#ifndef _HASH_
#define _HASH_

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/

#define HASH_TABLE_SIZE 997

enum HASH_SYMBOLS
{
    SYMBOL_IDENTIFIER,
    SYMBOL_INT,
    SYMBOL_BOOL,
    SYMBOL_REAL,
    SYMBOL_CHAR,
    SYMBOL_STRING,
    DECLARATION_VAR,
    DECLARATION_FUNC,
    DECLARATION_VEC,
    DECLARATION_PARAM,
    DATATYPE_INT,
    DATATYPE_BOOL,
    DATATYPE_CHAR,
    DATATYPE_REAL,
    DATATYPE_STRING,
    SYMBOL_LABEL
};

typedef struct HashTableNode 
{
    int type;
    char* text;
    int dataType;
    struct HashTableNode* NextHashNode;
} HashTableNode;

void InitHashTable(void);
void HashAdress(char *text);
HashTableNode* hashFind(char *text, int address);
HashTableNode* HashInsert(int type, char* text);
void HashPrint(void);
int HashCheckDeclaration(void);
HashTableNode* MakeTemp(void);
HashTableNode* MakeLabel(void);

#endif