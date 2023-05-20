#include "../Stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR_1 -1000000 // Stack is full error
#define ERROR_2 -1000003 // Stack empty error
#define ERROR_3 -1000002 // Non-existant index error

typedef struct node Node;

// Defining the node structure
struct node
{
    int data;   // Value in a node
    Node *next; // Pointer that points to the next node
};

// Defining the stack structure
struct stack
{
    int size;
    int lenght;
    Node *last;
    Node *first; // Pointer to the first node
};

/*Function to create the Stack*/
Stack *stack_create(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack)); // Allocation of the list in the memory
    stack->first = NULL;                           // Defining that the first node is NULL
    stack->last = NULL;
    stack->size = size;
    stack->lenght = 0;
    return stack; // Return the address of the stack
}

/*Function to free the Stack and array*/
void stack_free(Stack *stack)
{
    /*If list doesn't exist, return an error*/
    if (stack == NULL)
    {
        printf("List not found!\n");
        return;
    }
    /*If the list is empty, free the list and return*/
    if (stack_is_empty(stack))
    {
        free(stack);
        return;
    }

    Node *aux;     // Defining an aux
    Node *current; // Defining a current node

    /*While the next node exists*/
    while (stack->first->next != NULL)
    {
        aux = stack->first->next; // Aux receive the pointer to the second node
        current = stack->first;   // Current receive the pointer to the first node
        stack->first = aux;       // List->first now is the second node
        free(current);            // Free current node
    }

    free(stack->first); // Free list->first
    free(stack);        // Free list
}

/*Function to add values to the top of the Stack*/
void stack_push(Stack *stack, int value)
{
    if (stack_is_full(stack))
    {
        printf("Your stack is already full!\n");
        return;
    }

    if (stack_is_empty(stack))
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;
        stack->first = new_node;
        stack->last = new_node;
        stack->lenght++;
    }
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;
        stack->last->next = new_node;
        stack->last = new_node;
        stack->lenght++;
    }
}

/*Function that remove the value from the top of the Stack*/
int stack_pop(Stack *stack)
{
    // If stack is empty, return an error
    if (stack_is_empty(stack))
    {
        printf("Your stack is already empty!\n");
        return ERROR_2;
    }

    int removed_value;

    if (stack->lenght == 1)
    {
        removed_value = stack->first->data;
        free(stack->first);
        stack->first = NULL;
        stack->last = NULL;
        stack->lenght--;
        return removed_value;
    }

    Node *current = stack->first;
    Node *previous = NULL;

    for (int i = 0; i < stack->lenght - 1; i++)
    {
        previous = current;
        current = current->next;
    }

    stack->last = previous;
    stack->last->next = NULL;
    removed_value = current->data;
    free(current);
    stack->lenght--;
    return removed_value;
}

/*Function to see a value at a specific index*/
int stack_peek(Stack *stack, int index)
{
    // If stack is empty, return an error
    if (stack_is_empty(stack))
    {
        printf("Your stack is already empty!\n");
        return ERROR_2;
    }

    if (index < 0 || index >= stack->lenght)
    {
        printf("Invalid index!\n");
        return ERROR_3;
    }

    Node *current = stack->first;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

/*Function to see the value at the top of the Stack*/
int stack_top(Stack *stack)
{
    // If stack is empty, return an error
    if (stack_is_empty(stack))
    {
        printf("Your stack is already empty!\n");
        return ERROR_2;
    }

    return stack->last->data;
}

/*Function to verify if the stack is empty*/
bool stack_is_empty(Stack *stack)
{
    if (stack->lenght == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Function to verify if the stack is full*/
bool stack_is_full(Stack *stack)
{
    if (stack->lenght == stack->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}