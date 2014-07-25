#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();
	for(i = 0; i < 11; i++) {
		if (n1 != 0) {
			printf("%d forked into %d\n", getpid(), n1);			
			n1 = fork();
		}
		else
			break;		
	}
	return 0;
}