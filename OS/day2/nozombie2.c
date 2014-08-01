#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void Talahashi();
int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();

	if (n1 == 0) {	
		printf("Hey Talahashi, try this one..\n");	
	}
	else{
		signal(SIGCHLD, Talahashi);		
		getchar();
	}	
	return 0;
}

void Talahashi(){
	sleep(5);
	printf("Talahashi: Foof.. piece of cake!\n");
	sleep(2);
	wait();
}