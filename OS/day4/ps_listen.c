#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#define SIZE 20


int main(int argc, char const *argv[]){	
	int segment_id, sval;
	char * shared_memory;
	char * chatbox;
	char * front;
	char * count;
	FILE *f1;
	sem_t *s1;

	/* Read segment_id from file. */
	f1 = fopen("segment_id.txt", "r");
	fscanf(f1, "%d", &segment_id);
	fclose(f1);
	
	/* Attach the shared memory segment */
	shared_memory = (char *)shmat(segment_id, NULL, 0);

	/* Get the count variable */
	count = shared_memory;

	/* Get the front variable */
	front = shared_memory +1;

	/* Get the chatbox */
	chatbox = shared_memory + 2;

	/* Get the semaphore */
	s1 = sem_open("/binny", NULL, NULL, NULL);
	
	sem_getvalue(s1, &sval);
	printf("%d\n", sval);
	
	/* ready to listen */
	printf("%s\n", "Listening..");
	while(1){
		if(*count > 0 && sem_wait(s1)) {
			putchar(*(chatbox + *front));
			*front = (*front + 1)%SIZE;
			(*count)--;
			sem_post(s1);
		}
	}
	sem_close(s1);
	shmdt(shared_memory);
	return 0;
}