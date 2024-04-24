#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

std::vector<std::vector<double>> constructClockwiseRotationMatrix(double angle) {
    double radian = angle * M_PI / 180.0;
    double cosAngle = std::cos(radian);
    double sinAngle = std::sin(radian);

    std::vector<std::vector<double>> matrix = {
        {cosAngle, sinAngle, 0},
        {-sinAngle, cosAngle, 0},
        {0, 0, 1}
    };
    return matrix;
}

Point applyTransformation(const std::vector<std::vector<double>>& matrix, const Point& point) {
    Point result;
    result.x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2];
    result.y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2];
    return result;
}

int main() {
    // Define the points
    Point points[] = { {2, 3}, {5, 5}, {4, 3} };
    Point center = { 1, 1 };

    // Calculate the clockwise rotation matrix
    double angle = 45; // in degrees
    std::vector<std::vector<double>> clockwiseRotationMatrix = constructClockwiseRotationMatrix(angle);

    for (const auto& point : points) {
        Point rotatedPoint = applyTransformation(clockwiseRotationMatrix, { point.x - center.x, point.y - center.y });
        rotatedPoint.x += center.x;
        rotatedPoint.y += center.y;
        std::cout << "Clockwise Rotated point: (" << rotatedPoint.x << ", " << rotatedPoint.y << ")" << std::endl;
    }

    return 0;
}