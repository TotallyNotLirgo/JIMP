#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strcmp

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB
#define MAXLINES 100000 // maksymalna liczba linii

int alphacmp( const void *a, const void *b ) {
	char **ca = (char**)a;
	char **cb = (char**)b;
	return strcmp( *ca, *cb );
}

int cmpint( const void *a, const void *b ) {
	return (*(int*)a) - (*(int*)b);
}

int main( int argc, char **argv ) {
	int i;
	char *copy[MAXLINES];
  	int number_of_lines;
    int current_argument;
    int *arguments;
	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

    arguments = malloc((argc - 2) * sizeof(int));
    for(i = 0; i < argc - 2; i++)
        arguments[i] = atoi(argv[i + 2]);

    qsort( arguments, argc - 2, sizeof *arguments, cmpint );

	number_of_lines = 0;
    current_argument = 0;
	while( fgets( buf, BUFSIZE, in ) != NULL && current_argument < argc - 2) {
		if(arguments[current_argument] != ++number_of_lines)
            continue;
        copy[current_argument] = malloc((strlen(buf) + 1) * sizeof(char));
        strcpy(copy[current_argument], buf);
        current_argument++;
	}

	qsort( copy, current_argument, sizeof *copy, alphacmp );

	for( i= 0; i < current_argument; i++ )
		printf( "%s", copy[i] );

	return EXIT_SUCCESS;
}
