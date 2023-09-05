#include <stdio.h>
#include <assert.h>
#include "BinarySearchTree.h"

int main()
{
    // Create a new binary search tree
    BST *tree = BST_Create();

    // Test BST_Add
    assert(BST_Add(tree, 10) == true);
    assert(BST_Add(tree, 5) == true);
    assert(BST_Add(tree, 20) == true);
    assert(BST_Add(tree, 3) == true);
    assert(BST_Add(tree, 7) == true);
    assert(BST_Add(tree, 15) == true);
    assert(BST_Add(tree, 25) == true);
    assert(BST_Add(tree, 25) == false);
    assert(BST_Add(tree, 2) == true); // Additional nodes to create an imbalanced tree
    assert(BST_Add(tree, 1) == true);

    // Test BST_FindMin and BST_FindMax
    assert(BST_FindMin(tree) == 1);
    assert(BST_FindMax(tree) == 25);

    // Test BST_IsPresent
    assert(BST_IsPresent(tree, 10) == true);
    assert(BST_IsPresent(tree, 15) == true);
    assert(BST_IsPresent(tree, 30) == false);

    // Test BST_IsBST
    assert(BST_IsBST(tree) == true);

    // Test BST_FindMinHeight and BST_FindMaxHeight
    assert(BST_FindMinHeight(tree) == 3); // Shortest path: 1 -> 2 -> 3
    assert(BST_FindMaxHeight(tree) == 5); // Longest path: 1 -> 2 -> 3 -> 5 -> 10

    // Test BST_IsBalanced
    assert(BST_IsBalanced(tree) == false); // The tree is not balanced

    // Test BST_InOrder
    int in_order_result[9];
    BST_InOrder(tree, in_order_result);
    assert(in_order_result[0] == 1);
    assert(in_order_result[1] == 2);
    assert(in_order_result[2] == 3);
    assert(in_order_result[3] == 5);
    assert(in_order_result[4] == 7);
    assert(in_order_result[5] == 10);
    assert(in_order_result[6] == 15);
    assert(in_order_result[7] == 20);
    assert(in_order_result[8] == 25);

    // Test BST_LevelOrder
    int level_order_result[9];
    BST_LevelOrder(tree, level_order_result);
    assert(level_order_result[0] == 10);
    assert(level_order_result[1] == 5);
    assert(level_order_result[2] == 20);
    assert(level_order_result[3] == 3);
    assert(level_order_result[4] == 7);
    assert(level_order_result[5] == 15);
    assert(level_order_result[6] == 25);
    assert(level_order_result[7] == 2);
    assert(level_order_result[8] == 1);

    // Destroy the tree
    BST_Destroy(tree);

    printf("All tests passed!\n");

    return 0;
}
