#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#define SIZE 20

int main(){
	char queue[SIZE];
	int count = 0;
	int front = 0;
	sem_t *s1;
	s1 = sem_open("/binny", O_CREAT, S_IWUSR| S_IRUSR | S_IWOTH | S_IROTH, 1);
	
	printf("%d\n", s1);
	/* Insert data into queue */
	while(count < SIZE) {
		queue[(front+count)%SIZE] = getchar();
		count++;
	}

	/* Print data from queue */
	while(count > 0) {
		putchar(queue[(front++)%SIZE]);
		count--;
	}

	putchar('\n');
	return 0;
}