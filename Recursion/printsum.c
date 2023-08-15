// Print 1 to n
#include <stdio.h>

void print(int n){
if(n){

print(n-1);
printf("%d\n", n);
}
}

int main(){
int input;
scanf("%d", &input);
print(input);
return 0;
}


// // print sum of 1 to n
// #include <stdio.h>

// int print(int n){
// if(n){
// int sum = n+print(n-1);
// return sum;

// }
// else{
// return 0;
// }

// }

// int main(){
// int input;
// scanf("%d", &input);

// int sum = print(input);
// printf("The sum of 1 to %d is : %d",input, sum);
// return 0;
// }
