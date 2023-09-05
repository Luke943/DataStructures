#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

int main()
{
    // Create an empty queue
    Queue *q = QueueCreateEmpty();

    // Enqueue some elements
    for (int i = 1; i <= 20; i++)
    {
        QueueEnqueue(q, i * 10);
    }

    // Print the front element and the queue size
    printf("Front element: %d\n", QueueFront(q));
    printf("Queue size: %zu\n", QueueSize(q));

    // Dequeue elements and print them
    while (!QueueIsEmpty(q))
    {
        int value = QueueDequeue(q);
        printf("Dequeued: %d\n", value);
    }

    // Check if the queue is empty now
    if (QueueIsEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }

    // Clean up and destroy the queue
    QueueDestroy(q);

    return 0;
}