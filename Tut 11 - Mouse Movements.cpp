#include "graphics.h"
#include<iostream>
using namespace std;

/*
POINT:
    A structure in which you can store mouse coordinates as x,y .
*/

/*
Used functions:

    - void GetCursorPos(&POINT);
    // Returns the mouse coordinates

    - int GetAsyncKeystate(arg);
    // Returns true if the specified key is pressed.
    // VK_LBUTTON : for left button press event
    // VK_RBUTTON : for right button press event
*/



int main(){

    // initialize window
    initwindow(800, 500, "KEYBOARD MOVEMENTS");

    int COLOR = RED;

    POINT cursorPos;


    while(true){

        // get mouse cursor position
        GetCursorPos(&cursorPos);

        // clear the window after each iteration
        cleardevice();
        

        // draw a rectangle after updating the center in each iteration
        rectangle(cursorPos.x, cursorPos.y, cursorPos.x + 100, cursorPos.y + 100);
        

        // set bg color and fill the object with specified color
        setfillstyle(SOLID_FILL, COLOR);
        floodfill(cursorPos.x+25, cursorPos.y+25, WHITE);
        setbkcolor(BLACK);

        // EVENT HANDLING
        if (GetAsyncKeyState(VK_LBUTTON))
            break;


        // 50 ms delay
        delay(50);

    }


    getch();
    closegraph();
    return 0;
}