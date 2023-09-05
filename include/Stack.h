// Functionality of a stack implemented for type int

#pragma once

#include <stdbool.h>

typedef struct Stack
{
    size_t size;
    size_t capacity;
    int *base;
} Stack;

Stack *Stack_Create(int *data, size_t size);
Stack *Stack_CreateEmpty();
void Stack_Push(Stack *stack, int value);
int Stack_Pop(Stack *stack);
int Stack_Peek(Stack *stack);
bool Stack_IsEmpty(Stack *stack);
void Stack_Clear(Stack *stack);
void Stack_Destroy(Stack *stack);
void Stack_Print(Stack *stack);
