// WAP to swap Kth node from beginning with Kth node from end in a singly linked list
// count-k+1
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
int count=0;
void insertAtLast(int x){
    count++;
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
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
void swap(int k){
    if(count!=0){
        if(k>count || k<=0){
            printf("Enter a valid position");
            return;
        }
        else{
            int fromStart=k;
            int fromEnd=count-k+1;
            struct node *start=first;
            for(int i=1;i<fromStart;i++){
                start=start->link;
            }
            struct node *end=first;
            for(int i=1;i<fromEnd;i++){
                end=end->link;
            }
            int temp=start->info;
            start->info=end->info;
            end->info=temp;
            display();
        }
    }
    else{
        printf("Can't swap in empty list");
    }
}
void main(){
    int ch,x;
    printf("Enter your choice:");
    while(1){
        printf("\n1.Insert node\n2.Display Normal List\n3.Display List with kth element swapped\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the value:");
            scanf("%d",&x);
            insertAtLast(x);
            break;
            case 2:
            display();
            break;
            case 3:
            printf("Enter the place of the element you want to swap:");
            scanf("%d",&x);
            swap(x);
            break;
            case 4:
            break;
        }
    }
}