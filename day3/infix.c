#include <stdio.h>
#include <string.h>
#define MAXOP 20
#define SIZE 20

/* variables for stack ADT */
static double Stack[SIZE];
static int pos = -1;

/* function prototypes for stack
 * both return 1 on success and
 * 0 on failure */
int push(double);
int pop(double *);


/* main function */
int main(int argc, char *argv[])
{
    char infix[MAXOP];
    char *postfix[];

    if(argc < 2)
    {
        puts("Usage: ./infix.o \"INFIX_EXPRESSION\"\n");
        return 0;
    }
    else
    {
        strcpy(infix, argv[1]);

    }

    return 0;
}

/* definition of stack functions */
int push(double value)
{
    if(pos < (SIZE -1))
    {
        Stack[++pos] = value;
        return 1;
    }
    else
    {
        printf("error: stack is full\n");
        return 0;
    }
}

int pop(double *poped)
{
    if(pos > -1)
    {
        *poped = Stack[pos--];
        return 1;
    }
    else
    {
        printf("error: Stack is empty\n");
        return 0;
    }
}
