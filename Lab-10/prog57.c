// Write a menu driven program to implement following operations on the singly linked list.
// • 1.Insert a node at the front of the linked list.
// • 2.Display all nodes.
// • 3.Delete a first node of the linked list.
// • 4.Insert a node at the end of the linked list.
// • 5.Delete a last node of the linked list.
// • 6.Delete a node from specified position.
// • 7.count the number of nodes
#include<stdio.h>
#include<stdlib.h>
void choice();
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtFirst(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
    choice();
}
void display(){ 
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    struct node *save=first;
    while(save->link!=NULL){
        printf("%d,",save->info);
        save=save->link;
    }
    choice();
}
void deleteAtFirst(int x){
    struct node *save=first;
    first=save->link;
    save->link=NULL;
    free(save);
    choice();
}
void insertAtLast(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=NULL;
    if(first==NULL){
        first=newNode;
        return;
    }
    else{
        struct node *save=first;
        while(save->link!=NULL){
            save=save->link;
        }
        save->link=newNode;
        return;
    }    
    choice();
}
void deleteAtLast(int x){
    if(first==NULL)
    {
        return;
    }
    else if(first->link==NULL){
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
    choice();
}
void deletePosition(int x){
    struct node *save=first;
    struct node *pred=NULL;
    if(first==NULL){
        return;
    }
    else if(first->link==NULL){
        free(first);
        first=NULL;
    }
    else{
        while(x){
            pred=save;
            save=save->link;
            x--;
        }
        pred->link=save->link;
        free(save);
    }
    choice();
}
void countNode(){
    int a=0;
    struct node *save=first;
    while(save->link!=NULL){
        save=save->link;
        a++;
    }
    printf("Number of Elements:%d",a);
    choice();
}
void choice(){
    int choice;
    printf("Enter operation:\n1.Insert a node at the front of the linked list.\n2.Display all nodes.\n3.Delete a first node of the linked list.\n4.Insert a node at the end of the linked list.\n5Delete a last node of the linked list.\n6.Delete a node from specified position.\n7.count the number of nodes\n8.Exit\n");
    scanf("%d",&choice);
    int x;
    switch(choice){
        case 1:
        printf("Enter the value of node to be inserted at the front of the linked list:");
        scanf("%d",&x);
        insertAtFirst(x);
        break;
        case 2:
        display();
        break;
        case 3:
        printf("Enter the value of node to be deleted from the front of the linked list:");
        scanf("%d",&x);
        deleteAtFirst(x);
        break;
        case 4:
        printf("Enter the value of node to be inserted at the end of the linked list:");
        scanf("%d",&x);
        insertAtLast(x);
        break;
        case 5:
        printf("Enter the value of node to be deleted from the end of the linked list:");
        scanf("%d",&x);
        deleteAtLast(x);
        break;
        case 6:
        printf("Enter the value of node to be deleted from specified position:");
        scanf("%d",&x);
        deletePosition(x);
        break;
        case 7:
        countNode();
        break;
        case 8:
        break;
    }
}
void main()
{
    choice();
}
