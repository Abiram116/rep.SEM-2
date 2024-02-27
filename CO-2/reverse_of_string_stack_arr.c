#include <stdio.h>
#include <string.h>
#define ms 100

struct Stack {
    int top;
    char array[ms];
};

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

void revstr(char* str) {
    int length =strlen(str);
    struct Stack stack;
    stack.top= -1;
    for (int i=0;i<length;i++)
        push(&stack,str[i]);
    for (int i=0;i<length;i++)
        str[i]=pop(&stack);
}
int main() {
    char str[ms];
    printf("Enter a string: ");
    fgets(str,ms,stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    printf("Original string: %s\n",str);
    revstr(str);
    printf("Reversed string: %s\n",str);
}
