/**************************************************
 * This file contais the source code for the
 * functions required to process the text data and
 * modify it during runtime.
 *************************************************/

#include "hangman.h"


void loadWord(int line_number, FILE *infile, char outputArray[]){		//loads the selected word into a string.
	int count=0;
	char result[512];

	if(infile == NULL){
		printf("Error with findLine(). Please debug.");
		
	}

	else{
		while(fgets(result, sizeof(result), infile) != NULL){
			if(count == (line_number - 1)){
				sscanf(result, "%s", outputArray);
				break;
			}

			else{
				count++;
			}
		}
	}
}


char* fillBlanks(char guess, char* answer, char blanks[]){
	int wordSize=strlen(answer);

	for(int i=0; i<=(wordSize-1); i++){		//wordsize - 1 becaue arrays count from 0.
		if(answer[i]==guess){
			blanks[2*i]=guess;
		}
	}

	return blanks;
}


int checkGuess(char guess, char* string){		//Checks if a guess is present in a string.
	int wordSize=strlen(string), count=0;

	for(int i=0; i<=(wordSize-1); i++){		//wordsize - 1 becaue arrays count from 0.
		if(string[i]==guess){
			count++;
		}
	}

	return count;					//The number of times the guess appeared in the string.
}
