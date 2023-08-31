#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct node Node;

struct node
{
    Node* prev;
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
    if (list == NULL)
    {
        printf("List not found!\n");
        return;
    }
    if (list->head == NULL)
    {
        free(list);
        return;
    }

    Node* current;

    while(list->head->next != NULL)
    {
        current = list->head->next; 
        list->head = current;
        free(current->prev);   
        current->prev = NULL;
    }

    free(list->head);
    free(list);
}

void list_insert_head(List *list, int value)
{
    if(list->head == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->prev = NULL;
        new_node->value = value;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    else 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->prev = NULL;
        list->head->prev = new_node;
        new_node->value = value;
        new_node->next = list->head;
        list->head = new_node;
    }
}

void list_remove_head(List *list)
{
    if(list->head == NULL)
    {
        printf("List is empty!");
        return;
    }
    else if(list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else 
    {
        Node *aux = list->head;
        list->head = aux->next;
        list->head->prev = NULL;
        free(aux);
    }
}

void list_remove_tail(List *list)
{
    if(list->head == NULL)
    {
        printf("List is empty!");
        return;
    }
    else if(list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else 
    {
        Node *aux = list->tail;
        list->tail = aux->prev;
        list->tail->next = NULL;
        free(aux);
    }
}

void list_insert_tail(List *list, int value)
{
    if(list->head == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->prev = NULL;
        new_node->value = value;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    else 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->prev = list->tail;
        new_node->next = NULL;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void list_display(List *list)
{
    if(list == NULL || list->head == NULL)
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