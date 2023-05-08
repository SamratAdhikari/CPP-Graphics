#include "graphics.h"

int main(){

    // initialize window
    initwindow(800, 500, "IMAGE");

    setbkcolor(WHITE);
    cleardevice();

    // void readimagefile(const char* "filename.ext", int left, 
    //                      int top, int right, int bottom);
    
    readimagefile("assets/LOGO.bmp" , 300, 200, 450, 350);

    getch();
    closegraph();
    return 0;
}