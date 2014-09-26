#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>
#define SIZE 20

int main(int argc, char const *argv[]){	
	int segment_id, sval;
	char * shared_memory;
	char * chatbox;
	char * front;
	char * count;
	struct timeval current_time;
	FILE *f1;
	sem_t *mutex;
	sem_t *sig;
	FILE *f = fopen("data2.dat", "w");

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
	mutex = sem_open("/binny", O_CREAT, S_IWUSR | S_IRUSR , NULL);
	sig = sem_open("/sig", O_CREAT, S_IWUSR | S_IRUSR , NULL);

	/* ready to listen */
	printf("%s\n", "Listening..");
	while(1){
		sem_wait(sig);
		sem_wait(mutex);
		if(*count == -1)
			break;
		if(*count > 0) {
			putchar(*(chatbox + *front));

			gettimeofday(&current_time, NULL);
			fprintf(f, "%f\t1\n", (double)current_time.tv_usec);

			*front = (*front + 1)%SIZE;
			(*count)--;
		}
		sem_post(mutex);
	}
	fclose(f);
	
	sem_close(mutex);
	sem_close(sig);
	shmdt(shared_memory);
	printf("%s\n", "Adios!\n");
	return 0;
}