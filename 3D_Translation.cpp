#include <iostream>

using namespace std;

// Define a 3D point
struct Point {
    double x, y, z;
};

// Function to perform translation
void translate(Point& p, double dx, double dy, double dz) {
    p.x += dx;
    p.y += dy;
    p.z += dz;
}

int main() {
    // Define a point
    Point p = { 1, 2, 3 };

    // Translation amounts
    double dx = 2, dy = -1, dz = 3;

    // Perform translation
    translate(p, dx, dy, dz);

    // Print the translated point
    cout << "Translated Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    return 0;
}