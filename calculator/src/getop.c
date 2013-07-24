#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int getop(char s[], int *j, char * exp) /* output, index of current
                                       character in exp[], expression */
{
    int i, c;

    while((s[0] = c = exp[(*j)]) == ' ' || c == '\t')
        (*j)++;
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
