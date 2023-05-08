#include "graphics.h"
#include <string.h>
#include <math.h>
#include <ctime>
#include <iostream>

using namespace std;

#define PI 3.1415


int main(){

	initwindow(500, 500, "ANALOG CLOCK");

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	int page = 0;

	while (true){


		// double buffering
		setactivepage(page);
		setvisualpage(1-page);

		cleardevice();
		setlinestyle(0, 0, 3);
		setcolor(LIGHTBLUE);

		// Clock structure
		circle(250, 250, 200);
		circle(250, 250, 5);

		for (int i=1; i<=12; i++){
			string str = to_string(i);
			outtextxy(250+175*sin(i*PI/6), 250-180*cos(i*PI/6), &str[0]);
		}

		// get current time
		time_t now = time(0);
		tm *ltm = localtime(&now);

		// hour hand
		setcolor(RED);
		line(250, 250, 250+150*sin(ltm->tm_hour * PI/6), 250-80*cos(ltm->tm_hour * PI/6));

		// minute hand
		setcolor(GREEN);
		line(250, 250, 250+150*sin(ltm->tm_min * PI/30), 250-150*cos(ltm->tm_min * PI/30));

		// second hand
		setcolor(YELLOW);
		setlinestyle(0, 0, 1);
		line(250, 250, 250+150*sin(ltm->tm_sec * PI/30), 250-150*cos(ltm->tm_sec * PI/30));

		// Event handling
		if (GetAsyncKeyState(VK_SPACE))
			break;


		delay(10);
		page = 1-page;
	}
	getch();
	closegraph();
	return 0;
}