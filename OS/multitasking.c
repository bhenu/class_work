#include <stdio.h>
#include <sys/time.h>

int main(void) {
	int i;
	struct timeval current_time;
	FILE *f = fopen("data2.dat", "w");
	for (i = 0; i < 1000000; i++) {
		gettimeofday(&current_time, NULL);
		fprintf(f, "%f\t1\n", (double)current_time.tv_usec);
	}
	fclose(f);
	return 0;
}