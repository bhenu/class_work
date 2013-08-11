/* function prototypes */
int getorder(char);
double pfxcal(char exps[]);

/* main function */
int pfxcal(int argc, char *argv[])
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

        /*  print the result */
        if (pos > 0)
            printf("something went wrong. check if the input is correct.\n");
        else
            printf("result: %.2f\n", Stack[pos]);

    }

    return 0;
}

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
