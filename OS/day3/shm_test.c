/*
	Shared memory sharing by two threads.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

/* define container for thread arguments */
struct args {
	void * shm1;
	void * shm2;
};

void * thread1(void *shared_memory);
void * thread2(void *shared_memory);

int main(int argc, char const *argv[])
{
	int segment_id1, segment_id2;
	char * shared_memory1, shared_memory2;
	struct args a1; 
	size_t size = 64;
	pthread_t tid1, tid2;
	
	/* Create shared memory segments */
	segment_id1 = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	segment_id2 = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

	/* Attach the shared memory segments */
	a1.shm1 = (char *)shmat(segment_id1, NULL, 0);
	a1.shm2 = (char *)shmat(segment_id2, NULL, 0);

	pthread_create(&tid1, NULL, thread1, &a1);
	pthread_create(&tid2, NULL, thread2, &a1);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	/* Detach the shared memory segments */
	shmdt(a1.shm1);
	shmdt(a1.shm2);

	/* Deallocate the shared memory segment. */
	shmctl(segment_id1, IPC_RMID, NULL);
	shmctl(segment_id2, IPC_RMID, NULL);
	
	return 0;
}

void * thread1(void * a1){
	char * chatbox1;
	char * chatbox2;
	// struct args a1;
	// a1 = (struct args)a;
	/* type cast the shared mem segment */
	chatbox1 = (char *)(a1.shm1);
	chatbox2 = (char *)(a1.shm2);
	
	sprintf((chatbox1 + 1), "Hi I'm thread 1\n");
	*chatbox1 = 1;

	while(1){
		/* read control character */
		if(*chatbox2 > 0) {
			printf("thread1: the other guy said \"%s\"\n", (chatbox2 + 1));
			break;
		}
	}
}

void * thread2(void * a1) {
	char * chatbox1;
	char * chatbox2;
	// struct args a1;
	// a1 = (struct args)a;

	/* type cast the shared mem segment */
	chatbox1 = (char *)(a1.shm1);
	chatbox2 = (char *)(a1.shm2);
	
	sprintf((chatbox2 + 1), "Hello I'm thread 2\n");
	*chatbox2 = 1;

	while(1){
		/* read control character */
		if(*chatbox1 > 0) {
			printf("thread2: the other guy said \"%s\"\n", (chatbox2 + 1));
			break;
		}
	}
}