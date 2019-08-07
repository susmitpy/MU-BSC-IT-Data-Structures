#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head = NULL;
struct Node* last = NULL;

void insertNode()
{
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = last;
  last->next = newNode;
  last = newNode;
  printf("\nNode inserted\n");
}


void createList(int n) {
    int i, data;
    if (head == NULL)
    {
      printf("\nEnter data of first node: ");
      scanf("%d",&data);
      head = (struct Node*) malloc(sizeof(struct Node));
      head->data=data;
      head->prev=NULL;
      head->next=NULL;
      last=head;
      n=n-1;
    }
    for(i=1;i<=n;i++)
    {
      insertNode();
    }
}

void sort()
{
  struct Node* curr, *prev;
  
}

void display()
{
  struct Node* cn = head;
  while (cn!=NULL) {
    printf("%d ",cn->data);
    cn = cn->next;
  }
  printf("\n");
}


int main()
{
  int n;
  printf("How many elements: ");
  scanf("%d",&n);
  createList(n);
  printf("Original: ");
  display();
  printf("Sorted: ");
  display();
}


void insertNodeAtStart()
{
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;
  head->prev=newNode;
  head = newNode;
  printf("\nNode inserted\n");
}

void displayRL()
{
  struct Node* cn = last;
  while (cn!=NULL) {
    printf("%d ",cn->data);
    cn = cn->prev;
  }
  printf("\n");
}
