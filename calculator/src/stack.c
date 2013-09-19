/* Stack data-type definition */
static struct STACK
{
    int stack[SIZE];
    int pos;
};

/* Stack function definitions */
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
    printf("stack: ");
    while (i <= mystack.pos)
        printf("%d ", mystack.stack[i++]);
    printf("\n");
}
