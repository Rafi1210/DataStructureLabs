#include <stdio.h>

int stringLength(char S[], int index) {
    if (S[index] == '\0') {
        return 0; // Base case: empty string has length 0
    } else {
        return 1 + stringLength(S , index+ 1); // Recursive case: move to the next character
    }
}

int main() {
   char inputString[] = "one two three four five";
    int length = stringLength(inputString, 0);
    printf("Length = %d\n", length);
    return 0;
}
