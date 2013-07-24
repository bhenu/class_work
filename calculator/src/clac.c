#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"calc.h"

#define MAXOP 100

int main(int argc, char * argv[])
{
    double v1, v2;
    char op[20];        /* store the output of getop */
    char * exp;
    int j = 0;          /* index of expression */

    if(argc < 1)
    {
        printf("Usage: calc POSTFIX_EXPRESSION\n");
        return 0;
    }
    exp = argv[1];
    while( exp[j] != '\0')
    {
        printf("%s || %d\n", op, getop(op, &j, argv[1]));
        /*if(getop(op, &j, argv[1]) == '\0')
            push(atof(op));
        else
        {
            switch(op[0])
            {
                case '+':   v1 = pop();
                            v2 = pop();
                            push(v2+v1);
                            break;
                case '-':   v1 = pop();
                            v2 = pop();
                            push(v2-v1);
                            break;
                case '*':   v1 = pop();
                            v2 = pop();
                            push(v2*v1);
                            break;
                case '/':   v1 = pop();
                            v2 = pop();
                            push(v2/v1);
                            break;
                default:
                            printf("error: unknown command %s\n", op);
                            break;
                }
            }*/
        }

        printf("result: %f\n", pop());

        return 0;
}
