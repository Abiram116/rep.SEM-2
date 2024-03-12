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
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->link = start;
    start=newnode;
}

void insert_at_end(){
    struct node* newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if (curr != NULL)
        curr->link = newnode;
    curr=newnode;
}

void display() {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int find_min() {
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

void reverse_list() {
    struct node *prev = NULL;
    struct node *current = start;

    while (current != NULL) {
        struct node *next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    start = prev; // Update start to point to the new head of the reversed list
}


int main() {
    char choice;
    int exit_flag = 0;

    do {
        printf("\n1.Insert\n2.Insert at begin\n3.Insert at end\n4.Find Max value\n5.Find Min value\n6.Display\n7.Reverse List\n8.Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Notice the space before %c to consume newline

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
                printf("Maximum value: %d\n", find_max());
                break;
            case '5':
                printf("Minimum value: %d\n", find_min());
                break;
            case '6':
                display();
                break;
            case '7':
                reverse_list();
                printf("List reversed.\n");
                break;
            case '8':
                exit_flag = 1;
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (!exit_flag);

    // Free memory before exiting
    struct node *temp = start;
    while (temp != NULL) {
        struct node *next = temp->link;
        free(temp);
        temp = next;
    }

    return 0;
}