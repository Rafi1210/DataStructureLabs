#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define maxsize 10


int top = -1;
        char arr[maxsize];

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
        void push(char input){
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

            char show;
            show = arr[top];
            printf("%c\n",show);
        }
        void display(char arr[]){

        for (int i = 0; i <= top; i++){
        printf("%dth element in the stack is %c\n", i,arr[i]);
        }
        printf("\n");
        }


bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')'){
        printf("Balanced");
        return true;
    }
    else if (opening == '{' && closing == '}')
     {   printf("Balanced");
        return true;
     }
    else if (opening == '[' && closing == ']')
      {  printf("Balanced");
        return true;
      }
    else{
        printf("Not Balanced");
        return false;
}
}
bool isBalanced(char expression[]) {
    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1 || !isMatchingPair(arr[top], expression[i]))
                return false;
            else
                pop();
        }
    }
    return (top == -1);
}

                int main(){

                int flag = false;
                while (!flag){
				int num;
                printf("Enter option to choose - \n1 for push \n2 for pop \n3 for peek \n4 for check balanced \n5 for display \n6 for exit \n");
                scanf("%d",&num);
                char input ;

                switch (num)
                {
                case 1: {
                printf("Enter element of array: \n");
                scanf("%s",&input);
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
					 isBalanced(arr);
                        break;
                }
                case 5 : {
					display(arr);
                    break;
                }
                
                case 6 : {
                    printf("Exit code!!!\n");
                    flag = true;
                    break;
                    }
                default :{
                printf("Wrong Input!!!\n\n");    
            }
            }
            
                }
    }
