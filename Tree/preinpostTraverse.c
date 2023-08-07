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
void printPreorder(struct node* root){
    if(root == NULL){
    return;
    }
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
   }
void printInorder(struct node* root){
    if(root == NULL){
    return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
   }
   void printPostorder(struct node* root){
    if(root == NULL){
    return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
   }
   void searchTree(struct node * root, int key){
    if(root==NULL){
      return;
    }searchTree(root->left,key);
      searchTree(root->right,key);
    if(root->data == key){
      printf("\nKey Found - %d", root -> data);
      
    }
    else{
      printf("\nNot found!");
    }
   }
   int main(){
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right =newnode(5);

    printf("DFS traversal of binary tree is -\n");
    printf("\nPre-order traversals: ");
    printPreorder(root);
    printf("\nIn-order traversals: ");
    printInorder(root);
    printf("\nPost-order traversals: ");
    printPostorder(root);
    searchTree(root,5);
    return 0;
   }
   