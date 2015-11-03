#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256

int main(){
	unsigned char S[BLOCK_SIZE];
	unsigned char T[BLOCK_SIZE];
	unsigned char K[BLOCK_SIZE];
	unsigned char temp, CKey;
	char Key[256];
	int iii, jjj, keylen, keybitlen;

	// input the key
	keylen = 0;
	printf("Enter the key len (must be between 1 and 256: \n");
	scanf("%d", &keylen);
	while(keylen<1 || keylen>256){
		printf("Sorry wrong key length, must be between 1 and 256\n");
		scanf("%d", &keylen);
	}

	printf("Enter the key:\n");
	scanf("%s",  Key);
	while(strlen(Key) != keylen){
		printf("The key is of wrong size:\n");
		scanf("%s", Key);
	}

	// initiate S
	for(iii=0; iii<BLOCK_SIZE; iii++){
		S[iii]=iii;
	}

	for(iii=0, jjj=0; iii<BLOCK_SIZE; iii++){
		jjj = (jjj + S[iii]+ Key[iii%keylen])%256;
		temp = S[iii];
		S[iii] = S[jjj];
		S[jjj] = temp;
	}

	//take plain text as input
	int Ckey;
	char c;
	FILE * ptext = fopen("plaintext.txt", "r");
	FILE * ctext = fopen("ciphertxt.txt", "w");
	jjj =iii = 0;
	while((c=fgetc(ptext))!=EOF){
		// keep on generating the keys
		Ckey = 0;
		iii = (iii+1)%256;
		jjj = (jjj+S[iii])%256;
		temp = S[iii];
		S[iii] = S[jjj];
		S[jjj] = temp;
		Ckey = S[(S[iii]+S[jjj])%256];
		// printf("%c, %x\n", c, Ckey);
		fprintf(ctext, "%c", c^Ckey);
	}
	fclose(ctext);
	fclose(ptext);
	return 0;
}