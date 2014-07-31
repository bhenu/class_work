#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/time.h>

int fib(int);
int main(){
	struct timeval current_time;
	int i;

	// Make the program run on a single cpu
	cpu_set_t core;
	CPU_ZERO(&core);
	CPU_SET(0, &core);
	sched_setaffinity(0, sizeof(cpu_set_t), &core);  
	
	// Initialise the files
	FILE *f1;
	FILE *f2;

	// Fork the process
	pid_t pid;
	pid = fork();

	// Get the time for each process 
	if(pid == 0) {
        f2 = fopen("data2.dat", "w");
        for (i = 0; i < 100000; i++) {
                gettimeofday(&current_time, NULL);
                fprintf(f2, "%f\t2\n", (double)current_time.tv_usec);
        }
        fclose(f2);
	}
	else {  
        f1 = fopen("data.dat", "w");
        for (i = 0; i < 100000; i++) {
                gettimeofday(&current_time, NULL);
                fprintf(f1, "%f\t1\n", (double)current_time.tv_usec);
        }
        fclose(f1);
	}	
	return 0;
}