#include <iostream>
#include <graphics.h>

using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BELOW = 4;  // 0100
const int ABOVE = 8;  // 1000

int bitvalue(double x, double y, double xmin, double ymin, double xmax, double ymax)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BELOW;
    else if (y > ymax)
        code |= ABOVE;

    return code;
}

void cohenSutherland(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax, double m)
{
    int code1 = bitvalue(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = bitvalue(x2, y2, xmin, ymin, xmax, ymax);
    bool flag = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // Both endpoints are inside the window
            flag = true;
            break;
        }
        else if (code1 & code2)
        {
            // Both endpoints are outside the window and on the same side
            cout << "The line segment is invisble" << endl;
            break;
        }
        else
        {
            // Some part of the line may be inside the window
            int codeOut = code1 ? code1 : code2;

            double x, y;

            if (codeOut & ABOVE)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (codeOut & BELOW)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + m * (xmax - x1);
                x = xmax;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + m * (xmin - x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = bitvalue(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = bitvalue(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (flag)
    {
        cout << "The line segment is clipped" << endl;
        cout << "Coordinates of the clipped line segment: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;

        setcolor(YELLOW);
        line(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double x1, y1, x2, y2;
    cout << "Enter coordinates of the line segment (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    double xmin, ymin, xmax, ymax;
    cout << "Enter coordinates of the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    double m = (x2 - x1 == 0) ? 0 : (y2 - y1) / (x2 - x1);

    line(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
    rectangle(static_cast<int>(xmin), static_cast<int>(ymin), static_cast<int>(xmax), static_cast<int>(ymax));

    cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax, m);

    delay(5000);

    return 0;
}