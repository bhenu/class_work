#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{
	FILE * image;
	FILE * msg;
	FILE * op;
	char c, d;
	unsigned char msgbit;
	int _i, _j, msgover;
	int parsedint = 0;

	if (argc < 4)
	{
		printf("%s\n", "usage: embed <image file> <text file> <output image file>");
		return 0;
	}
	const char * image_path = argv[1];
	const char * msg_path = argv[2];
	const char * output_path = argv[3];

	// open files
	image = fopen(image_path, "r");
	msg = fopen(msg_path, "r");
	op = fopen(output_path, "w");

	_i = _j = msgover = 0; 
	while((c = getc(image)) != EOF){
		
		// skip first 4 lines
		if(_j < 4){
			putc(c, op);
			if (c == '\n')
				_j++;
			continue;			
		}
		
		if (!msgover)
		{
			// get the pixel values
			if(isdigit(c)){
				ungetc(c, image);
				fscanf(image, "%d", &parsedint);
			}
			else{
				putc(c, op);
				continue;
			}

			// read a character from msg
			if (_i == 0)
			{
				d = getc(msg);
				if(d == EOF){
					msgover = 1;
				};
			}

			// overuse of bitwise operator
			msgbit = d & 1;
			d = d >> 1;
			parsedint &= 0xfe;
			parsedint |= msgbit;

			fprintf(op, "%d", parsedint);
			_i++; _i %= 8;
		}
		else{
			putc(c, op);
		}
	}

	// close the files
	fclose(image);
	fclose(msg);
	fclose(op);
	return 0;
}