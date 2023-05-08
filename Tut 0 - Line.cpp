#include "graphics.h"

/*  -- set the line style and width
    void setlinestyle(int linestyle, unsigned upattern, int thickness);

LINE STYLES:
NAME            VALUE           DESCRIPTION
SOLID_LINE          0           Solid line
DOTTED_LINE         1           Dotted line
CENTER_LINE         2           Centered line
DASHED_LINE         3           Dashed line
USERBIT_LINE        4           User-defined line

THICKNESS:
NAME            VALUE           DESCRIPTION
NORM_WIDTH      1               1 pixel wide
THICK_WIDTH     3               3 pixel wide
*/



int main(){

    // initialize window
    initwindow(800, 500, "LINE");


    setlinestyle(1, 0, 3);

    // line(int x1, int y1, int x2, int y2);
    line(200, 250, 400, 250);

    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    line(100, 250, 500, 400);

    getch();
    closegraph();
    return 0;
}