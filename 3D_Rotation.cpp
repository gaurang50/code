#include <iostream>
#include <cmath>

using namespace std;

// Define a 3D point
struct Point {
    double x, y, z;
};

// Function to perform rotation about the z-axis
void rotateZ(Point& p, double theta) {
    double newX = p.x * cos(theta) - p.y * sin(theta);
    double newY = p.x * sin(theta) + p.y * cos(theta);
    p.x = newX;
    p.y = newY;
}

int main() {
    // Define a point
    Point p = { 1, 2, 3 };

    // Rotation angle (in radians)
    double theta = M_PI / 4;  // 45 degrees

    // Perform rotation
    rotateZ(p, theta);

    // Print the rotated point
    cout << "Rotated Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    return 0;
}