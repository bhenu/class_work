#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{

	if (argc < 2) {
		printf("%s\n", "usage: embed <image file>");
		return 0;
	}

	// open files
	FILE * image;
	image = fopen(argv[1], "r");

	int _i, _j, msgover, parsedint; 
	unsigned char msgbit, d, c;
	_i = _j = msgover = parsedint = d = 0;
	while((c = getc(image)) != EOF) {
		
		// skip first 4 lines
		if(_j < 4) {
			if (c == '\n') {
				_j++;
			}
			continue;			
		}
		
		if (!msgover) {
			if (_i == 0 ) {
				if(_j >4) {
					putchar(d);
				}
				// check for end of message
				if (d == '@') {
					msgover = 1;
					putchar('\n');
				}
				d = 0;
				_j++;
			}

			// get the pixel values
			if(isdigit(c)) {
				ungetc(c, image);
				fscanf(image, "%d", &parsedint);
			}
			else {
				continue;
			}
			
			// overuse of bitwise operator
			msgbit = parsedint & 1;
			d >>= 1;
			msgbit <<= 7;
			d |= msgbit;
			
			_i = (_i+1)%8;
		}
		else {
			break;
		}
	}

	// close the files
	fclose(image);
	return 0;
}