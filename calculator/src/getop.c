#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int getop(char s[], int *j, char * exp);

/*test*/
/*int main(void)
{
    char exp[] = " + 12.24  3";
    char op[20];
    int j = 0;
    while(exp[j] != '\0')
    {
        getop(op, &j, exp);
        printf("operator %s\n", op);
    }
    return 0;
}
*/

int getop(char s[], int *j, char * exp) /* output, index of current
                                       character in exp[], expression */
{
    int i, c;

    while((s[0] = c = exp[(*j)++]) == ' ' || c == '\t')
    {
        printf("space\n");
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /*not a number*/
    i = 0;
    if(isdigit(c))      /*collect integer part*/
        while(isdigit(s[++i] = c = exp[(*j)++]))
            ;
    if (c == '.')       /*collect fraction part*/
        while (isdigit(s[++i] = c = exp[(*j)++]))
            ;
    s[i] = '\0';
    if (c != '\0')
        (*j)--;
    return '\0';
}
