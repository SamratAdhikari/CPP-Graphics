#include "graphics.h"
#include<iostream>
using namespace std;


void colorOpt(){
    setcolor(LIGHTGRAY);
    rectangle(10, 10, 150, 70);

    rectangle(10, 10, 40, 40);
    setfillstyle(SOLID_FILL, RED);
    floodfill(15, 15, LIGHTGRAY);

    rectangle(40, 10, 70, 40);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(45, 15, LIGHTGRAY);

    rectangle(70, 10, 100, 40);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(75, 15, LIGHTGRAY);

    rectangle(10, 40, 40, 70);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(15, 45, LIGHTGRAY);

    rectangle(70, 40, 100, 70);
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(75, 45, LIGHTGRAY);

    rectangle(40, 40, 70, 70);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(45, 45, LIGHTGRAY);


    setcolor(BLACK);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    outtextxy(110, 28, "X");
    // setcolor(LIGHTGRAY);
    // setfillstyle(SOLID_FILL, WHITE);
    // floodfill(105, 45, LIGHTGRAY);

}



int main(){

    int Width = GetSystemMetrics(SM_CXSCREEN);
    int Height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(Width, Height, "", -3, -3); 

    int COLOR = RED;
    int BACKGROUND = WHITE;
    int radius = 5;


    bool selectRed ;
    bool selectBlue;
    bool selectYellow;
    bool selectGreen;
    bool selectMagenta;
    bool selectBlack;
    bool selectClear;

    setbkcolor(WHITE);
    cleardevice();

    POINT cursorPos;

    while(true){
        colorOpt();
        setcolor(COLOR);

        GetCursorPos(&cursorPos);
        selectRed = ((cursorPos.x>10) && (cursorPos.y>10) && (cursorPos.x<40) && (cursorPos.y<40));
        selectBlue = ((cursorPos.x>40) && (cursorPos.y>10) && (cursorPos.x<70) && (cursorPos.y<40));
        selectYellow = ((cursorPos.x>70) && (cursorPos.y>10) && (cursorPos.x<100) && (cursorPos.y<40));
        selectGreen = ((cursorPos.x>10) && (cursorPos.y>40) && (cursorPos.x<40) && (cursorPos.y<70));
        selectMagenta = ((cursorPos.x>70) && (cursorPos.y>40) && (cursorPos.x<100) && (cursorPos.y<70));
        selectBlack = ((cursorPos.x>40) && (cursorPos.y>40) && (cursorPos.x<70) && (cursorPos.y<70));
        selectClear = ((cursorPos.x>100) && (cursorPos.y>10) && (cursorPos.x<150) && (cursorPos.y<70));
        

        if (GetAsyncKeyState(VK_LBUTTON) && (cursorPos.y > 100)){
            circle(cursorPos.x, cursorPos.y, radius);        

            setfillstyle(SOLID_FILL, COLOR);
            floodfill(cursorPos.x, cursorPos.y, COLOR);
        }


        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        // color change
        if (GetAsyncKeyState(VK_LBUTTON) && selectRed)
            COLOR = RED;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectBlue)
            COLOR = BLUE;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectYellow)
            COLOR = YELLOW;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectGreen)
            COLOR = GREEN;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectMagenta)
            COLOR = MAGENTA;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectBlack)
            COLOR = BLACK;

        else if (GetAsyncKeyState(VK_LBUTTON) && selectClear)
            cleardevice();


        delay(0);

    }


    getch();
    closegraph();
    return 0;
}