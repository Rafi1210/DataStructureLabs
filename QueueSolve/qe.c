#include <stdio.h>
#include<stdlib.h>

#define max 100

int a[max];
int rear = -1;
int front = -1;
void enQ()
{
	int insert;
	if(rear == max-1){
		printf("Overflow!\n"); //maximum index
	}
	else{
		if(front == -1){  // insert at the beginning 
			front = 0 ;
			}
	}	
			printf("Insert element : "); // first make the front 0 then insert 
			scanf("%d", &insert);
			rear = rear+1;
			a[rear] = insert;
			
	
}
void dQ(){
	if(front == -1 || front > rear )
	{
		printf("underflow\n");
		}
		else if (front  ==  rear ){
			front = rear = -1;
		}
		else {
			 printf("Element deleted from the queue : %d\n", a[front]);
			 front = front+1;
		}
}
void show(){
if(rear == -1 && front == -1){
	printf("empty\n");
}
else{
	printf("Q : \n");
	for(int i = front; i <=rear ;i ++ ){
		printf("%d", a[i]);
		printf("\n");
	}
}

}

void reverse(){
if(rear == -1 && front == -1){
	printf("empty\n");
}
else{
	printf("Q : \n");
	for(int i = rear; i >=front ;i-- ){
		printf("%d", a[i]);
		printf("\n");
	}
}
}

int main()
{
    int ch;
    while (1)
    {
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
			reverse();
			break;
            case 5:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
    return 0 ;
}

