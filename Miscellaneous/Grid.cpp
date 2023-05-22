#include "graphics.h"

int main(){

    // Initialize game window
    int WIDTH = GetSystemMetrics(SM_CXSCREEN);
    int HEIGHT = GetSystemMetrics(SM_CYSCREEN);


    // variables
    int w = WIDTH/2;
    int h = HEIGHT/2;
    int o = 5; // offset

    initwindow(WIDTH, HEIGHT, "", -3, -3);



    // Text
    setcolor(GREEN);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 6);
    outtextxy(w-15*o, h-50*o, "GRID");



    // Lines
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);

    // main border
    line(w-40*o, h-40*o, w+40*o, h-40*o); // top
    line(w-40*o, h+40*o, w+40*o, h+40*o); // bottom
    line(w-40*o, h-40*o, w-40*o, h+40*o); // left
    line(w+40*o, h-40*o, w+40*o, h+40*o); // right

    // mid section
    line(w, h-40*o, w, h+40*o); // vertical
    line(w-40*o, h, w+40*o, h); // horizontal

    // 1st quartile section
    line(w-20*o, h-40*o, w-20*o, h+40*o); // vertical
    line(w-40*o, h-20*o, w+40*o, h-20*o); // horizontal

    // 2nd quartile section
    line(w+20*o, h-40*o, w+20*o, h+40*o); // vertical
    line(w-40*o, h+20*o, w+40*o, h+20*o); // horizontal

    // main diagonals
    line(w-40*o, h-40*o, w+40*o, h+40*o); // -ve diag
    line(w-40*o, h+40*o, w+40*o, h-40*o); // +ve diag

    // sub diagonals
    line(w-40*o, h, w, h-40*o); // 1st quadrant
    line(w+40*o, h, w, h-40*o); // 2nd quadrant
    line(w-40*o, h, w, h+40*o); // 3rd quadrant
    line(w+40*o, h, w, h+40*o); // 4th quadrant


    getch();
    closegraph();
    return 0;
}