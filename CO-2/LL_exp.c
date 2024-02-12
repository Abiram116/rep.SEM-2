#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL , *curr = NULL;

void insert(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = data;
    newnode->link = NULL;

    if (start == NULL) {
        start = curr = newnode;
    } else {
        curr->link = newnode;
        curr = newnode;
    }
}

void insert_at_begin(int data){
    struct node* newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = start;
    start=newnode;
}

void insert_at_end(int data){
    struct node* newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    if(start == NULL) {
        start = newnode;
        curr = newnode;
    } else {
        curr->link = newnode;
        curr = newnode;
    }
}

void display() {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int find_min() {
    if (start == NULL) {
        return -1; // Handle empty list gracefully
    }

    int min_value = start->data;
    struct node *temp = start->link;
    while (temp != NULL) {
        if (temp->data < min_value) {
            min_value = temp->data;
        }
        temp = temp->link;
    }

    return min_value;
}

int find_max() {
    if (start == NULL) {
        return -1; // Handle empty list gracefully
    }

    int max_value = start->data;
    struct node *temp = start->link;
    while (temp != NULL) {
        if (temp->data > max_value) {
            max_value = temp->data;
        }
        temp = temp->link;
    }

    return max_value;
}

void delete_at_begin() {
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = start;
    start = start->link;
    free(temp);
}

void delete_at_end() {
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // Handle single node case
    if (start->link == NULL) {
        free(start);
        start = NULL;
        return;
    }

    // Traverse to the second last node
    struct node *temp = start;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    // Free the last node and update its previous node's link
    free(temp->link);
    temp->link = NULL;
}

void delete_at_position(int pos) {
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        delete_at_begin();
        return;
    }

    struct node *prev = start;
    struct node *temp = start->link;
    int count = 2; // Position of the second node

    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if (temp == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

int main() {
printf("%s", "Abiram-2310080040");


    char choice;
    int exit_flag = 0, data;

    while (!exit_flag) {
        printf("\n1. Insert\n");
        printf("2. Insert at begin\n");
        printf("3. Insert at end\n");
        printf("4. Find Max value\n");
        printf("5. Find Min value\n");
        printf("6. Delete at begin\n");
        printf("7. Delete at end\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case '2':
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_at_begin(data);
                break;
            case '3':
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case '4':
                if (start != NULL) {
                    printf("Maximum value: %d\n", find_max());
                } else {
                    printf("List is empty.\n");
                }
                break;
            case '5':
                if (start != NULL) {
                    printf("Minimum value: %d\n", find_min());
                } else {
                    printf("List is empty.\n");
                }
                break;
            case '6':
                delete_at_begin();
                break;
            case '7':
                delete_at_end();
                break;
            case '8':
                if (start != NULL) {
                    display();
                    printf("\n");
                } else {
                    printf("List is empty.\n");
                }
                break;
            case '9':
                exit_flag = 1;
                break;
            case '10':
            printf("Enter the position of the node to delete: ");
            int pos;
            scanf("%d", &pos);
            delete_at_position(pos);
            break;
            default:
                printf("Invalid choice!\n");
        }
    }
}
