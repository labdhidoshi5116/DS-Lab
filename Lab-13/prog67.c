// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int info;
//     struct node *link;
// };
// struct node *first=NULL;
// void gcd(int n1,int n2){
//     int min=(n1>n2)?n2:n1;
//     for(int i=min;i>=1;i--){
//         if(n1%i==0 && n2%i==0){
//             min=i;
//             break;
//         }
//         return min;
//     }
// }
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtFirst(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
}
int GCD(int a, int b){
    if(first==NULL){
        printf("Linklist Is Empty");
    }
    int min=(a>b)?b:a;
    int i;
    for( i=min;i>=1;i--){
        if(a%i==0 && b%i==0){
            min=i;
            break;
        }
    }
    return min;
}
void display(){
    struct node *save=first;
    if(first==NULL){
        printf("Linklist Is Empty");
        return;
    }
    else {
        struct node* save = first;

        while (save != NULL)
        {
            printf("%d -> ",save->info);
            save = save->link;
        }
        printf("null\n");
    }
}
void insertGcd(){
    if(first==NULL){
        printf("Linklist Is Empty");
        return;
    }
    struct node *curr=first;
    struct node *next=first->link;
    
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    
    while(curr!=NULL){
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=GCD(curr->info,next->info);
        curr=curr->link;
        next=next->link;
    }
}

void main()
{
	int choice,a;
    printf("Enter your choice\n");
	while(1){
		printf("1.Enter an element\n2.Display Gcd Inserted List\n3.Display List\n4. EXIT\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("ENTER ELEMENT:");
				scanf("%d",&a);
				insertAtFirst(a);
				display();
				break;
				
			case 2:
				insertGcd();
				display();
				break;
				
			case 3:
				display();
				
			case 4:
				return;
		}
	}
}
