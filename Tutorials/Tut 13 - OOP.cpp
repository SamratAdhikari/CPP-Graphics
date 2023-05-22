#include <graphics.h>

class CIRCLE{
private:
	int X, Y, Radius;
	int FillColor, OutlineColor;

public:
	CIRCLE(int x, int y, int radius, int fillColor, int outlineColor){
		this->X = x;
		this->Y = y;
		this->Radius = radius;
		this->FillColor = fillColor;
		this->OutlineColor = outlineColor;
	}

	void draw(){
		setcolor(OutlineColor);
		setfillstyle(SOLID_FILL, FillColor);

		circle(X, Y, Radius);
		floodfill(X, Y, OutlineColor);
	}

};


int main(){

	initwindow(800, 500, "OOP");

	CIRCLE c1 (100, 100, 50, GREEN, RED);
	CIRCLE c2 (300, 300, 100, BLUE, YELLOW);

	c1.draw();
	c2.draw();


	getch();
	closegraph();
	return 0;

}