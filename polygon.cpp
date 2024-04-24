#include <iostream>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int gd, gm, n, *x, i, k = 0;
    int w[] = {220, 140, 420, 140, 420, 340, 220, 340, 220, 140};

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    std::cout << "Window:-";
    setcolor(RED);
    drawpoly(5, w);
    std::cout << "Enter the no. of vertices of polygon: ";
    std::cin >> n;
    x = (int *)malloc(n * 2 + 1);
    std::cout << "Enter the coordinates of points:\n";
    k = 0;
    for (i = 0; i < n * 2; i += 2)
    {
        std::cout << "(x" << k << ",y" << k << "): ";
        std::cin >> x[i] >> x[i + 1];
        k++;
    }
    x[n * 2] = x[0];
    x[n * 2 + 1] = x[1];
    setcolor(WHITE);
    drawpoly(n + 1, x);
    std::cout << "\nPress a button to clip a polygon..";
    getch();
    setcolor(RED);
    drawpoly(5, w);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(2, 2, RED);
    outtextxy(1, 1, "This is the clipped polygon..");
    std::cout << "\nThis is the clipped polygon..";
    getch();

    cleardevice();
    closegraph();
    free(x);
    return 0;
}