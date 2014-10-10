#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/time.h>

int main() {
	void *handle;
	int (*factr)(int);
	int (*facti)(int);
	char *error;
	struct timeval start_time, end_time;	
	double time_lapsedr, time_lapsedi;
	int resultr, resulti;

	handle = dlopen("/home/student/binayak/class_work/OS/day5/libfact.so", RTLD_LAZY);
	if (!handle) {
	   fprintf(stderr, "%s\n", dlerror());
	   exit(EXIT_FAILURE);
	}

	dlerror(); /* Clear any existing error */

	*(void **) (&factr) = dlsym(handle, "factr");
	*(void **) (&facti) = dlsym(handle, "facti");

	if ((error = dlerror()) != NULL)  {
	   fprintf(stderr, "%s\n", error);
	   exit(EXIT_FAILURE);
	}

	gettimeofday(&start_time, NULL);
	resultr = (*factr)(20);
	gettimeofday(&end_time, NULL);
	time_lapsedr = (double)(end_time.tv_usec - start_time.tv_usec);


	gettimeofday(&start_time, NULL);
	resulti = (*facti)(20);
	gettimeofday(&end_time, NULL);
	time_lapsedi = (double)(end_time.tv_usec - start_time.tv_usec);

	printf("fact(recursive) 10 computed in %lfusec: %d\n", time_lapsedr, resultr);
	printf("fact(iterative) 10 computed in %lfusec: %d\n", time_lapsedi, resulti);
	dlclose(handle);
	return 0;
}


