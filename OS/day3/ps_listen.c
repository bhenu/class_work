#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

void * shout(int *seg_id);
void * listen(int *seg_id);

int main(int argc, char const *argv[]){	
	int ctrl_char, segment_id;
	char * shared_memory;
	char input[100];
	size_t size = 64;
	pthread_t tid1, tid2;
	FILE *f1;

	/* Read segment_id from file. */
	f1 = fopen("segment_id.txt", "r");
	fscanf(f1, "%d", &segment_id);
	fclose(f1);
	
	printf("sge id read: %d\n", segment_id);
	/* Attach the shared memory segment */
	shared_memory = (char *)shmat(segment_id, NULL, 0);

	/* ready to listen */
	printf("%s\n", "Listening..");
	while(1){
		/* read control character */
		ctrl_char = *shared_memory;
		if(ctrl_char < 0) break;
		if(ctrl_char > 0){
			*shared_memory = 0;
			printf("%s\n", (shared_memory + 1));
		}
	}
	shmdt(shared_memory);
	return 0;
}