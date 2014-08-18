#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

void * shout(int *seg_id);
void * listen(int *seg_id);

int main(int argc, char const *argv[])
{
	int segment_id;
	char * shared_memory;
	char input[100];
	size_t size = 64;
	pthread_t tid1, tid2;
	FILE *f1;

	/* Create shared memory segment */
	segment_id = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	
	/* Attach the shared memory segment */
	shared_memory = (char *)shmat(segment_id, NULL, 0);

	/* Initiate the shared memory control character */
	*shared_memory = 0;

	/* Write segment_id to file. */
	f1 = fopen("segment_id.txt", "w");
	fprintf(f1, "%d", segment_id);
	fclose(f1);

	printf("%s%d\n", "seg id written: ", segment_id);
	/* ready to shout */
	printf("%s\n", "Shout out!");
	while(1){
		/* read user input */
		scanf("%s", input);

		/* exit the program on q */
		if(strcmp(input, "q") == 0){
			*shared_memory = -1;
			break;	
		}

		sprintf((shared_memory + 1), input);
		*shared_memory = 1;
	}
	shmdt(shared_memory);

	/* Deallocate the shared memory segment. */
	shmctl(segment_id, IPC_RMID, NULL);
	return 0;
}

void * listen(int * seg_id) {
	int ctrl_char;
	char * chatbox;
	size_t size = 64;
	
	chatbox = (char *)shmat(*seg_id, NULL, 0);
	printf("%s\n", "Listening..");
	while(1){
		/* read control character */
		ctrl_char = *chatbox;
		if(ctrl_char < 0) break;
		if(ctrl_char > 0){
			*chatbox = 0;
			printf("%s\n", (chatbox + 1));
		}
	}
	shmdt(chatbox);
}