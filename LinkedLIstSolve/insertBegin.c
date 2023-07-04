#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
int count(struct Node *p){
    int c = 0;
    while(p){  //while(p) means while(p!= NULL)
    c++;
    p = p -> next;
    }
    return c;
}

void Insert(struct Node *p,int index,int x)
{
 struct Node *t;
 int i;

 if(index < 0 || index > count(p)){
 printf("Invalid Index, you can't add into this index !!!\n\n");
 return;                              // this statement executes when index is invalid , it returns nothing!
}
 t=(struct Node *)malloc(sizeof(struct Node)); // t is for new data for inserting 
 t->data=x;

 if(index == 0) // the condn is for insert in the beginning before first node 
 {
 t->next=first;
 first=t;
 }
 else       // ----->>>> this condn is to insert at any position except index = 0 , index < 0 && index > count(p);;;;;
 {
 for(i=0;i<index-1;i++){  // index-1 is for 1,2,3,4,5 --- 5 positions means count 4 ( 1 --> 2 = 1,  2 --> 3 = 1+1 =2 , 3 --> 4 = 2+1 = 3.....like this continued)
 p=p->next; 
 }
 t->next=p->next;
 p->next=t;
 
 }
}
int main()
{

  int n;
    printf("Enter size of the Linked list : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
 create(a,n);

//  int A[]={10,20,30,40,50};
//  create(A,5);
//  Insert(first,6,5);----------> just use the defined function 


 printf("Current Linked List : ");
 Display(first);
 int newNumber, pos;
 printf("\nEnter position to insert : ");
 scanf("%d", &pos);
 printf("Enter new number :");
 scanf("%d", &newNumber);
 printf("\nUpdated Linked List : ");
 Insert(first,pos,newNumber);
 Display(first);

 return 0;
}
