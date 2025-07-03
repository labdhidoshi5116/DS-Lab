// WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *first = NULL;

void display();
void insertAtFirst(int x);
void deleteAlt();
void insertAtLast(int x);

void main(){
    int ch,x;
    printf("Enter a choice:\n");
    while(1){
        printf("\n1.Insert a node at first\n2.Delete alternate nodes\n3.Insert a node at end\n4.Display nodes\n5.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert at first: ");
                scanf("%d", &x);
                insertAtFirst(x);
                display();
                break;
            case 2:
                deleteAlt();
                printf("inside main");
                display();
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
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    if(first == NULL){
        first = newNode;
    } else {
        first->lptr = newNode;
        newNode->rptr = first;
        first=newNode;
    }
}

void deleteAlt(){
    if(first==NULL){
        printf("Empty List\n");
    }
    else{
        struct node *save=first;
        int count=0;
        while(save!=NULL){
            struct node *next=save->rptr;
            if(count%2!=0){
                if(save->lptr!=NULL){
                    save->lptr->rptr=next;
                }
                if(save->rptr!=NULL){
                    next->lptr=save->lptr;
                }
                free(save);
            }
            save=next;
            count++;
        }
    }
}

void insertAtLast(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
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
    if(first==NULL){
        printf("Empty List\n");
    } else {
        struct node *save = first;
        while(save != NULL){
            printf("%d ->", save->info);
            save = save->rptr;
        }
        printf("NULL");
    }
}