// WAP to check whether the string is Palindrome or not using Pointer
#include <stdio.h>
void main(){
    char str[100], *ptr, *rev_ptr;
    int length = 0, is_palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate length of the string
    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    ptr = str; // Pointer to the start of the string
    rev_ptr = str + length - 1; // Pointer to the end of the string

    // Check for palindrome
    for (int i = 0; i < length / 2; i++) {
        if (*ptr != *rev_ptr) {
            is_palindrome = 0;
            break;
        }
        ptr++;
        rev_ptr--;
    }

    if (is_palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }   
}