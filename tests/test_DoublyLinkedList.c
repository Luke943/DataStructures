#include <stdio.h>
#include <assert.h>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList *list = DLL_Create();

    // Test DLL_Add
    DLL_Add(list, 10);
    DLL_Add(list, 20);
    DLL_Add(list, 30);

    // Test DLL_Remove
    assert(DLL_Remove(list, 20) == true);
    assert(DLL_Remove(list, 40) == false);

    // Test DLL_Reverse
    DLL_Reverse(list);

    // Test list traversal after reversing
    DLL_Node *current = list->head;
    int expected_data[] = {30, 10};
    for (int i = 0; i < 2; i++)
    {
        assert(current->data == expected_data[i]);
        current = current->next;
    }

    // Test DLL_Destroy
    DLL_Destroy(list);

    printf("All tests passed!\n");

    return 0;
}