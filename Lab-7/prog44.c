#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int a[100];
int top = -1;
void push(int x){
    a[++top] = x;
}

int pop(){
    return a[top--];
}

void eval_prefix(char prefix[]){
    int i;
    for(i=0; i<strlen(prefix);i++){
        if(isdigit(prefix[i]))
            push(prefix[i] - '0');
        else{
            int operand1 = pop();
            int operand2 = pop();
            switch(prefix[i]){
                case '+':
                push(operand1 + operand2);
                break;
                case '-':
                push(operand1 - operand2);
                break;
                case '*':
                push(operand1 * operand2);
                break;
                case '/':
                push(operand1 / operand2);
                break;
                case '^':
                push(pow(operand1, operand2));
            }
        }
    }
    
}

void main(){
    char prefix[100];
    printf("Enter a prefix expression :");
    scanf("%s",prefix);
    strrev(prefix);
    eval_prefix(prefix);
    printf("Answer : %d",pop());
}