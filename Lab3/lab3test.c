#include <stdio.h>
#include <stdlib.h>

// Function Declarations
char * strAlloc(int size);
int strLen(char *str);
void strCpy(char *dest, char *source);
int strRev(char *dest, char *source);
void strFree(char *str);

int main() {
    char *source = strAlloc(5);
    char *dest = strAlloc(8);
    if (source == NULL || dest == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize source
    strCpy(source, "HELLO");

    // Copy source to dest
    strCpy(dest, source);

    // Reverse copy source to dest
    //int result = strRev(dest, source);

    // Free allocated memory
    strFree(source);
    strFree(dest);

    return 0;
}

char * strAlloc(int size)
{
    if(size <= 0)
    {
        printf("Invalid array size.\n");
        return NULL;
    }

    char *memAlloc = (char*) malloc(sizeof(int) + size * sizeof(char));
    if(memAlloc == NULL)
    {
        printf("There was an error allocating memory.\n");
        return NULL;
    }

    *((int*) memAlloc) = size;

    return memAlloc + sizeof(int);
}

int strLen(char *str)
{
    if(str == NULL)
    {
        return 0;
    }

    int *sizePtr = (int*)(str - sizeof(int));
    int size = *sizePtr;

    return size;
}

void strCpy(char *dest, char *source)
{
    if (dest == NULL || source == NULL)
    {
        printf("You thought you got me with that NULL pointer.\n");
        return;
    }

    int sourceSize = strLen(source);
    int destSize = strLen(dest);

    if (destSize < sourceSize)
    {
        printf("Destination array is smaller than source array.\n");
        return;
    }

    for (int i = 0; i < sourceSize; ++i)
    {
        dest[i] = source[i];
    }
}

int strRev(char *dest, char *source)
{
    if (dest == NULL || source == NULL)
    {
        return -1;
    }

    int sourceSize = strLen(source);
    int destSize = strLen(dest);

    if (destSize < sourceSize)
    {
        return -1;
    }

    for (int i = 0; i < sourceSize; ++i)
    {
        dest[sourceSize - i - 1] = source[i];
    }

    return destSize == sourceSize ? 1 : 0;
}

void strFree(char *str)
{
    if (str == NULL)
    {
        printf("Error: NULL pointer provided.\n");
        return;
    }

    char *originalMemBlock = str - sizeof(int);

    free(originalMemBlock);
}