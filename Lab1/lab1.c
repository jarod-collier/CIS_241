#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])   
{
      char ch;
      FILE *in, *out;
      in = fopen ("input.txt","r" );
      out = fopen ("output.txt", "w" );
      if ( in == NULL || out == NULL )	
      {
	printf ( "file could not be opened!\n" );
	exit (1);
      }

if (argc > 1) {
	 printf("This program does not allow more than one command-line arguments!\n");
	  exit(1);
}
      while ( ! feof(in) )   {
	fscanf ( in, "%c", &ch );

	if (ch >= 65 && ch < 97) {
	 ch+= 32;
}
	else if (ch >= 97 && ch < 123) {
	 ch-= 32;
}

	fprintf (out, "%c", ch);

      }

      fclose(in);
      fclose(out);
      return 0;
}
