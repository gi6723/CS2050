#ifndef _LAB5_H
#define _LAB5_H

// Types
typedef struct Node Node;

struct Node {
	void *data;
	Node *next;
};


// Prototypes
int makeList(Node **list);
int getSize(Node *list);
int insertAtHead(Node **list, void *data);
void * removeFromTail(Node **list);
void freeList(Node **list);

#endif