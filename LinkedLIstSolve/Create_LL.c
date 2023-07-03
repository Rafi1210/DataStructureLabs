#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*head = NULL;
void create (int a[], int n){
    int i ;
    struct node *temp, *nextNode;
    head = (struct node *)malloc(sizeof(struct node ));
    head -> data = a[0];
    head -> next  = NULL;
    nextNode = head;
    for ( i = 1; i <n; i++)
    {
       temp = (struct node *)malloc(sizeof(struct node ));
       temp -> data  = a[i];
       temp -> next = NULL;
       nextNode -> next = temp;
       nextNode  = temp;
    }
    
}

void display(struct node *p){
    while(p != NULL){
        printf("%d\n", p-> data);
        p = p ->next;
    }
}
void Rdisplay(struct node *p){
    if(p!= NULL){
        Rdisplay(p->next);
        printf("%d\n", p->data);
    }
}
int main(){
    struct node *temp;
    int n;
    printf("Enter size of the Linked list : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    create(a, n);
    printf("Linked List Display : \n");
    display(head);
    printf("Linked List Display Recursively : \n"); //Reverse order print , reverse Linked List
    Rdisplay(head);
    return 0;
}