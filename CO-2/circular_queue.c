#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int que[MAX_SIZE];
int rear = -1;
int front = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enque(int value) {
    if (isFull()) {
        printf("Queue Overflow: Cannot enqueue element, queue is full.\n");
        return;
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        que[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

void deque() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot dequeue element, queue is empty.\n");
        return;
    } else {
        printf("Dequeued element: %d\n", que[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}                                                                                                                                                                                                           

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", que[i]);
        i = (i + 1) % MAX_SIZE;
    }
    // Print the last element if front and rear are not equal
    printf("%d\n", que[rear]);
}

int main() {
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    //enque(60); gives stack overflow
    display();
    deque();
    deque();
    deque();
    display();
    enque(60);
    display();
    //enque(60);
    //deque();
    return 0;
}