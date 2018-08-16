#include "hangman.h"

#define FIGHEIGHT 29
#define FIGWIDTH 45
#define SCOREHEIGHT 4
#define SCOREWIDTH 45

#define YCENTRE(height) (LINES - (height)) / 2
#define XCENTRE(width) (COLS - (width)) / 2

WINDOW* createWindow(int height, int width, int starty, int startx);
void destroyWindow(WINDOW* targetWindow);

int main(void){
	initscr();
	raw();
	refresh();

	WINDOW *hangmanWindow, *scoreWindow;
	hangmanWindow = createWindow(FIGHEIGHT, FIGWIDTH, YCENTRE(FIGHEIGHT +\
			       	SCOREHEIGHT), XCENTRE(FIGWIDTH));
	scoreWindow = createWindow(SCOREHEIGHT, SCOREWIDTH, YCENTRE(FIGHEIGHT +\
			       	SCOREHEIGHT) + FIGHEIGHT, XCENTRE(SCOREWIDTH));

	int lineNumber, wordSize, misses=0, hits=0, scoreChange;
	char guess, answer[25], blankSpace[50], wrong[8]="       \0", correct[25]="                        \0";
	FILE *wordlist; 
	wordlist=fopen("wordlist", "r");
	
	if(wordlist==NULL){
		printw("Sorry failed to read the wordlist.\n");
		refresh();
		getch();
		endwin();
		exit(1);
	}

	srand(time(NULL));
	//This randomly picks an entry number for the wordlist.	
	//loadWord() finds and loads the selected entry.
	lineNumber=rand()%(LIST_SIZE - 1);
	loadWord(lineNumber, wordlist, answer);
	wordSize=strlen(answer);

	//(wordSize-1) becuase arrays count from 0. Multiplied by 2 because
	//we want spacing.
	for(int i=0; i<=2*(wordSize-1); i++){
		if(i%2==0){
			blankSpace[i]='_';
		}
		
		else{
			blankSpace[i]=' ';
		}
	}

	while(misses < 7 && hits < wordSize){		//This block actually runs the game.
		while(1){
			int past_misses=0, past_hits=0;	//These variables are used to guard against repeated guesses.

			mvprintw(1, 0, "Enter your guess: ");
			refresh();
			scanw(" %c", &guess );

			if(isalpha(guess)){						//This block checks the validity of the guess
				if(isupper(guess)){					//Makes uppercase guesses valid.
					guess=tolower(guess);
				}
			
				past_misses=checkGuess(toupper(guess), wrong);		//checkGuess() will return zero only if
				past_hits=checkGuess(toupper(guess), correct);		//the guess is not a repeat.

				if(past_misses>0 || past_hits>0){
					mvprintw(0, 0, " ****You have already guessed that!****");
				}

				else{
					break;
				}
			}

			else{
				mvprintw(0, 0, "****Sorry! Only alphabets allowed!****");
			}
		}

		scoreChange=checkGuess(guess, answer);

		{
			static int i_wrong=0, i_correct=0;

			if(scoreChange==0){							//Block for wrong guesses.
				wrong[i_wrong]=toupper(guess);
				i_wrong++;
				misses++;
				//puts("\n\n    ************************************************************");
				mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far: %s", wrong);
				mvwprintw(scoreWindow, 2, 2, "Correct guesses so far: %s", correct);
				//puts("    ************************************************************");
			}

			else{									//Block for correct guesses.
				correct[i_correct]=toupper(guess);
				i_correct++;
				hits=hits+scoreChange;
				//puts("\n----------------------------------------------------------------------------------------");
				//drawMan(misses);
				//puts("\n\n    ************************************************************");
				mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far: %s", wrong);
				mvwprintw(scoreWindow, 2, 2, "Correct guesses so far: %s", correct);
				//puts("    ************************************************************");
			}

			wclrtoeol(scoreWindow);
			box(scoreWindow, 0, 0);
			wrefresh(scoreWindow);
		}

		mvprintw(LINES - 3, 4, " %s", fillBlanks(guess, answer, blankSpace));		//Fill in blanks if needed.
	}

	refresh();
	getch();
	destroyWindow(hangmanWindow);
	destroyWindow(scoreWindow);
	endwin();
}

WINDOW* createWindow(int height, int width, int starty, int startx){
	WINDOW* localWindow = newwin(height, width, starty, startx);

	box(localWindow, 0, 0);
	wrefresh(localWindow);

	return localWindow;
}

void destroyWindow(WINDOW* targetWindow){
	wborder(targetWindow, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(targetWindow);
	delwin(targetWindow);
}
