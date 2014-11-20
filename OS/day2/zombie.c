#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;
	pid_t n1;
	for(i = 0; i < 11; i++) {
		n1 = fork();
		if (n1 != 0) {
			printf("Parent(%d): Yo Talahashi.. Here comes a zombie no. %d\n", getpid(), n1);			
		}
		else break;		
	}

	if(n1 != 0) {
		getchar();
	}
	
	return 0;
}