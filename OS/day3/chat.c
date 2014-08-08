#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <sys/ipc.h>
#include <sys/shm.h>


void shout(char * msg);
void listen();

void * thread_start1();
void * thread_start2();

int main(int argc, char const *argv[])
{
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread_start1, NULL);
	pthread_create(&tid2, NULL, thread_start2, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid1, NULL);
	return 0;
}

void shout(char * msg) {
	printf("%s\n", msg);
}

void listen() {
	printf("%s\n", "listening...");
}

void * thread_start1() {
	int f;
	char * chatbox;
	char * msg;

	f = shm_open("/chatbox", O_CREAT | O_RDWR, S_IWUSR);
	ftruncate(f, 1024);
	
	chatbox = mmap(NULL, 1024 , PROT_WRITE , MAP_SHARED , f, 0);
	close(f);
	
	while(1) {
		msg = "message from from the dark side..\n";
		memcpy(chatbox, msg, strlen(msg));
	}
}

void * thread_start2() {
	int f;
	char msg[100];
	char * chatbox;
	struct shmid_ds chatstat;
	sleep(2);

	f = shm_open("/chatbox", O_RDWR, S_IWUSR);
	ftruncate(f, 1024);

	chatbox = mmap(NULL, 1024 , PROT_WRITE , MAP_SHARED , f, 0);
	close(f);

	printf("%d\n", f);
	// printf("%s\n", "start typing:");

	while(1) {
		// shmctl(f, IPC_STAT, &chatstat); 
		// printf("%d\n", (int)chatstat.shm_cpid);
		memcpy(chatbox, msg, strlen(msg));
		printf("%s\n", msg);
		sleep(2);
	}
}