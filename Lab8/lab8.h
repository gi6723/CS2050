#ifndef _LAB8_H
#define _LAB8_H


typedef struct _PQueue * PQueue;

// O(1)
int pqGetErrorCode(PQueue q);

// O(1)
PQueue pqInit();

// O(n)
int pqInsert(void *data, int priority, PQueue q);

// O(1)
void * pqRemoveMin(PQueue q);

// O(1)
void * pqPeek(PQueue q);

// O(1)
int pqGetSize(PQueue q);

// O(n)
void pqFree(PQueue q);
#endif