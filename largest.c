#include<stdio.h>

int main(void)
{
    int largest = -9999;
    int current;
    int i = 0;

    printf("Enter 10 numbers seperated by a space\n");
    while(i < 10)
    {
        scanf("%d", &current);
        largest = largest>current?largest:current;
        i++;
    }

    printf("the largest number is: %d\n", largest);

    return 0;
}
