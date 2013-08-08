
#include<stdio.h>
#define SIZE 10

void pop(int type);
void push(int type, int value);
void display(void);

int Stack[SIZE];                   //global variable to hold the Stack
int pos1=-1, pos2 = SIZE;          //position of the topmost element

int main(void)
{
    int n = 5, type = 1;
    int value= 5;

    while(n != 0)
    {
        printf("## 1: push\n## 2: pop\n## 3: display\n## 0: quit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                    printf("choose a stack: 1 or 2\n");
                    scanf("%d", &type);
                    type--;printf("Enter an integer to push\n");
                    scanf("%d", &value);
                    push(type, value);
                    break;
            case 2:
                    printf("choose a stack: 1 or 2\n");
                    scanf("%d", &type);
                    type--;
                    pop(type);
                    break;
            case 3: display();
                    break;
        }
    }
    return 0;
}

void push(int type, int value) //value to push into the Stack
{
    if(type)
    {
        if(pos2 <= (pos1+1))
            printf("Stack is full! \n");
        else
        {
            Stack[--pos2] = value;
            printf("pushed to stack 2\n");
        }
    }
    else
    {
        if(pos1 >= (pos2-1))
            printf("Stack is full!\n");
        else
        {
            Stack[(++pos1)] = value;
            printf("pushed! to stack 1\n");
        }
    }
}

void pop(int type)
{
    if(type)
    {
        if(pos2 >= SIZE)
            printf("Stack is empty\n");
        else
        {
            printf("%d removed from stack 2.\n", Stack[pos2]);
            pos2++;
        }
    }
    else
    {
        if(pos1 <= -1)
            printf("Stack is empty\n");
        else
        {
            printf("%d removed from stack 1.\n", Stack[pos1]);
            pos1--;
        }
    }
}

void display(void)
{
    int i,j;
    printf("-S1------S2-\n");
    for(i = pos1, j = pos2; (i > -1) || j  < SIZE; )
        printf(" %d\t%d\n", Stack[i--], Stack[j++]);
    printf("-------------\n");
}
