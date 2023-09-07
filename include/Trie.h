// Trie structure for storing words
// Words must be null terminated strings containing letters

#pragma once

#include <stdbool.h>

typedef struct TrieNode
{
    struct TrieNode *children[26];
    bool isWord;
} TrieNode;

typedef struct Trie
{
    TrieNode *root;
} Trie;

Trie *Trie_Create();
bool Trie_Insert(Trie *trie, const char *word);
bool Trie_Contains(Trie *trie, const char *word);
int Trie_Print(Trie *trie);
void Trie_Destroy(Trie *trie);