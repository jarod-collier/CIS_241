#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char encrypt_decrypt(char ch, int k);

int main(int argc, char* argv[])
{
	int choice, n, count;
	int key[26];
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("\nUsage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption \n \n");
		exit(1);
	}
	
	// Takes the users key and converts it to the integer equivalent
	char string[26];
	strcpy (string, argv[2]);
	for (int i = 0; i < strlen(argv[2]); i++) { 
		if (isupper(string[i]))		
			key[i] = string[i] - 'A';
		if (islower(string[i])) 		
			key[i] = string[i] - 'a';
	}
	
	
	// Checks if letter is in array already, if not it adds the reversed alphabet to the key
	count = 25;
	bool add = true;
	for( int i = 0; i < 26; i++){
		for (int j = 0; j < strlen(argv[2]); j++) {
			
			if ((key[j] == i)) 
				add = false;	
		}
		if (add == true) {
			key[count] = i;
			count--;
		}
		add = true;
	}
	
	
	
	
	
	printf("Key: ");
	for (int s = 0; s < 26; s++)
		printf("%d ", key[s]);	
	printf("\n");
	
	// key = atoi(argv[2]);   //convert from string to integer, e.g., string "12" to integer 12

	if (strcmp(argv[4],"d")==0){  //decryption
		
		for (int index = 0; index < 26; index++)
			key[index] = -key[index];	
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
		n = (n+1)%26;
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
