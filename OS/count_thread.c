#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

void * func();
int main(int argc, char const *argv[])
{
	int count = 0;
	pthread_t tid;
	struct rlimit res;
	int max_threads = getrlimit(RLIMIT_NPROC, &res);
	printf("Max threads that can be created by current user: %d\n", (int)res.rlim_cur);
	while(pthread_create(&tid, NULL, func, NULL) == 0)
		count++;

	printf("No. of threads current process was able to create: %d \n", count);
	return 0;
}

void * func(){
	getchar();
	return 0;
}