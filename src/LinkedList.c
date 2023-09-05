#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *LL_Create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list)
    {
        fprintf(stderr, "Failed to allocate memory for linked list\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void LL_Append(LinkedList *list, int data)
{
    LL_Node *new_node = (LL_Node *)malloc(sizeof(LL_Node));
    if (!new_node)
    {
        fprintf(stderr, "Failed to allocate memory for node\n");
        exit(1);
    }
    new_node->element = data;
    new_node->next = NULL;
    list->size++;
    if (!list->head)
    {
        list->head = new_node;
        return;
    }
    LL_Node *node = list->head;
    while (node->next)
        node = node->next;
    node->next = new_node;
}

bool LL_RemoveElement(LinkedList *list, int element)
{
    LL_Node *node = list->head;
    LL_Node *prev = NULL;
    while (node != NULL)
    {
        if (node->element == element)
        {
            if (prev == NULL)
                list->head = node->next;
            else
                prev->next = node->next;
            free(node);
            list->size--;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

bool LL_IsEmpty(LinkedList *list)
{
    return list->size == 0;
}

int LL_IndexOf(LinkedList *list, int element)
{
    LL_Node *node = list->head;
    int index = 0;
    while (node != NULL)
    {
        if ((node->element) == element)
            return index;
        node = node->next;
        index++;
    }
    return -1;
}

int LL_ElementAt(LinkedList *list, size_t index)
{
    if (index >= list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    LL_Node *node = list->head;
    for (int i = 0; i < index; i++)
        node = node->next;
    return node->element;
}

int LL_RemoveAt(LinkedList *list, size_t index)
{
    if (index >= list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    LL_Node *node = list->head;
    LL_Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {
        prev = node;
        node = node->next;
    }
    int element = node->element;
    if (prev == NULL)
        list->head = node->next;
    else
        prev->next = node->next;
    free(node);
    list->size--;
    return element;
}

void LL_AddAt(LinkedList *list, size_t index, int element)
{
    if (index > list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    LL_Node *new_node = (LL_Node *)malloc(sizeof(LL_Node));
    if (!new_node)
    {
        fprintf(stderr, "Failed to allocate memory for node\n");
        exit(1);
    }
    new_node->element = element;
    new_node->next = NULL;
    LL_Node *node = list->head;
    LL_Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {
        prev = node;
        node = node->next;
    }
    new_node->next = node;
    if (prev == NULL)
        list->head = new_node;
    else
        prev->next = new_node;
    list->size++;
}

void LL_Destroy(LinkedList *list)
{
    LL_Node *node = list->head;
    while (node != NULL)
    {
        LL_Node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
