#include <stdio.h>
#define SIZE 20

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top < SIZE - 1) {
        stack[++top] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int main() {
    char input[SIZE], x;
    int i;
    printf("Enter expression: ");
    scanf("%s", input);
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '[' || input[i] == '{' || input[i] == '(') {
            push(input[i]);
        } else {
            x = pop();
            if ((input[i] == ']' && x != '[') ||
                (input[i] == '}' && x != '{') ||
                (input[i] == ')' && x != '(')) {
                printf("Invalid\n");
                return 0;
            }
        }
    }
    if (top == -1) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
}