#include "graphics.h"
#include<iostream>
using namespace std;

/*
enum colors {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, 
    LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};
*/

/*
Types of Patterns/Styles:
    EMPTY_FILL, SOLID_FILL, LINE_FILL, LTSLASH_FILL, SLASH_FILL, 
    BKSLASH_FILL, LTBKSLASH_FILL, HATCH_FILL, XHATCH_FILL, 
    INTERLEAVE_FILL, WIDE_DOT_FILL, CLOSE_DOT_FILL, USER_FILL, 
*/

int main(){

    // initialize window
    initwindow(800, 500, "COLORS");


    // ----------------- BACKGROUND ----------------- //


    // return the max no of colors available i.e. 15
    // worthless function as we know there are 16 colors in total i.e. 0 to 15
    // int getmaxcolor();
    int maxColors = getmaxcolor();
    cout << "Maximum number of Colors is: " << maxColors << endl;


    // return the current background color
    // int getbkcolor();
    int backgroundColor = getbkcolor();
    cout << "Current background color is: " << backgroundColor << endl;
    

    // set the current background color
    // void setbkcolor(int color);
    setbkcolor(BROWN);
    cleardevice();



    // ----------------- PALLETE ----------------- //

    // return current pallete color
    // int getcolor(); 
    int palleteColor = getcolor();
    cout << "Current pallete color is: " << palleteColor << endl;


    // sets the current pallete color
    // void setcolor(int color);
    setcolor(RED);
    circle(200, 200, 100);




    // ----------------- FILL COLOR ----------------- //

    // select the color and color pattern in order to fill
    // void setfillstyle(int pattern, int color);
    setfillstyle(INTERLEAVE_FILL, GREEN);

    // fill the object with set color and pattern
    // the fill coordinates should be inside the border of the object
    // it fills the object until the object's border color is reached. 
    // int floodfill(int x, int y, int obj_border_color);
    floodfill(200, 200, RED);


    getch();
    closegraph();
    return 0;
}