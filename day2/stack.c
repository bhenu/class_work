#include<stdio.h>
#define SIZE 10

void pop(void);
void push(int);
void display(void);

int Stack[SIZE];   //global variable to hold the Stack
int pos=-1;          //position of the topmost element

int main(void)
{
    int n = 5;
    int value= 5;

    while(n != 0)
    {
        printf("## 1: push\n## 2: pop\n## 3: display\n## 0: quit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1: printf("Enter an integer to push\n");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
        }
    }
    return 0;
}

void push(int value) //value to push into the Stack
{
    if(pos >= (SIZE -1))
        printf("Stack is full!\n");
    else
    {
        Stack[(++pos)] = value;
        printf("pushed!\n");
    }
}

void pop(void)
{
    if(pos <= -1)
        printf("Stack is empty\n");
    else
    {
        printf("%d poped from position %d of the Stack.\n", Stack[pos], pos);
        pos--;
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
