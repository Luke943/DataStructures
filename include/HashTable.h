// Hash table implementation for string keys and string values.

#pragma once

#include <stdbool.h>

typedef struct Item
{
    char *key;
    char *value;
    struct Item *next;
} Item;

typedef struct HashTable
{
    size_t size;
    size_t count;
    Item **items;
} HashTable;

unsigned long hashstring(char *str); // dbj2 hash function
HashTable *HashTable_Create(int size);
bool HashTable_Add(HashTable *table, char *key, char *value);
bool HashTable_Remove(HashTable *table, char *key);
const char *HashTable_Get(HashTable *table, char *key);
void HashTable_Destroy(HashTable *table);
