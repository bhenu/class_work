#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void Tallahassee();
int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();

	if (n1 == 0) {	
		printf("Hey Tallahassee, try this one..\n");	
	}
	else{
		signal(SIGCHLD, Tallahassee);		
		getchar();
	}	
	return 0;
}

void Tallahassee(){
	sleep(5);
	printf("Tallahassee: Foof.. piece of cake!\n");
	sleep(2);
	wait();
}