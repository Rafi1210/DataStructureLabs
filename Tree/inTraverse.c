#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

 struct node* newnode(int value){
    struct node *res = malloc(sizeof(struct node));
    if(res != NULL){
      res-> data = value; 
      res->left = NULL;
      res->right  = NULL;
       
    }
    return res;
}

void printInorder(struct node* root){
    if(root == NULL){
    return;
    }
    printInorder(root->left);
    printf("%d\n", root->data);
    printInorder(root->right);
   }

   int main(){
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right =newnode(5);

    printf("Inorder traversal of binary tree is \n");
    printInorder(root);

    return 0;
   }
