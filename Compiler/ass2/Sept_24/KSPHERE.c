#include <stdio.h>
#include <stdlib.h>

int sum;

int combine(int * T, int * freq, int n, int k){
	int U[2000];
	int iii, jjj;

	// printf("n: %d, k: %d\n T: ", n, k);
	for(iii=0; iii<k; iii++){
		U[iii] = T[iii];
		// printf("%d ", T[iii]);
	}
	// printf("\n");

	iii = k;
	while(iii>=1 && T[iii-1] == n-k+iii){
		iii--;
	}
	if(iii==0){
		return 0;
	}
	else{
		for(jjj=iii; jjj<=k; jjj++){
			U[jjj-1] = T[iii-1] + 1 + jjj - iii;
		}
		// for(iii=0; iii<k; iii++){
		// 	printf("%d ", U[iii]);
		// }
		// printf("\n");
	}
	int lsum = 1; 
	for(iii=0; iii<k; iii++){
		lsum *= freq[U[iii] - 1];
	}
	sum += lsum;
	while(combine(U, freq, n, k));
	return 0;
}

int main(){
	int n, m, c, iii, jjj;
	scanf("%d%d%d", &n, &m, &c);

	// take the inputs
	int uphems[100001];
	int lowhems[100001];

	for(iii=0; iii<n; iii++){
		scanf("%d", &uphems[iii]);
	}

	for(iii=0; iii<m; iii++){
		scanf("%d", &lowhems[iii]);
	}

	// count the freq and sort
	int * frequ;
	int * freql;
	frequ  = (int *)calloc(1001, sizeof(int));
	freql  = (int *)calloc(1001, sizeof(int));

	for(iii=0; iii<n; iii++){
		frequ[uphems[iii]]++;
	}
	for(iii=0; iii<m; iii++){
		freql[lowhems[iii]]++;
	}
	for(iii=1; iii<=1001; iii++){
		frequ[iii] *= freql[iii];
	}

	for(iii=1, jjj=0; iii<=1001; iii++){
		if(frequ[iii]){
			freql[jjj] = frequ[iii];
			uphems[jjj++] = iii;
		}
	}

	int numelems = jjj;
	// printf("length: %d\n", numelems);
	int T[2000];
	for(iii=2; iii<=c+1; iii++){
		if(iii > numelems){
			printf("%d ", 0);
			continue;
		}
		// generate T and initial sum
		sum = 1;
		for(jjj=1; jjj<=numelems; jjj++){
			T[jjj-1]=jjj;
			sum *= freql[jjj-1];
		}

		combine(T, freql, numelems, iii);
		printf("%d ", sum);
	}
	printf("\n");

	return 0;
}