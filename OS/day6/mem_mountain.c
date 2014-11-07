#include <stdio.h>
#include <stdint.h>

#define MINBYTES (1 << 10)
#define MAXBYTES (1 << 25)
#define MAXSTRIDE 16
#define MAXELEMS MAXBYTES/sizeof(int)

int data[MAXELEMS];

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

double fcyc2(void (*funcPtr)(int, int), int elems, int stride , int n){
	uint64_t start, finish;
	start = rdtsc();
	while(n>0){
		(*funcPtr)(elems, stride);
		n--;		
	}
	finish = rdtsc();
	return (double)finish - start;
}

/* The test function */
void test(int elems, int stride) { 
	int i, result = 0;
	volatile int sink;
	for (i = 0; i < elems; i += stride)
		result += data[i];
	sink = result; /* So compiler doesn't optimize away the loop */
}

/* Run test(elems stride) and return read throughput (MB/s) */
double run(int size, int stride, double Mhz) {
	double cycles;
	int elems = size / sizeof(int);

	test(elems, stride);						/* warm up the cache */
	cycles = fcyc2(&test, elems, stride, 1);		/* call test(elems, stride) */
	return (size / stride) / (cycles / Mhz);	/* convert cycles to MB/s */
}

void init_data(int * data, long int n){
	while(n >= 0) {
		data[n] = 1;
		n--;
	}
}

int main(int argc, char const *argv[])
{
	int size, stride;
	int Mhz;

	init_data(data, MAXELEMS);
	Mhz = 1600;

	printf("\t");
    for (stride = 1; stride <= MAXSTRIDE; stride++)
		printf("s%d\t", stride);
    printf("\n");

	for (size = MAXBYTES; size >= MINBYTES;  size >>= 1)
	{ 
		if (size > (1 << 20))
	    	printf("%dm\t", size / (1 << 20));
		else
	    	printf("%dk\t", size / 1024);
		for (stride = 1; stride <= MAXSTRIDE; stride++){
			printf("%.1f\t", run(size, stride, Mhz));
		}
		printf("\n");
	}
	return 0;
}