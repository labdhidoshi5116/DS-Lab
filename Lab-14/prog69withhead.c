//circular linked list with head;
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *head = NULL; 

void head_node() {
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 0;         
    head->link = head;     
}

void insertAtFirst(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;

    struct node *temp = head;
    newNode->link = head->link;
    head->link = newNode;

    if (newNode->link == head)
    {
        newNode->link = head;
    }
}

void insertAtLast(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = head;

    struct node *temp = head;

    while (temp->link != head)
        temp = temp->link;

    temp->link = newNode;
}

void deleteAtFirst() {
    if (head->link == head) {
        printf("List is empty.\n");
        return;
    }

    struct node *save = head->link;
    head->link = save->link;
    free(save);
}

void deleteAtLast() {
    if (head->link == head) {
        printf("List is empty.\n");
        return;
    }

    struct node *prev = head;
    struct node *curr = head->link;

    while (curr->link != head) {
        prev = curr;
        curr = curr->link;
    }

    prev->link = head;
    free(curr);
}

void deleteAtPosition(int pos) {
    if (head->link == head || pos < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct node *save = head;
    for (int i = 1; i < pos && save->link != head; i++) {
        save = save->link;
    }

    if (save->link == head) {
        printf("Position out of bounds.\n");
        return;
    }

    struct node *del = save->link;
    save->link = del->link;
    free(del);
}

int countNodes() {
    int count = 0;
    struct node *temp = head->link;

    while (temp != head) {
        count++;
        temp = temp->link;
    }

    return count;
}

void Display() {
    struct node *save = head->link;

    if (save == head) {
        printf("List is empty.\n");
        return;
    }

    while (save != head) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("(head)\n");
}


void main() {
    int a, num, pos;
    head_node();
    while (1) {
        printf("\n1. Insert At First\n2. Insert At Last\n3. Delete At Position\n4.Count Node\n5.Display");
        
        printf("\nEnter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                insertAtFirst(num);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &num);
                insertAtLast(num);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 5:
                Display();
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}