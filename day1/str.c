#include<stdio.h>

int main(void)
{
    char mystring[1000], number[20];
    int i = 0, j=0;

    printf("Enter a desired string:\n");
    fgets(mystring, 1000, stdin);

    printf("Enter an integer:\n");
    fgets(number, 20, stdin);

    while(mystring[i++] != '\n');
    i--;
    while(number[j] != '\n')
    {
        mystring[i++] = number[j++];
    }
    i--;
    while(i >= 0)
        printf("%c", mystring[i--]);

    printf("\n");
    return 0;
}
