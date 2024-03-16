#include<stdio.h>
#include<stdlib.h>

#define n 10

struct node {
    int x;
    struct node *link;
} *a[n];

void insert(int value) {
    int k;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->x = value;
    newnode->link = NULL;
    k = value % n;

    if (a[k] == NULL)
        a[k] = newnode;
    else {
        struct node *temp = a[k];
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        struct node *temp = a[i];
        printf("Index %d:", i);
        while (temp != NULL) {
            printf(" %d", temp->x);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < n; i++)
        a[i] = NULL; //initialize all the arrray spaces to NULL

    insert(5);
    insert(3);
    insert(12);
    insert(6);
    insert(14);
    insert(26);
    insert(76);
    insert(10);
    insert(20);
    insert(8);

    display();
}