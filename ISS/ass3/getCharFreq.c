#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{
	char * path;
	FILE * fd;
	char c;
	int freq[256];
	int _i, _j;

	if (argc < 2)
	{
		printf("%s\n", "usage: getCharFreq <file name>");
		return 0;
	}
	path = argv[1];

	// open file
	fd = fopen(path, "r");

	// initiate the array
	for(_i=0; _i < 256; _i++){
		freq[_i] = 0;
	} 

	// read from file and print
	while((c = getc(fd)) != EOF){
		(freq[tolower(c)])++;
	}

	for (_i = 0; _i < 256; ++_i)
	{
		if(/*isalpha(_i) && !isupper(_i)*/ 1){
			putchar(_i);
			_j = freq[_i];
			_j = _j/15;
			while(_j > 0){
				putchar('=');
				_j--;
			}
			putchar('\n');
		}
	}

	// close the file
	fclose(fd);
	return 0;
}