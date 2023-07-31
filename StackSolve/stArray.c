#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
    int size;
    int top;
    int *s;
};

void create (struct stack *st){
    printf("Enter Size : ");
    scanf("%d", &st ->size);
    st -> top = -1;
    st ->s = (int *)malloc(st->size*sizeof(int));
}
void display(struct stack st){
    int i;
    for(i = st.top;i >0 ;i--){
        printf("%d ",st.s[i]);
        printf("\n");
    }
}

void push(struct stack *st , int x){
    if(st->top == st->size-1){
        printf("Overflow\n");
    }
    else{
        st->top++;
        st-> s[st->top]=x;
    }
}

int pop (struct stack *st){
    int x = -1;
    if(st-> top ==-1){
        printf("Underflow");
    }
    else{
        x = st -> s[st->top--];
    }
    return x;
}
int peek(struct stack st, int index){
    int x = -1;
    if(st.top-index+1<0){
        printf("Invalid Imdex!!");
    } 
    else{
        x = st.s[st.top-index+1];
    }
}
bool isempty(struct stack st){
    if(st.top == -1)
    return true;
    return false;
}
int isfull(struct stack st){ 
    return st.top == st.size-1;
}
int stacktop(struct stack st){
    if(!isempty(st)){
        return st.s[st.top];
    }
    return -1;
}

int isBalanced(char exp)
{
 int i;
 
 for(i=0;exp[i]!='\0';i++)
 {
 if(exp[i]=='(')
 push(exp[i]);
 else if(exp[i]==')')
 {
 if(top==NULL)
 return 0;
 pop();
 }
 }
 if(top==NULL)
 return 1;
 else
 return 0;
}


int main(){
struct stack st;
create(&st);
push(&st,10);
push(&st, 20);
printf("%d \n",peek(st,2));
 
 
 display(st);
 
 return 0;
}