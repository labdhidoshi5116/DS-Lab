//Valid Parenthesis Problem
#include<stdio.h>
int top=-1;
int a[10];
void push(int x){
    if(top>=9){
        printf("Stack Overflow");
        return;
    }
    else{
        top++;
        a[top]=x;
        return;
    }
}
void main(){
    
}