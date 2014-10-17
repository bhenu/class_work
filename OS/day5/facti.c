#include <stdio.h>

double factr(double n) {
	if(n == 0 || n == 1)
		return 1;
	else
		return factr(n-1)*n;		
}