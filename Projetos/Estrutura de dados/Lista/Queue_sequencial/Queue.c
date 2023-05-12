#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define ERRO_1 -1000000 // Queue is full error

// Defining Queue struct
struct queue
{
    int *array;
    int size;
    int lenght;
};

/*Function to create the Queue*/
Queue *queue_create(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));           // Reserves a space in the heap memory for the struct
    queue->size = size;                                      // Define the size of the array
    queue->lenght = 0;                                       // Define the lenght of the array
    queue->array = (int *)malloc(queue->size * sizeof(int)); // Reserves a space in the heap memory for the array
    return queue;
}

/*Function to free the Queue and array*/
void queue_free(Queue *queue)
{
    free(queue->array);
    free(queue);
}

/*Function to add values to the top of the Queue*/
void queue_enqueue(Queue *queue, int value)
{
    bool is_full = queue_is_full(queue); // Receive a bool from queue_is_full

    if (is_full) // If it's full, return
    {
        printf("Queue is already full. Enqueue function interrupted!\n");
        return;
    }
    else // If it's not full, proceed the enqueue function
    {
        queue->array[queue->lenght] = value; // Add the value
        queue->lenght++;                     // Increase Queue lenght
    }
}

/*Function that remove the value from the start of the Queue and shifts the value*/
int queue_dequeue(Queue *queue)
{
    bool is_empty = queue_is_empty(queue); // Receive a bool from stack_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("Queue is already empty. Dequeue function interrupted!\n");
        return ERRO_1;
    }
    else // If not, proceed the dequeue function
    {
        int removed_value = queue->array[0];    // Receive the value that will be removed
        for (int i = 0; i < queue->lenght; i++) // Shift the values
        {
            queue->array[i] = queue->array[i + 1];
        }
        queue->lenght--;      // Decrease the queue lenght
        return removed_value; // Return the removed value
    }
}

/*Function to see the value at the top of the Queue*/
int queue_first(Queue *queue)
{
    bool is_empty = queue_is_empty(queue); // Receive a bool from queue_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("There is no values in this queue!\n");
        return ERRO_1;
    }
    else // If not, return the value
    {
        return queue->array[0];
    }
}

/*Function to see the value at the top of the Queue*/
int queue_last(Queue *queue)
{
    bool is_empty = queue_is_empty(queue); // Receive a bool from queue_is_empty

    if (is_empty) // If it's empty, return an error
    {
        printf("There is no values in this queue!\n");
        return ERRO_1;
    }
    else // If not, return the value
    {
        return queue->array[queue->lenght - 1];
    }
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