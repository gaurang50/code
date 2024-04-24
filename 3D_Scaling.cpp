#include <iostream>

using namespace std;

// Define a 3D point
struct Point {
    double x, y, z;
};

// Function to perform scaling
void scale(Point& p, double sx, double sy, double sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

int main() {
    // Define a point
    Point p = { 1, 2, 3 };

    // Scaling factors
    double sx = 2, sy = 0.5, sz = 3;

    // Perform scaling
    scale(p, sx, sy, sz);

    // Print the scaled point
    cout << "Scaled Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    return 0;
}