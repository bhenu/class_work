#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int nstates, nchars, ntransitions, iii, jjj;
	char *buff;
	
	printf("%s\n", "Enter the no of states: ");
	scanf("%d", &nstates);
	char *states[nstates];
	char *startState;
	char *finalStates[nstates];

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

	printf("%s\n", "Enter the start state: ");
	buff = (char *)calloc(100, 1);
	scanf("%s", buff);
	startState = buff;

	int nfinal = 0;
	printf("%s\n", "No of final states?");
	scanf("%d", &nfinal);
	printf("%s\n", "Enter the final states separated by space");
	for(iii = 0; iii<nfinal; iii++){
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		finalStates[iii] = buff;
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
			printf("%s\t", transitions[nchars*iii + jjj]);
			jjj++;
		}
		printf("\n");
		iii++;
	}
	printf("%s: %s\n","start state", startState);
	printf("%s\n", "final states:");
	for(iii=0; iii<nfinal; iii++){
		printf("%s ", finalStates[iii]);
	}
	puts("");

	char * inputString;
	printf("%s\n", "Enter the input string: ");
	buff = (char *)calloc(100, 1);
	scanf("%s", buff);
	inputString = buff;
	int ilen = strlen(inputString);
	char * cState;
	char c;
	int si, ci;
	cState = startState;
	// printf("length%d\n", ilen);
	// printf("%s %s\n", "input string: ", inputString);
	for(iii=0; iii<ilen; iii++){
		c = inputString[iii];
		si = getSindex(states, cState, nstates);
		ci = getCindex(chars, c, nchars);
		if(ci >= 0 && si >= 0){
			cState = transitions[nchars*si + ci];
		}
		else{
			printf("%s\n", "Not accpted");
			return 0;
		}
	}
	int res = getSindex(finalStates, cState, nfinal);
	if(res >= 0 ){
		printf("%s\n", "Accepted!");		
	}
	else {
		printf("%s\n", "Not accpted.");
	}
	return 0;
}