#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int iii, jjj, len;

	int terminals[30] = {0}; // lowercase characters and *, +, -, /
	int nonterminals[30] = {0}; // all uppercase characters
	int terminals_check[30] = {0};
	int nonterminals_check[30 = {0};

	int noter, nonter;
	printf("%s\n", "Enter no of terminals:");
	scanf("%d", &noter);
	printf("%s\n", "Enter the terminals separated by spaces:");
	iii = 0; char c;
	while(iii < noter){
		c = getchar();
		if (c != ' ' && c != '\n' && c != '\t'){
			if(islower(c)){
				terminals_check['a' - c]++;	
			}
			else{
				switch(c){
					case '*': terminals_check[26]++; break;
					case '+': terminals_check[27]++; break;
					case '-': terminals_check[28]++; break;
					case '/': terminals_check[29]++; break;
					default: printf("%s\n", "Invalid terminals symbol"); --iii;
				}
			}
			iii++;
		}
	}

	printf("%s\n", "Enter no of non terminals: ");
	scanf("%d", &nonter);
	printf("%s\n", "Enter the non terminal symbols:");
	iii=0;
	while(iii < nonter){
		c = getchar();
		if (c != ' ' && c != '\n' && c != '\t'){
			nonterminals_check['A' - c];
			iii++;
		}
	}

	char ** Productions = (char **)(calloc(npro, sizeof(char *)));
	char * buff = (char *)(calloc(100, sizeof(char)));
	int npro;
	printf("%s\n", "Enter the no of Productions:");
	scanf("%d", &npro);
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

	char startsym;
	printf("%s\n", "Enter the start symbol");
	scanf("%c", &startsym);
	while(startsym == ' ' || startsym == '\n' || startsym == '\t'){
		scanf("%c", &startsym);
	}

	iii = 0;
	while(iii < npro){
		jjj = 0;
		len = strlen(Productions[iii]);
		while(jjj < len){
			if(islower(Productions[iii][jjj])){
				terminals[Productions[iii][jjj] - 'a']++;
			}
			else if (isupper(Productions[iii][jjj])){
				nonterminals[Productions[iii][jjj] - 'A']++;
			}
			else if(Productions[iii][jjj] == '*') {
					terminals[26]++;
			}
			else if(Productions[iii][jjj] == '+') {
					terminals[27]++;
			}
			else if(Productions[iii][jjj] == '-') {
					terminals[28]++;
			}
			else if(Productions[iii][jjj] == '/') {
					terminals[29]++;
			}
			jjj++;
		}
		iii++;
	}

	/* display */
	printf("%s\n", "The Productions you entered are: ");
	iii = 0;
	while(iii < npro){
		printf("%s\n", Productions[iii++]);
	}

	printf("%s\n", "The terminals are: ");
	iii = 0;
	int comma = 0;
	while(iii < 30){
		if(terminals[iii]){
			if(iii < 26){
				if(comma){
	 				printf(", %c", 'a' + iii);
				}
				else{
	 				printf("%c", 'a' + iii);
	 				comma = 1;
				}
			}
			else{
				switch(iii){
					case 26: printf(", %c", '*'); break;
					case 27: printf(", %c", '+'); break;
					case 28: printf(", %c", '-'); break;
					case 29: printf(", %c", '/'); break;
				}
			}
		}
		iii++;
	}
	printf("\n");

	printf("%s\n", "The non terminals are: ");
	iii = 0;
	comma = 0;
	while(iii < 26){
		if(nonterminals[iii]){
			if(comma){
				printf(", %c", 'A' + iii);
			}
			else{
				printf("%c", 'A' + iii);
				comma = 1;
			}
		}
		iii++;
	}
	printf("\n");
	return 0;
}