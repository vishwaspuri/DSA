#include "cycle.h"
#include <stdbool.h>
#include <stddef.h>

struct node
{
    VAL val;
    POSITION pos;
    ListNode *next;
};

// Implements hare and tortoise algorithm
bool testCyclic(ListNode *head) {
    ListNode *hare = head->next->next, *tort = head->next;
    while(hare!=NULL && tort!=NULL){
        POSITIONS hare_is = compare_node_positions(hare, tort);
        if (hare_is == BEHIND || hare_is == LEVEL) {
            return true;
        }
        if(hare->next == NULL) return false;
        else hare = hare->next;
        if(hare->next == NULL) return false;
        else hare = hare->next;
        tort =  tort->next;
    }
    return false;
}