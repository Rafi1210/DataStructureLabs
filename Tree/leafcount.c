#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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


    struct node* insertnumber(struct node **rootptr, int value){
  struct node *root = *rootptr;
  if(root == NULL){
    (*rootptr) = newnode(value);
    return root;
  }
  if(value == root->data){
    return root;
  }
  if(value < root->data){
    return insertnumber(&(root->left), value);
  }
  else{
    return insertnumber(&(root->right), value);

  }
}

int leafcount(struct node *root) {
    if (root == NULL) {
        return 0; // Base case: empty subtree has 0 leaf nodes
    }
    
    if (root->left == NULL && root->right == NULL) {
      printf("%d ", root->data);
        return 1; // Base case: leaf node
    }
    
    int leftCount = leafcount(root->left);
    int rightCount = leafcount(root->right);
    
    return leftCount + rightCount; // Total leaf count of the subtree
}

   int main(){
    struct node* root = NULL;
    insertnumber(&root, 15);
    insertnumber(&root, 11);
    insertnumber(&root, 24);
    insertnumber(&root, 5);
    insertnumber(&root, 19);
    insertnumber(&root, 16);
    insertnumber(&root, 14);
    printf("DFS traversal of binary tree is -\n");
    printf("\nPre-order traversals: ");
    printPreorder(root);
    printf("\nLeaf nodes : ");
    int count = leafcount(root);
    printf("\nNumber of leaf nodes: %d\n", count);

    return 0;
   }
   