#ifndef _HASH_
#define _HASH_

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/

#define HASH_TABLE_SIZE 997

typedef struct HashTableNode 
{
    int type;
    char* value;
    struct HashTableNode* NextHashNode;
} HashTableNode;

HashTableNode* HashTable[HASH_TABLE_SIZE];
void InitHashTable(void);
void HashAdress(char *text);
HashTableNode* hashFind(char *text, int address);
HashTableNode* HashInsert(int type, char* text);
void HashPrint(void);

#endif