// Write a program to remove the duplicates nodes from given sorted Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtLast(){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter element:");
    scanf("%d",&x);
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
        newNode->link;NULL;
    }
}

void display(){
    if(first=NULL)
    {
        printf("Empty list");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            printf("%d, ",save->info);
            save=save->link;
        }
    }
}
void removeDuplicate(){
    if(first=NULL){
        printf("Empty List");
    }
    else if(first->link=NULL){
        printf("%d ",first->info);
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            if(save->info==save->link->info){
                struct node *dupli=save->link;
                save->link=save->link->link;
                free(dupli);
            }
            else{
                save=save->link;
            }
        }
    }
}
void main(){
    int ch;
    printf("Enter your choice:");
    while(1){
        printf("\n1.Enter new Node\n2.Display Original List\n3.Display List without duplicated\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter elements in ascending order.");
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