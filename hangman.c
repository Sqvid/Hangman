#include "hangman.h"

int main(void){

	int lineNumber, wordSize, misses=0i, hits=0, scoreChange;
	char guess, answer[25], blankSpace[50];
	FILE *wordlist; 
	wordlist=fopen("./wordlist.txt", "r");
	
	if(wordlist==NULL){
		puts("Sorry failed to read the wordlist.");
		exit(1);
	}

	srand(time(NULL));
	lineNumber=rand()%(LIST_SIZE - 1);		//This randmomly picks an entry number for the nounlist.	
	loadWord(lineNumber, wordlist, answer);		//findWord() finds and loads the selected entry.

	wordSize=strlen(answer);
	printf("%s\n", answer);
	printf("\nThe word is %d letters long.\n", wordSize);
	
	for(int i=0; i<=2*(wordSize-1); i++){		//(wordSize-1) becuase arrays count from 0. Multiplied by 2 because we want spacing.
		if(i%2==0){
			blankSpace[i]='_';
		}
		
		else{
			blankSpace[i]=' ';
		}
	}

	printf("\n%s\n\n\n", blankSpace);
	drawMan(0);

	while(misses<7 && hits<wordSize){		//This block actually runs the game.
		printf("Enter your guess: ");
		scanf(" %c", &guess );
		scoreChange=checkGuess(guess, answer);

		if(scoreChange==0){
			misses++;
			drawMan(misses);
		}

		else{
			hits=hits+scoreChange;
			drawMan(misses);
		}

		printf("\n%s\n\n", fillBlanks(guess, answer, blankSpace));
	}

	fclose(wordlist);

	return 0;
}
