#include<stdio.h>
int main()
{

  int t,c,n,r;
  r=0;
  printf("enter number\n");
  scanf("%d",&n);
  t=n;
  while(n!=0)
  {
    c=n%10;
    n=n/10;
    r=r*10+c;
    }
  if(r=t)
    printf("%d is palindrome number\n",t);
  else
    printf("%d is not palindrome\n",t);
}
