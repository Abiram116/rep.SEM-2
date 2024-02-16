#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;
struct node *curr = NULL;

void insert_create() {
    struct node *newnode;
    int e;
    printf("Enter the element: ");
    scanf("%d", &e);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->link = NULL;
    if (start == NULL) {
        start = newnode;
    } else {
        curr->link = newnode;
    }
    curr = newnode;
}

void display() {
    struct node *temp = start;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void insert_at_begin() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int e;
    printf("Enter the element: ");
    scanf("%d", &e);
    newnode->data = e;
    newnode->link = start;
    start = newnode;
}

void insert_end() {
    struct node *newnode;
    int e;
    printf("Enter the element: ");
    scanf("%d", &e);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->link = NULL;
    if (start == NULL) {
        start = newnode;
    } else {
        curr->link = newnode;
    }
    curr = newnode;
}

void insert_at_pos() {
    struct node *prev = start, *next;
    int i = 1, e, pos;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    printf("Enter the element: ");
    scanf("%d", &e);
    while (prev != NULL) {
        if (i == pos) {
            break;
        } else {
            i++;
            next = prev;
            prev = prev->link;
        }
    }
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->link = next->link;
    next->link = newnode;
}

void max() {
    struct node *temp = start;
    int max = temp->data;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->link;
    }
    printf("\nMaximum element: %d\n", max);
}

void min() {
    struct node *temp = start;
    int min = temp->data;
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->link;
    }
    printf("\nMinimum element: %d\n", min);
}

void count() {
    struct node *temp = start;
    int c = 0;
    while (temp != NULL) {
        c++;
        temp = temp->link;
    }
    printf("\nCount of nodes: %d\n", c);
}

void search() {
    int i = 1, key;
    struct node *temp = start;
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position: %d\n", i);
            return;
        }
        i++;
        temp = temp->link;
    }
    printf("Element not found\n");
}

void del_at_begin() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    printf("Deleted element is %d\n", temp->data);
    start = start->link;
    free(temp);
}

void del_at_end() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    struct node *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    if (prev != NULL) {
        printf("Deleted element is %d\n", temp->data);
        prev->link = NULL;
        free(temp);
    } else {
        printf("Deleted element is %d\n", start->data);
        free(start);
        start = NULL;
    }
}

void del_at_pos() {
    struct node *prev = NULL;
    struct node *temp = start;
    int i = 1, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        del_at_begin();
        return;
    }
    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->link;
        i++;
    }
    if (temp == NULL) {
        printf("Position not found\n");
        return;
    }
    prev->link = temp->link;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

void bubble() {
    int t;
    struct node *temp, *prev, *next;
    temp = start;
    while (temp != NULL) {
        prev = temp;
        next = temp->link;
        while (next != NULL) {
            if (prev->data > next->data) {
                t = prev->data;
                prev->data = next->data;
                next->data = t;
            }
            prev = next;
            next = next->link;
        }
        temp = temp->link;
    }
}

void sort() {
    bubble(); // Assuming bubble sort function is implemented
    printf("List sorted successfully\n");
}

int main() {
    while (1) {
        printf("\n2310030334-Harshith\n");
        printf("Enter one option from the following\n");
        printf("1. Insert\n2. Display\n3. Insert at begin\n4. Insert at end\n5. Insert at position\n6. Maximum\n7. Minimum\n8. Count of Nodes\n9. Search\n10. Delete at begin\n11. Delete at end\n12. Delete at Position\n13. Sort\n14. Exit\n");
        int c, flag = 1;
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                insert_create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_at_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_at_pos();
                break;
            case 6:
                max();
                break;
            case 7:
                min();
                break;
            case 8:
                count();
                break;
            case 9:
                search();
                break;
            case 10:
                del_at_begin();
                break;
            case 11:
                del_at_end();
                break;
            case 12:
                del_at_pos();
                break;
            case 13:
                sort();
                break;
            case 14:
                flag = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if (flag == 0)
            break;
    }
    return 0;
}