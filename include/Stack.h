// Functionality of a stack implemented for type int

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack
{
    int size;
    int capacity;
    int *base; // int specific
} Stack;

Stack *StackCreate(int *data, int size);
Stack *StackCreateEmpty();
void StackPush(Stack *stack, int value);
int StackPop(Stack *stack);
int StackPeek(Stack *stack);
bool StackIsEmpty(Stack *stack);
void StackClear(Stack *stack);
void StackDestroy(Stack *stack);
void StackPrint(Stack *stack);

#endif // STACK_H