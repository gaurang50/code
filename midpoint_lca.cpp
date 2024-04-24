#include <graphics.h>
#include <iostream>

using namespace std;

// Define clipping window dimensions
#define X_MIN 100
#define X_MAX 400
#define Y_MIN 100
#define Y_MAX 400

// Function to compute region code for a point (x, y)
int compute_code(int x, int y)
{
    int code = 0;
    if (x < X_MIN)
        code |= 1; // LEFT
    else if (x > X_MAX)
        code |= 2; // RIGHT
    if (y < Y_MIN)
        code |= 4; // BOTTOM
    else if (y > Y_MAX)
        code |= 8; // TOP
    return code;
}

// Function to clip a line segment (x1, y1)-(x2, y2) against a viewport using Mid-Point algorithm
void mid_point_clip(int x1, int y1, int x2, int y2)
{
    int code1 = compute_code(x1, y1);
    int code2 = compute_code(x2, y2);
    bool accept = false;

    while (true)
    {
        if (!(code1 | code2))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out = code1 ? code1 : code2;

            int x = x1;
            int y = y1;

            if (code_out & 8) // TOP
            {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            }
            else if (code_out & 4) // BOTTOM
            {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            }
            else if (code_out & 2) // RIGHT
            {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            }
            else if (code_out & 1) // LEFT
            {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = compute_code(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = compute_code(x2, y2);
            }
        }
    }

    if (accept)
    {
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
    }
    else
    {
        cout << "Line segment is outside the viewport and rejected." << endl;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    int x1 = 150, y1 = 70, x2 = 160, y2 = 340;
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    mid_point_clip(x1, y1, x2, y2);

    delay(15000);
    closegraph();
    return 0;
}