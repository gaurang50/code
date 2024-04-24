#include <iostream>
#include <graphics.h>
using namespace std;

void drawCirclePoint(int xc, int yc, int x, int y)
{
    int points[8][2] = {
        {x, y}, {y, x}, {y, -x}, {x, -y}, {-x, -y}, {-y, -x}, {-y, x}, {-x, y}};

    for (int i = 0; i < 8; ++i)
    {
        putpixel(xc + points[i][0], yc + points[i][1], GREEN);
    }
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        drawCirclePoint(xc, yc, x, y);
        delay(100);
    }
}

int main()
{
    int xc, yc, r;
    cout << "Enter the center coordinates: ";
    cin >> xc >> yc;
    cout << "Enter radius of circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // X-axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Y-axis
    char centerText[20], radiusText[20];
    sprintf(centerText, "Center: (%d, %d)", xc, yc);
    sprintf(radiusText, "Radius: %d", r);
    outtextxy(10, 10, centerText);
    outtextxy(10, 30, radiusText);
    drawCircle(getmaxx() / 2 + xc, getmaxy() / 2 - yc, r);

    delay(5000);
    closegraph();
    return 0;
}
