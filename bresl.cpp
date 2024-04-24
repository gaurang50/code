#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>
int main()
{
    int dx, dy, x, y, p, x1, y1, x2, y2;
    int gd, gm;

    cout << "Enter coordinates of x1 y1" << endl;
    cin >> x1 >> y1;
    cout << "Enter coordinates of x2 y2" << endl;
    cin >> x2 >> y2;

    dx = (x2 - x1);
    dy = (y2 - y1);
    p = 2 * (dy) - (dx);
    x = x1;
    y = y1;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, (char *)"");

    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // X-axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Y-axis

    putpixel(x, y, RED);
    while (x <= x2)
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + 2 * (dy);
        }
        else
        {
            x = x + 1;
            y = y + 1;
            p = p + 2 * (dy - dx);
        }
        putpixel(x + getmaxx() / 2, getmaxy() / 2 - y, GREEN);
        delay(100);
    }
    getch();
    closegraph();
}
