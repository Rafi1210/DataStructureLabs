#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL;

void create(int a[], int n){
    int i;
    struct node *t, *last;
    head =(struct node*) malloc(sizeof(struct node));
    head->data = a[0];
    head -> next = NULL;
    last = head;
    for(i = 0; i<n ;i++){
        t = (struct node*) malloc(sizeof(struct node));
        t -> data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

int max(struct node *p){
    int max = -214483648;
    while(p){
        if((p-> data) > max){
            max = p-> data;   
        }

         p = p->next;
    }
    
return max;
}

int main(){
    int a[] = {3,4,5,2,6,2,1,9,3,1};
    create(a,10);
    printf("Max is %d", max(head));
    return 0;
}