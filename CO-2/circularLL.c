#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *start = NULL, *curr = NULL;

void insert_at_beginning(int n) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    if (start == NULL) {
        start = newnode;
        newnode->link = start;
        curr = newnode;
    } else {
        newnode->link = start;
        curr->link = newnode;
        start = newnode;
    }
}

void insert_at_end(int n) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    if (start == NULL) {
        start = newnode;
        newnode->link = start;
        curr = newnode;
    } else {
        newnode->link = start;
        curr->link = newnode;
        curr = newnode;
    }
}

void delete_element(int key) {
    if (start == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *prev = curr;
    struct node *temp = start;
    do {
        if (temp->data == key) {
            if (temp == start) {
                prev->link = temp->link;
                start = start->link;
                free(temp);
                printf("Element %d deleted successfully.\n", key);
                if (prev->link == start) // If only one node is left after deletion
                    curr = prev; // Update curr to the previous node
                return;
            } else {
                prev->link = temp->link;
                free(temp);
                printf("Element %d deleted successfully.\n", key);
                return;
            }
        }
        prev = temp;
        temp = temp->link;
    } while (temp != start);

    printf("Element %d not found in the list.\n", key);
}

void display() {
    struct node* temp = start;
    
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Circular linked list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != start);
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete an element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete_element(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
