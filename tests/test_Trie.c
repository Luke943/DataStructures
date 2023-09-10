#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "Trie.h"

int main()
{
    Trie *trie = Trie_Create();

    // Insert some words into the Trie
    Trie_Insert(trie, "apple");
    Trie_Insert(trie, "banana");
    Trie_Insert(trie, "app");
    Trie_Insert(trie, "bat");
    Trie_Insert(trie, "batman");

    // Check if words exist in the Trie
    assert(Trie_Contains(trie, "apple") == true);
    assert(Trie_Contains(trie, "banana") == true);
    assert(Trie_Contains(trie, "app") == true);
    assert(Trie_Contains(trie, "bat") == true);
    assert(Trie_Contains(trie, "batman") == true);
    assert(Trie_Contains(trie, "cat") == false);

    // Print the Trie and get the number of words printed
    printf("Trie Contents:\n");
    int wordsPrinted = Trie_Print(trie);
    assert(wordsPrinted == 5);

    // Clean up and destroy the Trie
    Trie_Destroy(trie);

    printf("All tests passed!\n");

    return 0;
}
