#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
struct point
{
    double x, y;
};
point subject_poly[100];
point window[100];
queue<point> q1, q2;
void dda_line(double x1, double y1, double x2, double y2);
void print_clipping_window()
{
    int i;
    for (i = 0; i < 4; i++)
    {
        line(window[i].x, window[i].y, window[i + 1].x, window[i + 1].y);
    }
}
void print_sub(int side)
{
    int i;
    for (i = 0; i < side; i++)
    {
        line(subject_poly[i].x, subject_poly[i].y, subject_poly[i + 1].x, subject_poly[i + 1].y);
    }
}
int left_code(point p)
{
    int code = 0;
    if (p.x >= window[0].x)
        code = 0;
    else
        code = 1;
    return code;
}
int right_code(point p)
{
    int code = 0;
    if (p.x > window[2].x)
        code = 1;
    else
        code = 0;
    return code;
}
int top_code(point p)
{
    int code = 0;
    if (p.y > window[2].y)
        code = 1;
    else
        code = 0;
    return code;
}
int bottom_code(point p)
{
    int code = 0;
    if (p.y >= window[0].y)
        code = 0;
    else
        code = 1;
    return code;
}
void sutherland_hodgman(int sides)
{
    int c = 4, i, t;
    point p1, p2, p;
    double m;
    for (i = 0; i <= sides; i++)
        q1.push(subject_poly[i]);
    while (c)
    {
        if (c % 2 == 0)
        {
            t = q1.size();
            while (t > 1)
            {
                p1 = q1.front();
                q1.pop();
                p2 = q1.front();
                if (p2.x != p1.x)
                    m = (p2.y - p1.y) / (p2.x - p1.x);
                if (c == 4) // left edge
                {
                    if (left_code(p1) == 0 && left_code(p2) == 0)
                        q2.push(p2);
                    else if (left_code(p1) == 0 && left_code(p2) == 1)
                    {
                        p.x = window[0].x;
                        p.y = p1.y + m * (p.x - p1.x);
                        q2.push(p);
                    }
                    else if (left_code(p1) == 1 && left_code(p2) == 0)
                    {
                        p.x = window[0].x;
                        p.y = p1.y + m * (p.x - p1.x);
                        q2.push(p);
                        q2.push(p2);
                    }
                }
                else if (c == 2) // top edge
                {
                    if (top_code(p1) == 0 && top_code(p2) == 0)
                        q2.push(p2);
                    else if (top_code(p1) == 0 && top_code(p2) == 1)
                    {
                        p.y = window[2].y;
                        p.x = p1.x + (p.y - p1.y) / m;
                        q2.push(p);
                    }
                    else if (top_code(p1) == 1 && top_code(p2) == 0)
                    {
                        p.y = window[2].y;
                        p.x = p1.x + (p.y - p1.y) / m;
                        q2.push(p);
                        q2.push(p2);
                    }
                }
                t--;
            }
            q2.push(q2.front());
            while (!q1.empty())
                q1.pop();
        }
        else
        {
            t = q2.size();
            while (t > 1)
            {
                p1 = q2.front();
                q2.pop();
                p2 = q2.front();
                if (p2.x != p1.x)
                    m = (p2.y - p1.y) / (p2.x - p1.x);
                if (c == 3) // right edge
                {
                    if (right_code(p1) == 0 && right_code(p2) == 0)
                    {
                        q1.push(p2);
                    }
                    else if (right_code(p1) == 0 && right_code(p2) == 1)
                    {
                        p.x = window[2].x;
                        p.y = p1.y + m * (p.x - p1.x);
                        q1.push(p);
                    }
                    else if (right_code(p1) == 1 && right_code(p2) == 0)
                    {
                        p.x = window[2].x;
                        p.y = p1.y + m * (p.x - p1.x);
                        q1.push(p);
                        q1.push(p2);
                    }
                }
                else
                {
                    if (bottom_code(p1) == 0 && bottom_code(p2) == 0)
                    {
                        q1.push(p2);
                    }
                    else if (bottom_code(p1) == 0 && bottom_code(p2) == 1)
                    {
                        p.y = window[0].y;
                        p.x = p1.x + (p.y - p1.y) / m;
                        q1.push(p);
                    }
                    else if (bottom_code(p1) == 1 && bottom_code(p2) == 0)
                    {
                        p.y = window[0].y;
                        p.x = p1.x + (p.y - p1.y) / m;
                        q1.push(p);
                        q1.push(p2);
                    }
                }
                t--;
            }
            q1.push(q1.front());
            while (!q2.empty())
                q2.pop();
        }
        c--;
    }
    t = q1.size();
    while (t > 1)
    {
        p = q1.front();
        q1.pop();
        p1 = q1.front();
        line(p.x, p.y, p1.x, p1.y);
        t--;
        // cout << p.x << " " << p.y << " " << p1.x << " " << p1.y;
    }
}
int main()
{

    int gm = DETECT, i, gd, side;
    int a, b;

    cout << "Enter coordinates of clipping window (in clockwise order):" << endl;
    for (i = 0; i < 4; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> window[i].x >> window[i].y;
    }
    window[4].x = window[0].x;
    window[4].y = window[0].y;

    initgraph(&gm, &gd, "C:\\TC\\BGI");

    print_clipping_window();

    cout << "Enter the number of sides of the subject polygon: ";
    cin >> side;

    cout << "Enter coordinates of the subject polygon vertices (in clockwise or anticlockwise order):" << endl;
    for (i = 0; i < side; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> subject_poly[i].x >> subject_poly[i].y;
    }
    subject_poly[i].x = subject_poly[0].x;
    subject_poly[i].y = subject_poly[0].y;

    print_sub(side);

    getch();
    cleardevice();

    sutherland_hodgman(side);

    print_clipping_window();

    getch();
    closegraph();
    return 0;
}