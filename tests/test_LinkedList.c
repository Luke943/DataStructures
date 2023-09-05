#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"

int main()
{
    LinkedList *list = LL_Create();

    // Test LL_IsEmpty on an empty list
    assert(LL_IsEmpty(list) == true);

    // Test LL_Append
    LL_Append(list, 10);
    LL_Append(list, 20);
    LL_Append(list, 30);

    // Test LL_IsEmpty on a non-empty list
    assert(LL_IsEmpty(list) == false);

    // Test LL_IndexOf
    assert(LL_IndexOf(list, 20) == 1);

    // Test LL_ElementAt
    assert(LL_ElementAt(list, 0) == 10);
    assert(LL_ElementAt(list, 2) == 30);

    // Test LL_RemoveElement
    assert(LL_RemoveElement(list, 20) == true);
    assert(LL_IndexOf(list, 20) == -1);

    // Test LL_RemoveAt
    assert(LL_RemoveAt(list, 1) == 30);
    // assert(LL_ElementAt(list, 1) == -1); // Throws an error

    // Test LL_AddAt
    LL_AddAt(list, 1, 25);
    assert(LL_ElementAt(list, 1) == 25);

    // Test LL_Destroy
    LL_Destroy(list);

    printf("All tests passed!\n");

    return 0;
}