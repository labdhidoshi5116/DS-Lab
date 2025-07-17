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
void pop(){
    if(top<0){
        printf("Stack Underflow");
    }
    else{
        top--;
    }
}
void display(){
    for(int c=top;c>=0;c--){
        printf("%d, ",a[c]);
    }
}
void peep(int i){
    if(top-i+1<0){
        printf("Stack Underflow");
        return;
    }
    else{
        printf("Element at index %d from top is %d",i,a[top-i+1]);
    }
}
void change(int i,int x){
    if(top-i+1<=0){
        printf("Stack Underflow");
        return;
    }
    else{
        a[top-i+1]=x;
    }
}
void main(){
    int ch,x=0,i=0;
    printf("Enter choice:");
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peep\n5.Change\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be added:");
            scanf("%d",&x);
            push(x);
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Enter i:");
            scanf("%d",&i);
            peep(i);
            display();
            break;
            case 5:
            printf("Enter i:");
            scanf("%d",&i);
            printf("Enter new element:");
            scanf("%d",&i);
            change(i,x);
            display();
            break;
            case 6:
            return;
            break;
        }
    }
}