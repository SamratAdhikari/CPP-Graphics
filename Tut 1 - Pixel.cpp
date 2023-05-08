#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "PIXEL");

    // putpixel(int x, int y, int color);
    putpixel(100, 200, WHITE);

    getch();
    closegraph();
    return 0;
}