#include<stdio.h>
#include<stdlib.h>

void insert(int a[], int n){
    int temp, i = n;
    temp = a[n];
    while(i>1 && temp >a[i/2]){
        a[i] = a[i/2];
        i = i/2; 
        }
        a[i] = temp;
        
   
}

void createheap(){
    int a[] = {0,10,20, 30, 25, 5, 40, 35};
    int i;
    for(i = 2;i<7 ;i++){
        insert(a,i);
    }
    for(i = 0;i<=7 ;i++){
        printf("%d\n", a[i]);
    }
}

int main(){
    
    createheap();
    return 0;
}