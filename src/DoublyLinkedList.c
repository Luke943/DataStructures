#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

DoublyLinkedList *DLL_Create()
{
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    if (!list)
    {
        fprintf(stderr, "DLL_Create: malloc failed\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void DLL_Add(DoublyLinkedList *list, int data)
{
    DLL_Node *node = (DLL_Node *)malloc(sizeof(DLL_Node));
    if (!node)
    {
        fprintf(stderr, "DLL_Add: malloc failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    if (list->tail)
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
    }
}

bool DLL_Remove(DoublyLinkedList *list, int data)
{
    DLL_Node *node = list->head;
    while (node)
    {
        if (node->data == data)
            break;
        node = node->next;
    }
    if (!node)
        return false;
    if (node == list->head)
    {
        list->head = node->next;
        node->next->prev = NULL;
    }
    else if (node == list->tail)
    {
        list->tail = node->prev;
        node->prev->next = NULL;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
    return true;
}

void DLL_Reverse(DoublyLinkedList *list)
{
    DLL_Node *node = list->head;
    while (node)
    {
        DLL_Node *tmp = node->next;
        node->next = node->prev;
        node->prev = tmp;
        node = node->prev;
    }
    DLL_Node *tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

void DLL_Destroy(DoublyLinkedList *list)
{
    DLL_Node *node = list->head;
    while (node)
    {
        DLL_Node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
    list = NULL;
}