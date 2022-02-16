#include "SeqListOps.h"
#include <stdio.h>

int main(void)
{
    int i;
    seqarr seq;
    joblist arr;
    initialize_elements (arr);

    seq[0] = create_list();
    seq[1] = create_list();
    seq[2] = create_list();
    insert_elements(arr, seq);

    copy_sorted_ele(seq, arr);

    print_joblist(arr);
}