#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(value){
    node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertLeft(node *root, int value) {
    root->left = createNode(value);
} 

void insertRight(node *root, int value){
    root->right = createNode(value);
}

void main(){
    node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
        printf("The elements of tree are %d %d %d", root->data, root->left->data, root->right->data);
getch();
}
