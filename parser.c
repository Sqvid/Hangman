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


int checkGuess(char guess, char* answer){		//Checks if a guess is a hit or a miss.
	int wordSize=strlen(answer), count=0;

	for(int i=0; i<=(wordSize-1); i++){		//wordsize - 1 becaue arrays count from 0.
		if(answer[i]==guess){
			count++; 			//Guess was successful.
		}
	}

	return count;					//Zero means the guess was wrong. A nonxero value
}							//indicates the number of hits.
