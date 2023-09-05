// Functionality of a stack implemented for type int

#pragma once

#include <stdbool.h>

typedef struct Stack
{
    size_t size;
    size_t capacity;
    int *base;
} Stack;

Stack *StackCreate(int *data, size_t size);
Stack *StackCreateEmpty();
void StackPush(Stack *stack, int value);
int StackPop(Stack *stack);
int StackPeek(Stack *stack);
bool StackIsEmpty(Stack *stack);
void StackClear(Stack *stack);
void StackDestroy(Stack *stack);
void StackPrint(Stack *stack);
