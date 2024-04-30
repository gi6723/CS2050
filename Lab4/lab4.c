/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*September 22,2023
*Lab 4
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void * makeArray(int arraySize, int elementSize)
{
    //checks to make sure that a valid array and element size are provided
    if(arraySize <=0 || elementSize <= 0)
    {
        printf("Invalid array size or element size.\n");
        return NULL;
    }

    //allocates memory for array based off array size and element size
    int * arrBLDR = malloc((arraySize * elementSize) + sizeof(int));

    //makes sure memory was allocated succesfully
    if(arrBLDR == NULL)
    {
        printf("There was an error allocating memory.\n");
        return NULL;
    }

    //grabs the size of the array 
    int *sizePtr = (int*) arrBLDR;
    *sizePtr = arraySize;

    //Return the array pointer excluding size at front fo array 
    return (void*) (arrBLDR + 1);
}

int getSize(void *array)
{

    //Checks if I was passed an array pointer
    if(array == NULL)
    {
        printf("You passed a NULL pointer.\n");
        return -1;
    }

    //calculates and return the stored size of array
    int *getSize = (int *)((char *)array - sizeof(int));
    return *getSize;
}

int countWithColors(InventoryItem *items, short colorCount)
{
    //Checks if I was passed NULL pointer
    if(items == NULL)
    {
        printf("You passed a NULL pointer.\n");
        return -1;
    }

    //Grabs size of array
    int sizeofArray = getSize(items);
    if (sizeofArray == -1)
    {
        printf("There was an issue getting the size of the array.\n");
        return -1;
    }
    
    //Initializing count and then uses for loop to find items with the specified color count
    int count = 0;
    for(int i = 0; i < sizeofArray; i++)
    {
        if(items[i].colors == colorCount)
        {
            count++;
        }
    }
    
    //Returns count
    return count;
}


void freeArray(void *array)
{

    //checks to make sure I wasnt passed NULL pointer
    if (array == NULL)
    {
        printf("You passed a NULL pointer.\n");
        return;
    }
    
    // calculates orginal pointer (inlude size of array metadata) then frees it
    int* originalPointer = ((int*) array) - 1;
    free(originalPointer);
}

