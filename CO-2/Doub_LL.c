#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL, *curr=NULL;
void create(int ele){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=ele;
    newnode->next=NULL;

    if(start==NULL) {
        start=newnode;
    }else{
        newnode->prev=curr;
        curr->next=newnode;
    }
    curr=newnode;
}

void display_forward(){
    printf("\nForward Traversal:\n");
    struct node*temp=start;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }printf("\n");
}

void display_backward(){
    struct node*temp=curr;
    printf("\nBackward Traversal:\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev; 
    }
}

void insert_at_begin(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int e;
    printf("Enter the element to insert at begin: ");
    scanf("%d", &e);
    newnode->data = e;
    newnode->next = start;
    newnode->prev = NULL; 
    if (start != NULL) {
        start->prev = newnode;
    }
    start = newnode;
}

void insert_at_end(){
    struct node *newnode;
    int e;
    printf("Enter the element to insert at end: ");
    scanf("%d", &e);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->prev=curr;
    newnode->next = NULL;
    curr->next = newnode;

    if (start == NULL) {
        start = newnode;
    }
    curr = newnode;
} 

/*void insert_at_pos() {
    int pos, e;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    printf("Enter the element: ");
    scanf("%d", &e);

    if (pos == 1) {
        insert_at_begin();
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;

    if (start == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        start = newnode;
        return;
    }

    struct node *temp = start;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL && pos > 1) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}*/





int main(){
    printf("\nAbhiram-2310080040\n");
    create(10);
    create(20);
    create(30);
    display_backward();
    display_forward();
    insert_at_begin();
    insert_at_end();
    display_forward();
    //insert at position to be implemented
    return 0;
}