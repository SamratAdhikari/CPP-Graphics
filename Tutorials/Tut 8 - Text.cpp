#include<iostream>
#include "graphics.h"
using namespace std;


/*
Font Options:
	DEFAULT_FONT, TRIPLEX_FONT, SMALL_FONT, SANS_SHERIF_FONT, 
	GOTHIC_FONT, SCRIPT_FONT, SIMPLEX_FONT, TRIPLEX_SCR_FONT, 
	COMPLEX_FONT, EUROPEAN_FONT, BOLD_FONT
*/

/*
Font Direction:
	HORIZ_DIR - to display the text horizontally
	VERT_DIR - to display the text vertically 
*/


int main(){

	// initialize window
	initwindow(800, 500, "TEXT");


	// Set text color
	setcolor(MAGENTA);

	// Set the text style and direction:
	// void settextstyle(int font, int dir, int text_size);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 20);


	// Display text on the screen:
	// void outtextxy(int x, int y, char* text_string);
	outtextxy(50, 50, "HELLO WORLD");


	getch();
	closegraph();
	return 0;
}