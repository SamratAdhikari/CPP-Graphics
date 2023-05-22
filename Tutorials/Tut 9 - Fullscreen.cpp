#include "graphics.h"

int main(){

    // Get the screen resolution
    // int GetSystemMetrics(arg);
    int Width = GetSystemMetrics(SM_CXSCREEN); // X dimension
    int Height = GetSystemMetrics(SM_CYSCREEN); // Y dimension

    // Initialize window with a fullscreen
    initwindow(Width, Height, "", -3, -3); 
    // last 2 args are to remove the borders

    getch();
    closegraph();
    return 0;
}