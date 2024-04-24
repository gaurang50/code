#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
void CMP(int xcenter, int ycenter, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    void plotpoints(int, int, int, int);
    plotpoints(xcenter, ycenter, x, y);
    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plotpoints(xcenter, ycenter, x, y);
    }
}

void plotpoints(int xcenter, int ycenter, int x, int y)
{
    putpixel(xcenter + x, ycenter + y, WHITE);
    putpixel(xcenter - x, ycenter + y, WHITE);
    putpixel(xcenter + x, ycenter - y, WHITE);
    putpixel(xcenter - x, ycenter - y, WHITE);
    putpixel(xcenter + y, ycenter + x, WHITE);
    putpixel(xcenter - y, ycenter + x, WHITE);
    putpixel(xcenter + y, ycenter - x, WHITE);
    putpixel(xcenter - y, ycenter - x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, r;
    cout << "Enter x and y coordinates of center" << endl;
    cin >> xc >> yc;
    cout << "Enter radius of circle" << endl;
    cin >> r;
    CMP(xc, yc, r);

    getch();
    return 0;
}