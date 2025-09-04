// Write a menu driven program to implement following operations on the Queue 
// using an Array 
// • ENQUEUE 
// • DEQUEUE 
// • DISPLAY
#include <stdio.h>
#define n 5
int queue[n];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear>=n-1){
        printf("Overflow\n");
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 || front>rear){
        printf("Empty\n");
    }
    else{
        front++;
    }
}
void display(){
    if(front==-1 || front>rear){
        printf("Empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
void main(){
    int ch;
    int x;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            printf("Enter element:\n");
            scanf("%d",&x);
            enqueue(x); 
            break;
            case 2: 
            dequeue();
            break;
            case 3: 
            display();
            break;
            case 4: 
            break;
        }
    }
}