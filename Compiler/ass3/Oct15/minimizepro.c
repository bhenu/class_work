#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int npro, iii;
	printf("%s\n", "Enter the no of Productions:");
	scanf("%d", &npro);

	char ** Productions = (char **)(calloc(npro, sizeof(char *)));
	char * buff = (char *)(calloc(100, sizeof(char)));
	int terminals[26] = {0};
	int nonterminals[26] = {0};
	char startsym;

	printf("%s\n", "Enter the production rules (avoid spaces): "); // formal E>ab|c
	iii = 0;
	while(iii < npro){
		scanf("%s", buff);
		Productions[iii] = (char *)(calloc(100, sizeof(char)));
		strcpy(Productions[iii], buff);
		/* chech if production is valid */
		if(isupper(Productions[iii][0]) && Productions[iii][1] == '>'){
			iii++;
		}
		else{
			printf("%s\n", "error: Invalid production rule");
		}
	}

	iii = 0;
	char nter;
	int jjj;
	while(iii < npro){
		if(Productions[iii] != NULL){
			nter = Productions[iii][0];
			/* find if the symbol exists in other productions */
			jjj = iii + 1;
			while(jjj < npro){
				if(Productions[jjj][0] == nter){
					strcat(&Productions[iii][jjj], "|");
					strcat(&Productions[iii][jjj], &Productions[jjj][2]);
					Productions[jjj] = NULL;
				}
				jjj++;
			}
		}
		iii++;
	}

	/* display the new productions */
	iii = 0;
	while(iii < npro){
		if(Productions[iii] != NULL){
			printf("%s\n", Productions[iii]);
		}
		iii++;
	}
	return 0;
}