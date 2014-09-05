#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>
#define SIZE 20

int x = 0;
void quit(void);

int main(int argc, char const *argv[])
{
	int segment_id, sval;
	char * shared_memory;
	char * chatbox;
	char * front;
	char * count;
	struct timeval current_time;
	size_t size = 64;
	sem_t *mutex;
	sem_t *sig;
	FILE *f1;
	FILE *f = fopen("data1.dat", "w");

	/* Create shared memory segment */
	segment_id = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	
	/* Attach the shared memory segment */
	shared_memory = (char *)shmat(segment_id, NULL, 0);


	/* NOTE: 
	   ---------------------------------
	   Instead of creating a second shared 
	   memory segment, I have used the first
	   and second element in the array as
	   the count and front variable.
	*/

	/* Initiate count variable */
	count = shared_memory;
	*count = 0;

	/* Initiate the front variable */
	front = shared_memory +1;
	*front = 0;

	/* Get the buffer */
	chatbox = shared_memory + 2;

	/* Write segment_id to file. */
	f1 = fopen("segment_id.txt", "w");
	fprintf(f1, "%d", segment_id);
	fclose(f1);

	/* Creat a semaphore */
	mutex = sem_open("/binny", O_CREAT | O_EXCL , S_IWUSR | S_IRUSR | S_IWOTH | S_IROTH, 1);
	sig = sem_open("/sig", O_CREAT | O_EXCL , S_IWUSR | S_IRUSR | S_IWOTH | S_IROTH, 0);

	/* Gracefully exit */
	signal(SIGINT, quit);

	/* ready to shout */
	printf("%s\n", "Shout out!");
	while(1){
		/* exit loop on keyboard interrupt */
		if(x) {
			sem_wait(mutex);
			*count = -1;
			sem_post(mutex);
			break;
		}

		/* read user input */
		if(*count < SIZE) {
			*(chatbox + (*front + *count)%SIZE) = getchar();
			sem_wait(mutex);

			gettimeofday(&current_time, NULL);
			fprintf(f, "%f\t2\n", (double)current_time.tv_usec);

			(*count)++;
			sem_post(mutex);
			sem_post(sig);
		}
	}
	fclose(f);

	/* Destroy the semaphore */
	sem_close(mutex);
	sem_close(sig);
	sem_unlink("/binny");
	sem_unlink("/sig");

	/* Detach the shared memory. */
	shmdt(shared_memory);
	/* Deallocate the shared memory segment. */
	shmctl(segment_id, IPC_RMID, NULL);

	printf("%s\n", "Bye. :)\n");
	return 0;
}

void quit(void) {
	x = 1;
}