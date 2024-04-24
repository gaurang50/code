#include <iostream>
#include <graphics.h>

void drawBresenhamCircle(int x_center, int y_center, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    //d is the decision parameter

    while (x <= y) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);

        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;

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

    drawBresenhamCircle(x_center, y_center, radius);
    delay(10000);

    getch();
    closegraph();
    return 0;
}