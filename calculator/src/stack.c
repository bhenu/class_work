#include<stdio.h>
#define SIZE 20

static struct STACK
{
    int stack[SIZE];
    int pos;
};        //position of the topmost element

void push(double value) //value to push into the Stack
{
    if(pos >= (SIZE -1))
        printf("Stack is full!\n");
    else
    {
        Stack[(++pos)] = value;
    }
}

double pop(void)
{
    if(pos <= -1)
    {
        printf("Stack is empty\n");
        return 0.0;
    }
    else
    {
        return Stack[pos--];
    }
}

void display(void)
{
    int i;
    printf("--------\n");
    for(i = pos; i > -1; i--)
        printf("%f\n", Stack[i]);
    printf("--------\n");
}

