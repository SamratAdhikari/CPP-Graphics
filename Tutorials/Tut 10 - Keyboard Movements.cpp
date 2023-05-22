#include "graphics.h"
#include<iostream>
using namespace std;

/*
Key Codes:
    VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_ESCAPE, 
    VK_RETURN, VK_SPACE, VK_LBUTTON, VK_RBUTTON, 'X'
*/

/*
Used functions:

    - void GetAsyncKeyState(KEY_CODE);
    // Returns true if key is pressed otherwise it gets on
*/



int main(){

    // initialize window
    initwindow(800, 500, "KEYBOARD MOVEMENTS");
    int x = 400;
    int y = 250;
    int COLOR = RED;

    // setcolor(WHITE);


    while(true){
        // clear the window after each iteration
        cleardevice();
        

        // draw a circle after updating the center in each iteration
        circle(x, y, 50);
        

        // set bg color and fill the object with specified color
        setfillstyle(SOLID_FILL, COLOR);
        floodfill(x, y, WHITE);
        setbkcolor(BLACK);

        // Change the color
        // COLOR = (COLOR + 1) % 16;


        // EVENT HANDLING
        if (GetAsyncKeyState(VK_RIGHT))
            x += 10;

        else if (GetAsyncKeyState(VK_LEFT))
            x -= 10;

        else if (GetAsyncKeyState(VK_UP))
            y -= 10;
        
        else if (GetAsyncKeyState(VK_DOWN))
            y += 10;

        else if (GetAsyncKeyState(VK_SPACE))
            break;


        // 10 ms delay
        delay(10);

    }


    getch();
    closegraph();
    return 0;
}