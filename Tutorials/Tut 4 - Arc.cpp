#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "ARC");

    // arc(int x, int y, int stangle, int endangle, int radius);
    // - angles are measured in anticlockwise direction from right hand side

    arc(100, 100, 45, 90, 50);
    arc(300, 100, 270, 45, 50);
    arc(100, 300, 0, 180, 50);
    arc(300, 300, 0, 90, 50);

    getch();
    closegraph();
    return 0;
}