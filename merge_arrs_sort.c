#include <stdio.h>
#include "stdlib.h"

void printArray(int *arr,int n)
{
  int i;
  for (i=0; i < n; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int* mergeSort(int *a1, int n1, int *a2, int n2)
{
  int i1, i2, j, k;
  int* a3 = malloc(sizeof(int)*(n1+n2));
  i1 = 0;
  i2 = 0;
  for(int j = 0; j<n1+n2; j++){
    if (i1>=n1 && i2<=n2)
    {
      while (i2<n2) {
        a3[j] = a2[i2];
        i2 += 1;
        j += 1;
      }
      break;
    }
    else if (i1<=n1 && i2>=n2)
    {
      while (i1<n1) {
        a3[j] = a1[i1];
        i1 += 1;
        j += 1;
      }
      break;
    }
    if (a1[i1] < a2[i2]){
      a3[j] = a1[i1];
      i1 += 1;
    }
    else{
      a3[j] = a2[i2];
      i2+=1;
    }
  }
  return a3;
}

int* getElems(int n)
{
  int *a = malloc(sizeof(int) * n);
  int i;
  printf("Enter elements: ");
  for (i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  return a;
}

int getSize()
{
  int n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  return n;
}

int main(){
  int *a1, *a2, *a3;
  int n1, n2;
  printf("Array 1: ");
  n1 = getSize();
  a1 = getElems(n1);
  printf("Array 2: ");
  n2 = getSize();
  a2 = getElems(n2);
  a3 = mergeSort(a1,n1,a2,n2);
  printf("Merged and sorted: ");
  printArray(a3,n1+n2);
  return 0;
}
