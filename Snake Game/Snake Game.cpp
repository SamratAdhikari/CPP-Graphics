#include <graphics.h>
#include <iostream>
#include <string>
#include <mmsystem.h>
#include <windows.h>
#include <fstream>


#pragma comment(lib, "winmm.lib")

#include "body.h"
#include "food.h"

using namespace std;
 

int main(){


	// Game Variables
	int WIDTH = GetSystemMetrics(SM_CXSCREEN);
	int HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	int page = 0;
	int highscore;
	int food = 0;
	bool checkX;
	bool checkY;

	std::ifstream readFile;
	readFile.open("assets/highscore.txt");
	if (readFile.is_open()){
		while(!readFile.eof())
			readFile >> highscore;
	}
	readFile.close();

	// Initialize game window
	initwindow(WIDTH, HEIGHT, "", -3, -3);

	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

	// Game Objects
	Snake sn;
	Food fd;

	fd.setPos(400, 400);

	// Game loop
	while (true){
		

		// PlaySound(TEXT("bgMusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		
		// Update game window
		setvisualpage(page);
		setactivepage(1-page);

		// ---------------------- MAIN SECTION ---------------------- //
		setcolor(LIGHTGRAY);
		rectangle(5, 5, WIDTH-5, HEIGHT-5);



		// ---------------------- INFO SECTION ---------------------- //
		setcolor(LIGHTBLUE);
		rectangle(10, 10, WIDTH-10, 100);
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(15, 15, LIGHTBLUE);

		// Highscore & Food count
		string str_highscore = to_string(highscore);
		string str_food = to_string(food);

		setbkcolor(BLUE);
		setcolor(LIGHTGRAY);
		settextstyle(BOLD_FONT, HORIZ_DIR, 5);
		outtextxy(35, 35, "FOOD:");
		outtextxy(170, 35, &str_food[0]);
		outtextxy(WIDTH-400, 35, "HIGHSCORE:");
		outtextxy(WIDTH-130, 35, &str_highscore[0]);


		// ---------------------- GAME SECTION ---------------------- //
		setcolor(LIGHTGREEN);
		rectangle(10, 105, WIDTH-10, HEIGHT-10);
		setfillstyle(INTERLEAVE_FILL, GREEN);
		floodfill(115, 115, LIGHTGREEN);


		// FOOD
		fd.drawFood();

		// SNAKE
		sn.drawSnake();
		sn.moveSnake(food);




		// ---------------------- KEY BINDINGS ---------------------- //
		
		// Quit game
		if (GetAsyncKeyState(VK_ESCAPE))
			break;

		// Move Up
		else if (GetAsyncKeyState(VK_UP)){
			sn.changeDir(UP);
		}
			
		// Move Down
		else if (GetAsyncKeyState(VK_DOWN)){
			sn.changeDir(DOWN);
		}

		// Move Left
		else if (GetAsyncKeyState(VK_LEFT)){
			sn.changeDir(LEFT);
		}

		// Move Right
		else if (GetAsyncKeyState(VK_RIGHT)){
			sn.changeDir(RIGHT);
		}


		// ---------------------- COLLISION ---------------------- //
		
		// Collision with the border
		if ((sn.getPosX() < 10) || (sn.getPosY() < 105) || (sn.getPosX() > WIDTH-10) || (sn.getPosY() > HEIGHT-10)){
			system("pause");
		}

		// Collision with food
		checkX = (sn.getPosX()+15 >= fd.getPosX()-20) && (sn.getPosX()+15 <= fd.getPosX()+20);
		checkY = (sn.getPosY()+15 >= fd.getPosY()-20) && (sn.getPosY()+15 <= fd.getPosY()+20);
 
		if (checkX && checkY){
			food++;
			fd.generateFood();
		}
		

		// Collision with itself
		if (sn.isCollision())
			system("pause");
	

		delay(60);
		page = 1 - page;
		}


		if (food > highscore)
			highscore = food;


		std::ofstream writeFile;
		writeFile.open("assets/highscore.txt");
		writeFile << highscore;
		writeFile.close();

	// close window
	getch();
	closegraph();
	return 0; 
}