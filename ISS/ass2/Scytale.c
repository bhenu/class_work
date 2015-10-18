#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int m, n, len, iii, jjj, kkk;
	printf("Enter the size of the Scytale:\n");
	scanf("%d%d", &m, &n);
	char * Scytale = (char *)calloc(n*m, 8);
	char * msg = (char *)calloc(n*m, 8);
	printf("Enter the message to encrypt:\n");
	
	// escape the white space chars
	char c = getchar();
	while(iswspace(c)){
		c = getchar();
	}
	ungetc(c, stdin);
	fgets(Scytale, n*m, stdin);
	
	// print the Scytale as a matrix
	len = strlen(Scytale);
	for(iii=0, kkk =0; iii<n*m; iii++, kkk++){
		if(kkk <= len){
			// printf("kkk %d, len %d\n", kkk, len);
			printf("%c ", Scytale[iii]);
		}
		else {
			printf("  ");
		}
		if((iii+1)%m == 0){
			printf("\n");
		}
	}

	// print Scytel as encrypted text
	for(iii=0; iii<m; iii++){
		for(jjj=0; jjj<n; jjj++){
			printf("%c ", Scytale[jjj*m + iii]);
		}
	}
	printf("\n");

	return 0;
}