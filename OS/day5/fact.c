#include <stdio.h>

double factr(double n) {
	if(n == 0 || n == 1)
		return 1;
	else
		return factr(n-1)*n;		
}

double facti(double n) {
	double result = 1;
	while(n>0){
		result *= n;
		n--;
	}
	return result;
}