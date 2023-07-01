#include "graphics.h"
#include <iostream>
#include <math.h>

int main(){

    initwindow(500, 500, "Digital Differential Analyzer");

    float x,y,x1,y1,x2,y2,dx,dy,step;

    std::cout << "ENTER x1, y1, x2, y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;


    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);
    
    if (dx >= dy)
        step = dx;
    else
        step = dy;

    dx = dx/step;
    dy = dy/step;
    int i = 1;
    x = x1;
    y = y1;

    while(i <= step){
        putpixel(x,y,WHITE);
        x = x + dx;
        y = y + dy;
        i = i + 1;
        delay(100);
    }

    system("pause");
    return 0;

}