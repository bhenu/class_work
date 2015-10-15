#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOTE: Use $ for epsilon transitions */

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

void eClosure(	char ** states, 
				int nstates,
				int nchars,
				transition * transitions,
				int * visited,
				int startState,
				int epsilon){
	int si, iii;
	printf("%s ", states[startState]);
	for(iii=0; iii<transitions[startState*nchars + epsilon].nstates; iii++){
		si = transitions[startState*nchars + epsilon].states[iii];
		if(si == -1){
			printf("Invalid transition.\n");
			break;
		}
		if(!visited[si]){
			visited[si] = 1;
			eClosure(states, nstates, nchars, transitions,  visited, si, epsilon);
		}
	}
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

	int epsilon = getCindex(chars, '$', nchars);
	if(epsilon == -1){
		printf("there are no epsilon transitions.\n");
		return 0;
	}

	int visited[nstates];
	int si;
	for(iii=0; iii<nstates; iii++){
		memset(visited, 0, sizeof(int)*nstates);
		printf("eClosure of %s: ", states[iii]);
		eClosure(states, nstates, nchars, transitions, visited, iii, epsilon);
		puts("");
	}
	
	return 0;
}