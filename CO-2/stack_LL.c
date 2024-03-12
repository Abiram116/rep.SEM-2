#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Stack structure
typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->items[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to peek at the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to display the elements of the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popping: %d\n", pop(&stack));
    printf("Popping: %d\n", pop(&stack));

    display(&stack);

    return 0;
}