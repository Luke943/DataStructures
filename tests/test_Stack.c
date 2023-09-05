#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

int main()
{
    // Create an empty stack
    Stack *stack = StackCreateEmpty();

    // Push some elements onto the stack
    for (int i = 1; i <= 20; i++)
    {
        StackPush(stack, i * 10);
    }

    // Print the top element and stack size
    printf("Top element: %d\n", StackPeek(stack));
    printf("Stack size: %zu\n", stack->size);

    // Pop and print elements from the stack
    while (!StackIsEmpty(stack))
    {
        int value = StackPop(stack);
        printf("Popped: %d\n", value);
    }

    // Check if the stack is empty now
    if (StackIsEmpty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    // Clean up and destroy the stack
    StackDestroy(stack);

    return 0;
}