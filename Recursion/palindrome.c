#include <stdio.h>
#include <string.h>

int isPalindrome(char a[], int start, int end) {
    if (start >= end) {
        return 1; // Base case: empty string or one character is a palindrome
    }
    
    if (a[start] == a[end]) {
        return isPalindrome(a, start + 1, end - 1); // Recursive case: check inner substring
    } else {
        return 0; // Not a palindrome
    }
}

void pal(char a[], int length) {
    if (isPalindrome(a, 0, length - 1)) {
        printf("Palindrome");
    } else {
        printf("!Palindrome");
    }
}

int main() {
    char a[] = "abba";
    int length = sizeof(a) / sizeof(a[0]) - 1; // Calculate length without using strlen
    pal(a, length);
    return 0;
}
