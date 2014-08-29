#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#define SIZE 20

int main(int argc, char const *argv[])
{
	int segment_id, sval;
	char * shared_memory;
	char * chatbox;
	char * front;
	char * count;
	size_t size = 64;
	FILE *f1;
	sem_t *s1;

	/* Create shared memory segment */
	segment_id = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	
	/* Attach the shared memory segment */
	shared_memory = (char *)shmat(segment_id, NULL, 0);


	/* NOTE: 
	   ---------------------------------
	   Instead of creating a second shared memory segment,
	   I have used the first and second element in the
	   array as the count and front variable.
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
	s1 = sem_open("/binny", O_CREAT | O_EXCL , S_IWUSR | S_IRUSR | S_IWOTH | S_IROTH, 1);
	sem_wait(s1);
	sem_getvalue(s1, &sval);
	printf("%d\n", sval);

	/* ready to shout */
	printf("%s\n", "Shout out!");
	while(1){
		/* read user input */
		if(*count < SIZE && sem_wait(s1)) {
			*(chatbox + (*front + *count)%SIZE) = getchar();
			(*count)++;
			sem_post(s1);
			sem_getvalue(s1, &sval);
			printf("%d\n", sval);
		}
		else {
			printf("%s\n", "Waiting for listner");
			sleep(2);
		}
	}
	sem_close(s1);
	sem_destroy(s1);

	shmdt(shared_memory);
	/* Deallocate the shared memory segment. */
	shmctl(segment_id, IPC_RMID, NULL);
	return 0;
}