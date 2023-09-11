#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "HashTable.h"

int main()
{
    // Create a hash table with a size of 10
    HashTable *table = HashTable_Create(10);

    // Add some key-value pairs to the hash table
    assert(HashTable_Add(table, "name", "John"));
    assert(HashTable_Add(table, "age", "30"));
    assert(HashTable_Add(table, "city", "New York"));

    // Retrieve and assert values from the hash table
    assert(strcmp(HashTable_Get(table, "name"), "John") == 0);
    assert(strcmp(HashTable_Get(table, "age"), "30") == 0);
    assert(strcmp(HashTable_Get(table, "city"), "New York") == 0);

    // Attempt to retrieve a non-existent key
    const char *nonExistentValue = HashTable_Get(table, "gender");
    assert(nonExistentValue == NULL);

    // Remove a key-value pair from the hash table
    assert(HashTable_Remove(table, "age"));

    // Attempt to retrieve the removed key
    const char *removedValue = HashTable_Get(table, "age");
    assert(removedValue == NULL);

    // Destroy the hash table and free memory
    HashTable_Destroy(table);

    printf("All tests passed!\n");

    return 0;
}
