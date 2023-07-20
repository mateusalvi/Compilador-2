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

void InitHashTable(void);
void HashAdress(char *value);
HashTableNode* hashFind(char *value, int address);
HashTableNode* HashInsert(int type, char* value);
void HashPrint(void);

#endif