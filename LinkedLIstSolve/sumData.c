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

    for(i = 1;i<n;i++){
        t = (struct node*)malloc(sizeof(struct node));
        t -> data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

// int sum(struct node *p){
//     int sum = 0;
//     while (p)
//     {
//         sum = sum + p->data;
//         p= p -> next;
//     }
//     return sum;
    
// }

int Rsum(struct node* p){
    if(p == NULL){
        return 0;
    }
    else
    return Rsum(p -> next)+p ->data;
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
    // printf("Sum is %d\n", sum(head));
    printf("Recursive Sum is %d\n", Rsum(head));
    return 0;
}