#include <stdio.h>
int fact(int num){
    int t ;
    if(num<=1){
        t = 1;
        return t;
    }
    else{
        t = num*fact(num-1);
        return t;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d", fact(n));

}