#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

struct queue{
	Node* first;
	Node* last;
	int size;
};

typedef struct queue Queue;


Queue newQ(); 

bool isEmptyQ(Queue q);

Queue delQ(Queue q);

Node front(Queue q); 

Queue addQ(Queue q , Node e); 

int lengthQ(Queue q); 

Node newNode(int data); 