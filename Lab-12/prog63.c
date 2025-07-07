// copy linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
struct node *firstCopy=NULL;
void copyList(){
    if(first==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            struct node *newNode=(struct node*) malloc(sizeof(struct node));
            newNode->info=save->info;
            newNode->link=NULL;
            if(firstCopy==NULL){
                firstCopy=newNode;
            }
            else{
                struct node *temp=firstCopy;
                while(temp->link!=NULL){
                    temp=temp->link;
                }
                temp->link=newNode;
            }
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
    newNode->link=NULL;
    if(first==NULL){
        first=newNode;
    }
    else{
        struct node *save=first;
        while(save->link!=NULL){
            save=save->link;
        }
        save->link=newNode;
    }   
}
void display(){
    if(first==NULL){
        printf("1st Linked List is Empty\n");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            printf("%d, ",save->info);
            save=save->link;
        }
    }
    printf("\n");
    if(firstCopy==NULL){
        printf("2nd Linked List is Empty");
    }
    else{
        struct node *saveCopy=first;
        while(saveCopy!=NULL){
            printf("%d, ",saveCopy->info);
            saveCopy=saveCopy->link;
        }
    }
}
void main(){
    int ch;
    printf("1.Insert at last\n2.Display\n3.Exit\n4.Display Copied\n");
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
            display();
        }
    }
}