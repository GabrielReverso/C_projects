#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

#define ERROR_1 -100000 // List don't exist or is empty
#define ERROR_2 -100001 // Invalid index

typedef struct node Node;

// Defining the node structure
struct node
{
    int data;   // Value in a node
    Node *next; // Pointer that points to the next node
};

// Defining the list structure
struct list
{
    Node *first; // Pointer to the first node
};

/*Function to create an empty linked list*/
List *list_create()
{
    List *new_list = (List *)malloc(sizeof(List)); // Allocation of the list in the memory
    new_list->first = NULL;                        // Defining that the first node is NULL
    return new_list;                               // Return the address of the list
}


/*Function to free the list and all nodes*/
void list_free(List *list)
{
    /*If list doesn't exist, return an error*/
    if (list == NULL)
    {
        printf("List not found!\n");
        return;
    }
    /*If the list is empty, free the list and return*/
    if (list->first == NULL)
    {
        free(list);
        return;
    }

    Node *aux;     // Defining an aux
    Node *current; // Defining a current node

    /*While the next node exists*/
    while (list->first->next != NULL)
    {
        aux = list->first->next; // Aux receive the pointer to the second node
        current = list->first;   // Current receive the pointer to the first node
        list->first = aux;       // List->first now is the second node
        free(current);           // Free current node
    }

    free(list->first); // Free list->first
    free(list);        // Free list
}

/*Function to show all values*/
void list_display(List *list)
{
    /*If list is empty, return an error */
    if (list->first == NULL)
    {
        printf("Empty list!\n");
        return;
    }

    Node *current = list->first; // Define a current node and set it to the first node in the list

    printf("[");
    /* While the next node exists */
    while (current->next != NULL)
    {
        printf("%d -> ", current->data); // Display the value of the current node
        current = current->next;         // Update current to the next node in the list
    }
    printf("%d", current->data); // Display the last value
    printf("]\n");
}

/*Function to add a new value to the list*/
void list_add(List *list, int value)
{
    // Creating a new node and setting its data and next attributes
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->first == NULL)
    {
        // If the list is empty, the new node becomes the first node
        list->first = new_node;
    }
    else
    {
        // If the list is not empty, go through the nodes until the last one is reached
        Node *current = list->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Set the next attribute of the last node to be the new node
        current->next = new_node;
    }
}

/*Function to get a value from a specific index*/
int list_get(List *list, int index)
{
    // If the list is empty or doesn't exist, return an error code
    if (list == NULL || list->first == NULL)
    {
        printf("List is empty or doesn't exist!\n");
        return ERROR_1;
    }

    // If the index is negative, return an error code
    if (index < 0)
    {
        printf("Invalid index!\n");
        return ERROR_2;
    }

    // Go through the nodes until the node at the specified index is reached
    Node *current = list->first;
    int i = 0;
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    // If the current node is NULL, the index is out of range and an error code is returned
    if (current == NULL)
    {
        printf("Invalid index!\n");
        return ERROR_2;
    }
    else
    {
        // Return the data stored in the current node
        return current->data;
    }
}

/*Function to remove a value at a specific index*/
int list_remove(List *list, int index)
{
    // If the list is empty or doesn't exist, return an error code
    if (list == NULL || list->first == NULL)
    {
        printf("List is empty or doesn't exist");
        return ERROR_1;
    }

    // If the index is negative, return an error code
    if (index < 0)
    {
        printf("Invalid index!\n");
        return ERROR_2;
    }

    // Go through the nodes until the node at the specified index is reached
    Node *previous = NULL;
    Node *current = list->first;
    int data;
    for (int i = 0; i < index && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }

    // If the current node is NULL, the index is out of range and an error code is returned
    if (current == NULL)
    {
        printf("Invalid index!\n");
        return ERROR_2;
    }
    else if (index == 0)
    {
        // If the index is 0, the first node is removed and the next node becomes the new first node
        list->first = current->next;
    }
    else
    {
        // Otherwise, set the next attribute of the previous node to be the next node of the current node
        previous->next = current->next;
    }

    // Store the data of the removed node and free its memory
    data = current->data;
    free(current);

    // Return the stored data
    return data;
}

/*Function to change a value at a specific index*/
void list_set(List *list, int index, int value)
{
    // If the list is empty or doesn't exist, return
    if (list == NULL || list->first == NULL)
    {
        printf("List is empty or does not exist");
        return;
    }

    // If index is negative, return
    if (index < 0)
    {
        printf("Invalid index!\n");
        return;
    }

    Node *current = list->first; // Define a current node and set it to the first node

    // Go through the list until the specified index is reached
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }

    // If the current node is NULL (the index is out of range) it returns
    if (current == NULL)
    {
        printf("Invalid index!\n");
        return;
    }
    else
    {
        // Set the value of the node at the specified index
        current->data = value;
    }
}

/*Function to insert a value btween two nodes*/
void list_insert(List *list, int index, int value)
{
    // If the list is empty or doesn't exist, return
    if (list == NULL || list->first == NULL)
    {
        printf("List is empty or does not exist");
        return;
    }

    // If index is negative, return
    if (index < 0)
    {
        printf("Invalid index!\n");
        return;
    }

    Node *current = list->first; // Define a current node and set it to the first node
    Node *previous = NULL;       // Define a previous node and set it to NULL

    // Go through the nodes until the desired index is reached
    for (int i = 0; i < index && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }

    // If the current node is NULL (the index is out of range) it returns
    if (current == NULL)
    {
        printf("Invalid index!\n");
        return;
    }
    // Insert new node at the beginning of the list
    else if (index == 0)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = current;
        list->first = new_node;
    }
    // Insert new node in the middle or at the end of the list
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = current;
        previous->next = new_node;
    }
}


/*SORTING*/

int wrapper_list_recursive_sequential_search(Node *current, int value, int index) 
{
    if(current == NULL)
    {
        return ERROR_1;
    }
    if(current->data == value)
    {
        return index;
    }
    return wrapper_list_recursive_sequential_search(current->next, value, index+1);
}

int list_recursive_sequential_search(List*list, int item)
{
    if(list == NULL || list->first == NULL)
    {
        return ERROR_1;
    }
    Node *current = list->first;
    int index = 0;
    return wrapper_list_recursive_sequential_search(current, item, index); 
}