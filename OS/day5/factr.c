#include <stdio.h>

double facti(double n) {
	double result = 1;
	while(n>0){
		result *= n;
		n--;
	}
	return result;
}