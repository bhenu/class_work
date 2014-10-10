#include <stdio.h>

int factr(int n) {
	if(n == 0 || n == 1)
		return 1;
	else
		return factr(n-1)*n;		
}

int facti(int n) {
	int result = 1;
	while(n>0){
		result *= n;
		n--;
	}
	return result;
}