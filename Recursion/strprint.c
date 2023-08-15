
//print string

#include <stdio.h>
#include<string.h>
void input(char a[], int i ){
if(a[i]=='\0'){
return;
}
else{
printf("%c ", a[i]);
input(a, i+1);
}
}
int main(){
int n;
// printf("Enter string size : ");
// scanf("%d", &n);
char a[40];
printf("Enter string : ");
gets(a);
 input(a,0);
 return 0;
}

//print in reverse string

//#include <stdio.h>
//#include<string.h>
//void input(char a[], int i ){
//if(a[i]=='\0'){
//    return;
//}
//input(a, i+1);
//
//printf("%c ", a[i]);
//}
//int main(){
//    int n;
//    printf("Enter string size : ");
//    scanf("%d", &n);
//    char a[n];
//      printf("Enter string : ");
//      gets(a);
//   input(a,0);
//   return 0;
//}