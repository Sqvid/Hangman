#ifndef INCLUDE_GUARD
	#define INCLUDE_GUARD

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <ctype.h>
	#define LIST_SIZE 4256		//This number defines the number of items in the wordlist.

	void loadWord(int line_number, FILE *fileptr, char outputArray[]);
	char* fillBlanks(char guess, char* answer, char* blanks);
	int checkGuess(char guess, char* answer);
	
	void drawMan(int missNumber);
#endif
