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

void insertNodeAtLast()
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

void displayLR()
{
  struct Node* cn = head;
  while (cn!=NULL) {
    printf("%d ",cn->data);
    cn = cn->next;
  }
  printf("\n");
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





int main()
{
  int n;
  printf("How many elements: ");
  scanf("%d",&n);
  createList(n);
  printf("Display LR: ");
  displayLR();
  printf("Display RL: ");
  displayRL();
}
  printf("Position:%d\n",index+1);
}

void delete()
{
  struct Node* toDel = head;
  head = head->next;
  free(toDel);
}

void reverse()
{
  struct Node* cn;
    printf("%d ",curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main()
  insert(30);
  printf("Searching for 20\n");
  search(20);
  display();
  printf("\nReversing\n");
  reverse();
  display();
  delete();
  display();
  delete();
  display();

  return 0;
}
