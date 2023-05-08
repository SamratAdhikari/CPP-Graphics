#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "RECTANGLE");

    // rectangle(int x1, int y1, int x2, int y2);
    rectangle(100, 150, 200, 200);
    rectangle(300, 300, 400, 400);

    getch();
    closegraph();
    return 0;
}