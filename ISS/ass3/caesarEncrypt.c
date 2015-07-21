#include "stdio.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{
	FILE * ip;
	FILE * op;
	char c;

	if (argc <4)
	{
		printf("%s\n", "usage: <key value> <input file> <output file>");
		return 0;
	}

	const char * inputFilePath = argv[2];
	const char * outputFilePath = argv[3];
	int keyValue = atoi(argv[1]);

	ip = fopen(inputFilePath, "r");
	op = fopen(outputFilePath, "w");

	while((c = getc(ip)) != EOF){
		putc((c + keyValue)%256, op);
	}

	fclose(ip);
	fclose(op);
	return 0;
}