#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

#define MIN_CAPACITY 16
#define MAX(a, b) (a > b ? a : b)

void _QueueShift(Queue *q)
{
    memcpy(q->buffer, q->buffer + q->front, (q->back - q->front) * sizeof(int));
    q->back -= q->front;
    q->front = 0;
}

void _QueueResize(Queue *q)
{
    q->capacity = MAX(q->front + (q->back - q->front) * 1.5, MIN_CAPACITY);
    q->buffer = (int *)realloc(q->buffer, q->capacity * sizeof(int));
    if (!q->buffer)
    {
        fprintf(stderr, "Failed to allocate memory for extension\n");
        exit(1);
    }
}

Queue *QueueCreate(int *data, int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->buffer = data;
    q->front = 0;
    q->back = size;
    q->capacity = size;
    return q;
}

Queue *QueueCreateEmpty()
{
    return QueueCreate(NULL, 0);
}

void QueueEnqueue(Queue *q, int value)
{
    if (q->back == q->capacity)
    {
        _QueueResize(q);
    }
    q->buffer[q->back++] = value;
}

int QueueDequeue(Queue *q)
{
    if (q->front == q->back)
    {
        fprintf(stderr, "Queue already empty\n");
        exit(1);
    }
    int value = q->buffer[q->front++];
    if (q->front > MAX(q->capacity, MIN_CAPACITY) / 4)
    {
        _QueueShift(q);
    }
    if (q->back < q->capacity / 2 && q->back > MIN_CAPACITY)
    {
        _QueueResize(q);
    }
    return value;
}

int QueueFront(Queue *q)
{
    return q->buffer[q->front];
}

int QueueSize(Queue *q)
{
    return q->back - q->front;
}

bool QueueIsEmpty(Queue *q)
{
    return q->front == q->back;
}

void QueueDestroy(Queue *q)
{
    free(q->buffer);
    free(q);
    q = NULL;
}