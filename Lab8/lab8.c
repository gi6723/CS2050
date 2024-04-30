/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*October 20,2023
*Lab 8
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"

//Defines node struct for the priority queue
typedef struct _Node 
{
    //pointer to the data held by the code
    void* item;
    //represents priority of node
    int priorityValue;
    //pointer to the next node 
    struct _Node* next;
} Node;

//Define the main priority Queues
struct _PQueue 
{
    //pointer to the front node in the priority queue
    Node* front;    
    //counter to keep track of number of nodes
    int count;     
    //integer flag to indicate any errors 
    int errorFlag;
};

int pqGetErrorCode(PQueue queue) 
{
    //check if passed queue pointer is NULL
    if (queue == NULL) 
    {
        return -1; 
    }
    
    //returns error code of queue
    return queue->errorFlag;
}

PQueue pqInit() 
{
    //allocates memory for new queue instance 
    PQueue queueInstance = (PQueue)malloc(sizeof(struct _PQueue));

    //check for memory allocation error 
    if (queueInstance == NULL) 
    {
        return NULL;
    }

    //setting initial values for queue instance
    queueInstance->front = NULL;
    queueInstance->count = 0;
    queueInstance->errorFlag = 0;

    //returns queue instance
    return queueInstance;
}

int pqInsert(void *data, int priority, PQueue queue) 
{
    //checks if passed data is NULL, priority is negative or if queue is initialized
    if (data == NULL || priority < 0 || queue == NULL) 
    {
        return 1;
    }

    //allocates memory for new node
    Node* freshNode = (Node*)malloc(sizeof(Node));
    
    //checks if malloc was successful 
    if (freshNode == NULL) 
    {
        queue->errorFlag = 1;
        return 1;
    }

    //sets data and priority for new node
    freshNode->item = data;
    freshNode->priorityValue = priority;
    freshNode->next = NULL;

    //Inserts new node in correct position based off of priority
    if (!queue->front || queue->front->priorityValue > priority) 
    {
        //sets next node of new node to front
        freshNode->next = queue->front;
        //updates front of queue to new node
        queue->front = freshNode;
    } 
    else 
    {
        //initialized a tracker node starting at front of queue
        Node* tracker = queue->front;
        //Iterates through queue while the next node exists and its priority is less than or equal to new node's 
        while (tracker->next && tracker->next->priorityValue <= priority) 
        {
            //moves tracker to next node in queue
            tracker = tracker->next;
        }
        //sets next node of new node to tracker's next node
        freshNode->next = tracker->next;
        //updates tracker's next node to new node
        tracker->next = freshNode;
    }

    //Increment the queue count
    queue->count++;
    //resets error flag
    queue->errorFlag = 0;

    return 0;
}

void * pqRemoveMin(PQueue queue) 
{
    //checks if queue is initialized 
    if (queue == NULL) 
    {
        return NULL;
    }

    //check if queue is empty 
    if (queue->count == 0) 
    {
        queue->errorFlag = 2;
        return NULL;
    }

    //gets front node and its data
    Node* toFree = queue->front;
    void* itemData = toFree->item;
    //updates the front of the queue
    queue->front = queue->front->next;
    //decreases queue count
    queue->count--;

    //free the removed node
    free(toFree);
    toFree = NULL;  // Nullifying the pointer after freeing

    //reset the error flag
    queue->errorFlag = 0;

    //return the data of the removed node
    return itemData;
}

void * pqPeek(PQueue queue) 
{
    //checks if queue is initialized
    if (queue == NULL) 
    {
        return NULL;
    }

    //checks if the queue is empty
    if (queue->count == 0) 
    {
        queue->errorFlag = 2;
        return NULL;
    }

    //resets error flag
    queue->errorFlag = 0;
    //returns the data of the front node
    return queue->front->item;
}

int pqGetSize(PQueue queue) 
{
    //checks if queue is initialized
    if (queue == NULL) 
    {
        return -1;
    }
    //return the count of items in the queue
    return queue->count;
}

void pqFree(PQueue queue) 
{
    //checks if queue is initialized
    if (queue == NULL) 
    {
        return;
    }

    //iterates through the queue and free each node
    while (queue->front) 
    {
        Node* toFree = queue->front;
        queue->front = queue->front->next;
        free(toFree);
        toFree = NULL;  
    }

    //Free the queue structure
    free(queue);
    queue = NULL;  
}

