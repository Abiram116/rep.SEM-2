#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    if ((rear + 1 == MAX_SIZE && front == 0) || (rear + 1 == front)) {
        return true;
    }
    return false;
}

void insertFront(int data) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        front--;
        if (front < 0) {
            front = MAX_SIZE - 1;
        }
    }
    deque[front] = data;
    printf("Inserted %d at front. Front points to index %d and Rear points to index %d\n", data, front, rear);
}

void insertRear(int data) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
        if (rear == MAX_SIZE) {
            rear = 0;
        }
    }
    deque[rear] = data;
    printf("Inserted %d at rear. Front points to index %d and Rear points to index %d\n", data, front, rear);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
        if (front == MAX_SIZE) {
            front = 0;
        }
    }
    printf("Deleted from front. Front points to index %d and Rear points to index %d\n", front, rear);
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
        if (rear < 0) {
            rear = MAX_SIZE - 1;
        }
    }
    printf("Deleted from rear. Front points to index %d and Rear points to index %d\n", front, rear);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (true) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\nFront points to: %d, Rear points to: %d\n", deque[front], deque[rear]);
}


int main() {
    int choice, data;
    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(data);
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
