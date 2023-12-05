#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
struct Color
{
    int r;
    int g;
    int b;

    Color(int red, int green, int blue) : r(red), g(green), b(blue) {}
};

Color interpolateColor(Color color1, Color color2, float t) {
    int r = static_cast<int>((1 - t) * color1.r + t * color2.r);
    int g = static_cast<int>((1 - t) * color1.g + t * color2.g);
    int b = static_cast<int>((1 - t) * color1.b + t * color2.b);
    return Color(r, g, b);
}


void quad(float x1, float x2, float y1, float y2, Color color, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(s * x1 + Tx, s * y1 + Ty);
    glVertex2f(s * x2 + Tx, s * y1 + Ty);
    glVertex2f(s * x2 + Tx, s * y2 + Ty);
    glVertex2f(s * x1 + Tx, s * y2 + Ty);
    glEnd();
}
void circle(float x, float y, float radius, float height, Color color)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(color.r, color.g, color.b);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}
void quad(vector<pair<float, float>> coord, Color color = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}
void triangle(vector<pair<float, float>> coord, Color color = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}
void polygon(vector<pair<float, float>> coord, Color color = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

void First_Building(float x, float y, int m = 1, Color buildingWall = {67, 55, 189}, Color buildingWall2 = {110, 79, 196}, Color buildingWall3 = {15, 18, 76}, Color windowColor = {50, 100, 150}, Color windowColor2={53, 28, 117}, Color windowColor3={47, 50, 70}) {

    // Base
    for (int i = 0; i < 70; ++i) {
        Color interpolatedColor = interpolateColor(buildingWall, buildingWall2, static_cast<float>(i) / 70.0f);
        polygon({{x + m * i, y + 0}, {x + m * (i + 1), y + 0}, {x + m * (i + 1), y + 245}, {x + m * i, y + 245}}, interpolatedColor);
    }



    polygon({{x + m * 70, y + 0}, {x + m * 125, y + 0}, {x + m *125, y + 245}, {x + m * 70, y + 245}}, buildingWall3);

    // Shadowed Pillar
    polygon({{x + m * 5, y + 0}, {x + m * 20, y + 0}, {x + m * 20, y + 240}, {x + m * 5, y + 240}}, windowColor2);
    polygon({{x + m * 25, y + 0}, {x + m * 45, y + 0}, {x + m * 45, y + 240}, {x + m * 25, y + 240}}, windowColor2);
    polygon({{x + m * 50, y + 0}, {x + m * 70, y + 0}, {x + m * 70, y + 240}, {x + m * 50, y + 240}}, windowColor2);
    polygon({{x + m * 75, y + 0}, {x + m * 95, y + 0}, {x + m * 95, y + 240}, {x + m * 75, y + 240}}, windowColor3);
    polygon({{x + m * 100, y + 0}, {x + m * 120, y + 0}, {x + m * 120, y + 240}, {x + m * 100, y + 240}}, windowColor3);


    // Window First Row
    for (int i = 0; i < 16; ++i) {
        quad({{x + m * 10, y + i * 15}, {x + m * 20, y + i * 15}, {x + m * 20, y + i * 15 + 10}, {x + m * 10, y + i * 15 + 10}}, windowColor);
    }

    for (int i = 0; i < 16; ++i) {
        quad({{x + m * 35, y + i * 15}, {x + m * 45, y + i * 15}, {x + m * 45, y + i * 15 + 10}, {x + m * 35, y + i * 15 + 10}}, windowColor);
    }

    for (int i = 0; i < 16; ++i) {
        quad({{x + m * 60, y + i * 15}, {x + m * 70, y + i * 15}, {x + m * 70, y + i * 15 + 10}, {x + m * 60, y + i * 15 + 10}}, windowColor);
    }

    for (int i = 0; i < 16; ++i) {
        quad({{x + m * 85, y + i * 15}, {x + m * 95, y + i * 15}, {x + m * 95, y + i * 15 + 10}, {x + m * 85, y + i * 15 + 10}}, windowColor);
    }

    for (int i = 0; i < 16; ++i) {
        quad({{x + m * 110, y + i * 15}, {x + m * 120, y + i * 15}, {x + m * 120, y + i * 15 + 10}, {x + m * 110, y + i * 15 + 10}}, windowColor);
    }
}


void Fifth_Building(float x, float y, int m = 1, Color buildingWall = {130, 86, 199}, Color buildingWall2 = {32, 35, 76}){

    polygon({{x + m * 0, y + 0}, {x + m * 70, y + 0}, {x + m * 70, y + 495}, {x + m * 0, y + 495}}, buildingWall);
    polygon({{x + m * 70, y + 0}, {x + m * 130, y + 0}, {x + m * 130, y + 495}, {x + m * 70, y + 495}}, buildingWall2);

    // Bottom Window
    polygon({{x + m * 5, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 10}, {x + m * 5, y + 10}}, {46, 21, 87});

    // Second Window
    polygon({{x + m * 5, y + 20}, {x + m * 65, y + 20}, {x + m * 65, y + 40}, {x + m * 5, y + 40}}, {38, 46, 127});
    polygon({{x + m * 5, y + 40}, {x + m * 65, y + 40}, {x + m * 65, y + 50}, {x + m * 5, y + 50}}, {47, 25, 89});

    // Third Window
    polygon({{x + m * 5, y + 60}, {x + m * 65, y + 60}, {x + m * 65, y + 80}, {x + m * 5, y + 80}}, {41, 221, 132});
    polygon({{x + m * 5, y + 80}, {x + m * 65, y + 80}, {x + m * 65, y + 90}, {x + m * 5, y + 90}}, {32, 130, 81});

    // Forth Window
    polygon({{x + m * 5, y + 100}, {x + m * 65, y + 100}, {x + m * 65, y + 120}, {x + m * 5, y + 120}}, {43, 71, 136});
    polygon({{x + m * 5, y + 120}, {x + m * 65, y + 120}, {x + m * 65, y + 130}, {x + m * 5, y + 130}}, {61, 56, 130});

    // Fifth Window
    polygon({{x + m * 5, y + 140}, {x + m * 65, y + 140}, {x + m * 65, y + 160}, {x + m * 5, y + 160}}, {43, 221, 207});
    polygon({{x + m * 5, y + 160}, {x + m * 65, y + 160}, {x + m * 65, y + 170}, {x + m * 5, y + 170}}, {34, 165, 146});

    // Sixth Window
    polygon({{x + m * 5, y + 180}, {x + m * 65, y + 180}, {x + m * 65, y + 200}, {x + m * 5, y + 200}}, {45, 87, 135});
    polygon({{x + m * 5, y + 200}, {x + m * 65, y + 200}, {x + m * 65, y + 210}, {x + m * 5, y + 210}}, {32, 62, 97});

    // Seventh Window
    polygon({{x + m * 5, y + 220}, {x + m * 65, y + 220}, {x + m * 65, y + 240}, {x + m * 5, y + 240}}, {102, 255, 147});
    polygon({{x + m * 5, y + 240}, {x + m * 65, y + 240}, {x + m * 65, y + 250}, {x + m * 5, y + 250}}, {67, 164, 97});

    // Eigth Window
    polygon({{x + m * 5, y + 260}, {x + m * 65, y + 260}, {x + m * 65, y + 290}, {x + m * 5, y + 290}}, {51, 87, 145});

     // Ninth Window
    polygon({{x + m * 5, y + 300}, {x + m * 65, y + 300}, {x + m * 65, y + 320}, {x + m * 5, y + 320}}, {38, 46, 127});
    polygon({{x + m * 5, y + 320}, {x + m * 65, y + 320}, {x + m * 65, y + 330}, {x + m * 5, y + 330}}, {47, 25, 89});

    // Tenth Window
    polygon({{x + m * 5, y + 340}, {x + m * 65, y + 340}, {x + m * 65, y + 360}, {x + m * 5, y + 360}}, {43, 221, 207});
    polygon({{x + m * 5, y + 360}, {x + m * 65, y + 360}, {x + m * 65, y + 370}, {x + m * 5, y + 370}}, {34, 165, 146});

    // Eleventh Window
    polygon({{x + m * 5, y + 380}, {x + m * 65, y + 380}, {x + m * 65, y + 400}, {x + m * 5, y + 400}}, {41, 221, 132});
    polygon({{x + m * 5, y + 400}, {x + m * 65, y + 400}, {x + m * 65, y + 410}, {x + m * 5, y + 410}}, {32, 130, 81});

    // Twelfth Window
    polygon({{x + m * 5, y + 420}, {x + m * 65, y + 420}, {x + m * 65, y + 440}, {x + m * 5, y + 440}}, {43, 71, 136});
    polygon({{x + m * 5, y + 440}, {x + m * 65, y + 440}, {x + m * 65, y + 450}, {x + m * 5, y + 450}}, {61, 56, 130});

    // Thirteenth Window
    polygon({{x + m * 5, y + 460}, {x + m * 65, y + 460}, {x + m * 65, y + 480}, {x + m * 5, y + 480}}, {102, 255, 147});
    polygon({{x + m * 5, y + 480}, {x + m * 65, y + 480}, {x + m * 65, y + 490}, {x + m * 5, y + 490}}, {67, 164, 97});
}

void display()
{
    //sky
    glBegin(GL_QUADS);
    glColor3ub(114, 77, 201);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glColor3ub(15, 3, 43);
    glVertex2f(1920, 1080);
    glVertex2f(0, 1080);
    glEnd();

    // First Building
    First_Building(0, 0);
    polygon({{0, 245}, {0, 250}, {115,250}, {115, 245}}, {0, 0, 0});
    First_Building(0, 250);

    // Fifth Building
    Fifth_Building(300, 0);


    // Thirteenth Building
    First_Building(1500, 0);
    polygon({{1500, 245}, {1500, 250}, {1615,250}, {1615, 245}}, {0, 0, 0});
    First_Building(1500, 250);




    glFlush();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.0F, 0.0F, 0.0F, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1920, 0, 1080, -100, 100);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Virtual City");
    glutFullScreen();
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
