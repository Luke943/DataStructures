#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

int main()
{
    // Create an empty stack
    Stack *stack = Stack_CreateEmpty();

    // Push some elements onto the stack
    for (int i = 1; i <= 20; i++)
    {
        Stack_Push(stack, i * 10);
    }

    // Print the top element and stack size
    printf("Top element: %d\n", Stack_Peek(stack));
    printf("Stack size: %zu\n", stack->size);

    // Pop and print elements from the stack
    while (!Stack_IsEmpty(stack))
    {
        int value = Stack_Pop(stack);
        printf("Popped: %d\n", value);
    }

    // Check if the stack is empty now
    if (Stack_IsEmpty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    // Clean up and destroy the stack
    Stack_Destroy(stack);

    return 0;
}