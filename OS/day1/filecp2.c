#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	size_t block = 32;
	char *buf;

	// Initialise the files
	FILE *f1;
	FILE *f2;
	FILE *f3;

	// Open the files
	f1 = fopen("data2.dat", "r");
	f2 = fopen("copy_data_ps1.dat", "w");
	f3 = fopen("copy_data_ps2.dat", "w");

	// Fork the process
	pid_t pid;
	pid = fork();

	// Copy the file using parent and child 
	// process simultaneously
	if(pid == 0) {
		buf = malloc(block);
		while (getline(&buf, &block, f1) != -1) {
        	fprintf(f3, "%s", buf);
    	}
    }
	else {
		buf = malloc(block);
		while (getline(&buf, &block, f1) != -1) {
			fprintf(f2, "%s", buf);
		}
	}	

    printf("done");
	fclose(f1);
	fclose(f2);
	fclose(f3);
	return 0;
}