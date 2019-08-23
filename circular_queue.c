#include <stdio.h>
#define MAX 4

int front = -1, rear = -1, CQ[MAX];

void enqueue(int x)
{
    if ((front == 0 && rear == MAX-1) || (front == rear + 1)){
      printf("Queue is full\n");
    }
    else{
      if (front==-1){
        front = 0;
        rear = 0;
      }
      else{
        if (rear == MAX-1)
          rear = 0;
        else
          rear ++;
      }
      CQ[rear] = x;
      printf("\nElement Inserted: %d",x);
    }
}

void dequeue()
{
  if (front == -1)
    printf("Queue is empty\n");
  else{
    printf("\nElement Deleted: %d",CQ[front]);
    if (front == rear){
      front = -1;
      rear = -1;
    }
    else{
      if (front == MAX-1)
        front = 0;
      else
        front ++;
    }
  }
}

void display()
{
  int i,f;
  if (front >= rear && front != -1)
  {
    for(i=front;i<MAX;i++){
      printf("%d ",CQ[i]);
    }
    for(i=0;i<=rear;i++){
      printf("%d ",CQ[i]);
    }
  }
  else{
    for(i=front;i<=rear;i++){
      printf("%d ",CQ[i]);
    }
  }
}

int main()
{
  printf("Enqueing 10,15,20,25");
  enqueue(10);
  enqueue(15);
  enqueue(20);
  enqueue(25);
  printf("\nQueue:\n");
  display();
  dequeue();
  dequeue();
  printf("\nAfter dequeing 2 elements:\n");
  display();
  enqueue(98);
  enqueue(99);
  printf("\nAfter enqueing 98,99\n");
  display();
  return 0;
}
