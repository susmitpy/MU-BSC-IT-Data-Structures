#include <stdio.h>

// Insert, Search, Sort Reverse

void printArray(int *arr,int n)
{
  int i;
  printf("The new array is: ");
  for (i=0; i < n; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int getIndex()
{
  int i;
  printf("Index: ");
  scanf("%d", &i);
  return i;
}

int getItem()
{
  int i;
  printf("Item: ");
  scanf("%d", &i);
  return i;

}

void insert(int *p, int n)
{
  int i, j, index, item;
  printf("Insert Operation\n");
  index = getIndex();
  item = getItem();
  j = n-1;
  while (j>=index)
  {
    p[j+1] = p[j];
    j = j-1;
  }
  n = n + 1;
  p[index] = item;
  printArray(p,n);
}

void delete(int *p, int n)
{
  int i, j, index;
  printf("Delete Operation\n");
  index = getIndex();
  j = index;
  n = n-1;
  while (j<=n)
  {
    p[j] = p[j+1];
    j = j+1;
  }

  printArray(p,n);
}

void update(int *p, int n)
{
  int index, item;
  printf("Update Operation\n");
  index = getIndex();
  item = getItem();
  p[index] = item;
  printArray(p,n);
}

void search(int *p, int n)
{
  int item, i;
  printf("Search Operation\n");
  item = getItem();
  for(i=0;i<n;i++)
  {
    if(p[i] == item)
    {
      printf("Index: %d\n",i);
      break;
    }
  }
  if(i == n)
  {
    printf("Not found\n");
  }
}

void reverse(int *p, int n)
{
  int temp, i=0, j=n-1;
  while (i<j) {
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
    i++;
    j--;
  }
  printArray(p,n);
}

void sort(int *p, int n)
{
  int i,j,k;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(p[j] > p[j+1])
      {
        k = p[j];
        p[j] = p[j+1];
        p[j+1] = k;
      }
    }
  }
  printArray(p,n);
}


void options(int *p, int n)
{
  char c;
  printf("What do you want to do? \n");
  scanf(" %c",&c);
  switch (c) {
    case 'i':
      insert(p, n);
      break;
    case 'd':
      delete(p, n);
      break;
    case 'u':
      update(p, n);
      break;
    case 's':
      search(p, n);
      break;
    case 'r':
      reverse(p,n);
      break;
    case 'a':
      sort(p,n);
      break;
    default:
      printf("Invalid operation\n");
  }
}

void getElems()
{
  char c;
  int *p, n, a[50],i, count=5;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  printf("Enter elements: ");
  for (i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  p = a;
  options(p,n);
}

int main(){
  getElems();
  return 0;
}
