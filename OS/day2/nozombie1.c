#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();

	if (n1 == 0) {	
		printf("Sorry Talahashi, no zombies this time.\n");	
	}
	else{
		wait();		
		getchar();
	}	
	return 0;
}