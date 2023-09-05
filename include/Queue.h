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

Queue *QueueCreate(int *data, size_t size);
Queue *QueueCreateEmpty();
void QueueEnqueue(Queue *q, int value);
int QueueDequeue(Queue *q);
int QueueFront(Queue *q);
size_t QueueSize(Queue *q);
bool QueueIsEmpty(Queue *q);
void QueueDestroy(Queue *q);
