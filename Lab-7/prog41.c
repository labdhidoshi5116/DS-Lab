//Write a program to convert infix notation to postfix notation using stack.
#include<stdio.h>
#include<string.h>
int top=-1;
char a[100];

void push(char x){
    a[++top]=x;
}
char pop(){
    return a[top--];
}
int stack_precedence(char x){
    if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 4;
    }
    else if(x == '^'){
        return 5;
    }
    else if(x == '('){
        return 0; 
    }
    else{
        return 8; 
    }
}
int input_precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 3;   
    }
    else if(x == '^'){
        return 6;
    }
    else if(x == '('){
        return 9;
    }
    else if(x == ')'){
        return 0;
    }
    else{    
        return 7;
    }   
}
int r(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x =='^'){
        return -1;
    }
    else{
        return 1;
    }
}
void convert_to_post(char infix[]){
    int i = 0;
    char postfix[100];
    int rank = 0;
    int j = 0;
    push('(');
    while(i != strlen(infix)){
        char next = infix[i];
        if(top < 0){
            printf("Invalid Expression.");
            return;
        }
        while(stack_precedence(a[top]) > input_precedence(next))
        {
            char temp = pop();
            postfix[j++] = temp;
            rank += r(temp);
            if(rank < 1){
                printf("Invalid Expression");
                return;
            }
        }

        if(stack_precedence(a[top]) != input_precedence(next)){
            push(next);
        }
        else{
            char temp = pop();
        }
        i++;
    }
    postfix[j] = '\0';
    if(top!=-1 || rank != 1)
        printf("Invalid");
    else{
        printf("%s", postfix);
    }
}  

void main(){
    a[top] ='(';
    char infix[100];
    printf("Enter an expression:");
    // gets(infix[100]);
    scanf("%s",infix);
    strcat(infix,")");
    convert_to_post(infix);
}