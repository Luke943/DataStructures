#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

bool _malloc_assined = false; // Determine if need to call free on key, value
#define IF_MALLOC_ASSIGNED(x) \
    if (_malloc_assined)      \
    x

// djb2
unsigned long hashstring(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

HashTable *HashTable_Create(int size)
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (!table)
    {
        fprintf(stderr, "Failed to allocate memory for hash table\n");
        exit(1);
    }
    table->size = size;
    table->count = 0;
    table->items = (Item **)malloc(sizeof(Item *) * size);
    for (int i = 0; i < size; i++)
        table->items[i] = NULL;
    return table;
}

bool HashTable_Add(HashTable *table, char *key, char *value)
{
    int index = hashstring(key) % table->size;
    Item *parent = NULL;
    Item *tmp = table->items[index];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
            return false;
        parent = tmp;
        tmp = tmp->next;
    }
    Item *item = (Item *)malloc(sizeof(Item));
    if (!item)
    {
        fprintf(stderr, "Failed to allocate memory for new item\n");
        exit(1);
    }
    item->key = key;
    item->value = value;
    item->next = NULL;
    if (parent)
        parent->next = item;
    else
        table->items[index] = item;
    table->count++;
    return true;
}

bool HashTable_Remove(HashTable *table, char *key)
{
    int index = hashstring(key) % table->size;
    Item *parent = NULL;
    Item *item = table->items[index];
    while (item)
    {
        if (strcmp(item->key, key) == 0)
        {
            if (parent)
                parent->next = item->next;
            else
                table->items[index] = item->next;
            IF_MALLOC_ASSIGNED(free(item->key));
            IF_MALLOC_ASSIGNED(free(item->value));
            free(item);
            table->count--;
            return true;
        }
        parent = item;
        item = item->next;
    }
    return false;
}

const char *HashTable_Get(HashTable *table, char *key)
{
    int index = hashstring(key) % table->size;
    Item *item = table->items[index];
    while (item)
    {
        if (strcmp(item->key, key) == 0)
            return item->value;
        item = item->next;
    }
    return NULL;
}

void HashTable_Destroy(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        Item *item = table->items[i];
        while (item)
        {
            Item *tmp = item;
            item = item->next;
            IF_MALLOC_ASSIGNED(free(tmp->key));
            IF_MALLOC_ASSIGNED(free(tmp->value));
            free(tmp);
        }
    }
    free(table->items);
    free(table);
}