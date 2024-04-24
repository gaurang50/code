#include <iostream>
#include <graphics.h>

void drawMidpointCircle(int x_center, int y_center, int radius) {
    int x = radius;
    int y = 0;
    int err = 0; //err is decision parameter

    while (x >= y) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);

        if (err <= 0) {
            y += 1; 
            err += 2*y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }

        delay(100);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_center, y_center, radius;

    std::cout << "Enter the center coordinates (x y): ";
    std::cin >> x_center >> y_center;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    drawMidpointCircle(x_center, y_center, radius);

    closegraph();
    return 0;
}