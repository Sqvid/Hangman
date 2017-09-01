#include "hangman.h"

int main(void){

	int lineNumber, wordSize, misses=0, hits=0, i_correct=0, scoreChange;
	char guess, answer[25], blankSpace[50], correct[25], wrong[7]="      \0";
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
	//printf("%s\n", answer);
	
	for(int i=0; i<=2*(wordSize-1); i++){		//(wordSize-1) becuase arrays count from 0. Multiplied by 2 because we want spacing.
		if(i%2==0){
			blankSpace[i]='_';
		}
		
		else{
			blankSpace[i]=' ';
		}
	}

	drawMan(0);
	printf("\n\n    The word is %d letters long.\n", wordSize);
	printf("\n    %s\n\n", blankSpace);



	while(misses<7 && hits<wordSize){		//This block actually runs the game.
		printf("\n\n    Enter your guess: ");
		scanf(" %c", &guess );
		scoreChange=checkGuess(guess, answer);

		if(scoreChange==0){
			wrong[misses]=toupper(guess);
			misses++;
			drawMan(misses);
			printf("\n\n    Incorrect guesses so far: %s\n", wrong);
			printf("    Correct guesses so far: %s\n", correct);
			
		}

		else{
			correct[hits]=toupper(guess);
			hits=hits+scoreChange;
			drawMan(misses);
			printf("\n\n    Incorrect guesses so far: %s\n", wrong);
			printf("    Correct guesses so far: %s\n", correct);
		}

		printf("\n\n    %s\n\n", fillBlanks(guess, answer, blankSpace));
	}

	if(misses==7)
	{
		printf("The word was: %s! Better luck next time.\n\n", answer);
	}

	else if(hits==wordSize){
		printf("Congratulations! You live another day.\n\n");
	}

	fclose(wordlist);

	return 0;
}
