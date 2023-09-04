// Functionality of a queue implemented for type int

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue
{
    int front;
    int back;
    int capacity;
    int *buffer;
} Queue;

Queue *QueueCreate(int *data, int size);
Queue *QueueCreateEmpty();
void QueueEnqueue(Queue *q, int value);
int QueueDequeue(Queue *q);
int QueueFront(Queue *q);
int QueueSize(Queue *q);
bool QueueIsEmpty(Queue *q);
void QueueDestroy(Queue *q);

#endif // QUEUE_H