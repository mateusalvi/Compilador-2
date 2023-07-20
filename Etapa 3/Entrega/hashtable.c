/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
***************************************
****** Amusing * the * amazing ********
**************************************/

#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTableNode* HashTable[HASH_TABLE_SIZE];

void InitHashTable (void)
{
    for(int i = 0; i < HASH_TABLE_SIZE; i++)
        HashTable[i] = 0;
}

int HashAddress(char *value)
{
    int address = 1;

    for(int i = 0; i < strlen(value); i++)
    {
        address = (address * value[i]) % HASH_TABLE_SIZE + 1;
    }

    return address - 1;
}

HashTableNode* HashFind(char *value)
{
    int address = HashAddress(value);
    HashTableNode* node;

    for(node = HashTable[address]; node != NULL; node = node->NextHashNode)
    {
        if(strcmp(value, node->value) == 0)
            return node;
    }

    return NULL;
}

HashTableNode* HashInsert(int type, char* value)
{
    HashTableNode* newNode = HashFind(value);
    int address = HashAddress(value);
    
    //If the element already exists in Hash Table, return the found node.
    if(newNode != NULL)
        return newNode;

    newNode = (HashTableNode*) calloc(1, sizeof(HashTableNode));

    newNode->type = type;
    newNode->value = calloc(strlen(value) + 1, sizeof(char));

    strcpy(newNode->value, value);

    newNode->NextHashNode = HashTable[address];
    HashTable[address] = newNode;

    return newNode;
}

void HashPrint(void)
{
    HashTableNode* node;

    printf("\n----------- PRINTING HASH TABLE -----------\n");

    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if(HashTable[i] != NULL)
        {
            for(node = HashTable[i]; node != NULL; node = node->NextHashNode)
            {
                printf("HashTable index: %d; Type: %d ; Value: %s \n", i, node->type, node->value);
            }
        }
    }

    printf("-------------- END OF TABLE --------------\n");
}