#include <iostream>
#include <graphics.h>
using namespace std;

void drawCirclePoint(int xc, int yc, int x, int y)
{
    int points[8][2] = {
        {x, y}, {y, x}, {y, -x}, {x, -y}, {-x, -y}, {-y, -x}, {-y, x}, {-x, y}};

    for (int i = 0; i < 8; ++i)
    {
        putpixel(xc + points[i][0], yc - points[i][1], RED);
    }
}

void drawCircle(int xc, int yc, int r)
{
    int x = r, y = 0;
    int P = 1 - r;

    while (x >= y)
    {
        drawCirclePoint(xc, yc, x, y);

        y++;
        if (P <= 0)
            P = P + 2 * y + 1;
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }
        delay(100);
    }
}

int main()
{

    int cx, cy, r;
    cout << "Enter the coordinates of center circle: ";
    cin >> cx >> cy;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // X-axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Y-axis

    char centerText[20], radiusText[20];
    sprintf(centerText, "Center: (%d, %d)", cx, cy);
    sprintf(radiusText, "Radius: %d", r);
    outtextxy(10, 10, centerText);
    outtextxy(10, 30, radiusText);

    drawCircle(getmaxx() / 2 + cx, getmaxy() / 2 - cy, r);

    delay(5000);
    closegraph();
    return 0;
}
