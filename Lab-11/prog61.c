#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

void enqueue(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (last == NULL) {
        first = last = newNode;
    } else {
        last->link = newNode;
        last = newNode;
    }
}

void dequeue() {
    if (first == NULL) {
        printf("Empty Queue\n");
    } else {
        struct node *save = first;
        first = first->link;

        if (first == NULL) {
            last = NULL;
        }

        free(save);
    }
}

void display() {
    if (first == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct node *save = first;
        printf("Queue Elements: ");
        while (save != NULL) {
            printf("%d ", save->info);
            save = save->link;
        }
        printf("\n");
    }
}

void countNodes() {
    int count = 0;
    struct node *save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }
    printf("Total nodes in queue: %d\n", count);
}

void main() {
    int ch, x;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Count Nodes\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                countNodes();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
}
