#include <stdio.h>

int n, arr[50];

void getElems(){
  int i;
  printf("Size of array: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    printf("Elem: ");
    scanf("%d", &arr[50]);
  }
}

void display(){
  int i;
  for (i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}

void merge_sort(int list[], int low, int mid, int high){
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

void partition(int list[], int low, int high){
  int mid;
  if (low <= high){
    mid = (low+high)/2;
    partition(list,low,mid);
    partition(list,mid+1,high);
    merge_sort(list,low,mid,high)
  }
}

int main(){
  getElems();
  printf("Elements: ");
  display();
  partition();
  printf("\nAfter Sorting: ");
  display();
}