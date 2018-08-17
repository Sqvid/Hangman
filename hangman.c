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

	//This randomly picks an entry number for the wordlist.	
	//loadWord() finds and loads the selected entry.
	srand(time(NULL));
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

	mvprintw(LINES - 3, 4, " %s", blankSpace);
	mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far:");
	mvwprintw(scoreWindow, 2, 2, "Correct guesses so far:");
	wrefresh(scoreWindow);

	//This block actually runs the game.
	while(misses < 7 && hits < wordSize){
		while(1){
			//These variables are used to guard against repeated guesses.
			int past_misses=0, past_hits=0;	

			mvprintw(1, 0, "Enter your guess: ");
			refresh();
			scanw(" %c", &guess );

			//This block checks the validity of the guess
			//Makes uppercase guesses valid.
			if(isalpha(guess)){						
				if(isupper(guess)){					
					guess=tolower(guess);
				}

				//checkGuess() will return zero only if
				//the guess is not a repeat.
				past_misses=checkGuess(toupper(guess), wrong);		
				past_hits=checkGuess(toupper(guess), correct);		

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

			//Block for wrong guesses.
			if(scoreChange==0){
				wrong[i_wrong]=toupper(guess);
				i_wrong++;
				misses++;
				mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far: %s", wrong);
				mvwprintw(scoreWindow, 2, 2, "Correct guesses so far: %s", correct);
			}

			//Block for correct guesses.
			else{
				correct[i_correct]=toupper(guess);
				i_correct++;
				hits=hits+scoreChange;
				mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far: %s", wrong);
				mvwprintw(scoreWindow, 2, 2, "Correct guesses so far: %s", correct);
			}

			wclrtoeol(scoreWindow);
			box(scoreWindow, 0, 0);
			wrefresh(scoreWindow);
		}

		//Fill in blanks if needed.
		mvprintw(LINES - 3, 4, " %s", fillBlanks(guess, answer, blankSpace));
	}

	clear();
	destroyWindow(hangmanWindow);
	destroyWindow(scoreWindow);

	if(misses==7){
		//THIS CENTERING WILL NOT WORK. CHANGE ASAP.
		mvprintw(LINES / 2, XCENTRE(23), "The word was %s! Better luck next time.", answer);
	}

	else if(hits==wordSize){
		//THIS CENTERING WILL NOT WORK. CHANGE ASAP.
		mvprintw(LINES / 2, XCENTRE(39), "Congratulations! You live another day.");
	}

	refresh();
	getch();
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
	wclear(targetWindow);
	wrefresh(targetWindow);
	delwin(targetWindow);
}
