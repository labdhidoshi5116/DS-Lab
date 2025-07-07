// WAP to remove duplicate elements from a singly linked list
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
    if(first==NULL)
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
void sortNodes()
{
    if (first == NULL || first->link == NULL)
    {
        printf("List is empty or has only one node.\n");
        return;
    } // if

    int swapped;
    struct node *save, *next;
    struct node *end = NULL;

    do
    {
        swapped = 0;
        save = first;

        while (save->link != end)
        {
            next = save->link;
            if (save->info > next->info)
            {
                int temp = save->info;
                save->info = next->info;
                next->info = temp;
                swapped = 1;
            } // if
            save = save->link;
        } // while
        end = save;
    } while (swapped); // do while
}
void removeDuplicate(){
    if(first==NULL){
        printf("Empty List");
        return;
    }
    else if(first->link==NULL){
        printf("%d ",first->info);
        return;
    }
    else{
        int flag=0;
        struct node *save=first;
        while(save!=NULL && save->link!=NULL){
            if(save->info==save->link->info){
                struct node *dupli=save->link;
                save->link=save->link->link;
                dupli->link=NULL;
                free(dupli);
                flag=1;
            }
            else{
                save=save->link;
        }
        if(flag==0){
            printf("No duplicate found");
        }
    }
}
            }
void main(){
    int ch;
    printf("Enter your choice:");
    while(1){
        printf("\n1.Enter new Node\n2.Display Original List\n3.Display List without duplicated elements\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertAtLast();
            break;
            case 2:
            display();
            break;
            case 3:
            sortNodes();
            removeDuplicate();
            display();
            break;
            case 4:
            break;
        }
    }
}