#include <stdio.h>
#include <sys/time.h>
#include <math.h>

int isPrime(int);
void drawGraph(void);
int main(int argc, char const * argv[]) {
	drawGraph();
	return 0;
}

int isPrime(int input) {
	int i;	
	if (input < 0) {
		return 0;
	}
	else if (input == 0 || input == 1 || input == 2) {
		return input;
	}
	else {
		for (i=2; i <= ((int)sqrt(input)); i++) {
			if( input % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}

void drawGraph() {
	struct timeval start_time, end_time;	
	double time_lapsed;
	int i;
	FILE *f = fopen("data2.txt", "w");	
	for(i = 999000; i < 1000001; i++){
		gettimeofday(&start_time, NULL);
		if (isPrime(i)) {
			gettimeofday(&end_time, NULL);
			time_lapsed = (double)(end_time.tv_usec - start_time.tv_usec);
			fprintf(f, "%d\t", i);
			fprintf(f, "%f\n", (double)time_lapsed);
		}
	}
	fclose(f);
}
