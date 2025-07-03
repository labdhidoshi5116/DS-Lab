// reverse linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void main(){
    int ch;
    printf("Enter your choice:\n");
    while(1){
        printf("\n1.Insert\n2.Display\n3.Display Reverse\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertAtLast();
            break;
            case 2:
            display();
            break;
            case 3:
            reverse();
            break;
            case 4:
            break;
        }
    }

}
void reverse(){
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *prev=NULL;
    struct node *current=first;
    struct node *next=NULL;
    while(current!=NULL){
        next=current->link; // Store next node
        current->link=prev; // Reverse the link
        prev=current; // Move prev to current
        current=next; // Move to next node
    }
    first=prev; // Update first to the new head
    printf("List reversed successfully\n");
}
void insertAtLast(){
    int x;
    printf("Enter the number to be inserted:");
    scanf("%d",&x);
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
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
    if(first=NULL){
        printf("List is empty");
    }
    else{
        struct node *save=first;
        while (save != NULL) {
            printf("%d ", save->info);
            save = save->link;
        }       
    }
}