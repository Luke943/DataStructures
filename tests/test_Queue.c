#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

int main()
{
    // Create an empty queue
    Queue *q = Queue_CreateEmpty();

    // Enqueue some elements
    for (int i = 1; i <= 20; i++)
    {
        Queue_Enqueue(q, i * 10);
    }

    // Print the front element and the queue size
    printf("Front element: %d\n", Queue_Front(q));
    printf("Queue size: %zu\n", Queue_Size(q));

    // Dequeue elements and print them
    while (!Queue_IsEmpty(q))
    {
        int value = Queue_Dequeue(q);
        printf("Dequeued: %d\n", value);
    }

    // Check if the queue is empty now
    if (Queue_IsEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }

    // Clean up and destroy the queue
    Queue_Destroy(q);

    return 0;
}