// Write a menu driven program to implement following operations on the circular
// linked list.
// • Insert a node at the front of the linked list.
// • Delete a node from specified position.
// • Insert a node at the end of the linked list.
// • Display all nodes
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
struct node *last=NULL;
void insertAtFirst(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    if(first == NULL){
        first=last=newNode;  
        // newNode->link = NULL; 
        // last->link = first;
        newNode->link = newNode;
        // first = last = newNode;
    }
    else{
        newNode->link = first;
        first = newNode;
        last->link = first;
    }
}
void insertAtLast(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    if(first==NULL){
        first=last=newNode;
        last->link=first;
    }
    else{
        last->link=newNode;
        newNode->link=first;
        last=newNode;
    }
}
void deleteNode(int x){
    if(first==NULL){
        printf("Empty List");
    }
    else if(first->link==NULL){
        free(first);
        first=NULL;
    }
    else{
        struct node *save=first;
        struct node *pred=NULL;
        while(x){
            pred=save;
            save=save->link;
            x--;
        }
        pred->link = save->link;
        free(save);
    }
}
void display(){
    if(first==NULL){
         printf("Empty List");
    }
    else{
        struct node *save=first;
        // while(save != first){
        //     printf("%d ,", save->info);
        //     save=save->link;
        // }
        do{
            printf("%d ,", save->info);
            save=save->link;
        }while(save != first);
        printf("\n");
}
}
void main(){
    int ch,x;
    printf("Enter your choice\n");
    while(1){
        printf("\n1.Insert a node at first\n2.Delete a node\n3.Insert a node at last\n4.Display all nodes\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the value to be added at first: ");
            scanf("%d",&x);
            insertAtFirst(x);
            break;
            case 2: 
            printf("Enter the position to delete: ");
            scanf("%d",&x);
            deleteNode(x);
            break;
            case 3:
            printf("Enter the value to be added at last: ");
            scanf("%d",&x);
            insertAtLast(x);
            break;
            case 4:
            display();
            break;
            case 5:
            return;
        }
    }
}