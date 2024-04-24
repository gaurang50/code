#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
// Constants for region codes
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

struct Point
{
    int x, y;
};

struct Window
{
    Point min, max;
};

int calculateRegionCode(const Window &win, const Point &p)
{
    int code = INSIDE;

    if (p.x < win.min.x)
        code |= LEFT;
    else if (p.x > win.max.x)
        code |= RIGHT;

    if (p.y < win.min.y)
        code |= BOTTOM;
    else if (p.y > win.max.y)
        code |= TOP;

    return code;
}

double calculateDistance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
bool clipLine(const Window &win, Point &p1, Point &p2)
{
    int code1 = calculateRegionCode(win, p1);
    int code2 = calculateRegionCode(win, p2);

    bool accept = false;

    while (true)
    {
        // Trivially accept
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;

            // Trivially reject
        }
        else if ((code1 & code2) != 0)
        {
            break;
        }
        else
        {
            // Line needs clipping
            int x, y;
            int codeOut;

            // Pick endpoint with code outside the window
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find intersection with window boundary
            if (codeOut & TOP)
            {
                x = p1.x + (p2.x - p1.x) * (win.max.y - p1.y) / (p2.y - p1.y);
                y = win.max.y;
            }
            else if (codeOut & BOTTOM)
            {
                x = p1.x + (p2.x - p1.x) * (win.min.y - p1.y) / (p2.y - p1.y);
                y = win.min.y;
            }
            else if (codeOut & RIGHT)
            {
                y = p1.y + (p2.y - p1.y) * (win.max.x - p1.x) / (p2.x - p1.x);
                x = win.max.x;
            }
            else if (codeOut & LEFT)
            {
                y = p1.y + (p2.y - p1.y) * (win.min.x - p1.x) / (p2.x - p1.x);
                x = win.min.x;
            }

            // Update point and its region code
            if (codeOut == code1)
            {
                p1.x = x;
                p1.y = y;
                code1 = calculateRegionCode(win, p1);
            }
            else
            {
                p2.x = x;
                p2.y = y;
                code2 = calculateRegionCode(win, p2);
            }
        }
    }
    return accept;
}

int main()
{
    Window win = {{100, 150}, {250, 250}};
    Point p1 = {70, 50};
    Point p2 = {130, 300};

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(win.min.x, win.min.y, win.max.x, win.max.y);

    setcolor(GREEN);
    line(p1.x, p1.y, p2.x, p2.y);

    double clippedLength = 0.0;
    if (clipLine(win, p1, p2))
    {
        setcolor(RED);
        line(p1.x, p1.y, p2.x, p2.y);
        clippedLength = calculateDistance(p1, p2);
    }
    cout << "Coordinates "
         << "(" << p1.x << "," << p1.y << ")"
         << "  "
         << "(" << p2.x << "," << p2.y << ")" << endl;
    std::cout << "Clipped Line Length: " << clippedLength << std::endl;

    getch();
    closegraph();
    return 0;
}