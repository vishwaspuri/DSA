#include "compare.h"
#include <stdio.h>

int nextFreeloc = 0;

seqlist insert(Job, seqlist);

seqlist create_list() 
{
    seqlist sl;
    sl.head = nextFreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return sl;
}

void insert_elements(joblist list, seqarr s)
{
    for(int i=0; i<MAX; i++){
        switch(list[i].pri)
        {
            case 0:
                s[0] = insert(list[i], s[0]); break;
            case 1:
                s[1] = insert(list[i], s[1]); break;
            case 2:
                s[2] = insert(list[i], s[2]); break;
        }
    }

}

seqlist insert(Job j, seqlist sl) {
    int i, temp;
    for(i = sl.head; st[i].next != -1; i=st[i].next)
    {
        if (compare(st[st[i].next].ele, j)==GREATER) break;
    }
    temp = nextFreeloc++;
    st[temp].next = st[i].next;
    st[temp].ele = j;
    st[i].next = temp;
    sl.size++;
    return sl;
}

void copy_sorted_ele(seqarr s, joblist ele)
{
    int i, j;
    int index = 0;
    printf ("\n \n");
    for(i=2; i>=0; i--){
        for(j=st[s[i].head].next; st[j].next != -1; j = st[j].next)
        {
            ele[index] = st[j].ele;
            index++;
        }
        ele[index] = st[j].ele;
        index++;
    }
}

void print_job (Job j)
{
    printf ("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

void print_seqlist(seqlist sl)
{
    int i;
    printf ("size of list = %d\n",sl.size);
    for (i=st[sl.head].next ; st[i].next != -1 ; i=st[i].next)
    {
    print_job (st[i].ele);
 }
}

void print_joblist (joblist j)
{
    int i;
    for (i=0;i<MAX;i++)
    {
    print_job (j[i]);
    }
}

void initialize_elements (joblist ele)
{
    int i,size;
    i=0;
    ele[0].id=1;
    ele[0].pri=0;
    ele[0].at=1;
    ele[0].et=5;
    ele[1].id=2;
    ele[1].pri=1;
    ele[1].at=9;
    ele[1].et=3;
    ele[2].id=3;
    ele[2].pri=2;
    ele[2].at=11;
    ele[2].et=12;
    ele[3].id=4;
    ele[3].pri=0;
    ele[3].at=4;
    ele[3].et=7;
    ele[4].id=5;
    ele[4].pri=1;
    ele[4].at=8;
    ele[4].et=2;
    ele[5].id=6;
    ele[5].pri=2;
    ele[5].at=12;
    ele[5].et=11;
    ele[6].id=7;
    ele[6].pri=0;
    ele[6].at=3;
    ele[6].et=9;
    ele[7].id=8;
    ele[7].pri=1;
    ele[7].at=7;
    ele[7].et=4;
    ele[8].id=9;
    ele[8].pri=2;
    ele[8].at=13;
    ele[8].et=10;
    ele[9].id=10;
    ele[9].pri=0;
    ele[9].at=2;
    ele[9].et=15;
}
