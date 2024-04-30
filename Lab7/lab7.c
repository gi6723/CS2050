/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*October 6,2023
*Lab 7
*FS 2023
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lab7.h"

int main() 
{
    // Initialize a new stack
    Stack* stack = initStack();

    // Push some elements onto the stack
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;

    pushStack(stack, &num1);
    pushStack(stack, &num2);
    pushStack(stack, &num3);

    // Check the size of the stack
    printf("Stack size: %d\n", getSize(stack));

    // Peek at the top element of the stack
    int* topElement = (int*)peekStack(stack);
    if (topElement != NULL) 
    {
        printf("Top element: %d\n", *topElement);
    }

    // Pop elements from the stack and print them
    while (getSize(stack) > 0) 
    {
        int* poppedElement = (int*)popStack(stack);
        if (poppedElement != NULL) 
        {
            printf("Popped element: %d\n", *poppedElement);
        }
    }

    // Check if an element is in the stack
    int numToCheck = 20;
    if (stackContains(stack, &numToCheck)) 
    {
        printf("%d is in the stack.\n", numToCheck);
    } 
    else 
    {
        printf("%d is not in the stack.\n", numToCheck);
    }

    // Free the stack
    freeStack(stack);

    return 0;
}

//Struct for a node in the stack
typedef struct _Info 
{
    void* element;
    struct _Info* nextNode;
} Info;

//Main stack structure 
struct _Stack 
{
    Info* topNode;  
    int count;     
};

Stack* initStack() 
{
    //allocate memory for stack
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    //checks if stack memory allocations was successful
    if (newStack == NULL) 
    {
        printf("Error: Failed to initialize stack.\n");
        return NULL;
    }
    //Makes the top of the stack and the size of the stack what they are supposed to be
    newStack->topNode = NULL;
    newStack->count = 0;
    return newStack;
}

int getSize(Stack* stack) 
{
    //checks if stack pointer is null
    if (stack == NULL) 
    {
        printf("Error: Stack not initialized.\n");
        return -1;  
    }
    //if not it returns its size
    return stack->count;
}

void* peekStack(Stack* stack) 
{
    // Checks if the stack or its top is NULL
    if (stack == NULL || stack->topNode == NULL) 
    {
        printf("Error: Stack not initialized or empty.\n");
        return NULL;
    }
    //returns data from top of stack
    return stack->topNode->element;
}

int pushStack(Stack* stack, void* item) 
{
    // Checks for NULL pointers in the stack or data
    if (stack == NULL || item == NULL) 
    {
        printf("Error: Stack not initialized or data is NULL.\n");
        return 1;
    }
    // Allocate memory for the new node
    Info* newNode = (Info*)malloc(sizeof(Info));
    //checks if memory allocation was successfull
    if (newNode == NULL) 
    {
        printf("Error: Memory allocation failed for new node.\n");
        return 1;
    }
    //Assigns the data and link the node
    newNode->element = item;
    newNode->nextNode = stack->topNode;
    stack->topNode = newNode;
    stack->count++;
    return 0;
}

void* popStack(Stack* stack) 
{
    // Check for NULL stack or empty stack
    if (stack == NULL || stack->topNode == NULL) 
    {
        printf("Error: Stack not initialized or empty.\n");
        return NULL;
    }
    //Gets top node and its data
    Info* currentNode = stack->topNode;
    void* item = currentNode->element;
    //Update the top of the Stack to point to the next node
    stack->topNode = stack->topNode->nextNode;
    free(currentNode);
    //Decreases the size of the Stack by one
    stack->count--;
    return item;
}

int stackContains(Stack* stack, void* item) 
{
    // Checks for NULL pointers in the stack or data
    if (stack == NULL || item == NULL) 
    {
        printf("Error: Stack not initialized or data is NULL.\n");
        return 0;
    }
    // Set current to point to the top node of the stack
    Info* currentNode = stack->topNode;
    //goes through stack to find data 
    while (currentNode) 
    {
        if (currentNode->element == item) 
        {
            //returns 1 if data is found
            return 1;
        }
        currentNode = currentNode->nextNode;
    }
    //returns 0 if data is not found
    return 0;
}

void freeStack(Stack* stack) 
{
    // Checks if the stack pointer is NULL
    if (stack == NULL) 
    {
        printf("Error: Stack not initialized.\n");
        return;
    }
    //Set current to point to the top node of the stack
    Info* currentNode = stack->topNode;
    //deallocates each node
    while (currentNode) 
    {
        Info* next = currentNode;
        currentNode = currentNode->nextNode;
        free(next);
    }
    //frees the memory for the stack itself
    free(stack);
}
