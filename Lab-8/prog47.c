// Write a menu driven program to implement following operations on the Queue 
// using an Array 
// • ENQUEUE 
// • DEQUEUE 
// • DISPLAY

#include <stdio.h>
#define n 5
int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % n == front) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

void main() {
    int ch, x;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
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
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}