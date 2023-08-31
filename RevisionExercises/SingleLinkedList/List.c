#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct node Node;

struct node
{
    int value;
    Node* next;
};

struct list
{
    Node* head;
    Node* tail;
};

List* list_create()
{
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void list_free(List *list)
{
    Node* current = list->head;

    while(current->next != NULL)
    {
        list->head = current->next;
        free(current);
        current = list->head;
    }

    free(current);
    free(list);
}

void list_add_head(List *list, int value)
{
    if(list->head == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    else 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->next = list->head;
        list->head = new_node;
    }
}

void list_add_tail(List *list, int value)
{
    if(list->head == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    else 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void list_display(List *list)
{
    if(list->head == NULL || list == NULL)
    {
        printf("List is empty");
        return;
    }

    Node* current = list->head;

    printf("[ ");
    while (current != list->tail) 
    {
        printf("%i, ", current->value);
        current = current->next;
    }
    printf("%i ]", current->value);
}