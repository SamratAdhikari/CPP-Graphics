#include <graphics.h>
#include <iostream>
using namespace std;



// Key binding for ENTER key
void waitForEnter() {
    while (true) {
        if (GetAsyncKeyState(VK_RETURN))
			break;
    }
}


// initial screen
void startScreen(int WIDTH, int HEIGHT) {
    
    cleardevice();

	setcolor(LIGHTGRAY);
	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	outtextxy(WIDTH/2 - 300, HEIGHT/2 - 100, "Welcome to the Snake Game");

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(WIDTH/2 - 150, HEIGHT/2, "Press ENTER to play ...");

    waitForEnter();
}


// initial screen
void exitScreen(int WIDTH, int HEIGHT) {

    // cleardevice();
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
	floodfill(115, 115, LIGHTGREEN);

	setcolor(LIGHTGRAY);
	settextstyle(BOLD_FONT, HORIZ_DIR, 7);
	outtextxy(WIDTH/2 - 150, HEIGHT/2 - 100, "Game Over");

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(WIDTH/2 - 100, HEIGHT/2, "Press ENTER to exit");

    waitForEnter();
}

