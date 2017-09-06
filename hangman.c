#include "hangman.h"

int main(void){

	int lineNumber, wordSize, misses=0, hits=0, scoreChange;
	char guess, answer[25], blankSpace[50], wrong[8]="       \0", correct[25]="                        \0";
	FILE *wordlist; 
	wordlist=fopen("wordlist.txt", "r");
	
	if(wordlist==NULL){
		puts("Sorry failed to read the wordlist.\n");
		exit(1);
	}

	srand(time(NULL));
	lineNumber=rand()%(LIST_SIZE - 1);		//This randmomly picks an entry number for the nounlist.	
	loadWord(lineNumber, wordlist, answer);		//findWord() finds and loads the selected entry.

	wordSize=strlen(answer);
	
	for(int i=0; i<=2*(wordSize-1); i++){		//(wordSize-1) becuase arrays count from 0. Multiplied by 2 because we want spacing.
		if(i%2==0){
			blankSpace[i]='_';
		}
		
		else{
			blankSpace[i]=' ';
		}
	}

	drawMan(0);					//Initialises the hangman graphic.

	puts("\n\n    ************************************************************");
	    puts("    *Incorrect guesses so far:                                 *");
	    puts("    *Correct guesses so far:                                   *");
	    puts("    ************************************************************");

	printf("\n    The word is %d letters long.\n", wordSize);
	printf("\n    %s\n\n", blankSpace);



	while(misses<7 && hits<wordSize){		//This block actually runs the game.
		while(1){
			printf("\n    Enter your guess: ");
			scanf(" %c", &guess );

			if(isalpha(guess)){			//This block checks the validity of the guess
				for(int j=0; j<7; j++){		//and protects against repeated guesses of the same letter.
					if(toupper(guess)==wrong[j]){
						printf("****You have already guessed that!****");
						misses--;
						break;
					}
				}
				
				for(int k=0; k<wordSize; k++){
					if(toupper(guess)==correct[k]){
						printf("****You have already guessed that!****");
						hits--;
						break;
					}
				}

				break;
			}

			else{
				//puts("\n\n    ********************************");
				puts("\n    ****Sorry! Only alphabets allowed!****");
				//puts("    *Please try again.             *");
				//puts("    ********************************\n");
			}
		}

		puts("\n\n----------------------------------------------------------------");

		scoreChange=checkGuess(guess, answer);

		{
			if(scoreChange==0){				//Block for wrong guesses.
				wrong[misses]=toupper(guess);
				misses++;
				drawMan(misses);
				puts("\n\n    ************************************************************");
				printf("    *Incorrect guesses so far: %s                         *\n", wrong);
				printf("    *Correct guesses so far: %s          *\n", correct);
				puts("    ************************************************************");
			}

			else{						//Block for correct guesses.
				correct[hits]=toupper(guess);
				hits=hits+scoreChange;
				drawMan(misses);
				puts("\n\n    ************************************************************");
				printf("    *Incorrect guesses so far: %s                         *\n", wrong);
				printf("    *Correct guesses so far: %s          *\n", correct);
				puts("    ************************************************************");
				//printf("\n\n    Incorrect guesses so far: %s\n", wrong);
				//printf("    Correct guesses so far: %s\n", correct);
			}
		}

		printf("\n\n    %s\n\n", fillBlanks(guess, answer, blankSpace));		//Fill in blanks if needed.
	}

	if(misses==7)
	{
		printf("    The word was %s! Better luck next time.\n\n", answer);
	}

	else if(hits==wordSize){
		printf("    Congratulations! You live another day.\n\n");
	}

	fclose(wordlist);

	return 0;
}
