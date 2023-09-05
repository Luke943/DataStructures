#pragma once

#include <stdbool.h>

typedef struct DLL_Node
{
    struct DLL_Node *prev;
    struct DLL_Node *next;
    int data;
} DLL_Node;

typedef struct DoublyLinkedList
{
    DLL_Node *head;
    DLL_Node *tail;
} DoublyLinkedList;

DoublyLinkedList *DLL_Create();
void DLL_Add(DoublyLinkedList *list, int data);
bool DLL_Remove(DoublyLinkedList *list, int data);
void DLL_Reverse(DoublyLinkedList *list);
void DLL_Destroy(DoublyLinkedList *list);