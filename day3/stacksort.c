#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define MAXOP 100

static struct STACK
{
    int stack[SIZE];
    int pos;
};

/* function prototypes for stack
 * both return 1 on success and
 * 0 on failure */
int push(int, struct STACK *);
int pop(int *, struct STACK *);
void display(struct STACK);
int fill_stack(struct STACK *);

/* function prototype for getop */
int getop(char [], int *, char []);



/* ######################### MAIN LOGIC ############################# */

int main(int argc, char *argv[])
{
    struct STACK stack1, stack2, stack3;
    stack1.pos = stack2.pos = stack3.pos = -1; //stack initialization

    int tmp, poped;

    /* take input into stack */
    printf("Stack 1: \n");
    fill_stack(&stack1);
    printf("Stack 2: \n");
    fill_stack(&stack2);
    printf("Stack 3: \n");
    fill_stack(&stack3);

    /* sorting algorithm */
    while (stack1.pos > -1)
    {
        pop(&poped, &stack1);
        push(poped, &stack3);
    }
    while (stack2.pos > -1)
    {
        tmp = stack3.pos;
        while ( stack1.stack[stack1.pos] < stack2.stack[stack2.pos] && stack1.pos > -1)
        {
            pop(&poped, &stack1);
            push(poped, &stack3);
        }
        pop(&poped, &stack2);
        push(poped, &stack1);
        while (stack3.pos > tmp)
        {
            pop(&poped, &stack3);
            push(poped, &stack1);
        }
    }

    while (stack3.pos > -1)
    {
        tmp = stack2.pos;
        while ( stack1.stack[stack1.pos] < stack3.stack[stack3.pos] && stack1.pos > -1)
        {
            pop(&poped, &stack1);
            push(poped, &stack2);
        }
        pop(&poped, &stack3);
        push(poped, &stack1);
        while (stack2.pos > tmp)
        {
            pop(&poped, &stack2);
            push(poped, &stack1);
        }
    }

    display(stack1);

    return 0;
}

/* ###############################O################################## */



/* definition of stack functions */
int push(int value, struct STACK *mystack)
{
    if(mystack->pos < (SIZE -1))
    {
        mystack->stack[++(mystack->pos)] = value;
        return 1;
    }
    else
    {
        printf("error: stack is full\n");
        return 0;
    }
}

int pop(int *poped, struct STACK *mystack)
{
    if(mystack->pos > -1)
    {
        *poped = mystack->stack[(mystack->pos)--];
        return 1;
    }
    else
    {
        printf("error: Stack is empty\n");
        return 0;
    }
}

void display(struct STACK mystack)
{
    int i = 0;
    while (i <= mystack.pos)
        printf("%d ", mystack.stack[i++]);
    printf("\n");
}

/* definition of getop function */
int getop(char string[], int *idx, char op[])
{
    char c;     /* temp variable to store current char */
    int i;

    while ((op[0] = c = string[(*idx)++]) == ' ' || c == '\t')
    /* loop through spaces */
        ;
    op[1] = '\0';

    if (!isdigit(c) && c != '.') /* not a number or decimal point */
        return 0;

    i = 0;
    if (isdigit(c))
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    if (c == '.')
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    op[i] = '\0';

    if(c != '\0')
        (*idx)--;

    return 1;
}

/* function to take input into the stacks */
int fill_stack(struct STACK *mystack)
{
    char input[MAXOP], op[20];
    int type, indx = 0;

    printf("Enter elements of the stack [type int] seperated by a space:\n");
    fgets(input, MAXOP, stdin);

    type = getop(input, &indx, op);
    while(op[0] != '\0')
    {
        if (type)
            push(atoi(op), mystack);

        type = getop(input, &indx, op);
    }

    return 1;
}
