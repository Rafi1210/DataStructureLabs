
#include <stdio.h>

int fibo(int num){
    if(num == 0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    else{
        return fibo(num-1)+fibo(num-2);
    }
}


int main(){
int input;
scanf("%d", &input);
for(int i = 0;i<input;i++){
    printf("%d ",fibo(i) );
}
return 0;
}
