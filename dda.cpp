#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>
int main()
{
    float x, y, x1, x2, y1, y2, dx, dy, length;
    int i, gd, gm;

    cout << "Enter Value of x1 y1" << endl;
    cin >> x1 >> y1;
    cout << "Enter Value of x2 y2" << endl;
    cin >> x2 >> y2;

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, (char *)"\n");

    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // X-axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Y-axis

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
    {
        length = dx;
    }
    else
    {
        length = dy;
    }
    x = x1;
    y = y1;
    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;

    i = 1;
    outtextxy(getmaxx() / 2 + 10, getmaxy() / 2 + 10, (char *)"0,0");
    while (i <= length)
    {

        putpixel(x + getmaxx() / 2, getmaxy() / 2 - y, GREEN); // Adjust the coordinates to be centered
        x = x + dx;
        y = y + dy;
        delay(100);
        i++;
    }
    getch();
    closegraph();
}