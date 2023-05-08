#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "SMILEY FACE");

    circle(400, 250, 200);
    circle(475, 200, 25);
    circle(325, 200, 25);
    rectangle(380, 250, 420, 290);
    arc(400, 250, 225, 315, 125);

    getch();
    closegraph();
    return 0;
}