/**************************************************
 *This file contains the source code required to
 *create and modify the ASCII hangman graphic
 *during runtime.
 *************************************************/

#include "hangman.h"


//void printTitle(void){
//	puts("\n");
//	puts("88                                                                                      ");
//	puts("88                                                                                      ");
//	puts("88                                                                                      ");
//	puts("88,dPPYba,  ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8 88,dPYba,,adPYba,  ,adPPYYba, 8b,dPPYba, ");
//	puts("88P'    `8a ``     `Y8 88P'   ``8a a8`    `Y88 88P'   `88`    `8a ``     `Y8 88P'   ``8a");
//	puts("88       88 ,adPPPPP88 88       88 8b       88 88      88      88 ,adPPPPP88 88       88");
//	puts("88       88 88,    ,88 88       88 `8a,   ,d88 88      88      88 88,    ,88 88       88");
//	puts("88       88 ``8bbdP`Y8 88       88  ``YbbdP`Y8 88      88      88 ``8bbdP`Y8 88       88");
//	puts("                                    aa,    ,88                                          ");
//	puts("                                     `Y8bbdP`                                           ");
//}

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

void drawMan(int missNumber, WINDOW* hangmanWindow){
	switch(missNumber){
		case 0 :
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "                                0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "                                 000         ");
			mvwprintw(hangmanWindow, 8, 1, "                                  00         ");
			mvwprintw(hangmanWindow, 9, 1, "                                  00         ");
			mvwprintw(hangmanWindow, 10, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 12, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 13, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 14, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 15, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 16, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 17, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 18, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 19, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 20, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 22, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 23, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 1 :
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "                                  00         ");
			mvwprintw(hangmanWindow, 10, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 12, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 13, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 14, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 15, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 16, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 17, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 18, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 19, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 20, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 22, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 23, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 2:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 14, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 15, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 16, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 17, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 18, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 19, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 20, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 22, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 23, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 3:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"         @8555558@                00         ");
			mvwprintw(hangmanWindow, 14, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 15, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 16, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 17, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 18, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 19, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 20, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 22, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 23, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 4:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"         @8555558@                00         ");
			mvwprintw(hangmanWindow, 14, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 15, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 16, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 17, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 18, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 19, 1,"           @@                     00         ");
			mvwprintw(hangmanWindow, 20, 1,"          @@                      00         ");
			mvwprintw(hangmanWindow, 21, 1,"         @@                       00         ");
			mvwprintw(hangmanWindow, 22, 1,"        @@                        00         ");
			mvwprintw(hangmanWindow, 23, 1,"       @@                         00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 5:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"         @8555558@                00         ");
			mvwprintw(hangmanWindow, 14, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 15, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 16, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 17, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 18, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 19, 1,"           @@@@                   00         ");
			mvwprintw(hangmanWindow, 20, 1,"          @@  @@                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"         @@    @@                 00         ");
			mvwprintw(hangmanWindow, 22, 1,"        @@      @@                00         ");
			mvwprintw(hangmanWindow, 23, 1,"       @@        @@               00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 6:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"         @8555558@                00         ");
			mvwprintw(hangmanWindow, 14, 1,"        @ |55555|                 00         ");
			mvwprintw(hangmanWindow, 15, 1,"       @  |55555|                 00         ");
			mvwprintw(hangmanWindow, 16, 1,"      @   |55555|                 00         ");
			mvwprintw(hangmanWindow, 17, 1,"     @    |55555|                 00         ");
			mvwprintw(hangmanWindow, 18, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 19, 1,"           @@@@                   00         ");
			mvwprintw(hangmanWindow, 20, 1,"          @@  @@                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"         @@    @@                 00         ");
			mvwprintw(hangmanWindow, 22, 1,"        @@      @@                00         ");
			mvwprintw(hangmanWindow, 23, 1,"       @@        @@               00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;

		case 7:
			mvwprintw(hangmanWindow, 1, 1, "             ooooooooooooooooooooooo         ");
			mvwprintw(hangmanWindow, 2, 1, "            /00000000000000000000000         ");
			mvwprintw(hangmanWindow, 3, 1, "            00               0    00         ");
			mvwprintw(hangmanWindow, 4, 1, "            00                0   00         ");
			mvwprintw(hangmanWindow, 5, 1, "            00                 0  00         ");
			mvwprintw(hangmanWindow, 6, 1, "             |                  0 00         ");
			mvwprintw(hangmanWindow, 7, 1, "             |                   000         ");
			mvwprintw(hangmanWindow, 8, 1, "             |                    00         ");
			mvwprintw(hangmanWindow, 9, 1, "            ooo                   00         ");
			mvwprintw(hangmanWindow, 10, 1,"           88888                  00         ");
			mvwprintw(hangmanWindow, 11, 1,"            888                   00         ");
			mvwprintw(hangmanWindow, 12, 1,"             l                    00         ");
			mvwprintw(hangmanWindow, 13, 1,"         @8555558@                00         ");
			mvwprintw(hangmanWindow, 14, 1,"        @ |55555| @               00         ");
			mvwprintw(hangmanWindow, 15, 1,"       @  |55555|  @              00         ");
			mvwprintw(hangmanWindow, 16, 1,"      @   |55555|   @             00         ");
			mvwprintw(hangmanWindow, 17, 1,"     @    |55555|    @            00         ");
			mvwprintw(hangmanWindow, 18, 1,"          |55555|                 00         ");
			mvwprintw(hangmanWindow, 19, 1,"           @@@@                   00         ");
			mvwprintw(hangmanWindow, 20, 1,"          @@  @@                  00         ");
			mvwprintw(hangmanWindow, 21, 1,"         @@    @@                 00         ");
			mvwprintw(hangmanWindow, 22, 1,"        @@      @@                00         ");
			mvwprintw(hangmanWindow, 23, 1,"       @@        @@               00         ");
			mvwprintw(hangmanWindow, 24, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 25, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 26, 1,"                                  00         ");
			mvwprintw(hangmanWindow, 27, 1,"                           d00000000000000b  ");
			mvwprintw(hangmanWindow, 28, 1,"                          doooooooooooooooob ");

			break;
	}

	wrefresh(hangmanWindow);
}
