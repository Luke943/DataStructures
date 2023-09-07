#include <stdio.h>
#include <stdlib.h>
#include "MaxHeap.h"

#define MIN_CAPACITY 16
#define MAX(a, b) (a > b ? a : b)

MaxHeap *MaxHeap_Create()
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->data = (int *)malloc(MIN_CAPACITY * sizeof(int));
    if (!heap || !heap->data)
    {
        fprintf(stderr, "MaxHeap_Create: failed to allocate memory\n");
        exit(1);
    }
    heap->capacity = MIN_CAPACITY;
    heap->size = 0;
    return heap;
}

void _MaxHeap_Resize(MaxHeap *heap, size_t new_capacity)
{
    heap->capacity = new_capacity;
    heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));
    if (!heap->data)
    {
        fprintf(stderr, "Resize failed to allocate memory\n");
        exit(1);
    }
}

void MaxHeap_Push(MaxHeap *heap, int value)
{
    if (heap->size == heap->capacity)
        _MaxHeap_Resize(heap, heap->capacity * 2);
    heap->data[heap->size++] = value;
    int index = heap->size - 1;
    int parent = (index - 1) / 2;
    while (index > 0 && heap->data[parent] < heap->data[index])
    {
        int tmp = heap->data[index];
        heap->data[index] = heap->data[parent];
        heap->data[parent] = tmp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

void _MaxHeap_IntegrateRoot(MaxHeap *heap)
{
    int index = 0;
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int max = heap->data[index];
        int max_index = index;
        if (left < heap->size && heap->data[left] > max)
        {
            max = heap->data[left];
            max_index = left;
        }
        if (right < heap->size && heap->data[right] > max)
        {
            max = heap->data[right];
            max_index = right;
        }
        if (max_index == index)
            break;
        int tmp = heap->data[max_index];
        heap->data[max_index] = heap->data[index];
        heap->data[index] = tmp;
        index = max_index;
    }
}

int MaxHeap_Pop(MaxHeap *heap)
{
    if (heap->size == 0)
    {
        fprintf(stderr, "MaxHeap_Pop: heap is empty\n");
        exit(1);
    }
    int value = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    if (heap->size < heap->capacity / 4 && heap->capacity > MIN_CAPACITY)
    {
        _MaxHeap_Resize(heap, MAX(heap->capacity / 2, MIN_CAPACITY));
    }
    _MaxHeap_IntegrateRoot(heap);
    return value;
}

int MaxHeap_PushPop(MaxHeap *heap, int value)
{
    int popped_value = heap->data[0];
    heap->data[0] = value;
    _MaxHeap_IntegrateRoot(heap);
    return popped_value;
}

void MaxHeap_Print(MaxHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

void MaxHeap_Destroy(MaxHeap *heap)
{
    free(heap->data);
    free(heap);
}

void HeapSort(int *array, size_t size)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->data = (int *)malloc(size * sizeof(int));
    if (!heap || !heap->data)
    {
        fprintf(stderr, "HeapSort: failed to allocate memory\n");
        exit(1);
    }
    heap->capacity = size;
    heap->size = 0;
    for (size_t i = 0; i < size; i++)
        MaxHeap_Push(heap, array[i]);
    for (size_t i = 0; i < size; i++)
        array[size - 1 - i] = MaxHeap_Pop(heap);
    MaxHeap_Destroy(heap);
}