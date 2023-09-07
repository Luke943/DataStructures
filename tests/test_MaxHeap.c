#include <stdio.h>
#include "MaxHeap.h"

int main()
{
    // Create a MaxHeap
    MaxHeap *heap = MaxHeap_Create();

    // Test MaxHeap_Push
    MaxHeap_Push(heap, 10);
    MaxHeap_Push(heap, 30);
    MaxHeap_Push(heap, 20);
    MaxHeap_Push(heap, 50);
    MaxHeap_Push(heap, 40);

    // Test MaxHeap_Print
    printf("MaxHeap elements: ");
    MaxHeap_Print(heap);

    // Test MaxHeap_Pop
    printf("Popped element: %d\n", MaxHeap_Pop(heap));

    // Test MaxHeap_PushPop
    printf("PushPop result: %d\n", MaxHeap_PushPop(heap, 60));

    // Test MaxHeap_Print after modifications
    printf("MaxHeap elements after popping and PushPop: ");
    MaxHeap_Print(heap);

    // Destroy the MaxHeap to free memory
    MaxHeap_Destroy(heap);

    // Create an array to demonstrate HeapSort
    int array[] = {3, 6, 8, 10, 1, 2, 5, 4, 9, 7};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    // Perform Heap Sort
    HeapSort(array, array_size);

    // Print the sorted array
    printf("Sorted array: ");
    for (size_t i = 0; i < array_size; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
