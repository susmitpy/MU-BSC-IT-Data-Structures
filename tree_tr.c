#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL) return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

node* createNode(value){
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertLeft(node *root, int value) {
    root->left = createNode(value);
    return root->left;
} 

node* insertRight(node *root, int value){
    root->right = createNode(value);
    return root->right;
}

void main(){
    node* root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);
    
    insertLeft(root->left, 5);
    insertRight(root->left, 6);
    
    printf("Inorder traversal \n");
    inorder(root);
    printf("\nPreorder traversal \n");
    preorder(root);
    printf("\nPostorder traversal \n");
    postorder(root);
    getch();
}
