#ifndef _HASH_
#define _HASH_

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/

#define HASH_TABLE_SIZE 997
#include <stdio.h>
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
    SYMBOL_LABEL,
    DECLARATION_VAR_TEMP
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
HashTableNode* HashFind(char *text);
HashTableNode* HashInsert(int type, char* text);
void HashPrint(void);
int HashCheckDeclaration(void);
HashTableNode* MakeTemp(void);
HashTableNode* MakeLabel(void);
void HashPrintASM(FILE* out);

#endif