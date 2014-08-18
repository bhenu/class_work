#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();

	if (n1 == 0) {	
		printf("Sorry Tallahassee, no zombie for you this time..\n");	
	}
	else{
		sigignore(SIGCHLD);
		sleep(2);		
		getchar();
	}	
	return 0;
}