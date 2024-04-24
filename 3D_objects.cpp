#include <GL/glut.h>

const int screenWidth = 800;
const int screenHeight = 600;

void drawCube(float size) {
    glutWireCube(size * 1.25);
}

void drawSphere(float radius) {
    glutWireSphere(radius * 1.25, 10, 10);
}

void drawCone(float baseRadius, float height) {
    glutWireCone(baseRadius * 1.25, height * 1.25, 10, 10);
}

void drawTorus(float innerRadius, float outerRadius) {
    glutWireTorus(innerRadius * 1.25, outerRadius * 1.25, 10, 10);
}

void drawCylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_LINE); // Wireframe
    // Increased baseRadius, topRadius, and height by 25%
    gluCylinder(quad, baseRadius * 1.25, topRadius * 1.25, height * 1.25, 12, 2);
    gluDeleteQuadric(quad);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0,  // Eye position
        0.0, 0.0, 0.0,  // Center position
        0.0, 1.0, 0.0); // Up vector



    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glPushMatrix();
    glTranslatef(-2.5f, 0.0f, 0.0f);
    drawCube(0.5);
    glPopMatrix();


    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glPushMatrix();
    glTranslatef(-0.75f, 0.0f, 0.0f);
    drawSphere(0.25);
    glPopMatrix();


    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glPushMatrix();
    glTranslatef(1.25f, 0.0f, 0.0f);
    drawCone(0.25, 0.5);
    glPopMatrix();


    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glPushMatrix();
    glTranslatef(3.0f, 0.0f, 0.0f);
    drawTorus(0.1, 0.25);
    glPopMatrix();


    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glPushMatrix();
    glTranslatef(0.0f, -1.25f, 0.0f);
    drawCylinder(0.25, 0.25, 0.5);
    glPopMatrix();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("3D Shapes Example");

    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}