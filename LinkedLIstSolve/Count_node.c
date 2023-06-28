#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL;

void create(int a[], int n){
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head -> data = a[0];
    head -> next = NULL;
    last = head;
    for(i = 1; i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t -> data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}
//count nodes 
int count(struct node *p){
    int c = 0;
    while(p){  //while(p) means while(p!= NULL)
    c++;
    p = p -> next;
    }
    return c;
}

//count Recursive nodes 
int Rcount(struct node *p){
    if(p){
        return Rcount(p -> next)+1;
    }
    else 
        return 0;
}
int main(){
    int n;
    printf("Enter size of the Linked list : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    create(a, n);
    printf("Count is %d\n", count(head));
    printf("Recursive Count is %d\n", Rcount(head));
    return 0;

}