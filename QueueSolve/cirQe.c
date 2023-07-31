#include <stdio.h>
#include<stdlib.h>

#define max 20

int a[max];
int rear = -1;
int front = -1;
void enQ()
{
	int insert;
		printf("Insert element : ");
		scanf("%d", &insert);
	if(((rear+1)%max)== front){
		printf("Overflow!\n");
	}
	else if(front == -1 && rear == -1){

			front  = 0 ;
			rear = rear+1;
			a[rear] = insert;

}
else{ // base condition...
	rear = (rear+1)%max;
	a[rear] = insert;
}
}
void dQ(){
	if(front == -1 && front == -1 )
	{
		printf("underflow\n");
		}
		else if (front  ==  rear ){
			front = rear = -1;
		}
		else {
			 printf("Element deleted from the queue : %d\n", a[front]);
			 front = (front+1)%max;
		}
}
void show(){
	int i = front;
if(rear == -1 && front == -1){
	printf("empty\n");
}
else{
		while(i != rear){
		printf("%d\n", a[i]);
		i = (i+1)%max;
		}
		printf("%d", a[rear]);
	}
}
int main()
{
    int ch;
    while (1)
    {
    	printf("\n");
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enQ();
            break;
            case 2:
            dQ();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
    return 0 ;
}

