#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 30

char stack[MAX_SIZE][MAX_SIZE]; // Stores characters for infix expression
int top = -1;

void push(char *op) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(stack[++top], op); // Copy the string to the stack
}

char* pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return NULL; // Or any other appropriate null value
    }
    return stack[top--];
}

char* infix(char *expr) {
    int i;
    char *operand1, *operand2, temp[MAX_SIZE];

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            sprintf(temp, "%c", expr[i]); // Convert digit to string for pushing
            push(temp);
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (expr[i]) {
                case '+':
                    sprintf(temp, "(%s + %s)", operand1, operand2);
                    break;
                case '-':
                    sprintf(temp, "(%s - %s)", operand1, operand2);
                    break;
                case '*':
                    sprintf(temp, "(%s * %s)", operand1, operand2);
                    break;
                case '/':
                    sprintf(temp, "(%s / %s)", operand1, operand2);
                    break;
                default:
                    printf("Invalid character in expression\n");
                    return NULL;
            }

            push(temp);
        }
    }

    if (top != 0) {
        printf("Invalid expression\n");
        return NULL;
    }
    return stack[top]; // Infix expression is at the top of the stack
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", expr);
    char *result = infix(expr);
    if (result != NULL) {
        printf("Infix expression: %s\n", result);
    }
}
