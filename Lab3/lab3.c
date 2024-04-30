/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*September 15,2023
*Lab 3
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

char * strAlloc(int size)
{
    //checks to make sure I am given a valid size for array
    if(size <= 0)
    {
        printf("Invalid array size.\n");
        return NULL;
    }

    //allocates a char array as well as a spot to store size of array
    char *memAlloc = (char*) malloc(sizeof(int) + size * sizeof(char));
    
    //check to make sure malloc was successful
    if(memAlloc == NULL)
    {
        printf("There was an error allocating memory");
        return NULL;
    }

    //takes the beginning address of memory block and treats it as a pointer to int
    int *sizePtr = (int*) memAlloc;
    //stores value in that location
    *sizePtr = size;
    
    //returns memAlloc array where the character array actually starts
    return memAlloc + sizeof(int);
}

int strLen(char *str)
{
    //checks to make sure we weren't passed a NULL pointer
    if(str == NULL)
    {
        return -1;
    }
    
    int len = 0;
    //This while loop loops through the given string untill it reaches 
    //string terminator while looping it increments the count len
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}

void strCpy(char *dest, char *source)
{
    //checks to make sure I wasn't given NULL pointers
    if (dest == NULL || source == NULL) 
    {
        printf("You thought you had me there didn't you.\n");
        return;
    }

    //gets the str length from source by calling strLen function
    int sizeOfSource = strLen(source);
    //grabs the allocated size of the destination array from its leading metadata
    int sizeOfDestination = *((int*) (dest - sizeof(int)));

    //checks to make sure the Destination array has enough space to fit source array
    if (sizeOfDestination < sizeOfSource) 
    {
        printf("Destination array is smaller than source array.\n");
        return;
    }

    //copys source array to destination array
    for (int i = 0; i < sizeOfSource; ++i)
    {
        dest[i] = source[i];
    }

    //adds the str terminating character to the end of dest
    dest[sizeOfSource] = '\0';
}

int strRev(char *dest, char *source)
{
    //checks to make sure I wasn't given NULL pointers
    if (dest == NULL || source == NULL) 
    {
        printf("You thought you had me there didn't you.\n");
        return -1;
    }

    //gets the str length from source by calling strLen function
    int sizeOfSource = strLen(source);
    //grabs the allocated size of the destination array from its leading metadata
    int sizeOfDestination = *((int*) (dest - sizeof(int)));

    //checks to make sure the Destination array has enough space to fit source array
    if (sizeOfDestination < sizeOfSource) 
    {
        return -1;
    }

    //reverses the string stored in source and copies it into destination
    for (int i = 0; i < sizeOfSource; ++i)
    {
        dest[sizeOfSource - i - 1] = source[i];
    }

    //This if statement is pretty self explanatory
    if (sizeOfDestination == sizeOfSource) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void strFree(char *str)
{
    //checks to make sure we weren't passed a NULL pointer
    if (str == NULL)
    {
        printf("NULL pointer provided.\n");
        return;
    }

    //makes a pointer to the start of the memory block inlcuding the meta data to free everything
    char *freeCharArray = str - sizeof(int);
    //frees everything
    free(freeCharArray);
}