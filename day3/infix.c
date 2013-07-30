#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define SIZE 20

/* variables for stack ADT */
static char Stack[SIZE];
static int pos = -1;
void display(void);

/* function prototypes for stack
 * both return 1 on success and
 * 0 on failure */
int push(char);
int pop(char *);

/* get operator function prototype */
int getop(char [], char []);

/* get precidance order or an operator */
int getorder(char);

/* main function */
int main(int argc, char *argv[])
{
    char infix[MAXOP];
    char op[20], poped;
    int type;

    if(argc < 2)
    {
        puts("Usage: ./infix.o \"INFIX_EXPRESSION\"\n");
        return 0;
    }
    else
    {
        strcpy(infix, argv[1]);
        type = getop(infix, op);
        while (op[0] != '\0')
        {
            if (type)
                printf("%f ", atof(op));
            else
            {
                if (op[0] == ')')
                {
                    if (pop(&poped))
                    {
                        while (poped != '(')
                        {
                            printf("%c ", poped);
                            if (!pop(&poped))
                            {
                                printf("error: wrong input\n");
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        printf("error: wrong input\n");
                        return 0;
                    }
                }
                else
                {
                    while (pos > -1 && getorder(op[0]) < getorder(Stack[pos]) && Stack[pos] != '(' && op[0] != '(')
                    {
                        pop(&poped);
                        printf("%c ", poped);
                    }
                    if(!push(op[0]))
                        return 0;
                }
            }
            //display();
            type = getop(infix, op);
        }

        while (pos > -1)
            printf("%c ", Stack[pos--]);

        printf("\n");
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
int push(char value)
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

int pop(char *poped)
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
        printf("%c ", Stack[i++]);
    printf("\n");
}
