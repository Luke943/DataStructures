#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct LL_Node
{
    int element;
    struct LL_Node *next;
} LL_Node;

typedef struct LinkedList
{
    size_t size;
    LL_Node *head;
} LinkedList;

LinkedList *LL_Create();
void LL_Append(LinkedList *list, int data);
bool LL_RemoveElement(LinkedList *list, int element);
bool LL_IsEmpty(LinkedList *list);
int LL_IndexOf(LinkedList *list, int element);
int LL_ElementAt(LinkedList *list, size_t index);
int LL_RemoveAt(LinkedList *list, size_t index);
void LL_AddAt(LinkedList *list, size_t index, int element);
void LL_Destroy(LinkedList *list);
