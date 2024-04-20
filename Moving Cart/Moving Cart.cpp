#include "graphics.h"

int main(){

    int x = 100;
    int Width = GetSystemMetrics(SM_CXSCREEN);
    int Height = GetSystemMetrics(SM_CYSCREEN);

    // initialize window
    initwindow(Width, Height, "", -3, -3);

    setlinestyle(0, 0, 3);

    int page = 0;



    while (true){

        setactivepage(page);
        setvisualpage(1-page);

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