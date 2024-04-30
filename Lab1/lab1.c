/*********************************************
*CMP_SC2050
*By Gianni Ioannou
*gci5k8
*September 1,2023
*Lab 1
*FS 2023
***********************************************/
#include <stdio.h>
#include "lab1.h"

int getAverage(int array[], int size, float *result)
{

    float avg = 0;
    if(size == 0) //check if array is empty if it is it throws error code 1
    {
        return 1;
    }
    else
    {
        for(int i = 0; i < size; i++) //loops through the values in the array
        {
            avg += array[i]; //adds all integers togethor 
        }
        *result = avg / size; //divides total by size of array to get average
        return 0; //return 0 for success code
    }

}

int sumPositive(int array[], int size, int *result) 
{

    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        if (array[i] > 0) //check if the int is postive
        {
            sum += array[i]; //sums positive int
        }
    }

    if(size == 0 || sum == 0) //if array is empty or there are no positives throws error
    {
        return 1;
    } 
    else //if there are positves it returns 0 and sets answer to result pointer
    {
        *result = sum;
        return 0;
    }

}


int sumOdd(int array[], int size, int *result)
{

    int sum = 0;
    for(int i = 0; i < size; i++) 
    {
        if (array[i] % 2 != 0) //check if int is odd
        {
            sum += array[i]; //sums odds
        }
    }

    if(size == 0 || sum == 0) //if array is empty or there are no positives throws error
    {
        return 1;
    } 
    else 
    {
        *result = sum; //if there are positves it returns 0 and sets answer to result pointer
        return 0;
    }

}
