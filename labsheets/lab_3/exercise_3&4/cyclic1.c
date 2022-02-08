#include "cycle.h"
#include <stdbool.h>
#include <stddef.h>

// Implements hare and tortoise algorithm
bool testCyclic(ListNode *head) {
    // Handling special cases
    if (head == NULL) return false;
    if (head->next == NULL) return false;
    ListNode *hare = head->next, *tort = head->next;
    if (hare->next == NULL) return false;
    else hare = hare ->next;

    
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