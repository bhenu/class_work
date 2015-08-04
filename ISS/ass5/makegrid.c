#include "stdio.h"
##include "string.h"
int main(int argc, char const *argv[])
{
	char matrix[5][5];

	if (argc < 2) {
		printf("%s\n", "usage: makegrid <key word>");
		return 0;
	}
	const char *keyword = argv[1];


	// fill the matrix
	char *m = (char *)matrix;
	for (int _j = 0; _j < 26; ++_j){
		if('a' + _j == 'j')
			continue;
		*m++ = 'a' +_j;
	}

	// put the keyword
	char c, temp; int _j = 0;
	m = (char *)matrix;
	l = strlen(keyword);
	while((c = *(keyword++))!= '\0') {
		temp = *(m+_j);


		*(m+_j) = c;
		// swap all
		if(c - 'a' > c - 'j')
			*(m + (c - 'a' -1)) = temp;
		else
			*(m + (c - 'a')) = temp;
		_j++;
	}

	m = (char *)matrix;
	// display the matrix
	for (int _i = 0; _i < 25; ++_i) {
		if (_i%5 == 0){
			putchar('\n');
		}
		putchar(*m++);
	}

	return 0;
}