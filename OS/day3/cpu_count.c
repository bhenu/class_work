#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int numCPU;
	numCPU = (int)sysconf( _SC_NPROCESSORS_ONLN);
	printf("%d\n", numCPU );
	return 0;
}