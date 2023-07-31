#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

        int arr[maxsize];
        int top = -1;
        int isempty(){
            if(top == -1){
                printf("this is empty stack!\n");
                return 1;
                }
            else
                {
                    return 0;
                }
            }
        int isfull(){
            if(top == maxsize-1){
                printf("stack is full!\n");
                return 1;
            }
            else{
                return 0;
            }
                }
        void push(int input){
            if(!isfull()){
                top = top +1;
                arr[top]=input;}
            }

        void pop(){

            if(!isempty()){
                top =top -1;
                }
        }
        void peek(){

            int show;
            show = arr[top];
            printf("%d\n",show);
        }
        void display(int arr[]){

        for (int i = 0; i <= top; i++){
        printf("%dth element in the stack is %d\n", i,arr[i]);
        }
        printf("\n");
        }

        void reverse(int arr[]) {
        for (int i = top; i >= 0; i--) {
            printf("%dth element in the stack is %d\n", i, arr[i]);
        }
        printf("\n");
        }


                int main(){

                
                while (1){
				int num;
                printf("Enter option to choose - \n1 for push \n2 for pop \n3 for peek \n4 for reverse \n5 for display \n6 Exit \n");
                scanf("%d",&num);
                int input ;

                switch (num)
                {
                case 1: {
                printf("Enter element of array: \n");
                scanf("%d",&input);
                push(input);
                break;
                }
                case 2 :{

                    pop();
                    break;
                }
                case 3 :{
                    peek();
                    break;

                }
                case 4 : {
						reverse(arr);
                        break;
                }
                case 5 : {
					display(arr);
                    break;
                }
                case 6 : {
                    printf("Exit code!!!\n");
                   exit(0);
                    }
                default :{
                printf("Wrong Input!!!\n\n");
            }
            }

                }
    }
