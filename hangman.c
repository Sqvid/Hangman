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
	lineNumber=rand()%(LIST_SIZE - 1);		//This randomly picks an entry number for the wordlist.	
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
	
	{						//These instructions initialise the graphics.
		printTitle();
		sleep(1);
		puts("\n----------------------------------------------------------------------------------------");
		drawMan(0);
	}


	puts("\n\n    ************************************************************");
	    puts("    *Incorrect guesses so far:                                 *");
	    puts("    *Correct guesses so far:                                   *");
	    puts("    ************************************************************");

	printf("\n    The word is %d letters long.\n", wordSize);
	printf("\n    %s\n\n", blankSpace);



	while(misses<7 && hits<wordSize){		//This block actually runs the game.
		while(1){
			int past_misses=0, past_hits=0;	//These variables are used to guard against repeated guesses.

			printf("\n    Enter your guess: ");
			scanf(" %c", &guess );

			if(isalpha(guess)){						//This block checks the validity of the guess
				if(isupper(guess)){					//Makes uppercase guesses valid.
					guess=tolower(guess);
				}
			
				past_misses=checkGuess(toupper(guess), wrong);		//checkGuess() will return zero only if
				past_hits=checkGuess(toupper(guess), correct);		//the guess is not a repeat.

				if(past_misses>0 || past_hits>0){
					puts("\n    ****You have already guessed that!****");
				}

				else{
					break;
				}
			}

			else{
				puts("\n    ****Sorry! Only alphabets allowed!****");
			}
		}


		scoreChange=checkGuess(guess, answer);

		{
			static int i_wrong=0, i_correct=0;

			if(scoreChange==0){							//Block for wrong guesses.
				wrong[i_wrong]=toupper(guess);
				i_wrong++;
				misses++;
				puts("\n----------------------------------------------------------------------------------------");
				drawMan(misses);
				puts("\n\n    ************************************************************");
				printf("    *Incorrect guesses so far: %s                         *\n", wrong);
				printf("    *Correct guesses so far: %s          *\n", correct);
				puts("    ************************************************************");
			}

			else{									//Block for correct guesses.
				correct[i_correct]=toupper(guess);
				i_correct++;
				hits=hits+scoreChange;
				puts("\n----------------------------------------------------------------------------------------");
				drawMan(misses);
				puts("\n\n    ************************************************************");
				printf("    *Incorrect guesses so far: %s                         *\n", wrong);
				printf("    *Correct guesses so far: %s          *\n", correct);
				puts("    ************************************************************");
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
