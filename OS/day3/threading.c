#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int factorial(int n);
int fibonacci(int n);
void * thread_start1();
void * thread_start2();

int main(int argc, char const *argv[])
{
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread_start1, NULL);
	pthread_create(&tid2, NULL, thread_start2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}

int factorial(int n) {
	if(n == 0 || n == 1) return 1;
	else return n*factorial(n-1);
}

int fibonacci(int n) {
	if (n == 0 || n == 1 || n == 2) return 1;
	else return fibonacci(n-1) + fibonacci(n-2);
}

void * thread_start1() {
	printf(" thread 1 (tid %lu): fib(42): %d\n", (long int)pthread_self(), fibonacci(42));
}

void * thread_start2() {
	printf(" thread 2 (tid %lu): fib(40): %d\n", (long int)pthread_self(), fibonacci(44));
}