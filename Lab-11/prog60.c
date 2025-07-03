//impleament a stack using singly linked linear list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
void main()
{
    int ch;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: 
                int x;
                printf("Enter value to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                display();
                break;
            case 4: 
                return;
        }
    }
}
void push(int x)//insert at first
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    if(first == NULL){
        first=newNode;
    }
    else{
        newNode->link = first;
        first = newNode;
    }
}
void pop()//remove from last
{
    if(first==NULL)//empty list
    {
        printf("Empty List");
    }
    else if(first->link==NULL){//only single element
        free(first);
        first=NULL;
    }
    else{
        struct node *save=first;
        struct node *pred=NULL;
        while(save->link!=NULL){
            pred=save;
            save=save->link;
        }
        free(save);
        pred->link=NULL;
    }
}
void display()
{
    if(first==NULL){
        printf("Empty Stack");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            printf("%d ", save->info);
            save = save->link;
        }
    }
}
