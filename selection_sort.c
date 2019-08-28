//
//  selection_sort.c
//
//  Created by Susmit Vengurlekar on 23/08/19.
//

#include <stdio.h>

int arr[100],n;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(){
    int i,j,min_idx;
    for (i=0; i < n - 1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx],&arr[i]);
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

