#ifndef INCLUDE_GUARD
	#define INCLUDE_GUARD

	#include <ncurses.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <ctype.h>
	#include <unistd.h>

	#define LIST_SIZE 4256		//This number defines the number of items in the wordlist.
	#define FIGHEIGHT 30
	#define FIGWIDTH 47
	#define SCOREHEIGHT 4
	#define SCOREWIDTH 47
	#define WARNINGY 2
	
	#define YCENTRE(height) (LINES - (height)) / 2
	#define XCENTRE(width) (COLS - (width)) / 2

	void loadWord(int line_number, FILE *fileptr, char outputArray[]);
	char* fillBlanks(char guess, char* answer, char* blanks);
	int checkGuess(char guess, char* string);

	//void printTitle(void);
	WINDOW* createWindow(int height, int width, int starty, int startx);
	void destroyWindow(WINDOW* targetWindow);
	void drawMan(int missNumber, WINDOW* hangmanWindow);
#endif
