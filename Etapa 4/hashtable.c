/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
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

int HashAddress(char *text)
{
    int address = 1;

    for(int i = 0; i < strlen(text); i++)
    {
        address = (address * text[i]) % HASH_TABLE_SIZE + 1;
    }

    return address - 1;
}

HashTableNode* HashFind(char *text)
{
    int address = HashAddress(text);
    HashTableNode* node;

    for(node = HashTable[address]; node != NULL; node = node->NextHashNode)
    {
        if(strcmp(text, node->text) == 0)
            return node;
    }

    return NULL;
}

HashTableNode* HashInsert(int type, char* text)
{
    HashTableNode* newNode = HashFind(text);
    int address = HashAddress(text);
    
    //If the element already exists in Hash Table, return the found node.
    if(newNode != NULL)
        return newNode;

    newNode = (HashTableNode*) calloc(1, sizeof(HashTableNode));
    newNode->type = type;

    switch (newNode->type)
    {
    case SYMBOL_CHAR:
        newNode->dataType = DATATYPE_CHAR;
        break;

    case SYMBOL_INT:
        newNode->dataType = DATATYPE_INT;
        break;

    case SYMBOL_BOOL:
        newNode->dataType = DATATYPE_INT;
        break;

    case SYMBOL_REAL:
        newNode->dataType = DATATYPE_REAL;
        break;

    case SYMBOL_STRING:
        newNode->dataType = DATATYPE_STRING;
        break;

    default:
        break;
    }

    newNode->text = calloc(strlen(text) + 1, sizeof(char));

    strcpy(newNode->text, text);

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
                printf("HashTable index: %d; Type: %d ; Value: %s ; DataType: %d \n", i, node->type, node->text, node->dataType);
            }
        }
    }

    printf("-------------- END OF TABLE --------------\n");
}

int HashCheckDeclaration(void)
{
    HashTableNode* node;
    int undeclared = 0;

    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if(HashTable[i] != NULL)
        {
            for(node = HashTable[i]; node != NULL; node = node->NextHashNode)
            {
                if(node->type == SYMBOL_IDENTIFIER)
                {
                    fprintf(stderr, "Identifier %s was not declared!\n", node->text);
                    undeclared++;
                }
            }
        }
    }

    return undeclared;
}