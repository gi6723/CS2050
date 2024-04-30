/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*October 6,2023
*Lab 6
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

//function initilizes a linked list witha dummy node
int makeList(Node **list)
{
    //JChecks if pointer to pointer is NULL
    if(list == NULL)
    {
        return 1;
    }
    //makes dummy node
    *list = (Node *) malloc(sizeof(Node)); 

    //checks if memory allocation was successfull
    if (*list == NULL) 
    {
        return 1;
    }

    //Initialize the next pointer of the dummy node to NULL
    (*list)->next = NULL;
    // Initialize the data of the dummy node to NULL
    (*list)->data = NULL;

    return 0; 
}

//calculates how many nodes there are in the linked list
int getSize(Node *list)
{
    int size = 0;
    //checks if provided list pointer is NULL
    if(list == NULL)
    {
        return 0;
    }
    //sets current to skip the dummy node so that it starts at the first actual node
    Node *current = list -> next;

    //loops through untill it finds the last node and increments counter
    while(current)
    {
        size++;
        current = current -> next;
    }

    return size;
}

//returns the node at the specific index in the linked list
void * getAtIndex(Node *list, int index)
{
    //checks if porvided list is NULL and if I am given a valid index
    if(list == NULL || index < 0)
    {
        return NULL;
    }
    
    int x = 0;

    //start traversal at first node (skip dummy node)
    Node *current = list->next;
    //goes through each node in the list untill it hits the one with the same index 
    while(current)
    {
        if(x == index)
        {
            return current ->data;
        }

        //increments counter if needed then moves to next node if index and count dont match 
        x++;
        current = current-> next;
    }
    //this returns if index is out of bounds
    return NULL; 
}

int insertAtTail(Node *list, void *data)
{
    //checks to make sure provided data and list aren't NULL
    if(list == NULL || data == NULL)
    {
        return 1;
    }

    //creates new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    //makes sure memory allocation was successfull
    if(newNode == NULL)
    {
        return 1;
    }

    //sets new nodes data = to the whatever data was passed in 
    newNode -> data = data;

    //since we are inserting at tail next needs to be NULL 
    newNode -> next = NULL;

    //Starts at dummy node
    Node *current = list;

    //keeps going untill it hits last node of the list
    while (current -> next)
    {
        current = current -> next;
    }

    // Sets the pointer of the last node to the pointer of the new node
    current ->next = newNode;

    return 0;
}

void * removeFromHead(Node *list)
{
    //checks is list pointer is null
    if(list == NULL)
    {
        return NULL;
    }

    //check if list is empty 
    if (list->next == NULL) 
    {
        return NULL;
    }   

    //points to the first actual node in the list
    Node *nodeToRemove = list->next;
    //Adjust the next pointer of the dummy node
    list->next = nodeToRemove->next; 
    //Relases the memory allocated for node to be removed
    void *data = nodeToRemove->data;
    // Free the node
    free(nodeToRemove); 
    return data;
}

void freeList(Node **list)
{
    //checks if list pointer-to-pointer or list pointer is NULL
    if(list == NULL || *list == NULL)
    {
        return;
    }

    //starts at dummy node
    Node *current = *list;
    //loops through each node in the list
    while (current) 
    {
        //stores current node in temporary pointer
        Node *temp = current;
        //moves to the next node
        current = current->next;
        //releases memory allocated for current node.
        free(temp); 
    }
    //sets the list pointer to NULL
    *list = NULL;
}