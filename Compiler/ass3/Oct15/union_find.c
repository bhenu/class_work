#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int * id;
	int * wt;
} union_set;

union_set * getcollection(int nelem){
	union_set * S = (union_set *)calloc(1, sizeof(union_set));
	S->id = (int *)calloc(nelem, sizeof(int));
	S->wt = (int *)calloc(nelem, sizeof(int));
	for (int iii = 0; iii < nelem; ++iii){
		S->id[iii] = iii;
		S->wt[iii] = 1;
	}
	return S;
}

int root(union_set * S, int a){
	int temp1 = a;
	int temp2;
	while(S->id[a] != a){
		a = S->id[a];
	}
	while(S->id[temp1] != temp1){
		temp2 = temp1;
		temp1 = S->id[temp1];
		S->id[temp2] = a;
	}
	return a;
}

int insameset(union_set * S, int a, int b){ //returns ture
	if(root(S, a) == root(S, b)){
		return 1;
	}
	return 0;
}

void unite(union_set *S, int a, int b){
	int i = root(S, a);
	int j = root(S, b);
	if(S->wt[i] < S->wt[j]){
		S->id[i] = j;
		S->wt[j] += S->wt[i];
	}
	else {
		S->id[j] = i;
		S->wt[i] += S->wt[j];
	}
}

int main(){
	union_set * S = getcollection(5);
	if(insameset(S, 0, 1)){
		printf("YES\n");	
	}
	else{
		printf("NO\n");
	}

	unite(S, 2, 3);
	if(insameset(S, 2, 3)){
		printf("YES\n");	
	}
	else{
		printf("NO\n");
	}

	return 0;
}