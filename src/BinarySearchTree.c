#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "Queue.h"

BST *BST_Create()
{
    BST *tree = (BST *)malloc(sizeof(BST));
    if (tree == NULL)
    {
        fprintf(stderr, "BST_Create: memory allocation error\n");
        exit(1);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

bool BST_Add(BST *tree, int value)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (!node)
    {
        fprintf(stderr, "BST_Add: memory allocation error\n");
        exit(1);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    tree->size++;
    if (!tree->root)
    {
        tree->root = node;
        return true;
    }
    BSTNode **p_dst = &(tree->root);
    while (*p_dst)
    {
        if (value < (*p_dst)->value)
            p_dst = &((*p_dst)->left);
        else if (value > (*p_dst)->value)
            p_dst = &((*p_dst)->right);
        else
            return false;
    }
    *p_dst = node;
    return true;
}

int BST_FindMin(BST *tree)
{
    if (!tree->root)
    {
        fprintf(stderr, "BST_FindMin: tree is empty\n");
        exit(1);
    }
    BSTNode *node = tree->root;
    while (node->left)
        node = node->left;
    return node->value;
}

int BST_FindMax(BST *tree)
{
    if (!tree->root)
    {
        fprintf(stderr, "BST_FindMax: tree is empty\n");
        exit(1);
    }
    BSTNode *node = tree->root;
    while (node->right)
        node = node->right;
    return node->value;
}

bool BST_IsPresent(BST *tree, int value)
{
    BSTNode *node = tree->root;
    while (node)
    {
        if (node->value == value)
            return true;
        if (value < node->value)
            node = node->left;
        else
            node = node->right;
    }
    return false;
}

static bool BST_IsBST_(BSTNode *node)
{
    if (!node)
        return true;
    if (node->left && node->left->value >= node->value)
        return false;
    if (node->right && node->right->value <= node->value)
        return false;
    return BST_IsBST_(node->left) && BST_IsBST_(node->right);
}

bool BST_IsBST(BST *tree)
{
    return BST_IsBST_(tree->root);
}

size_t _BST_FindMinHeight(BSTNode *node)
{
    if (!node)
        return 0;
    size_t left = _BST_FindMinHeight(node->left);
    size_t right = _BST_FindMinHeight(node->right);
    return (left < right) ? left + 1 : right + 1;
}

size_t BST_FindMinHeight(BST *tree)
{
    return _BST_FindMinHeight(tree->root);
}

size_t _BST_FindMaxHeight(BSTNode *node)
{
    if (!node)
        return 0;
    size_t left = _BST_FindMaxHeight(node->left);
    size_t right = _BST_FindMaxHeight(node->right);
    return (left > right) ? left + 1 : right + 1;
}

size_t BST_FindMaxHeight(BST *tree)
{
    return _BST_FindMaxHeight(tree->root);
}

bool BST_IsBalanced(BST *tree)
{
    return BST_FindMinHeight(tree) + 1 >= BST_FindMaxHeight(tree);
}

static void BST_InOrder_(BSTNode *node, int *buffer, size_t *p_index)
{
    if (!node)
        return;
    BST_InOrder_(node->left, buffer, p_index);
    buffer[(*p_index)++] = node->value;
    BST_InOrder_(node->right, buffer, p_index);
}

void BST_InOrder(BST *tree, int *dest) // buffer must be of size tree->size
{
    size_t index = 0;
    BST_InOrder_(tree->root, dest, &index);
}

void BST_LevelOrder(BST *tree, int *dest) // buffer must be of size tree->size
{
    if (!tree->root)
        return;
    size_t index = 0;
    BSTNode **queue = malloc(sizeof(BSTNode *) * tree->size);
    if (!queue)
    {
        fprintf(stderr, "BST_LevelOrder: memory allocation error\n");
        exit(1);
    }
    queue[0] = tree->root;
    size_t read_index = 0;
    size_t write_index = 1;
    while (read_index < write_index)
    {
        BSTNode *node = queue[read_index++];
        dest[index++] = node->value;
        if (node->left)
            queue[write_index++] = node->left;
        if (node->right)
            queue[write_index++] = node->right;
    }
    free(queue);
}

bool BST_Remove(BST *tree, int value)
{
    BSTNode **p_node = &(tree->root);
    while (*p_node)
    {
        if (value < (*p_node)->value)
            p_node = &((*p_node)->left);
        else if (value > (*p_node)->value)
            p_node = &((*p_node)->right);
        else
            break;
    }
    if (!*p_node)
        return false;
    tree->size--;
    BSTNode *node = *p_node;
    if (node->left && node->right)
    {
        BSTNode **p_min_node = &(node->right);
        while ((*p_min_node)->left)
            p_min_node = &((*p_min_node)->left);
        BSTNode *min_node = *p_min_node;
        node->value = min_node->value;
        if (min_node->right)
            *p_min_node = min_node->right;
        else
            *p_min_node = NULL;
        free(min_node);
        return true;
    }
    if (!node->left && !node->right)
        *p_node = NULL;
    else if (!node->left)
        *p_node = node->right;
    else if (!node->right)
        *p_node = node->left;
    if (node == tree->root)
        tree->root = *p_node;
    free(node);
    return true;
}

static void BST_DestroySubtree_(BSTNode *node)
{
    if (!node)
        return;
    BST_DestroySubtree_(node->left);
    BST_DestroySubtree_(node->right);
    free(node);
}

void BST_Destroy(BST *tree)
{
    BST_DestroySubtree_(tree->root);
    free(tree);
}