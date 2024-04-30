/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*September 29,2023
*Lab 5
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"

int makeList(Node **list) 
{
    //Checks to see if the list pointer is NULL
    if (list == NULL) 
    {
        return -1; 
    }
    //Initializes the list to NULL to indicate an empty list
    *list = NULL;

    return 0;
}

int getSize(Node *list) 
{
    //check if the List is NULL
    if (list == NULL)
    {
        return 0; 
    }
    //initilize count variable
    int count = 0;

    //Goes throught the list of nodes 
    while (list != NULL) 
    {
        //count increments when passing through each node
        count++;
        list = list->next;
    }

    return count;
}

int insertAtHead(Node **list, void *data) 
{
    //checks to see if input or data pointers are NULL
    if (list == NULL || data == NULL)
    {
        return -1;
    }

    //Initilizes a new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    //checks to make sure initilization was successful
    if (newNode == NULL) 
    {
        return -1; 
    }
    
    //Assigns the input data to the new node and links it to the current head of the list
    newNode->data = data;
    newNode->next = *list;

    //update the head of the list to be the new node
    *list = newNode;
    
    return 0; 
}

void *removeFromTail(Node **list) 
{
    //checks to see if list pointer is NULL or if list is empty
    if (list == NULL ||*list == NULL)
    {
        return NULL; 
    }

    //makes this pointer head of linked list
    Node *currentNode = *list;
    // temporaily stores the data of the node that is being worked on
    void *endData;
    
    //checks if there is only one node in the list
    if (currentNode->next == NULL) 
    { 
        //Saves the data from the last node
        endData = currentNode->data;

        //Frees the memory of the last node
        free(currentNode);
        //Updated the list to NULL since there is nothing left
        *list = NULL;
    } 
    else 
    {

        Node *previousNode = NULL;
        //goes through the list and finds thinds the last node and its previous node
        while (currentNode->next != NULL) 
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        //saves data from last node
        endData = currentNode->data;

        //frees memory of the last node and updates previous node's pointer to NULL
        free(currentNode);
        previousNode->next = NULL;
    }

    return endData;
}

void freeList(Node **list) 
{
    //checks if the input list pointer is NULL
    if (list == NULL) 
    {
        return; 
    }

    //makes this pointer head of linked list
    Node *currentNode = *list;
    //Holds the address of the next node in the list while the current one is being worked on
    Node *nextNode;
    
    //goes through the list freeing the memory of each node
    while (currentNode != NULL) 
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    
    //updates the list pointer to NULL after freeing all nodes
    *list = NULL;
}
