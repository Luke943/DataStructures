// Functionality of a queue implemented for type int

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct Queue
{
    size_t front;
    size_t back;
    size_t capacity;
    int *buffer;
} Queue;

Queue *Queue_Create(int *data, size_t size);
Queue *Queue_CreateEmpty();
void Queue_Enqueue(Queue *q, int value);
int Queue_Dequeue(Queue *q);
int Queue_Front(Queue *q);
size_t Queue_Size(Queue *q);
bool Queue_IsEmpty(Queue *q);
void Queue_Destroy(Queue *q);
