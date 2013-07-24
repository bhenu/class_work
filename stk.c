static double Stack[SIZE];    //global variable to hold the Stack
static int pos=-1;         //position of the topmost element

void push(double value) //value to push into the Stack
{
    if(pos >= (SIZE -1))
        printf("Stack is full!\n");
    else
    {
        Stack[(++pos)] = value;
        printf("pushed!\n");
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
        printf("%d\n", Stack[i]);
    printf("--------\n");
}

