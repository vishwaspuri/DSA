#include<stdio.h>

int search(int arr[], int n) {
    int i;
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]>max){
            max = arr[i];
        }
    }
    printf("\nmax\n");
    return max;
}