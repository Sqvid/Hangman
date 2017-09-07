/**************************************************
 *This file contains the source code required to
 *create and modify the ASCII hangman graphic
 *during runtime.
 *************************************************/

#include "hangman.h"


void printTitle(void){
	puts("\n");
	puts("88                                                                                      ");
	puts("88                                                                                      ");
	puts("88                                                                                      ");
	puts("88,dPPYba,  ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8 88,dPYba,,adPYba,  ,adPPYYba, 8b,dPPYba, ");
	puts("88P'    `8a ``     `Y8 88P'   ``8a a8`    `Y88 88P'   `88`    `8a ``     `Y8 88P'   ``8a");
	puts("88       88 ,adPPPPP88 88       88 8b       88 88      88      88 ,adPPPPP88 88       88");
	puts("88       88 88,    ,88 88       88 `8a,   ,d88 88      88      88 88,    ,88 88       88");
	puts("88       88 ``8bbdP`Y8 88       88  ``YbbdP`Y8 88      88      88 ``8bbdP`Y8 88       88");
	puts("                                    aa,    ,88                                          ");
	puts("                                     `Y8bbdP`                                           ");
}


void drawMan(int missNumber){
	switch(missNumber){
		case 0 :
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("                       	        0 00       \n");
			printf("                                 000       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                           d00000000000000b\n");
			printf("                          doooooooooooooooob\n");

			break;

		case 1 :
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                           d00000000000000b\n");      
			printf("                          doooooooooooooooob\n");

			break;

		case 2:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |                  0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             1                    00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                           d00000000000000b\n");
			printf("                          doooooooooooooooob\n");

			break;

		case 3:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             l                    00       \n");
			printf("          8555558                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");     
			printf("                                  00       \n");
			printf("                           d00000000000000b\n");
			printf("                          doooooooooooooooob\n");

			break;

		case 4:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             l                    00       \n");
			printf("          8555558                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("           @@                     00       \n");
			printf("          @@                      00       \n");
			printf("         @@                       00       \n");
			printf("        @@                        00       \n");
			printf("       @@                         00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");     
			printf("                                  00       \n");      
			printf("                           d00000000000000b\n");      
			printf("                          doooooooooooooooob\n");

			break;

		case 5:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             l                    00       \n");
			printf("          8555558                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("           @@@@                   00       \n");
			printf("          @@  @@                  00       \n");
			printf("         @@    @@                 00       \n");
			printf("        @@      @@                00       \n");
			printf("       @@        @@               00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");     
			printf("                                  00       \n");      
			printf("                           d00000000000000b\n");      
			printf("                          doooooooooooooooob\n");

			break;

		case 6:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             l                    00       \n");
			printf("         @8555558                 00       \n");
			printf("        @ |55555|                 00       \n");
			printf("       @  |55555|                 00       \n");
			printf("      @   |55555|                 00       \n");
			printf("     @    |55555|                 00       \n");
			printf("          |55555|                 00       \n");
			printf("           @@@@                   00       \n");
			printf("          @@  @@                  00       \n");
			printf("         @@    @@                 00       \n");
			printf("        @@      @@                00       \n");
			printf("       @@        @@               00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");     
			printf("                                  00       \n");      
			printf("                           d00000000000000b\n");      
			printf("                          doooooooooooooooob\n");

			break;

		case 7:
			puts("\n\n");
			printf("             ooooooooooooooooooooooo       \n");
			printf("            /00000000000000000000000       \n");
			printf("            00               0    00       \n");
			printf("            00                0   00       \n");
			printf("            00                 0  00       \n");
			printf("             |         	        0 00       \n");
			printf("             |                   000       \n");
			printf("             |                    00       \n");
			printf("            ooo                   00       \n");
			printf("           88888                  00       \n");
			printf("            888                   00       \n");
			printf("             l                    00       \n");
			printf("         @8555558@                00       \n");
			printf("        @ |55555| @               00       \n");
			printf("       @  |55555|  @              00       \n");
			printf("      @   |55555|   @             00       \n");
			printf("     @    |55555|    @            00       \n");
			printf("          |55555|                 00       \n");
			printf("           @@@@                   00       \n");
			printf("          @@  @@                  00       \n");
			printf("         @@    @@                 00       \n");
			printf("        @@      @@                00       \n");
			printf("       @@        @@               00       \n");
			printf("                                  00       \n");
			printf("                                  00       \n");     
			printf("                                  00       \n");      
			printf("                           d00000000000000b\n");      
			printf("                          doooooooooooooooob\n");

			break;
	}
}
