// WAP to remove duplicate elements from a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtLast(){
    int x;
    printf("Enter element:");
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
void removeDuplicate(){

}
void main(){
    int ch;
    printf("Enter your choice:");
    while(1){
        printf("\n1.Enter new Node\n2.Display Original List\n3.Display List without duplicated\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertAtLast();
            break;
            case 2:
            display();
            break;
            case 3:
            removeDuplicate();
            break;
            case 4:
            break;
        }
    }
}