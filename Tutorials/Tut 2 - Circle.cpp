#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "CIRCLE");

    // circle(int x, int y, int radius);
    circle(100, 200, 50);
    circle(200, 300, 100);
    circle(10, 50, 200);

    getch();
    closegraph();
    return 0;
}