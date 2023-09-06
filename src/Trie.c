#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Trie.h"

TrieNode *_Trie_CreateNode()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (!node)
    {
        fprintf(stderr, "Failed to allocate memory for TrieNode\n");
        exit(1);
    }
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    node->isWord = false;
    return node;
}

Trie *Trie_Create()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    if (!trie)
    {
        fprintf(stderr, "Failed to allocate memory for Trie\n");
        exit(1);
    }
    trie->root = _Trie_CreateNode();
    return trie;
}

bool Trie_Insert(Trie *trie, const char *word)
{
    TrieNode *node = trie->root;
    for (int i = 0; word[i]; i++)
    {
        int j = tolower(word[i]) - 'a';
        if (j < 0 || j >= 26)
        {
            fprintf(stderr, "Invalid character in word\n");
            exit(1);
        }
        if (!node->children[j])
            node->children[j] = _Trie_CreateNode();
        node = node->children[j];
    }
    node->isWord = true;
    return true;
}

bool Trie_Contains(Trie *trie, const char *word)
{
    TrieNode *node = trie->root;
    for (int i = 0; word[i]; i++)
    {
        int j = tolower(word[i]) - 'a';
        if (j < 0 || j >= 26)
        {
            fprintf(stderr, "Invalid character in word\n");
            exit(1);
        }
        if (!node->children[j])
            return false;
        node = node->children[j];
    }
    return node->isWord;
}

void _Trie_PrintNode(TrieNode *node, char *buffer, int level, int *p_count)
{
    if (!node)
        return;
    if (node->isWord)
    {
        buffer[level] = '\0';
        printf("%s\n", buffer);
        (*p_count)++;
    }
    for (int i = 0; i < 26; i++)
    {
        buffer[level] = (char)('a' + i);
        _Trie_PrintNode(node->children[i], buffer, level + 1, p_count);
    }
}

int Trie_Print(Trie *trie)
{
    char buffer[45]; // assume 45 is the max length of a word
    int level = 0;
    int count = 0;
    _Trie_PrintNode(trie->root, buffer, level, &count);
    return count;
}

void _Trie_DestroySubTree(TrieNode *node)
{
    if (!node)
        return;
    for (int i = 0; i < 26; i++)
        _Trie_DestroySubTree(node->children[i]);
    free(node);
}

void Trie_Destroy(Trie *trie)
{
    _Trie_DestroySubTree(trie->root);
    free(trie);
    trie = NULL;
}