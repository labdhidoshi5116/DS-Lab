#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int top=-1;
int a[100];

void push(char x){
    a[++top]=x;
}
int pop(){
    return a[top--];
}
void eval_post(char postfix[]){
    for(int i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
        {
            push(postfix[i]-'0');//takes ascii value of 0
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(postfix[i]){
                case '+':
                push(op1+op2);
                break;
                case '-':
                push(op1-op2);
                break;
                case '*':
                push(op1*op2);
                break;
                case '/':
                push(op1/op2);
                break;
                case '^':
                push(pow(op1,op2));
            }
        }
    }
}
void main(){
    char postfix[100];
    printf("Enter expression:");
    scanf("%s",postfix);
    eval_post(postfix);
    printf("Evaluation=%d",pop());
}