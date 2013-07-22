#include<stdio.h>

int fact(int);

int main(void)
{
    int n;
    printf("enter a number:\n");
    scanf("%d", &n);
    printf("the factorial of %d is %d\n", n, fact(n));
    return 0;
}

int fact(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
    {
        return n*fact(n - 1);
    }
}
