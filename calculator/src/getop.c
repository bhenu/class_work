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

