#include<bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
using namespace std;



int main() {

    int gd = DETECT, gm;


    initgraph(&gd, &gm, (char*)"");

    int x = 100, y = 100, x1 = 200, y1 = 200;
    int dx, dy, p;
    dx = x1 - x;
    dy = y1 - y;
 
    p = 2 * dy - dx; //p is decision parameter

    while (x < x1)
    {
        if (p >= 0)
        {
            putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, 7);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
    getch();
    closegraph();
}
 
