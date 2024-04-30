/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*September 8,2023
*Lab 2
*FS 2023
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int makeArray(int **array, int size) 
{
    //checks to make sure we are given a valid array size
    if(size <= 0)
    {
        //if we are not we return 1
        return 1; 
    }
    else
    {
        //makes the array pointer that's address will be stored in the pointer in main
        *array = (int *)malloc(size * sizeof(int));
        
        //checks for malloc error
        if(*array == NULL)
        {
           return 1; 
        }
        else
        {
            return 0;
        }
        
    }
    
}

void initArray(int *array, int size)
{
    //check if we are given valid sign and for any malloc issue
    if (size <=0 || array == NULL)
    {
        return;
    }
    else
    {
        //make the array an array of 0's
        for(int i = 0; i < size; i++)
        {
            array[i] = 0;
        }
    }
    
}

int multiplyEven(int *array, int size, int multiplicand)
{
    int count = 0; 

    //check if we are given valid sign and for any malloc issue
    if(size <=0 || array == NULL)
    {
        return 1;
    }
    else
    {
        //loops throgh array
        for(int i = 0; i < size; i++)
        {
            //checks if element is even
            if(array[i] %2 == 0)
            {
                //if even it multiplies it by the multiplicand
                array[i] *= multiplicand;
                /*
                increases count becuase we must return the count
                of integers that were multiplied + divisible by to
                */
                count ++;
            }
        }
        return count;
    }
    
}

void freeArray(int **array)
{
    //check to make sure there were no malloc errors
    if(*array == NULL || array == NULL)
    {
        return;
    }
    else
    {
        //freeing array and setting to NULL
        free(*array);
        *array = NULL;
    }
}