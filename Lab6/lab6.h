#ifndef _LAB6_H
#define _LAB6_H

// Types
typedef struct Node Node;

struct Node {
	Node *next;
	void *data;
};


int makeList(Node **list);
int getSize(Node *list);
void * getAtIndex(Node *list, int index);
int insertAtTail(Node *list, void *data);
void * removeFromHead(Node *list);
void freeList(Node **list);

#endif