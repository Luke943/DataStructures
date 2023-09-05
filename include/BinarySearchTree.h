// Binary search tree for integers
// Does not accept duplicate keys

#pragma once

#include <stdbool.h>

typedef struct BSTNode
{
    int value;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct BST
{
    BSTNode *root;
    size_t size;
} BST;

BST *BST_Create();
bool BST_Add(BST *tree, int value);
int BST_FindMin(BST *tree);
int BST_FindMax(BST *tree);
bool BST_IsPresent(BST *tree, int value);
bool BST_IsBST(BST *tree);
size_t BST_FindMinHeight(BST *tree);
size_t BST_FindMaxHeight(BST *tree);
bool BST_IsBalanced(BST *tree);
void BST_InOrder(BST *tree, int *dest);    // buffer must be of size tree->size
void BST_LevelOrder(BST *tree, int *dest); // buffer must be of size tree->size
void BST_Destroy(BST *tree);