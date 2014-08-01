#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	pid_t n1;
	n1 = fork();
	for(i = 0; i < 11; i++) {
		if (n1 != 0) {
			printf("Parent(%d): Yo Talahashi.. Here comes a zombie no. %d\n", getpid(), n1);			
			n1 = fork();
		}
		else{
			break;		
		}
	}

	if(n1 != 0) {
		getchar();
	}
	
	return 0;
}