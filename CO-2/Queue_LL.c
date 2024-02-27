#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue* link;
};
struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue(int x){
    struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = x;
    newnode->link = NULL;
    if(front == NULL) {
        rear = newnode;
        front = newnode;
    } else {
        rear->link = newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct queue *temp;
    if(front == NULL){
        printf("Underflow");
        return;
    } else if(front == rear){
        temp = front;
        front = rear = NULL;
        printf("%d is removed from the queue\n", temp->data);
        free(temp);
    } else {
        temp = front;
        front = front->link;
        printf("%d is removed from the queue\n", temp->data);
        free(temp);
    }
}

void display(){
    struct queue *temp;
    temp = front;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

int main(){
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("\n");
    display();
    printf("\n");
    dequeue();
    dequeue();
    printf("\n");
    display();
    return 0;
}
