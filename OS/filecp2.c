#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	size_t nmemb = 4;
	size_t size = 8;
	void *buf;

	// Initialise the files
	FILE *f1;
	FILE *f2;

	// Open the files
	f1 = fopen("data2.dat", "r");
	f2 = fopen("copy_data.dat", "w");

	// Fork the process
	pid_t pid;
	pid = fork();

	// Copy the file using parent and child 
	// process simultaneously
	if(pid == 0) {
		printf("%d\n", fread(buf, size, nmemb, f1));
		while (fread(buf, size, nmemb, f1)) {
        	fwrite(buf, size, nmemb, f2);
    	}
    }
	else {
		while (fread(buf, size, nmemb, f1)) {
			fwrite(buf, size, nmemb, f2);
		}
	}	

    printf("done");
	fclose(f1);
	fclose(f2);
	return 0;
}