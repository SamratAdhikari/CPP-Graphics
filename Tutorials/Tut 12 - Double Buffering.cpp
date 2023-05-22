#include "graphics.h"

/*
Visual Page (0) : The drawing is shown to the user using this page.
Active Page (1) : Next drawing is drawn in the active page.

These two pages/windows keep on changing after each iterations.
Now, Visual page becomes (1) and Active page becomes (0).
*/

/*
    - setvisualpage(int page);
    - setactivepage(int page);

    page values are changed in each iteration.
*/


int main(){

    int page = 0;
    int x = 100;
    int Width = GetSystemMetrics(SM_CXSCREEN);
    int Height = GetSystemMetrics(SM_CYSCREEN);

    // initialize window
    initwindow(Width, Height, "", -3, -3);

    setlinestyle(0, 0, 3);


    while (true){

        setactivepage(page);
        setactivepage(1-page);

        cleardevice();

        setcolor(RED);
        rectangle(x, 400, x+400, 600);

        setcolor(GREEN);
        circle(x+50, 650, 50);
        circle(x+350, 650, 50);


        if (GetAsyncKeyState(VK_RIGHT))
            x += 10;

        else if (GetAsyncKeyState(VK_LEFT))
            x -= 10;

        else if (GetAsyncKeyState(VK_ESCAPE))
            break;


        delay(10);

        page = 1 - page;
    }
   
    getch();
    closegraph();
    return 0;
}