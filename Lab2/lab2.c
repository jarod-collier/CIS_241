#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k);

int main(int argc, char* argv[])
{
	int choice, n;
	int key[10];
	//char input[] = "abcdef";
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("\nUsage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption \n \n");
		exit(1);
	}
	
	//strcpy(input, argv[2]);
	
	char string[20];
	strcpy (string, argv[2]);
	for (int i = 0; i < 4; i++) {
		key[i] = string[i] - 'A';
		
	}
	printf("The key is %d %d %d %d \n", key[0], key[1], key[2], key[3]);
	// key = atoi(argv[2]);   //convert from string to integer, e.g., string "12" to integer 12

	if (strcmp(argv[4],"d")==0){  //decryption
		
		for (int index = 0; index < 4; index++)
			key[index] = -key[index];	
		
		//key = -key;
	}

    	fin = fopen(argv[1], "r");
		fout = fopen(argv[3], "w");

    	if (fin ==  NULL || fout == NULL)
	{
		printf("File could not be opened!\n");
		exit(1);
	}

	n = 0;
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt_decrypt(ch, key[n]));
		n = (n+1)%4;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt_decrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';

	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}
