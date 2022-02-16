#include "cycle.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Global Variables
int lastInsertedPosition = 0;
long int heapMemoryUsed = 0;

// Function declarations
void insert_node_to_back(ListNode *node, ListNode *head);
bool toss();
int generatePosition(int N);

void *myalloc()
{
    heapMemoryUsed += (long int)sizeof(ListNode);
    return malloc(sizeof(ListNode));
}

ListNode* create_node(VAL val, POSITION pos) 
{
    ListNode *newNode = myalloc();
    newNode->pos = pos; 
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode* createList(int N) 
{
    ListNode *head = create_node(rand(), lastInsertedPosition++);
    for(int i=0; i<N-1; i++) {
        ListNode *node = create_node(rand(), lastInsertedPosition++);
        insert_node_to_back(node, head);
    }
    printf("Heap memory used: %ld\n", heapMemoryUsed);
    return head;
}

ListNode* createCycle(ListNode *head, int N) // N is the list size
{
    bool createCycle = toss();
    if (createCycle == false) return head;
    int pos = generatePosition(N), i;
    printf ("Creating Cycle at position: %d\n", pos);
    ListNode *cur = head, *node;
    for(i=0; i<N; i++) {
        if(i==pos) node = cur;
        if(i==N-1) cur->next = node;
        cur = cur-> next;
    }
    return head;
}

bool toss()
{
    srand(time(0));
    if(rand()%2==0) return true;
    return false;
}

int generatePosition(int N)
{
    int lower = 0; int upper = N-1;
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower;
}

POSITIONS compare_node_positions(ListNode *node1, ListNode *node2)
{
    if (node1->pos > node2->pos) return FORWARD;
    else if (node1->pos < node2->pos) return BEHIND;
    return LEVEL;
}

void insert_node_to_back(ListNode *node, ListNode *head)
{
    ListNode* cur = head;
    while(cur->next != NULL)
    {
        cur = cur -> next;
    }
    cur->next = node;
}

void print_node(ListNode *node)
{
    printf("Position-%d   Value-%d\n", node->pos, node->val);
}

void print_linked_list(ListNode *head) 
{
    ListNode *cur = head;
    while(cur != NULL)
    {
        print_node(cur);
        cur = cur->next;
    }
}