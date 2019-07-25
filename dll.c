#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = NULL;
struct Node* last = NULL;

void create(int d)
{
	struct Node* nn;
	nn = (struct Node*) malloc(sizeof(struct Node));
	nn->data = d;
	if (head == NULL)
	{
	  nn->next=NULL;
	  nn->prev=NULL;
	  head=nn;
	  last=nn;
	  printf("Linked List created\n");
	}
	else{
		printf("Linked List already exists!\n");
	}
}

void insertAtStart(int d)
{
	struct Node* nn;
	nn = (struct Node*) malloc(sizeof(struct Node));
	nn->data = d;
	if (head != NULL)
	{
	  nn->next=head;
	  nn->prev=NULL;
	  head->prev=NULL;
	  head=nn;
	  printf("Node added\n");
	}
	else{
		printf("Linked List does not exists!\n");
	}
}


int insertAtLast(int d)
{
	struct Node* nn;
	nn = (struct Node*) malloc(sizeof(struct Node));
	if (nn==NULL)
	{
		printf("Node cannot be created\n");
		return 1;
	}
	nn->data = d;
	nn->next=NULL;
	if (head != NULL)
	{
		nn->prev=last;
		last->next=nn;
		last=nn;
		printf("Node added\n");
	}
	else{
		printf("Linked List does not exists!\n");
	}
	return 0;
}

void reverse()
{

  struct Node* cn;
  struct Node* pn;
  printf("Reversing\n");
  last=head;
  pn = head;
  cn = head->next;
  head = head->next;
  pn->next = NULL;
  pn->prev=cn;
  while (head!=NULL) {
    head = head->next;
    cn->next = pn;
    pn->prev=cn;
    pn = cn;
    cn=head;
  }
  head = pn;


}


void search(int data)
{
  struct Node* curr = head;
  int index=0;
  printf("Searching for %d\n",data);
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
	head->prev=NULL;
	printf("Data: %d\n",toDel->data);
	free(toDel);
}


void display()
{
	struct Node* t;
	printf("Displaying linked list:\n");
	if (head != NULL)
	{
		t = head;
		while(t!=NULL){
			printf("%d ", t->data);
			t = t->next;
		}
		printf("\n");
	}
	else{
		printf("Linked List does not exist");
	}
}

int main()
{
	int i,n;
	printf("Enter data of first node: ");
	scanf("%d", &n);
	create(n);
	display();
	insertAtStart(10);
	insertAtStart(20);
	display();
	insertAtLast(30);
	display();
	reverse();
	display();
	search(10);
	delete();
	display();
	getch();
	return 0;
}
