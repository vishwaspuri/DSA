#include<stdbool.h>

typedef int VAL;
typedef int POSITION;
typedef enum {BEHIND, LEVEL, FORWARD} POSITIONS;
typedef struct node ListNode;


extern void insert_node_to_back(ListNode *node, ListNode *head); // inserts element to the front of the list
extern bool compare_nodes(ListNode *node1, ListNode *node2); // compares two nodes and returns true if node1->val is greater than node2->val;
extern POSITIONS compare_node_positions(ListNode *node1, ListNode *node2); // compares node positions and returns where node1 is wrt node2
extern void print_linked_list(ListNode *head); // prints linked list given the head of the linked list;
extern ListNode* create_node(VAL val, POSITION pos); // creates a new linkedlist node
extern ListNode* createList(int N); // Creates list and returns head
extern ListNode* createCycle(ListNode *head, int N); // Randomly decides to create a cyclic or normal linkedlist


