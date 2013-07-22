#include<stdio.h>

int main()
{
    char s[] = "hello world";
    printf("%s\n", &s[2]);
    printf("%s\n", s);
    printf("%s\n", &s);
    printf("%c\n", s[2]);

}
