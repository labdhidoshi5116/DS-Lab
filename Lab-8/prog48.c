// Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue

#include <stdio.h>
#define n 5
int deque[n];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = n - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

void insertRear(int x) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == n - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == n - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = n - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

void main() {
    int ch, x;
    while (1) {
        printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}