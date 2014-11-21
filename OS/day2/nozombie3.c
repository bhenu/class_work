#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();

	if (n1 == 0) {
		n1 = fork();
		if (n1 == 0) {
			printf("Wnaa wnaaa..\n");
			getchar();	
		}	
	}
	else{
		sleep(5);
		printf("Yeah! I have a grand child.\n");
		printf("But my child is now a zombie ;(\n");
		wait();
		printf("Killed the zombie; he wasn't my son any more.\n");	
		sleep(10);
	}	
	return 0;
}