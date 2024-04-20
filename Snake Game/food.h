#include <graphics.h>
#include <time.h>
#include <iostream>



struct POS{
	int x;
	int y;

};

class Food{
private:
	POS foodPos;
	int WIDTH = GetSystemMetrics(SM_CXSCREEN);
	int HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	int newX;
	int newY;

public:
	// Methods
	void drawFood();
	void generateFood();
	int getPosX();
	int getPosY();
	void setPos(int a, int b);
};



// draw the food on the screen randomly
void Food::drawFood(){
	setcolor(BLACK);
	circle(foodPos.x, foodPos.y, 15); //10
	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(foodPos.x, foodPos.y, BLACK);

}

void Food::generateFood(){

		srand(time(NULL));
		newX = (rand() % (WIDTH-400)) + 200; 
		newY = (rand() % (HEIGHT-400)) + 200;


	setPos(newX, newY);
	

}


// Getters
int Food::getPosX(){
	return foodPos.x;
}

int Food::getPosY(){
	return foodPos.y;
}


// Setters
void Food::setPos(int a, int b){
	foodPos.x = a;
	foodPos.y = b;
}