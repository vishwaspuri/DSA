#include "cycle.h"
#include <stdio.h>
#include <sys/time.h>

int main(void) {
    // Setting list size
    int list_size;
    printf("Enter list size: ");
    scanf("%d", &list_size);
    
    // Time measurement variables
    struct timeval t1, t2;
    double elapsedTime;

    // Timer start
    gettimeofday(&t1, NULL);
    
    // Creating list
    ListNode* head = createList(list_size);
    print_linked_list(head);
    
    // Randomly adding cycle to list
    head = createCycle(head, list_size);
    
    // Checking whether list has cycle
    bool isCyclic = testCyclic(head);
    if (isCyclic) printf("List Type: Cyclic List\n");
    else printf("List Type: Linear List\n");

    // Timer end
    gettimeofday(&t2, NULL);

    // Calculating elapsed time
    elapsedTime = ((double)(t2.tv_sec - t1.tv_sec))*1000;
    elapsedTime += ((double)(t2.tv_usec - t1.tv_usec))/1000;
    printf("Total time elapsed: %fms\n", elapsedTime);
    return 0;
}