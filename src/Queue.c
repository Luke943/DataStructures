#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

#define MIN_CAPACITY 16
#define MAX(a, b) (a > b ? a : b)

static void Queue_Shift_(Queue *q)
{
    memcpy(q->buffer, q->buffer + q->front, (q->back - q->front) * sizeof(int));
    q->back -= q->front;
    q->front = 0;
}

static void Queue_Resize_(Queue *q)
{
    q->capacity = MAX(q->front + (q->back - q->front) * 1.5, MIN_CAPACITY);
    q->buffer = (int *)realloc(q->buffer, q->capacity * sizeof(int));
    if (!q->buffer)
    {
        fprintf(stderr, "Failed to allocate memory for extension\n");
        exit(1);
    }
}

Queue *Queue_Create(int *data, size_t size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->buffer = data;
    q->front = 0;
    q->back = size;
    q->capacity = size;
    return q;
}

Queue *Queue_CreateEmpty()
{
    return Queue_Create(NULL, 0);
}

void Queue_Enqueue(Queue *q, int value)
{
    if (q->back == q->capacity)
    {
        Queue_Resize_(q);
    }
    q->buffer[q->back++] = value;
}

int Queue_Dequeue(Queue *q)
{
    if (q->front == q->back)
    {
        fprintf(stderr, "Queue already empty\n");
        exit(1);
    }
    int value = q->buffer[q->front++];
    if (q->front > MAX(q->capacity, MIN_CAPACITY) / 4)
    {
        Queue_Shift_(q);
    }
    if (q->back < q->capacity / 2 && q->back > MIN_CAPACITY)
    {
        Queue_Resize_(q);
    }
    return value;
}

int Queue_Front(Queue *q)
{
    return q->buffer[q->front];
}

size_t Queue_Size(Queue *q)
{
    return q->back - q->front;
}

bool Queue_IsEmpty(Queue *q)
{
    return q->front == q->back;
}

void Queue_Destroy(Queue *q)
{
    free(q->buffer);
    free(q);
    q = NULL;
}