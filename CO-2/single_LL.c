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

int find_min() {
    int min_value = start->data;
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->data < min_value) {
            min_value = temp->data;
        }
        temp = temp->link;
    }

    return min_value;
}

int find_max() {
    int max_value = start->data;
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->data > max_value) {
            max_value = temp->data;
        }
        temp = temp->link;
    }

    return max_value;
}

int main() {
    char choice;
    int exit_flag = 0;

    do {
        printf("1.Insert\n2.Insert at begin\n3.Insert at end\n4.Find Max value\n5.Find Min value\n6.Display\n7.Exit\n");
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
                find_max();
                break;
            case '5':
                find_min();
                break;
            case '6':
                display();
                break;
            case '7':
                exit_flag = 1;
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (!exit_flag);

    return 0;
}
