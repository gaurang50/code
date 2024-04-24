#include <GL/glut.h>
#include <cmath>

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.3, 0.3);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();
}

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.3);
    glVertex2f(-0.3, -0.3);
    glVertex2f(0.3, -0.3);
    glEnd();
}

void drawPentagon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        float angle = 2 * 3.1415926f / 5 * i;
        glVertex2f(cosf(angle) * 0.3, sinf(angle) * 0.3);
    }
    glEnd();
}

void drawHexagon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float angle = 2 * 3.1415926f / 6 * i;
        glVertex2f(cosf(angle) * 0.3, sinf(angle) * 0.3);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw square
    glColor3f(1.0, 0.0, 0.0); // Red
    drawSquare();

    // Draw circle
    glColor3f(0.0, 1.0, 0.0); // Green
    glPushMatrix();
    glTranslatef(-0.7, 0.0, 0.0);
    drawCircle(0.3, 30);
    glPopMatrix();

    // Draw triangle
    glColor3f(0.0, 0.0, 1.0); // Blue
    glPushMatrix();
    glTranslatef(0.7, 0.0, 0.0);
    drawTriangle();
    glPopMatrix();

    // Draw pentagon
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glPushMatrix();
    glTranslatef(0.0, -0.7, 0.0);
    drawPentagon();
    glPopMatrix();

    // Draw hexagon
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glPushMatrix();
    glTranslatef(0.0, 0.7, 0.0);
    drawHexagon();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set viewing area dimensions
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Different Shapes in OpenGL"); // Create a window with the given title
    init(); // Initialize OpenGL
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main event loop
    return 0;
}