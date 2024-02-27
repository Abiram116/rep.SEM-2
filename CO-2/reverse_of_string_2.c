
#include<stdio.h>
#define size 10
char stack[size];
int top=-1;

void push(char ele)
{
  if(top==size)
  {
    printf("stack is full\n");
    return;
  }
  else
  {
    stack[++top]=ele;
  }
}

int pop()
{
  if(top==-1)
  {
    printf("stack is empty\n");
    return -1;
  }
  else
  {
    printf("%c\n",stack[top--]);
  }
}

void display()
{
  int i;
  for(i=top;i>=0;i--)
  {
    printf("%c ",stack[i]);
  }
  printf("\n");
}

void main()
{
  int i;
  char s[20];
  printf("Enter String ");
  scanf("%s",s);
  for(i=0;s[i]!=0;i++)
  push(s[i]);
  display();
  printf("Deleted :\n");
  for(i=top;i>=0;i--)
  pop();
}