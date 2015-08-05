#include "stdio.h"
#include "string.h"
main()
{
	char M[5][5], k[99], *m;
	scanf("%s", &k);
	int f[26]={0},i=0,j=0;
	m = M;
	f[9] = 1;
	while(j < 26){
		if (i<strlen(k))
		{
			if(!f[k[i]-97]){
				*m++ =k[i];
				f[k[i]-97]=1;
			}

		}
		else{
			if(!f[j]){
				*m++ = 'a' + j;
				f['a' + j] = 1;
			}
			j++;
		}
		i++;
	}
	m = M;
	for(i= 0; i < 25; i++){
		if(i%5 == 0) puts("");
		putchar(*m++);
	}
	return 0;
}