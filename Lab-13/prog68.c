// Write a program to swap two consecutive nodes in the linked list. Don’t change the values of nodes, implement by changing the link of the nodes.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtFirst(int x){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    // newNode=first;
    first=newNode;
}
void display(){
    if(first==NULL){
        printf("Empty List");
    }
    else{
        struct node *save=first;
        while(save!=NULL){
            printf("%d, ",save->info);
            save=save->link;
        }
    }
}
    void swap(){
        if(first==NULL){
            printf("Empty List");
        }
        else if(first->link==NULL){ 
            printf("%d",first->info);
        }
        else{
            struct node *prev=NULL;
            struct node *save=first;
            first=save->link;
            while(save != NULL && save->link!=NULL){
                struct node *next=save->link;
                struct node *afterNext=next->link;//next=save->link
                next->link=save;
                save->link=afterNext;
                if(prev!=NULL){
                    prev->link=next;
                }
                prev=save;
                save=afterNext;
            }
        }
    }
void main(){
    int ch,x;
    printf("Enter you choice:");
    while(1){
        printf("\n1.Enter new Node\n2.Display Normal list\n3.Display Swapped List\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter element:");
            scanf("%d",&x);
            insertAtFirst(x);
            break;
            case 2:
            display();
            break;
            case 3:
            swap();
            display();
            break;
            case 4:
            return;
            break;
        }
    }
}