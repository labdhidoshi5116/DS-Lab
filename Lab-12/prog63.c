// copy linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void main(){
    int ch;
    printf("1.Insert at last\n2.Display\n3.Exit\n4.Display Reversed");
    while(1){
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            insertAtLast(); 
            break;
            case 2:
            display();
            break;
            case 3:
            break;
            case 4:
            copyList();
        }
    }
}
void copyList(){
    struct node *firstCopy=NULL;
    if(first==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *save=first;
        struct node *newNode=(struct node*) malloc(sizeof(struct node));
        while(save!=NULL){
            save=save->link;
            
        }
    }
}
void insertAtLast(){
    int x;
    printf("Enter the node to be inserted:");
    scanf("%d",&x);
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    if(first==NULL){
        first=newNode;
    }
    else{
        struct node *save=first;
        while(save->link!=NULL){
            save=save->link;
        }
        save->link=newNode;
        newNode->link=NULL;
    }   
}
void display(){
    if(first==NULL){
        printf("Empty Linked List");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            printf("%d,",save->info);
            save=save->link;
        }
    }
}