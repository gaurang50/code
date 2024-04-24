#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a structure to represent a point
struct Point {
    double x;
    double y;
};

// Function to calculate the center of the square
Point calculateCenter(const vector<Point>& square) {
    Point center;
    center.x = (square[0].x + square[1].x + square[2].x + square[3].x) / 4.0;
    center.y = (square[0].y + square[1].y + square[2].y + square[3].y) / 4.0;
    return center;
}

// Function to construct the scaling transformation matrix
vector<vector<double>> constructScalingMatrix(double Sx, double Sy) {
    vector<vector<double>> matrix = {
        {Sx, 0, 0},
        {0, Sy, 0},
        {0, 0, 1}
    };
    return matrix;
}

// Function to apply transformation matrix to a point
Point applyTransformation(const vector<vector<double>>& matrix, const Point& point) {
    Point result;
    result.x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2];
    result.y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2];
    return result;
}

int main() {
    // Define the square
    vector<Point> square = { {1, 1}, {3, 1}, {3, 3}, {1, 3} };

    // Calculate the center of the square
    Point center = calculateCenter(square);

    // Calculate the scaling factors
    double Sx = 0.5, Sy = 0.5;

    // Construct the scaling transformation matrix
    vector<vector<double>> scalingMatrix = constructScalingMatrix(Sx, Sy);

    // Apply the scaling transformation matrix to each corner of the square
    vector<Point> scaledSquare;
    for (const auto& point : square) {
        Point translatedPoint = { point.x - center.x, point.y - center.y };
        Point scaledPoint = applyTransformation(scalingMatrix, translatedPoint);
        scaledPoint.x += center.x;
        scaledPoint.y += center.y;
        scaledSquare.push_back(scaledPoint);
    }

    // Print the coordinates of the scaled square
    cout << "Coordinates of the scaled square:" << endl;
    for (int i = 0; i < scaledSquare.size(); ++i) {
        cout << "Point " << i + 1 << ": (" << scaledSquare[i].x << ", " << scaledSquare[i].y << ")" << endl;
    }

    return 0;
}