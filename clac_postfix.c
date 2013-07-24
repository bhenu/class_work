#include<stdio.h>
#include<ctype.h>
#include"stk.h"

int main()
{
    char postfix_arr[100];
    int i = 0;
    double v1, v2;

    /*Input postfix expression*/
    printf("Enter postfix expression:\n");
    fgets(postfix_arr, 100, stdin);

    /*scan postfix array and calculate the value*/
    while(postfix_arr[i] =! '\n')
    {
        if(isdigit(postfix_arr[i]))
            push(postfix_arr[i] - '0');
        else
        {
            switch(postfix_arr[i])
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

}
