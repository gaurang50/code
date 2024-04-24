#include<iostream>
#include<graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int gm, gd = DETECT;
    initgraph(&gd, &gm, "");

    int x = 0, y = ry;
    int p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;

    while (2 * ry * ry * x < 2 * rx * rx * y) {
        putpixel(xc + x, yc - y, WHITE);
        delay(5);  
        putpixel(xc - x, yc - y, MAGENTA);
        delay(5);
        putpixel(xc + x, yc + y, WHITE);
        delay(5);
        putpixel(xc - x, yc + y, MAGENTA);
        delay(5);

        if (p1 < 0) {
            x++;
            p1 = p1 + 2 * ry * ry * x + ry * ry;
        }
        else {
            x++;
            y--;
            p1 = p1 + 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }

    int p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        putpixel(xc + x, yc - y, MAGENTA);
        delay(5);
        putpixel(xc - x, yc - y, WHITE);
        delay(5);
        putpixel(xc + x, yc + y, MAGENTA);
        delay(5);
        putpixel(xc - x, yc + y, WHITE);
        delay(5);

        if (p2 > 0) {
            y--;
            p2 = p2 - 2 * rx * rx * y + rx * rx;
        }
        else {
            x++;
            y--;
            p2 = p2 + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }

    delay(5000);
    closegraph();
}

int main() {
    int xc, yc, rx, ry;
    std::cout << "Enter the center coordinates (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the semi-major axis (rx): ";
    std::cin >> rx;
    std::cout << "Enter the semi-minor axis (ry): ";
    std::cin >> ry;

    drawEllipse(xc, yc, rx, ry);

    return 0;
}