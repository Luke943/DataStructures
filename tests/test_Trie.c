#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    printf("Trie Contains 'apple': %s\n", Trie_Contains(trie, "apple") ? "Yes" : "No");
    printf("Trie Contains 'banana': %s\n", Trie_Contains(trie, "banana") ? "Yes" : "No");
    printf("Trie Contains 'app': %s\n", Trie_Contains(trie, "app") ? "Yes" : "No");
    printf("Trie Contains 'bat': %s\n", Trie_Contains(trie, "bat") ? "Yes" : "No");
    printf("Trie Contains 'batman': %s\n", Trie_Contains(trie, "batman") ? "Yes" : "No");
    printf("Trie Contains 'cat': %s\n", Trie_Contains(trie, "cat") ? "Yes" : "No");

    // Print the Trie and get the number of words printed
    printf("Trie Contents:\n");
    int wordsPrinted = Trie_Print(trie);
    printf("Number of words printed: %d\n", wordsPrinted);

    // Clean up and destroy the Trie
    Trie_Destroy(trie);

    return 0;
}
