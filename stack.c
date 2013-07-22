#include<stdio.h>
#define STACK_SIZE 1000

void pop(char *, int *);
void push(char *, int *);

int main(void)
{
    char stack[STACK_SIZE];
    int pos= -1; /*index position of stack*/

    }

void push(char * stack, int * pos)
{
    int n;
    if(*pos >= STACK_SIZE)
        printf("Stack is full!\n");
    else
    {
        printf("Enter an integer to push:\n");
        scanf("%d", &n);
        stack[++(*pos)];
    }
}

void pop(char * stack, int * pos)
{
    if(*pos <= -1)
        printf("Stack is empty\n");
    else
    {
        printf("%d removed from position %d of the stack.\n", stack[*pos], *pos);
        *pos--;
    }
}
