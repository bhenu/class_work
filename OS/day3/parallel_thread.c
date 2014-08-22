#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

int fib(int);
void * thread1();
void * thread2();

int main(){
	pthread_t tid1, tid2;
	// Make the program run on a single cpu
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	  
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}

void * thread1(){
	cpu_set_t core;
	CPU_ZERO(&core);
	CPU_SET(0, &core);
	struct timeval current_time;
	int i;
	FILE *f1;
	sched_setaffinity(0, sizeof(cpu_set_t), &core);
	f1 = fopen("data1.dat", "w");
	        for (i = 0; i < 100000; i++) {
	                gettimeofday(&current_time, NULL);
	                fprintf(f1, "%f\t1\n", (double)current_time.tv_usec);
	        }
	        fclose(f1);
}

void *thread2(){
	cpu_set_t core;
	CPU_ZERO(&core);
	CPU_SET(1, &core);	
	struct timeval current_time;
	int i;
	FILE *f2;
	sched_setaffinity(0, sizeof(cpu_set_t), &core);
	f2 = fopen("data2.dat", "w");
	        for (i = 1; i < 100000; i++) {
	                gettimeofday(&current_time, NULL);
	                fprintf(f2, "%f\t2\n", (double)current_time.tv_usec);
	        }
	        fclose(f2);	
}