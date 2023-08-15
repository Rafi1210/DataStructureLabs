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

   struct node* searchTree(struct node * root, int key){
    if(root==NULL){
      return root;
    }
    else if(root-> data <key ){
      return searchTree(root->right,key);
    }
    else if (root -> data > key ){
    return searchTree(root->left,key);
    }
    else if(root->data == key){
          return root;
      
    }
    else{
      printf("\nNot found!");
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


   int internalcount(struct node *root) {
    if (root == NULL) {
        return 0; // Base case: empty subtree has 0 internal nodes
    }
    
    // If both left and right are NULL, it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    
    // Print the data of internal node
    printf("%d ", root->data);
    
    // Recursive count internal nodes in the left and right subtrees
    int leftCount = internalcount(root->left);
    int rightCount = internalcount(root->right);
    
    // Return the total count of internal nodes
    return 1 + leftCount + rightCount;
}

struct node* searchmin(struct node* root) {
    if (root == NULL)
        return NULL; // Tree is empty
    if (root->left == NULL)
        return root; // Found the minimum node
    
    return searchmin(root->left);
}

struct node* searchmax(struct node* root) {
    if (root == NULL)
        return NULL; // Tree is empty
    if (root->right == NULL)
        return root; // Found the minimum node
    
    return searchmax(root->right);
}


   int main(){
    struct node* root = NULL;
    //....................................||||||||
    // insertnumber(&root, 15);
    // insertnumber(&root, 11);
    // insertnumber(&root, 24);
    // insertnumber(&root, 5);
    // insertnumber(&root, 14);
    // insertnumber(&root, 16);
    // insertnumber(&root, 19);
    // compile time declaration ...........||||||||
    printf("Enter how many nodes you want to create : ");
    int n,node;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &node);
     insertnumber(&root, node); 
    }

    printf("DFS traversal of binary tree is -\n");
    printf("\nPre-order traversals: ");
    printPreorder(root);
    printf("\nIn-order traversals: ");
    printInorder(root);
    printf("\nPost-order traversals: ");
    printPostorder(root);
    int key = 19;
    struct node* result = searchTree(root, key);
    if (result != NULL) {
        printf("\nKey %d found in the tree.\n", key);
    } else {
        printf("\nKey %d not found in the tree.\n", key);
    }


    printf("\nLeaf nodes : ");
    int count = leafcount(root);
    printf("\nNumber of leaf nodes: %d\n", count);


      printf("\nNon Leaf nodes : ");
      int internal = internalcount(root);
      printf("\nNumber of non-leaf nodes: %d\n", internal);


struct node* minNode = searchmin(root); 
if (minNode != NULL) {
    printf("Minimum value: %d\n", minNode->data);
} else {
    printf("The tree is empty.\n");
}

struct node* maxNode = searchmax(root); 
if (maxNode != NULL) {
    printf("Minimum value: %d\n", maxNode->data);
} else {
    printf("The tree is empty.\n");
}
   
}
   