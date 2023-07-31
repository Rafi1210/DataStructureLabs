#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define QUEUE_EMPTY INT_MIN


typedef struct{
    int *values;
    int head, tail, num, size;
}queue;


void init_queue(queue *q, int max_size){
    q->size = max_size;
    q->values = malloc(sizeof(int)*q->size);
    q->num = 0;
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue *q){
    return (q->num == 0);
}

bool queue_full(queue *q){
    return (q->num == q->size);
}

bool enqueue(queue *q, int value){
    if(queue_full(q)){
        return false;
    }
    q->values[q->tail] = value;
    q->num++;
    q->tail = (q->tail+1)%q->size;
    return true;
}

int dequeue(queue *q){
    int result;
    if(queue_empty(q)){
        return QUEUE_EMPTY;
    }
    result = q->values[q->head];
    q->head = (q->head +1) % q->size;
    q->num--;

    return result;
}

 int main(){

                int flag = false;
                int size_max;
                while (!flag){
				int num;
                printf("Enter option to choose - \n1 for initialize queue \n2 for enqueue \n3 for dequeue \n4 for empty \n5 for full \n6 for display \n");
                scanf("%d",&num);
                int input ;
                queue Q ;
                switch (num)
                {
                case 1: {
                    
               printf("Enter size for the queue : ");
               scanf("%d", &size_max);
               init_queue(&Q, size_max);
               break;
                }
                case 2 :{

                printf("Enter element of queue: \n");
                scanf("%d",&input);
                enqueue(&Q,input);
                break;
                }
                case 3 :{
                dequeue(&Q);    
                break;
                }
                case 4 : {
						 queue_empty(&Q);
                        break;
                }
                case 5 : {
					queue_full(&Q);
                    break;
                }
                case 6 : {
                    int data;
               
                     queue temp;  // Temporary queue for display purpose

                    while ((data = dequeue(&Q)) != QUEUE_EMPTY) {
                    printf("Queue: %d\n", data);
                    enqueue(&temp, data);  // Enqueue the element back to the original queue
                     }

                    // Re-enqueue the elements from the temporary queue to the original queue
                    while ((data = dequeue(&temp)) != QUEUE_EMPTY) {
                        enqueue(&Q, data);
                    }
                   // break;
                }
                case 7 : {
                    printf("Exit code!!!\n");
                    flag = true;
                    break;
                    }
                default :{
                printf("Wrong Input!!!\n\n");    
            }
            }
            
                }
                return 0;
    }


