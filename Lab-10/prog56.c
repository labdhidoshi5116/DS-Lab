// Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first=NULL;
void main(){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    int i;
    printf("Enter number:");
    scanf("%d",&i);
    newNode->info=i;
    newNode->link=first;
    first=newNode;
    printf("Info(NEW):%d\n",newNode->info);
    printf("Link(NEW):%d",newNode->link);
}
