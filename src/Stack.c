#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MIN_CAPACITY 16
#define MAX(a, b) (a > b ? a : b)

void _StackResize(Stack *stack)
{
    stack->capacity = MAX((size_t)(stack->size * 1.5), MIN_CAPACITY);
    stack->base = realloc(stack->base, sizeof(int) * stack->capacity);
    if (!stack->base)
    {
        fprintf(stderr, "Failed to allocate memory for resize\n");
        exit(1);
    }
}

Stack *StackCreate(int *data, size_t size)
{

    Stack *stack = malloc(sizeof(Stack));
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory for new stack\n");
        exit(1);
    }
    stack->size = size;
    stack->capacity = size;
    stack->base = data;
    return stack;
}

Stack *StackCreateEmpty()
{
    return StackCreate(NULL, 0);
}

void StackPush(Stack *stack, int value)
{
    if (stack->size == stack->capacity)
        _StackResize(stack);
    stack->base[stack->size++] = value;
}

int StackPop(Stack *stack)
{
    if (stack->size == 0)
    {
        fprintf(stderr, "Stack already empty\n");
        exit(1);
    }
    int value = stack->base[--stack->size];
    if (stack->size < stack->capacity / 2 && stack->capacity > MIN_CAPACITY)
    {
        _StackResize(stack);
    }
    return value;
}

int StackPeek(Stack *stack)
{
    if (stack->size == 0)
    {
        fprintf(stderr, "Stack already empty\n");
        exit(1);
    }
    return stack->base[stack->size - 1];
}

bool StackIsEmpty(Stack *stack)
{
    return stack->size == 0;
}

void StackClear(Stack *stack)
{
    stack->size = 0;
    _StackResize(stack);
}

void StackDestroy(Stack *stack)
{
    free(stack->base);
    free(stack);
    stack = NULL;
}

void StackPrint(Stack *stack)
{
    printf("(");
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d, ", stack->base[i]);
    }
    printf(")\n");
}
