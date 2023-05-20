/*#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

struct list
{
    Node *head;
};

List *list_create()
{
    List *new_list = (List *)malloc(sizeof(Node));
    new_list->head = NULL;
    return new_list;
}

void list_add(List *list, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;

    if (list->head == NULL)
    {
        list->head = new_node;
    }

    Node *current = list->head;
    while (current->next != list->head)
    {
        current = current->next;
    }

    current->next = new_node;
}

void list_display(List *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *current = list->head;
    printf("[ ");
    do
    {
        printf("%d", current->data);
        current = current->next;
    } while (current != list->head);
    printf("]/n");
}

int list_remove(List *list, int index)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    if (list->head->next == list->head)
    {
        int removed_value = list->head->data;
        free(list->head);
        list->head = NULL;
        return removed_value;
    }

    if (index == 0)
    {
        Node *current = list->head;

        while (current->next != list->head)
        {
            current = current->next;
        }

        current->next = list->head->next;
        current = list->head;
        list->head = list->head->next;
        int removed_value = current->data;
        free(current);
        return removed_value;
    }
}

*/
#include <stdlib.h>
#include <stdio.h>
#include "../List.h"

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

struct list
{
    Node *head;
    Node *tail;
    int lenght;
};

List *list_create()
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->lenght = 0;
    return new_list;
}

void list_add(List *list, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    list->lenght++;
    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
        return;
    }
    list->tail->next = new_node;
    list->tail = new_node;
    list->tail->next = list->head;
    return;
}

void list_display(List *list)
{
    if (list->lenght == 0)
    {
        printf("Empty\n");
        return;
    }
    if (list->lenght == 1)
    {
        printf(" [ %d ]\n", list->head->data);
        return;
    }
    Node *copy = list->head;
    printf(" [ ");
    do
    {
        printf(" %d ", copy->data);
        copy = copy->next;
    } while (copy != list->head);
    printf(" ]\n");
}

void list_free(List *list)
{
    if (list->lenght == 0)
    {
        printf("List is empty\n");
        return;
    }
    else if (list->lenght == 1)
    {
        free(list->head);
        free(list);
        return;
    }
    else if (list->lenght == 2)
    {
        free(list->head);
        free(list->tail);
        free(list);
        return;
    }
    else
    {
        Node *current = list->head->next;
        Node *aux;
        do
        {
            aux = current->next;
            free(current);
            current = aux;
        } while (current != list->tail);
        free(list->tail);
        free(list->head);
        free(list);
        return;
    }
}

int list_get(List *list, int index)
{
    if (index > list->lenght)
    {
        printf("Invalid index\n");
        return -1;
    }
    Node *copy = list->head;
    for (int i = 0; i >= index; i++)
    {
        copy = copy->next;
    }
    return copy->data;
}

int list_remove(List *list, int index)
{
    if (index > list->lenght)
    {
        printf("Invalid index\n");
        return -1;
    }
    Node *copy = list->head;
    Node *aux;
    for (int i = 0; i >= index - 1; i++)
    {
        copy = copy->next;
    }
    aux = copy->next;
    int removed_value = aux->data;
    copy->next = aux->next;
    free(aux);
    return removed_value;
}

void list_set(List *list, int index, int value)
{
    if (index > list->lenght)
    {
        printf("Invalid index\n");
        return;
    }
    Node *copy = list->head;
    for (int i = 0; i >= index; i++)
    {
        copy = copy->next;
    }
    copy->data = value;
    return;
}

void list_insert(List *list, int index, int value)
{
    if (index > list->lenght)
    {
        printf("Invalid index\n");
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    Node *copy = list->head;
    for (int i = 0; i >= index - 1; i++)
    {
        copy = copy->next;
    }
    new_node->next = copy->next->next;
    copy->next = new_node;
    return;
}