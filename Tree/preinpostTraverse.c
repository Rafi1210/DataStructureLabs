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

int oneleaf(struct node* root){
  if(root == NULL){
    return 0;
  }
   if (root->left == NULL && root->right == NULL) {
        return 0;
    }
  if(root->left == NULL || root->right == NULL){
    return 1;
  }
    int lefttra = oneleaf(root->left);
    int righttra = oneleaf(root->right);

    return 1;
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
        return root; // Found the maximum node
    
    return searchmax(root->right);
}
int sumValues(struct node* root) {
    if (root == NULL) {
        return 0; // Base case: empty subtree contributes 0 to the sum
    } else {
        int leftSum = sumValues(root->left);   // Sum of values in the left subtree
        int rightSum = sumValues(root->right); // Sum of values in the right subtree
        return root->data + leftSum + rightSum; // Return total sum of values
    }
}


struct node* deleteLeaves(struct node* root) {
    if (root == NULL) {
        return NULL; // Base case: empty tree
    }
    
    if (root->left == NULL && root->right == NULL) {
        free(root); // Delete the leaf node
        return NULL;
    }
    
    root->left = deleteLeaves(root->left);   // Recursively delete leaves in the left subtree
    root->right = deleteLeaves(root->right); // Recursively delete leaves in the right subtree
    
    return root;
}


struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value) {
    struct node *del;
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        del = inOrderPredecessor(root);
        root->data = del->data;
        root->left = deleteNode(root->left, del->data);
    }
    return root;
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

int sumNodeValue = sumValues(root); 
printf("Sum of node values: %d\n", sumNodeValue);


deleteNode(root, 15);
deleteLeaves(root);
printf("\nLeaves Deleted!!!\n");
 printf("\nIn-order traversals: ");
    printInorder(root);


  int oneL = oneleaf(root);
  if(oneL == 1)
{
  printf("\nYES");
}
else{
  printf("NO");
}
return 0;
}