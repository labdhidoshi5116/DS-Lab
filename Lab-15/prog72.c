// Write a menu driven program to implement following operations on the doubly
// linked list.
// • Insert a node at the front of the linked list.
// • Delete a node from specified position.
// • Insert a node at the end of the linked list. (Home Work)
// • Display all nodes. (Home Work)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *lptr;
    struct node *rptr;

};
struct node *first = NULL;
void main(){
    int ch, x;
    printf("Enter a choice:\n");
    while(1){
        printf("\n1. Insert at front\n2. Delete from specified position\n3. Insert at end\n4. Display nodes\n5. Exit\n");   
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &x);
                insertAtFirst(x);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &x);
                deletePos(x);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &x);
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
void insertAtFirst(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    if(first == NULL){
        newNode->lptr = NULL;
        newNode->rptr = NULL;
    } else {
        first->lptr = newNode;
        newNode->lptr = NULL;
        newNode->rptr = first;
    }
    first = newNode;
}
deletePos(int x){
    if(first==NULL){
        printf("Empty List");
    }
    // else if(x==1){
    //     first->rptr=NULL;
    //     free(first);
    // }
    else{
        struct node *save=first;
        struct node *pred = NULL;
        while(x){
            save=save->rptr;
            x--;
        }
        pred=save->lptr;
        pred->rptr=save->rptr;
        save->rptr->lptr=pred;
        free(save);
    }
}
void insertAtLast(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->rptr = NULL;
    if(first == NULL){
        newNode->lptr = NULL;
        first = newNode;
    } else {
        struct node *save = first;
        while(save->rptr != NULL){
            save = save->rptr;
        }
        save->rptr = newNode;
        newNode->lptr = save;
    }
}
void display(){
    if(first == NULL){
        printf("Empty List\n");
    } 
    else {
        struct node *save = first;
        while(save != NULL){
            printf("%d ", save->info);
            save = save->rptr;
        }
    }
}