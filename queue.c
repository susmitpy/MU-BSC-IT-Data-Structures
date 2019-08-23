#include <stdio.h>
#define MAX 10

int front = -1, rear = -1, Q[MAX];

void enqueue(int x)
{
    if (front == MAX - 1){
      printf("Queue is full\n");
    }
    else{
      if (front==-1){
        front = 0;
      }
      rear ++;
      Q[rear] = x;
      printf("Element Inserted\n");
    }
}

void dequeue()
{
  printf("\nElement Deleted: %d",Q[front]);
  front++;
}

void display()
{
  int i;
  for(i=front;i<=rear;i++){
    printf("%d ",Q[i]);
  }
}

int main()
{
  int n, i, e;
  printf("How many elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Elem: ");
    scanf("%d",&e);
    enqueue(e);
  }
  printf("Queue:\n");
  display();
  dequeue();
  dequeue();
  printf("\nAfter dequeing 2 elements:\n");
  display();
  return 0;
}
