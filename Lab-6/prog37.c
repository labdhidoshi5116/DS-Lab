#include <stdio.h>
#include <string.h>
char stack[1001];
int top = -1;

void push(char x) {
    if (top >= 1000) 
    {
        return; 
    }
    stack[++top] = x;
}
void pop() {
    if (top < 0) 
    {
        return;
    }
    top--;
}
char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char* s) {
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
        {   
            push(s[i]);
        } 
        else {
            if (isEmpty()) 
            {
                return 0; 
            }

            char c = peek();
            
            if ((s[i] == ')' && c == '(') ||(s[i] == '}' && c == '{') ||(s[i] == ']' && c == '[')) 
            {
                pop();
            } 
            else {
                return 0;
            }
        }
    }

    return isEmpty();
}

void main() {
    int t;
    printf("Enter the number of Test Cases:");
    scanf("%d", &t);

    while (t--) {
        char str[1001];
        scanf("%s", str);

        top = -1;

        if (isBalanced(str)) 
        {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}