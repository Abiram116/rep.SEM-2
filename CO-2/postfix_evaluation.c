#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(int op) {
    if (top == 19) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = op;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; 
    }
    return stack[top--];
}

int main() {
    char expr[30];
    int i, operand1, operand2;

    printf("Enter the postfix expression: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');//ASCII digit to integer
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (expr[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    if (operand1 == 0) {
                        printf("Division by zero\n");
                        return 1;
                    }
                    push(operand2 / operand1);
                    break;
                default:
                    printf("Invalid character in expression\n");
                    return 1;
            }
        }
    }
    if (top != 0) {
        printf("Invalid expression\n");
        return 1;
    }
    printf("Result: %d\n", stack[top]);
}
