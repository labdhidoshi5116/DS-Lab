// WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *first = NULL;
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
                break;
            case 2:
                deleteAlt();
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
    if(first == NULL){
        newNode->lptr = NULL;
        newNode->rptr = NULL;
    } else {
        first->lptr = newNode;
        newNode->lptr = NULL;
        newNode->rptr = first;
    }
}
void deleteAlt(){
    if(first==NULL){
        printf("Empty List\n");
    }
    else{
        struct node *save = first;
        struct node *pred = NULL;
        int a=0;
        while(save!=NULL){
            if(a%2==0){
                while(a){
                    save=save->rptr;
                    a--;
                }
                pred=save->lptr;
                pred->rptr=save->rptr;
                save->rptr->lptr=pred;
                free(save);
            }
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
            printf("%d ", save->info);
            save = save->rptr;
        }
    }
}