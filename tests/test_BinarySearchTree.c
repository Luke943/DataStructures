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
    assert(BST_Add(tree, 2) == true);
    assert(BST_Add(tree, 1) == true);
    assert(BST_Add(tree, 12) == true);
    assert(BST_Add(tree, 18) == true);
    assert(BST_Add(tree, 18) == false);

    // Test BST_Remove
    assert(BST_Remove(tree, 5) == true);   // Remove a node with two children
    assert(BST_Remove(tree, 10) == true);  // Remove the root node
    assert(BST_Remove(tree, 2) == true);   // Remove a node with one child
    assert(BST_Remove(tree, 25) == true);  // Remove a node with no children
    assert(BST_Remove(tree, -1) == false); // Try to remove a node that doesn't exist

    // Test BST_FindMin and BST_FindMax
    assert(BST_FindMin(tree) == 1);
    assert(BST_FindMax(tree) == 20);

    // Test BST_IsPresent
    assert(BST_IsPresent(tree, 5) == false);  // Removed earlier
    assert(BST_IsPresent(tree, 11) == false); // Never in tree
    assert(BST_IsPresent(tree, 18) == true);

    // Test BST_IsBST
    assert(BST_IsBST(tree) == true);

    // Test BST_FindMinHeight and BST_FindMaxHeight
    assert(BST_FindMinHeight(tree) == 2);
    assert(BST_FindMaxHeight(tree) == 4);

    // Test BST_IsBalanced
    assert(BST_IsBalanced(tree) == false);

    // Test BST_InOrder
    int in_order_result[7];
    BST_InOrder(tree, in_order_result);
    assert(in_order_result[0] == 1);
    assert(in_order_result[1] == 3);
    assert(in_order_result[2] == 7);
    assert(in_order_result[3] == 12);
    assert(in_order_result[4] == 15);
    assert(in_order_result[5] == 18);
    assert(in_order_result[6] == 20);

    // Test BST_LevelOrder
    int level_order_result[7];
    BST_LevelOrder(tree, level_order_result);
    assert(level_order_result[0] == 12);
    assert(level_order_result[1] == 7);
    assert(level_order_result[2] == 20);
    assert(level_order_result[3] == 3);
    assert(level_order_result[4] == 15);
    assert(level_order_result[5] == 1);
    assert(level_order_result[6] == 18);

    // Destroy the tree
    BST_Destroy(tree);

    printf("All tests passed!\n");

    return 0;
}
