#include <graphics.h>

int main(){

	// initialize window
    initwindow(800, 500, "ELLIPSE");

	// ellipse(int x, int y, int startangle, int endangle, int xrad, int yrad);
	
    // full ellipse
	ellipse(400, 200, 0, 360, 50, 30);

	// part of ellipse
	ellipse(300, 200, 90, 180, 200, 100);

	getch();
	closegraph();

	return 0;
}