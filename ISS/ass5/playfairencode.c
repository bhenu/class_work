#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int getPlayFairMatrix(char * keyword, char ** matrix);

int main(int argc, char *argv[]){
	if (argc < 3)
	{
		fprintf(stderr, "%s\n", "usage: playfairencode <keyword> <msg file>");
		return 0;
	}

	FILE * msg = fopen(argv[2], "r");
	FILE * temp = fopen("temp.txt", "w+");

	// pad the message
	char c, d; int len = 0, iii; char *m;
	while((c = getc(msg)) != EOF){
		len++;
		d = getc(msg);
		if (d == EOF){
			break;
		}
		len++;
		putc(c, temp);
		if (c == d){
			putc('x', temp);
			ungetc(d, msg);
		}
		else{
			putc(d,temp);
		}
	}
	if (len % 2 != 0){
		putc(c, temp);
		putc('x', temp);
	}

	// generate the palyfair matrix
	char * matrix;
	getPlayFairMatrix(argv[1], &matrix);

	// print the playfair matrix
	m = matrix;
	for (iii = 0; iii < 25; ++iii){
		if (iii%5 == 0)
			puts("");
		putchar(*m++);
	}
	puts("");

	// start encoding
	int frow, fcol, srow, scol;
	rewind(temp);
	while((c = getc(temp)) != EOF){
		d = getc(temp);

		// find c
		m = matrix;
		for(iii = 0; iii < 25; iii++){
			if (*m == c){
				frow = iii/5;
				fcol = iii%5;
				break;
			}
			m++;
		}
		// printf("%c (%d, %d)\n", c, frow, fcol);

		// find d
		m = matrix;
		for(iii = 0; iii < 25; iii++){
			if (*m == d){
				srow = iii/5;
				scol = iii%5;
				break;
			}
			m++;
		}
		// printf("%c (%d, %d)\n", d, srow, scol);

		// encoding logic
		m = matrix;
		if (fcol == scol){
			putchar(*(m + ((frow+1)%5)*5 + fcol));
			putchar(*(m + ((srow+1)%5)*5 + scol));
			// printf("%d\n", ((frow+1)%5)*5 + fcol);
		}
		else if(frow == srow){
			putchar(*(m + (frow*5 + (fcol+1)%5)));
			putchar(*(m + (srow*5 + (scol+1)%5)));
		}
		else {
			putchar( *(m + frow*5 + scol));
			putchar(*(m + srow*5 + fcol ));
		}

	}

	puts("");
	fclose(msg);
	fclose(temp);
	// remove("temp.txt");
	return 0;
}

int getPlayFairMatrix(char * keyword, char ** matrix){
	if (strlen(keyword) > 10)
	{
		fprintf(stderr, "%s\n", "error: keyword too long");
		return -1;
	}
	*matrix = (char *)(calloc(25, sizeof(char)));
	int f[26]={0},i=0,j=0;
	f[9] = 1;
	char * m = *matrix;
	while(j < 26){
		if (i<strlen(keyword))
		{
			if(!f[keyword[i]-97]){
				*m++ =keyword[i];
				f[keyword[i]-97]=1;
			}

		}
		else{
			if(!f[j]){
				*m++ = 'a' + j;
				f['a' + j] = 1;
			}
			j++;
		}
		i++;
	}
	return 1;
}