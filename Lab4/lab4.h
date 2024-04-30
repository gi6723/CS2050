#ifndef _LAB4_H
#define _LAB4_H

// Types
struct _InventoryItem 
{
	int ID;
	float weight;
	int stockCount;
	short colors;
};
typedef struct _InventoryItem InventoryItem;


// Prototypes
void * makeArray(int arraySize, int elementSize);
int getSize(void *array);
int countWithColors(InventoryItem *items, short colorCount);
void freeArray(void *array);

#endif