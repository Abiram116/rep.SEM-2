#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL, *curr = NULL;

void insert() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;

    if (start == NULL) {
        start = curr = newnode;
    } else {
        curr->link = newnode;
        curr = newnode;
    }
}

void insert_at_begin(){
    struct node* newnode =(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
        newnode->link = start;
        start=newnode;
}

void insert_at_end(){
    struct node* newnode =(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    curr->link=newnode;
}

void display() {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main() {
    char choice;
    int exit_flag = 0;

    do {
        printf("1.Insert\n2.Insert at begin\n3.Insert at end\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                insert();
                break;
            case '2':
                insert_at_begin();
                break;
            case '3':
                insert_at_end();
                break;
            case '4':
                display();
                break;
            case '5':
                exit_flag = 1;
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (!exit_flag);

    return 0;
}
