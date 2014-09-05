#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>

int main(){
	sem_t *s1;
	s1 = sem_open("/binny", O_CREAT, S_IWUSR | S_IRUSR , NULL);
	sem_close(s1);
	sem_unlink("/binny");
	printf("%s\n", "done!");
	return 0;
}