#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void createList(int data)
{
  head = (struct Node*) malloc(sizeof(struct Node));
  head->data=data;
  head->next=NULL;
}

void insertAtStart(int data)
{
  struct Node* link = (struct Node*) malloc(sizeof(struct Node));
  link->data=data;
  link->next=head;
  head=link;
}

void insertAtLast(int data)
{
  struct Node* nn = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp = head;
  while (temp->next!=NULL) {
    temp=temp->next;
  }
  nn->data=data;
  temp->next=nn;
}

void search(int data)
{
  struct Node* curr = head;
  int index=0;
  while (curr!=NULL && curr->data!=data) {
    index++;
    curr = curr->next;
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
  struct Node* pn;
  pn = head;
  cn = head->next;
  head = head->next;
  pn->next = NULL;
  while (head!=NULL) {
    head = head->next;
    cn->next = pn;
    pn = cn;
    cn=head;
  }
  head = pn;
}


void display()
{
  struct Node* curr = head;
  while (curr!=NULL) {
    printf("%d ",curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main()
{
  // Insert at beginning of list
  createList(10);
  display();
  insertAtLast(20);
  display();
  insertAtLast(30);
  display();
  printf("Searching for 20\n");
  search(20);
  reverse();
  display();
  delete();
  display();
  delete();
  display();

  return 0;
}
