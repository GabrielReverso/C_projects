#include "../Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define ERRO_1 -1000000 // Stack is full error
#define ERRO_2 -1000001 // Non-existant index error

// Defining Stack struct
struct stack
{
    int *array;
    int size;
    int lenght;
};

/*Function to create the Stack*/
Stack *stack_create(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));           // Reserves a space in the heap memory for the struct
    stack->size = size;                                      // Define the size of the array
    stack->lenght = 0;                                       // Define the lenght of the array
    stack->array = (int *)malloc(stack->size * sizeof(int)); // Reserves a space in the heap memory for the array
    return stack;
}

/*Function to free the Stack and array*/
void stack_free(Stack *stack)
{
    free(stack->array);
    free(stack);
}

/*Function to add values to the top of the Stack*/
void stack_push(Stack *stack, int value)
{
    bool is_full = stack_is_full(stack); // Receive a bool from stack_is_full

    if (is_full) // If it's full, return
    {
        printf("Stack is already full. Push function interrupted!\n");
        return;
    }
    else // If it's not full, proceed the push function
    {
        stack->array[stack->lenght] = value; // Add the value
        stack->lenght++;                     // Increase Stack lenght
    }
}

/*Function that remove the value from the top of the Stack*/
int stack_pop(Stack *stack)
{
    bool is_empty = stack_is_empty(stack); // Receive a bool from stack_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("Stack is already empty. Pop function interrupted!\n");
        return ERRO_1;
    }
    else // If not, proceed the pop function
    {
        int removed_value = stack->array[stack->lenght - 1]; // Receive the value that will be removed
        stack->array[stack->lenght - 1] = (uintptr_t)NULL;   // Remove the value
        stack->lenght--;                                     // Decrease the Stack lenght
        return removed_value;                                // Return the removed value
    }
}

/*Function to see a value at a specific index*/
int stack_peek(Stack *stack, int index)
{
    bool is_empty = stack_is_empty(stack); // Receive a bool from stack_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("There is no values in this stack!\n");
        return ERRO_1;
    }
    else if (index > stack->lenght - 1 || index < 0) // If the index don't exist, return an error
    {
        printf("Index don't exist!\n");
        return ERRO_2;
    }
    else // If not, return the value
    {
        return stack->array[index];
    }
}

/*Function to see the value at the top of the Stack*/
int stack_top(Stack *stack)
{
    bool is_empty = stack_is_empty(stack); // Receive a bool from stack_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("There is no values in this stack!\n");
        return ERRO_1;
    }
    else // If not, return the value
    {
        return stack->array[stack->lenght - 1];
    }
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