#include <stdio.h>

int n;
int arr[50];

void getElems(){
  int i;
  printf("Size of array: ");  
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    printf("Elem: ");
    scanf("%d", &arr[i]);
  }
}

void display(){
  printf("\nin display\n");
  int i;
  for (i=0;i<n;i++){
    printf("%d",arr[i]);
  }
}

void merge_sort(int *list, int low, int mid, int high){
  int i,k,lo,mi,temp[50];
  lo = low;
  i = lo;

  while ((lo <= mid) && (mi <= high)){
    if (list[lo] <= list[mi]){
      temp[i] = list[lo];
      lo++;
    }
    else{
      temp[i] = list[mi];
      mi++;
    }
    i++;
  }
  if (lo > mid){
    for (k=mi;k<=high;k++){
      temp[i] = list[k];
      i++;
    }
  }
  else{
    for (k=lo;k<=mid;k++){
      temp[i] = list[k];
      i++;
    }
  }
  for(k=low;k<=high;k++){
    arr[k] = temp[k];
  }

}

void partition(int *list, int low, int high){
  int mid;
  if (low <= high){
    mid = (low+high)/2;
    partition(list,low,mid);
    partition(list,mid+1,high);
    merge_sort(list,low,mid,high);
  }
}

int main(){
  getElems();
  printf("Elements: ");
  display();
  // Looks like error is here
  /*
   list=<error reading variable: Cannot access memory at address 0x7fffff7fefe8>,                                                           
    low=<error reading variable: Cannot access memory at address 0x7fffff7fefe4>, high=<error reading variable: Cannot access memory at addre
ss 0x7fffff7fefe0>)                                                                                                                          
    at main.c:60                                                                                                                             
60      void partition(int *list, int low, int high){       
  */
  partition(arr,0,n-1);
  printf("\nAfter Sorting: ");
  display();
}