//
//  insertion_sort.c
//
//  Created by Susmit Vengurlekar on 23/08/19.
//

#include <stdio.h>

int arr[100],n;

void sort(){
    int i,j,k;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                k=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=k;
            }
        }
    }
}

void getElems(){
    int i, e;
    printf("How many elements: ");
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        printf("Elem: ");
        scanf("%d",&e);
        arr[i] = e;
    }
}

void display(){
    int i;
    for (i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
}


int main(){
    getElems();
    printf("Array: \n");
    display();
    printf("\nAfter sorting: \n");
    sort();
    display();
}

