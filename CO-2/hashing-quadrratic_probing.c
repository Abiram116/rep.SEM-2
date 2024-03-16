#include<stdio.h>
#include<stdlib.h>

#define n 10

struct node {
    int x;
    struct node *link;
} *a[n];

void insert(int value) {
    int k = value % n;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->x = value;
    newnode->link = NULL;

    if (a[k] == NULL) {
        a[k] = newnode;
    } else {
        // Quadratic probing
        int i = 1;
        int index = (k + i * i) % n;
        while (a[index] != NULL && index != k) {
            i++;
            index = (k + i * i) % n;
        }
        if (a[index] == NULL) {
            a[index] = newnode;
        } else {
            printf("Hash table is full. Unable to insert %d.\n", value);
            free(newnode);
        }
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
        a[i] = NULL;

    insert(5);
    insert(15);
    insert(25);
    insert(6);
    insert(16);
    insert(26);
    insert(7);
    insert(17);
    insert(27);
    insert(8);

    display();

    return 0;
}
