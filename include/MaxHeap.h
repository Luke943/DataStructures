// Max heap for integers.
// It uses an array to store the elements starting at index 0.

#pragma once

#include <stddef.h>

typedef struct MaxHeap
{
    size_t size;
    size_t capacity;
    int *data;
} MaxHeap;

MaxHeap *MaxHeap_Create();
void MaxHeap_Push(MaxHeap *heap, int value);
int MaxHeap_Pop(MaxHeap *heap);
int MaxHeap_PushPop(MaxHeap *heap, int value);
void MaxHeap_Print(MaxHeap *heap);
void MaxHeap_Destroy(MaxHeap *heap);

void HeapSort(int *array, size_t size);