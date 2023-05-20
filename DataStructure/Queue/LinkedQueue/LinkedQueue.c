#include "../Queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR_1 -1000000 // Queue is full error
#define ERROR_2 -1000003 // Queue empty error
#define ERROR_3 -1000002 // Non-existant index error

typedef struct node Node;

// Defining the node structure
struct node
{
    int data;   // Value in a node
    Node *next; // Pointer that points to the next node
};

// Defining the queue structure
struct queue
{
    int size;
    int lenght;
    Node *last;
    Node *first; // Pointer to the first node
};

/*Function to create the Queue*/
Queue *queue_create(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // Allocation of the list in the memory
    queue->first = NULL;                           // Defining that the first node is NULL
    queue->last = NULL;
    queue->size = size;
    queue->lenght = 0;
    return queue; // Return the address of the stack
}

/*Function to free the Queue and array*/
void queue_free(Queue *queue)
{
    /*If list doesn't exist, return an error*/
    if (queue == NULL)
    {
        printf("List not found!\n");
        return;
    }
    /*If the list is empty, free the list and return*/
    if (queue_is_empty(queue))
    {
        free(queue);
        return;
    }

    Node *aux;     // Defining an aux
    Node *current; // Defining a current node

    /*While the next node exists*/
    while (queue->first->next != NULL)
    {
        aux = queue->first->next; // Aux receive the pointer to the second node
        current = queue->first;   // Current receive the pointer to the first node
        queue->first = aux;       // List->first now is the second node
        free(current);            // Free current node
    }

    free(queue->first); // Free list->first
    free(queue);        // Free list
}

/*Function to add values to the top of the Queue*/
void queue_enqueue(Queue *queue, int value)
{
    if (queue_is_full(queue))
    {
        printf("Your queue is already full!\n");
        return;
    }

    if (queue_is_empty(queue))
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;
        queue->first = new_node;
        queue->last = new_node;
        queue->lenght++;
    }
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;
        queue->last->next = new_node;
        queue->last = new_node;
        queue->lenght++;
    }
}

/*Function that remove the value from the start of the Queue and changes the first value to the second*/
int queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Your queue is already empty!\n");
        return ERROR_2;
    }

    int removed_value;

    if (queue->lenght == 1)
    {
        removed_value = queue->first->data;
        free(queue->first);
        queue->first = NULL;
        queue->last = NULL;
        queue->lenght--;
        return removed_value;
    }

    Node *second_node = queue->first->next;
    removed_value = queue->first->data;
    free(queue->first);
    queue->first = second_node;
    queue->lenght--;
    return removed_value;
}

/*Function to see the value at the start of the Queue*/
int queue_first(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Your queue is already empty!\n");
        return ERROR_2;
    }

    return queue->first->data;
}

/*Function to see the value at the top of the Queue*/
int queue_last(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Your queue is already empty!\n");
        return ERROR_2;
    }

    return queue->last->data;
}

/*Function to verify if the queue is empty*/
bool queue_is_empty(Queue *queue)
{
    if (queue->lenght == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Function to verify if the queue is full*/
bool queue_is_full(Queue *queue)
{
    if (queue->lenght == queue->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}