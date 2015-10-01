#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct transition{
	int nstates;
	int * states;
} transition;

int getSindex(char ** arr, char * key, int size){
	int i = 0;
	for(i=0; i<size; i++){
		if(!strcmp(arr[i], key)){
			return i;
		}
	}
	return -1;
}

int getCindex(char * arr, char key, int size){
	int i = 0;
	for(i=0; i<size; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int nstates, nchars, ntransitions, iii, jjj, kkk;
	char *buff;
	
	printf("%s\n", "Enter the no of states: ");
	scanf("%d", &nstates);
	char *states[nstates];
	int startState;
	int finalStates[nstates];

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
	transition transitions[ntransitions];

	iii = jjj = 0;
	int nts;
	buff = (char *)calloc(100, 1);
	while(iii < ntransitions){
		printf("Enter no of transitions for [%s]->[%c]: \n", states[iii/nchars], chars[iii%nchars]);
		scanf("%d", &nts);
		transitions[iii].nstates = nts;
		transitions[iii].states = (int *)calloc(nts, sizeof(int));
		printf("Enter transitions for [%s]->[%c]: \n", states[iii/nchars], chars[iii%nchars]);
		for(jjj=0; jjj<nts; jjj++){
			scanf("%s", buff);
			transitions[iii].states[jjj] = getSindex(states, buff, nstates);
		}
		iii++;
	}

	printf("%s\n", "Enter the start state: ");
	scanf("%s", buff);
	startState = getSindex(states, buff, nstates);

	int nfinal = 0;
	printf("%s\n", "No of final states?");
	scanf("%d", &nfinal);
	printf("%s\n", "Enter the final states separated by space");
	for(iii = 0; iii<nfinal; iii++){
		scanf("%s", buff);
		finalStates[iii] = getSindex(states, buff, nstates);
	}

	/* print the table */
	jjj = iii = 0;
	printf("st/sym\t");
	while(jjj < nchars){
		printf("%c\t", chars[jjj++]);
	}
	printf("\n");
	while(iii < nstates){
		printf("%s\t", states[iii]);
		jjj = 0;
		while(jjj < nchars){
			kkk = 0;
			while( kkk < transitions[nchars*iii + jjj].nstates){
				printf("%s,", states[transitions[nchars*iii + jjj].states[kkk]]);
				kkk++;
			}
			printf("\t");
			jjj++;
		}
		printf("\n");
		iii++;
	}
	printf("%s: %s\n","start state", states[startState]);
	printf("%s\n", "final states:");
	for(iii=0; iii<nfinal; iii++){
		printf("%s ", states[finalStates[iii]]);
	}
	puts("");

	char * inputString;
	printf("%s\n", "Enter the input string: ");
	free(buff);
	buff = (char *)calloc(100, 1);
	scanf("%s", buff);
	inputString = buff;
	int ilen = strlen(inputString);
	transition cState, nState;
	cState.states= (int *)calloc(nstates, sizeof(int));
	cState.states[startState] = 1;
	char c;
	int si, ci, ni;
	for(iii=0; iii<ilen; iii++){
		c = inputString[iii];
		nState.states = (int *)calloc(nstates, sizeof(int));
		ci = getCindex(chars, c, nchars);
		if(ci >= 0){
			for(jjj=0; jjj<nstates; jjj++){
				if (cState.states[jjj]){
						for(kkk = 0; kkk < transitions[nchars*jjj + ci].nstates; kkk++){
							ni = transitions[nchars*jjj + ci].states[kkk];
							nState.states[ni] = 1;
						}
				}
			}
		}
		else{
			printf("%s\n", "Not accpted.");
			return 0;
		}

		free(cState.states);
		cState.states = nState.states;
		puts("cStates: ");
		for(int lll= 0; lll< nstates; lll++){
			if(cState.states[lll]){
				printf("%s ", states[lll]);
			}
		}
		puts("");
	}

	for(iii=0; iii<nfinal; iii++){
		if(cState.states[finalStates[iii]]){
			printf("%s\n", "Accepted!");
			return 0;
		}
	}

	printf("%s\n", "Not accpted.");
	return 0;
}