
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define SIZE 30

/* variables for stack ADT */
static double Stack[SIZE];
static int pos = -1;
void display(void);

/* function prototypes for stack
 * both return 1 on success and
 * 0 on failure */
int push(double);
int pop(double *);

/* get operator function prototype */
int getop(char [], char []);

/* get precidance order or an operator */
int getorder(char);

/* main function */
int main(int argc, char *argv[])
{
    char postfix[MAXOP];
    char op[20];
    int type;
    double v1, v2;

    if(argc < 2)
    {
        puts("Usage: ./pfxcal.o \"POSTFIX_EXPRESSION\"\n");
        return 0;
    }
    else
    {
        strcpy(postfix, argv[1]);
        type = getop(postfix, op);
        while(op[0] != '\0')
        {
            if (type)
            {
                if(!push(atof(op)))
                    printf("error: can't push\n");
            }
            else
            {
                switch (op[0])
                {
                    case '+':   pop(&v1);
                                pop(&v2);
                                push((v2 + v1));
                                break;
                    case '-':   pop(&v1);
                                pop(&v2);
                                push((v2 - v1));
                                break;
                    case '*':   pop(&v1);
                                pop(&v2);
                                push((v2 * v1));
                                break;
                    case '/':   pop(&v1);
                                pop(&v2);
                                push((v2 / v1));
                                break;
                    default:    printf("error:wrong input %c\n", op[0]);
                                break;
                }
            }

            type = getop(postfix, op);
        }

        display();

    }

    return 0;
}

/* ****************************************************************** */
/* get digit or character from given string */
int getop(char string[], char op[])
{
    static int idx = 0;
    char c;     /* temp variable to store current char */
    int i;

    while ((op[0] = c = string[idx++]) == ' ' || c == '\t')
    /* loop through spaces */
        ;
    op[1] = '\0';

    if (!isdigit(c) && c != '.') /* not a number or decimal point */
        return 0;

    i = 0;
    if (isdigit(c))
        while (isdigit(op[++i] = c = string[idx++]))
            ;
    if (c == '.')
        while (isdigit(op[++i] = c = string[idx++]))
            ;
    op[i] = '\0';

    if(c != '\0')
        idx--;

    return 1;
}

/* ****************************************************************** */
/* definition of get precedance order */
int getorder(char c)
{
    char order[] = "-+/*";
    int i;

    for (i = 0; order[i] != c && i < 4; i++)
        ;
    if (i == 4)
        return -1;
    else
        return i;
}


/* ****************************************************************** */
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

void display(void)
{
    int i = 0;
    printf("stack: ");
    while (i <= pos)
        printf("%f ", Stack[i++]);
    printf("\n");
}
