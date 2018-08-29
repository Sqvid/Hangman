#include "hangman.h"

int main(void){
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	refresh();

	WINDOW *hangmanWindow, *scoreWindow;
	hangmanWindow = createWindow(FIGHEIGHT, FIGWIDTH,\
			YCENTRE(FIGHEIGHT + SCOREHEIGHT), XCENTRE(FIGWIDTH));
	scoreWindow = createWindow(SCOREHEIGHT, SCOREWIDTH,\
			YCENTRE(FIGHEIGHT + SCOREHEIGHT) + FIGHEIGHT,\
			XCENTRE(SCOREWIDTH));

	int lineNumber, wordSize, misses = 0, hits = 0, scoreChange;
	char guess, answer[25], blankSpace[50] = {'\0'}, wrong[8], correct[25], exitmsg[128];
	char repeatWarning[] = "**** You have already guessed that! ****";
	char nonAlphaWarning[] = "**** Sorry! Only alphabets allowed! ****";

	//Initialises these arrays with spaces so that they print correctly.
	memset(wrong, ' ', 7);
	memset(correct, ' ', 24);
	FILE *wordlist;
	wordlist = fopen("wordlist", "r");

	if(wordlist == NULL){
		printw("Sorry failed to read the wordlist.\n");
		refresh();
		getch();
		endwin();
		exit(1);
	}

	//This randomly picks an entry number for the wordlist.
	//loadWord() finds and loads the selected entry.
	srand(time(NULL));
	lineNumber = rand()%(LIST_SIZE - 1);
	loadWord(lineNumber, wordlist, answer);
	wordSize = strlen(answer);

	//(wordSize-1) becuase arrays count from 0. Multiplied by 2 because
	//we want spacing.
	for(int i=0; i<=2*(wordSize-1); i++){
		if(i%2 == 0){
			blankSpace[i] = '_';
		}

		else{
			blankSpace[i] = ' ';
		}
	}

	drawMan(0, hangmanWindow);
	mvprintw(LINES - 3, XCENTRE(strlen(blankSpace)), " %s", blankSpace);
	mvwprintw(scoreWindow, 1, 2, "Incorrect guesses so far:");
	mvwprintw(scoreWindow, 2, 2, "Correct guesses so far:");
	wrefresh(hangmanWindow);
	wrefresh(scoreWindow);

	//This block actually runs the game.
	while(misses < 7 && hits < wordSize){
		while(1){
			//These variables are used to guard against repeated guesses.
			int past_misses = 0, past_hits = 0;

			//mvprintw(1, 0, "Enter your guess: ");
			refresh();
			//scanw(" %c", &guess );
			guess = getch();

			//This block checks the validity of the guess
			//Makes uppercase guesses valid.
			if(isalpha(guess)){
				if(isupper(guess)){
					guess = tolower(guess);
				}

				//checkGuess() will return zero only if
				//the guess is not a repeat.
				past_misses = checkGuess(toupper(guess), wrong);
				past_hits = checkGuess(toupper(guess), correct);

				if(past_misses > 0 || past_hits > 0){
					mvprintw(WARNINGY, XCENTRE(strlen(repeatWarning)), repeatWarning);
				}

				else{
					move(WARNINGY, 0);
					clrtoeol();
					break;
				}
			}

			else{
				mvprintw(WARNINGY, XCENTRE(strlen(nonAlphaWarning)), nonAlphaWarning);
			}
		}

		scoreChange=checkGuess(guess, answer);

		{
			static int i_wrong = 0, i_correct=0;

			//Block for wrong guesses.
			if(scoreChange == 0){
				wrong[i_wrong] = toupper(guess);
				i_wrong++;
				misses++;
				drawMan(misses, hangmanWindow);
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
		mvprintw(LINES - 3, XCENTRE(strlen(blankSpace)), " %s",\
						fillBlanks(guess, answer, blankSpace));
	}

	getch();
	clear();
	destroyWindow(hangmanWindow);
	destroyWindow(scoreWindow);

	if(misses == 7){
		sprintf(exitmsg, "The word was %s! Better luck next time.", answer);
	}

	else if(hits == wordSize){
		strcpy(exitmsg, "Congratulations! You live another day.");
	}

	int exitmsgy = (LINES - 1) / 2;
	int exitmsgx = (COLS - strlen(exitmsg)) / 2;
	mvprintw(exitmsgy, exitmsgx, exitmsg);

	refresh();
	getch();
	endwin();

	return 0;
}
