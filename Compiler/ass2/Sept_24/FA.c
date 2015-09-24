#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int nstates, nchars, ntransitions, iii, jjj;
	char *buff;
	
	printf("%s\n", "Enter the no of states: ");
	scanf("%d", &nstates);
	char *states[nstates];

	iii = 0;
	printf("%s\n", "Enter the states separated by space: ");
	while(iii < nstates){
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		states[iii++] = buff;
	}

	printf("%s\n", "Enter the no of input alphabets: ");
	scanf("%d", &nchars);
	char chars[nchars];

	iii = 0;
	printf("%s\n", "Enter the input alphabets separated by space: ");
	while(iii < nchars){
		chars[iii] = getchar();
		if (chars[iii] != ' ' && chars[iii] != '\n' && chars[iii] != '\t'){
			iii++;
		}
	}

	ntransitions = nstates*nchars;
	char *transitions[ntransitions];
	iii = 0;
	while(iii < ntransitions){
		printf("Enter transition for [%s]->[%c]: \n", states[iii/nchars], chars[iii%nchars]);
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		transitions[iii++] = buff;
	}

	/* print the table */
	jjj = iii = 0;
	printf("\t");
	while(jjj < nchars){
		printf("%c\t", chars[jjj++]);
	}
	printf("\n");
	while(iii < nstates){
		
	}

	return 0;
}