#include "graphics.h"
#include<iostream>
using namespace std;


int main(){

    int Width = GetSystemMetrics(SM_CXSCREEN);
    int Height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(Width, Height, "", -3, -3); 

    int COLOR = RED;

    POINT cursorPos;


    while(true){

        GetCursorPos(&cursorPos);

        circle(cursorPos.x, cursorPos.y, 30);        

        setfillstyle(SOLID_FILL, COLOR);
        floodfill(cursorPos.x, cursorPos.y, WHITE);



        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        else if (GetAsyncKeyState(VK_SPACE))
            cleardevice();

        else if (GetAsyncKeyState(VK_RETURN))
            COLOR = (COLOR+1) % 16;


        delay(20);

    }


    getch();
    closegraph();
    return 0;
}