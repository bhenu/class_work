#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
	void *handle;
	int (*fact)(int);
	char *error;

	handle = dlopen("/home/student/binayak/class_work/OS/day5/libfact.so", RTLD_LAZY);
	if (!handle) {
	   fprintf(stderr, "%s\n", dlerror());
	   exit(EXIT_FAILURE);
	}

	dlerror(); /* Clear any existing error */

	*(void **) (&fact) = dlsym(handle, "factr");

	if ((error = dlerror()) != NULL)  {
	   fprintf(stderr, "%s\n", error);
	   exit(EXIT_FAILURE);
	}

	printf("fact 5 is: %d\n", (*fact)(5));
	dlclose(handle);
	return 0;
}