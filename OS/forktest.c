#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();
	if (n1 == 0) {
			printf("Inside Child my pid is (%d) the parent id is %d\n",getpid(), getppid());
	}
	else {
		printf(" the child id is: %d and the parent id is: %d\n", n1, getpid());
	}
	return 0;
}