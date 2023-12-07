#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
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


void Second_Building(float x, float y, int m = 1){
    // Base
    polygon({{x + m * 0, y + 0}, {x + m * 70, y + 0}, {x + m * 70, y + 10}, {x + m * 0, y + 10}}, {49, 33, 196});
    polygon({{x + m * 70, y + 0}, {x + m * 140, y + 0}, {x + m * 140, y + 10}, {x + m * 70, y + 10}}, {29, 1, 50});

    //First Floor

    polygon({{x + m * 0, y + 10}, {x + m * 70, y + 10}, {x + m * 70, y + 20}, {x + m * 0, y + 20}}, {22, 37, 128});
    polygon({{x + m * 0, y + 20}, {x + m * 70, y + 20}, {x + m * 70, y + 30}, {x + m * 0, y + 30}}, {33, 25, 108});

    polygon({{x + m * 70, y + 10}, {x + m * 140, y + 10}, {x + m * 140, y + 20}, {x + m * 70, y + 20}}, {49, 0, 49});
    polygon({{x + m * 70, y + 20}, {x + m * 140, y + 20}, {x + m * 140, y + 30}, {x + m * 70, y + 30}}, {41, 0, 54});

    // Windows
    polygon({{x + m * 10, y + 10}, {x + m * 20, y + 10}, {x + m * 20, y + 25}, {x + m * 10, y + 25}}, {5, 67, 157});
    polygon({{x + m * 30, y + 10}, {x + m * 40, y + 10}, {x + m * 40, y + 25}, {x + m * 30, y + 25}}, {34, 203, 197});
    polygon({{x + m * 50, y + 10}, {x + m * 60, y + 10}, {x + m * 60, y + 25}, {x + m * 50, y + 25}}, {5, 67, 157});

    polygon({{x + m * 80, y + 10}, {x + m * 90, y + 10}, {x + m * 90, y + 25}, {x + m * 80, y + 25}}, {29, 18, 90});
    polygon({{x + m * 100, y + 10}, {x + m * 110, y + 10}, {x + m * 110, y + 25}, {x + m * 100, y + 25}}, {29, 18, 90});
    polygon({{x + m * 120, y + 10}, {x + m * 130, y + 10}, {x + m * 130, y + 25}, {x + m * 120, y + 25}}, {29, 18, 90});

    //Second Floor
    polygon({{x + m * 0, y + 30}, {x + m * 70, y + 30}, {x + m * 70, y + 40}, {x + m * 0, y + 40}}, {48, 38, 193});
    polygon({{x + m * 70, y + 30}, {x + m * 140, y + 30}, {x + m * 140, y + 40}, {x + m * 70, y + 40}}, {36, 0, 51});

    polygon({{x + m * 0, y + 40}, {x + m * 70, y + 40}, {x + m * 70, y + 50}, {x + m * 0, y + 50}}, {22, 37, 128});
    polygon({{x + m * 0, y + 50}, {x + m * 70, y + 50}, {x + m * 70, y + 60}, {x + m * 0, y + 60}}, {33, 25, 108});

    polygon({{x + m * 70, y + 40}, {x + m * 140, y + 40}, {x + m * 140, y + 50}, {x + m * 70, y + 50}}, {49, 0, 49});
    polygon({{x + m * 70, y + 50}, {x + m * 140, y + 50}, {x + m * 140, y + 60}, {x + m * 70, y + 60}}, {41, 0, 54});

    //polygon({{x + m * 70, y + 10}, {x + m * 140, y + 10}, {x + m * 140, y + 20}, {x + m * 70, y + 20}}, {0, 0, 0});
    //polygon({{x + m * 70, y + 20}, {x + m * 140, y + 20}, {x + m * 140, y + 30}, {x + m * 70, y + 30}}, {255, 255, 255});

    // Windows
    polygon({{x + m * 10, y + 40}, {x + m * 20, y + 40}, {x + m * 20, y + 55}, {x + m * 10, y + 55}}, {5, 67, 157});
    polygon({{x + m * 30, y + 40}, {x + m * 40, y + 40}, {x + m * 40, y + 55}, {x + m * 30, y + 55}}, {34, 203, 197});
    polygon({{x + m * 50, y + 40}, {x + m * 60, y + 40}, {x + m * 60, y + 55}, {x + m * 50, y + 55}}, {39, 80, 92});

    polygon({{x + m * 80, y + 40}, {x + m * 90, y + 40}, {x + m * 90, y + 55}, {x + m * 80, y + 55}}, {39, 80, 92});
    polygon({{x + m * 100, y + 40}, {x + m * 110, y + 40}, {x + m * 110, y + 55}, {x + m * 100, y + 55}}, {39, 80, 92});
    polygon({{x + m * 120, y + 40}, {x + m * 130, y + 40}, {x + m * 130, y + 55}, {x + m * 120, y + 55}}, {5, 67, 157});

    // Third Floor
    polygon({{x + m * 0, y + 60}, {x + m * 70, y + 60}, {x + m * 70, y + 70}, {x + m * 0, y + 70}}, {48, 38, 193});
    polygon({{x + m * 70, y + 60}, {x + m * 140, y + 60}, {x + m * 140, y + 70}, {x + m * 70, y + 70}}, {27, 2, 50});

    polygon({{x + m * 0, y + 70}, {x + m * 70, y + 70}, {x + m * 70, y + 80}, {x + m * 0, y + 80}}, {22, 37, 128});
    polygon({{x + m * 0, y + 80}, {x + m * 70, y + 80}, {x + m * 70, y + 90}, {x + m * 0, y + 90}}, {33, 25, 108});

    polygon({{x + m * 70, y + 70}, {x + m * 140, y + 70}, {x + m * 140, y + 80}, {x + m * 70, y + 80}}, {49, 0, 49});
    polygon({{x + m * 70, y + 80}, {x + m * 140, y + 80}, {x + m * 140, y + 90}, {x + m * 70, y + 90}}, {41, 0, 54});

    // Windows
    polygon({{x + m * 10, y + 70}, {x + m * 20, y + 70}, {x + m * 20, y + 85}, {x + m * 10, y + 85}}, {5, 67, 157});
    polygon({{x + m * 30, y + 70}, {x + m * 40, y + 70}, {x + m * 40, y + 85}, {x + m * 30, y + 85}}, {34, 203, 197});
    polygon({{x + m * 50, y + 70}, {x + m * 60, y + 70}, {x + m * 60, y + 85}, {x + m * 50, y + 85}}, {5, 67, 157});

    polygon({{x + m * 80, y + 70}, {x + m * 90, y + 70}, {x + m * 90, y + 85}, {x + m * 80, y + 85}}, {34, 203, 197});
    polygon({{x + m * 100, y + 70}, {x + m * 110, y + 70}, {x + m * 110, y + 85}, {x + m * 100, y + 85}}, {25, 67, 157});
    polygon({{x + m * 120, y + 70}, {x + m * 130, y + 70}, {x + m * 130, y + 85}, {x + m * 120, y + 85}}, {5, 67, 157});

    // Middle Portion
    polygon({{x + m * 0, y + 90}, {x + m * 70, y + 90}, {x + m * 70, y + 100}, {x + m * 0, y + 100}}, {77, 50, 202});
    polygon({{x + m * 70, y + 90}, {x + m * 140, y + 90}, {x + m * 140, y + 100}, {x + m *70, y + 100}}, {43, 17, 78});

    polygon({{x + m * 0, y + 100}, {x + m * 140, y + 100}, {x + m * 140, y + 110}, {x + m * 0, y + 110}}, {27, 2, 50});

    polygon({{x + m * 0, y + 110}, {x + m * 70, y + 110}, {x + m * 70, y + 125}, {x + m * 0, y + 125}}, {77, 50, 202});
    polygon({{x + m * 70, y + 110}, {x + m * 140, y + 110}, {x + m * 140, y + 125}, {x + m * 70, y + 125}}, {43, 17, 78});

    // Fourth Floor

    polygon({{x + m * 0, y + 125}, {x + m * 70, y + 125}, {x + m * 70, y + 135}, {x + m * 0, y + 135}}, {29, 53, 142});
    polygon({{x + m * 0, y + 135}, {x + m * 70, y + 135}, {x + m * 70, y + 145}, {x + m * 0, y + 145}}, {40, 24, 106});

    polygon({{x + m * 70, y + 125}, {x + m * 140, y + 125}, {x + m * 140, y + 145}, {x + m * 70, y + 145}}, {33, 11, 58});

    // Windows
    polygon({{x + m * 10, y + 125}, {x + m * 20, y + 125}, {x + m * 20, y + 140}, {x + m * 10, y + 140}}, {5, 67, 157});
    polygon({{x + m * 30, y + 125}, {x + m * 40, y + 125}, {x + m * 40, y + 140}, {x + m * 30, y + 140}}, {34, 203, 197});
    polygon({{x + m * 50, y + 125}, {x + m * 60, y + 125}, {x + m * 60, y + 140}, {x + m * 50, y + 140}}, {5, 67, 157});

    polygon({{x + m * 80, y + 125}, {x + m * 90, y + 125}, {x + m * 90, y + 140}, {x + m * 80, y + 140}}, {5, 67, 157});
    polygon({{x + m * 100, y + 125}, {x + m * 110, y + 125}, {x + m * 110, y + 140}, {x + m * 100, y + 140}}, {5, 67, 157});
    polygon({{x + m * 120, y + 125}, {x + m * 130, y + 125}, {x + m * 130, y + 140}, {x + m * 120, y + 140}}, {5, 67, 157});

    // Fifth Floor
    polygon({{x + m * 0, y + 145}, {x + m * 70, y + 145}, {x + m * 70, y + 155}, {x + m * 0, y + 155}}, {36, 50, 127});
    polygon({{x + m * 70, y + 145}, {x + m * 140, y + 145}, {x + m * 140, y + 155}, {x + m * 70, y + 155}}, {40, 24, 106});

    polygon({{x + m * 0, y + 155}, {x + m * 70, y + 155}, {x + m * 70, y + 165}, {x + m * 0, y + 165}}, {29, 53, 142});
    polygon({{x + m * 0, y + 165}, {x + m * 70, y + 165}, {x + m * 70, y + 175}, {x + m * 0, y + 175}}, {40, 24, 106});

    polygon({{x + m * 70, y + 155}, {x + m * 140, y + 155}, {x + m * 140, y + 175}, {x + m * 70, y + 175}}, {33, 11, 58});

    // Windows
    polygon({{x + m * 10, y + 155}, {x + m * 20, y + 155}, {x + m * 20, y + 170}, {x + m * 10, y + 170}}, {34, 203, 197});
    polygon({{x + m * 30, y + 155}, {x + m * 40, y + 155}, {x + m * 40, y + 170}, {x + m * 30, y + 170}}, {34, 203, 197});
    polygon({{x + m * 50, y + 155}, {x + m * 60, y + 155}, {x + m * 60, y + 170}, {x + m * 50, y + 170}}, {51, 111, 188});

    polygon({{x + m * 80, y + 155}, {x + m * 90, y + 155}, {x + m * 90, y + 170}, {x + m * 80, y + 170}}, {5, 67, 157});
    polygon({{x + m * 100, y + 155}, {x + m * 110, y + 155}, {x + m * 110, y + 170}, {x + m * 100, y + 170}}, {5, 67, 157});
    polygon({{x + m * 120, y + 155}, {x + m * 130, y + 155}, {x + m * 130, y + 170}, {x + m * 120, y + 170}}, {5, 67, 157});

    // Sixth Floor
    polygon({{x + m * 0, y + 175}, {x + m * 70, y + 175}, {x + m * 70, y + 185}, {x + m * 0, y + 185}}, {36, 50, 127});
    polygon({{x + m * 70, y + 175}, {x + m * 140, y + 175}, {x + m * 140, y + 185}, {x + m * 70, y + 185}}, {40, 24, 106});

    polygon({{x + m * 0, y + 185}, {x + m * 70, y + 185}, {x + m * 70, y + 195}, {x + m * 0, y + 195}}, {29, 53, 142});
    polygon({{x + m * 0, y + 195}, {x + m * 70, y + 195}, {x + m * 70, y + 205}, {x + m * 0, y + 205}}, {40, 24, 106});

    polygon({{x + m * 70, y + 185}, {x + m * 140, y + 185}, {x + m * 140, y + 205}, {x + m * 70, y + 205}}, {33, 11, 58});

    // Windows
    polygon({{x + m * 10, y + 185}, {x + m * 20, y + 185}, {x + m * 20, y + 200}, {x + m * 10, y + 200}}, {34, 203, 197});
    polygon({{x + m * 30, y + 185}, {x + m * 40, y + 185}, {x + m * 40, y + 200}, {x + m * 30, y + 200}}, {34, 203, 197});
    polygon({{x + m * 50, y + 185}, {x + m * 60, y + 185}, {x + m * 60, y + 200}, {x + m * 50, y + 200}}, {51, 111, 188});

    polygon({{x + m * 80, y + 185}, {x + m * 90, y + 185}, {x + m * 90, y + 200}, {x + m * 80, y + 200}}, {51, 111, 188});
    polygon({{x + m * 100, y + 185}, {x + m * 110, y + 185}, {x + m * 110, y + 200}, {x + m * 100, y + 200}}, {51, 111, 188});
    polygon({{x + m * 120, y + 185}, {x + m * 130, y + 185}, {x + m * 130, y + 200}, {x + m * 120, y + 200}}, {51, 111, 188});

    // Terrace
    polygon({{x + m * 0, y + 205}, {x + m * 70, y + 205}, {x + m * 70, y + 220}, {x + m * 0, y + 220}}, {123, 82, 198});
    polygon({{x + m * 70, y + 205}, {x + m * 140, y + 205}, {x + m * 140, y + 220}, {x + m * 70, y + 220}}, {16, 40, 59});
}


void Tomb(float x, float y, int m = 1, Color buildingWall = {132, 82, 211}, Color buildingWall2 = {33, 43, 80}, Color shadow = {56, 99, 164}, Color shadow2 = {16, 41, 83} , Color LeftWindow = {40, 82, 149}, Color RightWIndow = {9, 36, 78}){
    polygon({{x + m * 0, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 8}, {x + m * 0, y + 8}}, buildingWall);
    polygon({{x + m * 40, y + 0}, {x + m * 80, y + 0}, {x + m * 80, y + 8}, {x + m * 40, y + 8}}, buildingWall2);

    polygon({{x + m * 5, y + 8}, {x + m * 40, y + 8}, {x + m * 40, y + 16}, {x + m * 5, y + 16}}, shadow);
    polygon({{x + m * 40, y + 8}, {x + m * 75, y + 8}, {x + m * 75, y + 16}, {x + m * 40, y + 16}}, shadow2);

    // First Floor Left Window
    polygon({{x + m * 10, y + 8}, {x + m * 15, y + 8}, {x + m * 15, y + 14}, {x + m * 10, y + 14}}, LeftWindow);
    polygon({{x + m * 25, y + 8}, {x + m * 30, y + 8}, {x + m * 30, y + 14}, {x + m * 25, y + 14}}, LeftWindow);

    // First Floor Right Window
    polygon({{x + m * 50, y + 8}, {x + m * 55, y + 8}, {x + m * 55, y + 14}, {x + m * 50, y + 14}}, RightWIndow);
    polygon({{x + m * 65, y + 8}, {x + m * 70, y + 8}, {x + m * 70, y + 14}, {x + m * 65, y + 14}}, RightWIndow);

    polygon({{x + m * 0, y + 16}, {x + m * 40, y + 16}, {x + m * 40, y + 24}, {x + m * 0, y + 24}}, buildingWall);
    polygon({{x + m * 40, y + 16}, {x + m * 80, y + 16}, {x + m * 80, y + 24}, {x + m * 40, y + 24}}, buildingWall2);

    polygon({{x + m * 5, y + 24}, {x + m * 40, y + 24}, {x + m * 40, y + 32}, {x + m * 5, y + 32}}, shadow);
    polygon({{x + m * 40, y + 24}, {x + m * 75, y + 24}, {x + m * 75, y + 32}, {x + m * 40, y + 32}}, shadow2);

    // Second Floor Left Window
    polygon({{x + m * 10, y + 24}, {x + m * 15, y + 24}, {x + m * 15, y + 30}, {x + m * 10, y + 30}}, LeftWindow);
    polygon({{x + m * 25, y + 24}, {x + m * 30, y + 24}, {x + m * 30, y + 30}, {x + m * 25, y + 30}}, LeftWindow);

    // Third Floor Right Window
    polygon({{x + m * 50, y + 24}, {x + m * 55, y + 24}, {x + m * 55, y + 30}, {x + m * 50, y + 30}}, RightWIndow);
    polygon({{x + m * 65, y + 24}, {x + m * 70, y + 24}, {x + m * 70, y + 30}, {x + m * 65, y + 30}}, RightWIndow);

    polygon({{x + m * 0, y + 32}, {x + m * 40, y + 32}, {x + m * 40, y + 40}, {x + m * 0, y + 40}}, buildingWall);
    polygon({{x + m * 40, y + 32}, {x + m * 80, y + 32}, {x + m * 80, y + 40}, {x + m * 40, y + 40}}, buildingWall2);

    polygon({{x + m * 5, y + 40}, {x + m * 40, y + 40}, {x + m * 40, y + 48}, {x + m * 5, y + 48}}, shadow);
    polygon({{x + m * 40, y + 40}, {x + m * 75, y + 40}, {x + m * 75, y + 48}, {x + m * 40, y + 48}}, shadow2);

    // Third Floor Left Window
    polygon({{x + m * 10, y + 40}, {x + m * 15, y + 40}, {x + m * 15, y + 46}, {x + m * 10, y + 46}}, LeftWindow);
    polygon({{x + m * 25, y + 40}, {x + m * 30, y + 40}, {x + m * 30, y + 46}, {x + m * 25, y + 46}}, LeftWindow);

    // Third Floor Right Window
    polygon({{x + m * 50, y + 40}, {x + m * 55, y + 40}, {x + m * 55, y + 46}, {x + m * 50, y + 46}}, RightWIndow);
    polygon({{x + m * 65, y + 40}, {x + m * 70, y + 40}, {x + m * 70, y + 46}, {x + m * 65, y + 46}}, RightWIndow);

    polygon({{x + m * 0, y + 48}, {x + m * 40, y + 48}, {x + m * 40, y + 56}, {x + m * 0, y + 56}}, buildingWall);
    polygon({{x + m * 40, y + 48}, {x + m * 80, y + 48}, {x + m * 80, y + 56}, {x + m * 40, y + 56}}, buildingWall2);

    polygon({{x + m * 5, y + 56}, {x + m * 40, y + 56}, {x + m * 40, y + 64}, {x + m * 5, y + 64}}, shadow);
    polygon({{x + m * 40, y + 56}, {x + m * 75, y + 56}, {x + m * 75, y + 64}, {x + m * 40, y + 64}}, shadow2);

    // Fourth Floor Left Window
    polygon({{x + m * 10, y + 56}, {x + m * 15, y + 56}, {x + m * 15, y + 62}, {x + m * 10, y + 62}}, LeftWindow);
    polygon({{x + m * 25, y + 56}, {x + m * 30, y + 56}, {x + m * 30, y + 62}, {x + m * 25, y + 62}}, LeftWindow);

    // Fourth Floor Right Window
    polygon({{x + m * 50, y + 56}, {x + m * 55, y + 56}, {x + m * 55, y + 62}, {x + m * 50, y + 62}}, RightWIndow);
    polygon({{x + m * 65, y + 56}, {x + m * 70, y + 56}, {x + m * 70, y + 62}, {x + m * 65, y + 62}}, RightWIndow);

    polygon({{x + m * 0, y + 64}, {x + m * 40, y + 64}, {x + m * 40, y + 72}, {x + m * 0, y + 72}}, buildingWall);
    polygon({{x + m * 40, y + 64}, {x + m * 80, y + 64}, {x + m * 80, y + 72}, {x + m * 40, y + 72}}, buildingWall2);

    polygon({{x + m * 5, y + 72}, {x + m * 40, y + 72}, {x + m * 40, y + 80}, {x + m * 5, y + 80}}, shadow);
    polygon({{x + m * 40, y + 72}, {x + m * 75, y + 72}, {x + m * 75, y + 80}, {x + m * 40, y + 80}}, shadow2);

    // Top Layer

    polygon({{x + m * 10, y + 80}, {x + m * 40, y + 80}, {x + m * 40, y + 85}, {x + m * 10, y + 85}}, {155, 204, 239});
    polygon({{x + m * 40, y + 80}, {x + m * 75, y + 80}, {x + m * 75, y + 85}, {x + m * 40, y + 85}}, {122, 165, 198});
}

void Third_Building(float x, float y, int m = 1){

    // Bottom Portion
    // Left Portion
    polygon({{x + m * 0, y + 0}, {x + m * 15, y + 0}, {x + m * 15, y + 245}, {x + m * 0, y + 245}}, {33, 72, 136});

    // Window Column One
    polygon({{x + m * 5, y + 0}, {x + m * 15, y + 0}, {x + m * 15, y + 10}, {x + m * 5, y + 10}}, {41, 94, 135});

    polygon({{x + m * 5, y + 20}, {x + m * 15, y + 20}, {x + m * 15, y + 30}, {x + m * 5, y + 30}}, {34, 203, 197});
    polygon({{x + m * 5, y + 30}, {x + m * 15, y + 30}, {x + m * 15, y + 40}, {x + m * 5, y + 40}}, {41, 94, 135});

    polygon({{x + m * 5, y + 50}, {x + m * 15, y + 50}, {x + m * 15, y + 60}, {x + m * 5, y + 60}}, {34, 203, 197});
    polygon({{x + m * 5, y + 60}, {x + m * 15, y + 60}, {x + m * 15, y + 70}, {x + m * 5, y + 70}}, {41, 94, 135});

    polygon({{x + m * 5, y + 80}, {x + m * 15, y + 80}, {x + m * 15, y + 100}, {x + m * 5, y + 100}}, {28, 0, 149});

    polygon({{x + m * 5, y + 110}, {x + m * 15, y + 110}, {x + m * 15, y + 130}, {x + m * 5, y + 130}}, {28, 0, 149});

    polygon({{x + m * 5, y + 140}, {x + m * 15, y + 140}, {x + m * 15, y + 160}, {x + m * 5, y + 160}}, {28, 0, 149});

    polygon({{x + m * 5, y + 170}, {x + m * 15, y + 170}, {x + m * 15, y + 180}, {x + m * 5, y + 180}}, {34, 203, 197});
    polygon({{x + m * 5, y + 180}, {x + m * 15, y + 180}, {x + m * 15, y + 190}, {x + m * 5, y + 190}}, {41, 94, 135});

    polygon({{x + m * 5, y + 200}, {x + m * 15, y + 200}, {x + m * 15, y + 220}, {x + m * 5, y + 220}}, {28, 0, 149});

    polygon({{x + m * 5, y + 230}, {x + m * 15, y + 230}, {x + m * 15, y + 250}, {x + m * 5, y + 250}}, {28, 0, 149});

    // Pillar One
    polygon({{x + m * 15, y + 0}, {x + m * 25, y + 0}, {x + m * 25, y + 245}, {x + m * 15, y + 245}}, {135, 82, 214});

    polygon({{x + m * 25, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 245}, {x + m * 25, y + 245}}, {33, 72, 136});

    // Window Column Two
    polygon({{x + m * 30, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 10}, {x + m * 30, y + 10}}, {28, 0, 149});

    polygon({{x + m * 30, y + 20}, {x + m * 40, y + 20}, {x + m * 40, y + 30}, {x + m * 30, y + 30}}, {34, 203, 197});
    polygon({{x + m * 30, y + 30}, {x + m * 40, y + 30}, {x + m * 40, y + 40}, {x + m * 30, y + 40}}, {41, 94, 135});

    polygon({{x + m * 30, y + 50}, {x + m * 40, y + 50}, {x + m * 40, y + 60}, {x + m * 30, y + 60}}, {34, 203, 197});
    polygon({{x + m * 30, y + 60}, {x + m * 40, y + 60}, {x + m * 40, y + 70}, {x + m * 30, y + 70}}, {41, 94, 135});

    polygon({{x + m * 30, y + 80}, {x + m * 40, y + 80}, {x + m * 40, y + 100}, {x + m * 30, y + 100}}, {28, 0, 149});

    polygon({{x + m * 30, y + 110}, {x + m * 40, y + 110}, {x + m * 40, y + 130}, {x + m * 30, y + 130}}, {28, 0, 149});

    polygon({{x + m * 30, y + 140}, {x + m * 40, y + 140}, {x + m * 40, y + 160}, {x + m * 30, y + 160}}, {28, 0, 149});

    polygon({{x + m * 30, y + 170}, {x + m * 40, y + 170}, {x + m * 40, y + 180}, {x + m * 30, y + 180}}, {34, 203, 197});
    polygon({{x + m * 30, y + 180}, {x + m * 40, y + 180}, {x + m * 40, y + 190}, {x + m * 30, y + 190}}, {41, 94, 135});

    polygon({{x + m * 30, y + 200}, {x + m * 40, y + 200}, {x + m * 40, y + 220}, {x + m * 30, y + 220}}, {28, 0, 149});

    polygon({{x + m * 30, y + 230}, {x + m * 40, y + 230}, {x + m * 40, y + 250}, {x + m * 30, y + 250}}, {28, 0, 149});

    // Pillar Two
    polygon({{x + m * 40, y + 0}, {x + m * 50, y + 0}, {x + m * 50, y + 245}, {x + m * 40, y + 245}}, {135, 82, 214});

    polygon({{x + m * 50, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 245}, {x + m * 50, y + 245}}, {33, 72, 136});

    // Window Column Three
    polygon({{x + m * 55, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 10}, {x + m * 55, y + 10}}, {28, 0, 149});

    polygon({{x + m * 55, y + 20}, {x + m * 65, y + 20}, {x + m * 65, y + 30}, {x + m * 55, y + 30}}, {34, 203, 197});
    polygon({{x + m * 55, y + 30}, {x + m * 65, y + 30}, {x + m * 65, y + 40}, {x + m * 55, y + 40}}, {41, 94, 135});

    polygon({{x + m * 55, y + 50}, {x + m * 65, y + 50}, {x + m * 65, y + 60}, {x + m * 55, y + 60}}, {34, 203, 197});
    polygon({{x + m * 55, y + 60}, {x + m * 65, y + 60}, {x + m * 65, y + 70}, {x + m * 55, y + 70}}, {41, 94, 135});

    polygon({{x + m * 55, y + 80}, {x + m * 65, y + 80}, {x + m * 65, y + 100}, {x + m * 55, y + 100}}, {28, 0, 149});

    polygon({{x + m * 55, y + 110}, {x + m * 65, y + 110}, {x + m * 65, y + 130}, {x + m * 55, y + 130}}, {28, 0, 149});

    polygon({{x + m * 55, y + 140}, {x + m * 65, y + 140}, {x + m * 65, y + 160}, {x + m * 55, y + 160}}, {28, 0, 149});

    polygon({{x + m * 55, y + 170}, {x + m * 65, y + 170}, {x + m * 65, y + 180}, {x + m * 55, y + 180}}, {34, 203, 197});
    polygon({{x + m * 55, y + 180}, {x + m * 65, y + 180}, {x + m * 65, y + 190}, {x + m * 55, y + 190}}, {41, 94, 135});

    polygon({{x + m * 55, y + 200}, {x + m * 65, y + 200}, {x + m * 65, y + 220}, {x + m * 55, y + 220}}, {28, 0, 149});

    polygon({{x + m * 55, y + 230}, {x + m * 65, y + 230}, {x + m * 65, y + 250}, {x + m * 55, y + 250}}, {28, 0, 149});

    // Pillar Three
    polygon({{x + m * 65, y + 0}, {x + m * 75, y + 0}, {x + m * 75, y + 245}, {x + m * 65, y + 245}}, {135, 82, 214});

    // Terrace
    polygon({{x + m * 0, y + 245}, {x + m * 75, y + 245}, {x + m * 75, y + 250}, {x + m * 0, y + 250}}, {135, 82, 214});
    polygon({{x + m * 75, y + 245}, {x + m * 145, y + 245}, {x + m * 145, y + 250}, {x + m * 75, y + 250}}, {26, 46, 74});

    // Terrace Layer
    polygon({{x + m * 10, y + 250}, {x + m * 75, y + 250}, {x + m * 75, y + 255}, {x + m * 10, y + 255}}, {122, 165, 198});
    polygon({{x + m * 10, y + 255}, {x + m * 75, y + 255}, {x + m * 75, y + 260}, {x + m * 10, y + 260}}, {155, 204, 239});

    polygon({{x + m * 75, y + 250}, {x + m * 140, y + 250}, {x + m * 140, y + 255}, {x + m * 75, y + 255}}, {78, 105, 131});
    polygon({{x + m * 75, y + 255}, {x + m * 140, y + 255}, {x + m * 140, y + 260}, {x + m * 75, y + 260}}, {90, 125, 149});

    polygon({{x + m * 15, y + 260}, {x + m * 80, y + 260}, {x + m * 80, y + 265}, {x + m * 15, y + 265}}, {122, 165, 198});
    polygon({{x + m * 15, y + 265}, {x + m * 80, y + 265}, {x + m * 80, y + 270}, {x + m * 15, y + 270}}, {155, 204, 239});

    polygon({{x + m * 80, y + 260}, {x + m * 135, y + 260}, {x + m * 135, y + 265}, {x + m * 80, y + 265}}, {78, 105, 131});
    polygon({{x + m * 80, y + 265}, {x + m * 135, y + 265}, {x + m * 135, y + 270}, {x + m * 80, y + 270}}, {90, 125, 149});

    polygon({{x + m * 20, y + 270}, {x + m * 130, y + 270}, {x + m * 130, y + 275}, {x + m * 20, y + 275}}, {0, 0, 0});

    // Right Portion
    polygon({{x + m * 75, y + 0}, {x + m * 85, y + 0}, {x + m * 85, y + 245}, {x + m * 75, y + 245}}, {26, 46, 74});

    // Section One
    polygon({{x + m * 85, y + 0}, {x + m * 105, y + 0}, {x + m * 105, y + 245}, {x + m * 85, y + 245}}, {6, 23, 52});

    // Window Column Four
    polygon({{x + m * 85, y + 0}, {x + m * 98, y + 0}, {x + m * 98, y + 10}, {x + m * 85, y + 10}}, {28, 0, 149});

    polygon({{x + m * 85, y + 20}, {x + m * 98, y + 20}, {x + m * 98, y + 30}, {x + m * 85, y + 30}}, {34, 203, 197});
    polygon({{x + m * 85, y + 30}, {x + m * 98, y + 30}, {x + m * 98, y + 40}, {x + m * 85, y + 40}}, {41, 94, 135});

    polygon({{x + m * 85, y + 50}, {x + m * 98, y + 50}, {x + m * 98, y + 60}, {x + m * 85, y + 60}}, {34, 203, 197});
    polygon({{x + m * 85, y + 60}, {x + m * 98, y + 60}, {x + m * 98, y + 70}, {x + m * 85, y + 70}}, {41, 94, 135});

    polygon({{x + m * 85, y + 80}, {x + m * 98, y + 80}, {x + m * 98, y + 100}, {x + m * 85, y + 100}}, {28, 0, 149});

    polygon({{x + m * 85, y + 110}, {x + m * 98, y + 110}, {x + m * 98, y + 130}, {x + m * 85, y + 130}}, {28, 0, 149});

    polygon({{x + m * 85, y + 140}, {x + m * 98, y + 140}, {x + m * 98, y + 160}, {x + m * 85, y + 160}}, {28, 0, 149});

    polygon({{x + m * 85, y + 170}, {x + m * 98, y + 170}, {x + m * 98, y + 180}, {x + m * 85, y + 180}}, {34, 203, 197});
    polygon({{x + m * 85, y + 180}, {x + m * 98, y + 180}, {x + m * 98, y + 190}, {x + m * 85, y + 190}}, {41, 94, 135});

    polygon({{x + m * 85, y + 200}, {x + m * 98, y + 200}, {x + m * 98, y + 220}, {x + m * 85, y + 220}}, {28, 0, 149});

    polygon({{x + m * 85, y + 230}, {x + m * 98, y + 230}, {x + m * 98, y + 245}, {x + m * 85, y + 245}}, {28, 0, 149});

    // Pillar
    polygon({{x + m * 105, y + 0}, {x + m * 115, y + 0}, {x + m * 115, y + 245}, {x + m * 105, y + 245}}, {26, 46, 74});


    polygon({{x + m * 115, y + 0}, {x + m * 135, y + 0}, {x + m * 135, y + 245}, {x + m * 115, y + 245}}, {6, 23, 52});

    // Window Column Five
    polygon({{x + m * 115, y + 0}, {x + m * 130, y + 0}, {x + m * 130, y + 10}, {x + m * 115, y + 10}}, {28, 0, 149});

    polygon({{x + m * 115, y + 20}, {x + m * 130, y + 20}, {x + m * 130, y + 30}, {x + m * 115, y + 30}}, {34, 203, 197});
    polygon({{x + m * 115, y + 30}, {x + m * 130, y + 30}, {x + m * 130, y + 40}, {x + m * 115, y + 40}}, {41, 94, 135});

    polygon({{x + m * 115, y + 50}, {x + m * 130, y + 50}, {x + m * 130, y + 60}, {x + m * 115, y + 60}}, {34, 203, 197});
    polygon({{x + m * 115, y + 60}, {x + m * 130, y + 60}, {x + m * 130, y + 70}, {x + m * 115, y + 70}}, {41, 94, 135});

    polygon({{x + m * 115, y + 80}, {x + m * 130, y + 80}, {x + m * 130, y + 100}, {x + m * 115, y + 100}}, {28, 0, 149});

    polygon({{x + m * 115, y + 110}, {x + m * 130, y + 110}, {x + m * 130, y + 130}, {x + m * 115, y + 130}}, {28, 0, 149});

    polygon({{x + m * 115, y + 140}, {x + m * 130, y + 140}, {x + m * 130, y + 160}, {x + m * 115, y + 160}}, {28, 0, 149});

    polygon({{x + m * 115, y + 170}, {x + m * 130, y + 170}, {x + m * 130, y + 180}, {x + m * 115, y + 180}}, {34, 203, 197});
    polygon({{x + m * 115, y + 180}, {x + m * 130, y + 180}, {x + m * 130, y + 190}, {x + m * 115, y + 190}}, {41, 94, 135});

    polygon({{x + m * 115, y + 200}, {x + m * 130, y + 200}, {x + m * 130, y + 220}, {x + m * 115, y + 220}}, {28, 0, 149});

    polygon({{x + m * 115, y + 230}, {x + m * 130, y + 230}, {x + m * 130, y + 245}, {x + m * 115, y + 245}}, {28, 0, 149});

    polygon({{x + m * 135, y + 0}, {x + m * 145, y + 0}, {x + m * 145, y + 245}, {x + m * 135, y + 245}}, {26, 46, 74});


    // Top Portion
    // Left Section

    polygon({{x + m * 50, y + 275}, {x + m * 65, y + 275}, {x + m * 65, y + 395}, {x + m * 50, y + 395}}, {33, 72, 136});
    polygon({{x + m * 15, y + 275}, {x + m * 40, y + 275}, {x + m * 40, y + 395}, {x + m * 15, y + 395}}, {33, 72, 136});

    // Window Column One
    polygon({{x + m * 20, y + 290}, {x + m * 40, y + 290}, {x + m * 40, y + 300}, {x + m * 20, y + 300}}, {34, 203, 197});
    polygon({{x + m * 20, y + 300}, {x + m * 40, y + 300}, {x + m * 40, y + 310}, {x + m * 20, y + 310}}, {41, 94, 135});

    polygon({{x + m * 20, y + 320}, {x + m * 40, y + 320}, {x + m * 40, y + 330}, {x + m * 20, y + 330}}, {34, 203, 197});
    polygon({{x + m * 20, y + 330}, {x + m * 40, y + 330}, {x + m * 40, y + 340}, {x + m * 20, y + 340}}, {41, 94, 135});

    polygon({{x + m * 20, y + 350}, {x + m * 40, y + 350}, {x + m * 40, y + 360}, {x + m * 20, y + 360}}, {34, 203, 197});
    polygon({{x + m * 20, y + 360}, {x + m * 40, y + 360}, {x + m * 40, y + 370}, {x + m * 20, y + 370}}, {41, 94, 135});

    polygon({{x + m * 20, y + 380}, {x + m * 40, y + 380}, {x + m * 40, y + 390}, {x + m * 20, y + 390}}, {34, 203, 197});

    // Pillar One
    polygon({{x + m * 40, y + 275}, {x + m * 50, y + 275}, {x + m * 50, y + 395}, {x + m * 40, y + 395}}, {135, 82, 214});

    // Window Column Two
    polygon({{x + m * 55, y + 290}, {x + m * 70, y + 290}, {x + m * 70, y + 300}, {x + m * 55, y + 300}}, {34, 203, 197});
    polygon({{x + m * 55, y + 300}, {x + m * 70, y + 300}, {x + m * 70, y + 310}, {x + m * 55, y + 310}}, {41, 94, 135});

    polygon({{x + m * 55, y + 320}, {x + m * 70, y + 320}, {x + m * 70, y + 340}, {x + m * 55, y + 340}}, {28, 0, 149});
    //polygon({{x + m * 55, y + 330}, {x + m * 70, y + 330}, {x + m * 70, y + 340}, {x + m * 55, y + 340}}, {41, 94, 135});

    polygon({{x + m * 55, y + 350}, {x + m * 70, y + 350}, {x + m * 70, y + 370}, {x + m * 55, y + 370}}, {28, 0, 149});
    //polygon({{x + m * 55, y + 360}, {x + m * 70, y + 360}, {x + m * 70, y + 370}, {x + m * 55, y + 370}}, {41, 94, 135});

    polygon({{x + m * 55, y + 380}, {x + m * 70, y + 380}, {x + m * 70, y + 390}, {x + m * 55, y + 390}}, {28, 0, 149});

    // Pillar Two
    polygon({{x + m * 65, y + 275}, {x + m * 75, y + 275}, {x + m * 75, y + 395}, {x + m * 65, y + 395}}, {135, 82, 214});

    // Right Section
    // Pillar One
    polygon({{x + m * 75, y + 275}, {x + m * 85, y + 275}, {x + m * 85, y + 395}, {x + m * 75, y + 395}}, {26, 46, 74});

    // Shadowed Portion One
    polygon({{x + m * 85, y + 275}, {x + m * 105, y + 275}, {x + m * 105, y + 395}, {x + m * 85, y + 395}}, {6, 23, 52});

    // Window Column Three
    polygon({{x + m * 87, y + 290}, {x + m * 98, y + 290}, {x + m * 98, y + 300}, {x + m * 87, y + 300}}, {34, 203, 197});
    polygon({{x + m * 87, y + 300}, {x + m * 98, y + 300}, {x + m * 98, y + 310}, {x + m * 87, y + 310}}, {41, 94, 135});

    polygon({{x + m * 87, y + 320}, {x + m * 98, y + 320}, {x + m * 98, y + 330}, {x + m * 87, y + 330}}, {34, 203, 197});
    polygon({{x + m * 87, y + 330}, {x + m * 98, y + 330}, {x + m * 98, y + 340}, {x + m * 87, y + 340}}, {41, 94, 135});

    polygon({{x + m * 87, y + 350}, {x + m * 98, y + 350}, {x + m * 98, y + 370}, {x + m * 87, y + 370}}, {28, 0, 149});

    polygon({{x + m * 87, y + 380}, {x + m * 98, y + 380}, {x + m * 98, y + 390}, {x + m * 87, y + 390}}, {34, 203, 197});

    // Pillar Two
    polygon({{x + m * 105, y + 275}, {x + m * 115, y + 275}, {x + m * 115, y + 395}, {x + m * 105, y + 395}}, {26, 46, 74});

    // Shadowed Portion Two
    polygon({{x + m * 115, y + 275}, {x + m * 135, y + 275}, {x + m * 135, y + 395}, {x + m * 115, y + 395}}, {6, 23, 52});

    // Window Column Four
    polygon({{x + m * 117, y + 290}, {x + m * 127, y + 290}, {x + m * 127, y + 310}, {x + m * 117, y + 310}}, {28, 0, 149});

    polygon({{x + m * 117, y + 320}, {x + m * 127, y + 320}, {x + m * 127, y + 330}, {x + m * 117, y + 330}}, {34, 203, 197});
    polygon({{x + m * 117, y + 330}, {x + m * 127, y + 330}, {x + m * 127, y + 340}, {x + m * 117, y + 340}}, {41, 94, 135});

    polygon({{x + m * 117, y + 350}, {x + m * 127, y + 350}, {x + m * 127, y + 370}, {x + m * 117, y + 370}}, {28, 0, 149});

    polygon({{x + m * 117, y + 380}, {x + m * 127, y + 380}, {x + m * 127, y + 390}, {x + m * 117, y + 390}}, {28, 0, 149});

    // Pillar Three
    polygon({{x + m * 130, y + 275}, {x + m * 135, y + 275}, {x + m * 135, y + 395}, {x + m * 130, y + 395}}, {26, 46, 74});

    // Top Portion's Bottom Layer
    polygon({{x + m * 15, y + 275}, {x + m * 75, y + 275}, {x + m * 75, y + 280}, {x + m * 15, y + 280}}, {135, 82, 214});
    polygon({{x + m * 75, y + 275}, {x + m * 135, y + 275}, {x + m * 135, y + 280}, {x + m * 75, y + 280}}, {26, 46, 74});

    // Top Portion's Top Layer
    polygon({{x + m * 15, y + 395}, {x + m * 75, y + 395}, {x + m * 75, y + 400}, {x + m * 15, y + 400}}, {135, 82, 214});
    polygon({{x + m * 75, y + 395}, {x + m * 135, y + 395}, {x + m * 135, y + 400}, {x + m * 75, y + 400}}, {26, 46, 74});

    // Top Portion's Terrace Layer
    polygon({{x + m * 20, y + 400}, {x + m * 75, y + 400}, {x + m * 75, y + 405}, {x + m * 20, y + 405}}, {122, 165, 198});
    polygon({{x + m * 20, y + 405}, {x + m * 75, y + 405}, {x + m * 75, y + 410}, {x + m * 20, y + 410}}, {155, 204, 239});

    polygon({{x + m * 75, y + 400}, {x + m * 130, y + 400}, {x + m * 130, y + 405}, {x + m * 75, y + 405}}, {78, 105, 131});
    polygon({{x + m * 75, y + 405}, {x + m * 130, y + 405}, {x + m * 130, y + 410}, {x + m * 75, y + 410}}, {90, 125, 149});

    polygon({{x + m * 25, y + 410}, {x + m * 80, y + 410}, {x + m * 80, y + 415}, {x + m * 25, y + 415}}, {122, 165, 198});
    polygon({{x + m * 25, y + 415}, {x + m * 80, y + 415}, {x + m * 80, y + 420}, {x + m * 25, y + 420}}, {155, 204, 239});

    polygon({{x + m * 80, y + 410}, {x + m * 125, y + 410}, {x + m * 125, y + 415}, {x + m * 80, y + 415}}, {78, 105, 131});
    polygon({{x + m * 80, y + 415}, {x + m * 125, y + 415}, {x + m * 125, y + 420}, {x + m * 80, y + 420}}, {90, 125, 149});

    Tomb(1735, 420);
    Tomb(235, 420);
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

void Seventh_Building(float x, float y, int m = 1){
    // Bottom Portion
    // Left Portion
    polygon({{x + m * 0, y + 0}, {x + m * 15, y + 0}, {x + m * 15, y + 245}, {x + m * 0, y + 245}}, {33, 72, 136});

    // Window Column One
    polygon({{x + m * 5, y + 0}, {x + m * 15, y + 0}, {x + m * 15, y + 10}, {x + m * 5, y + 10}}, {41, 94, 135});

    polygon({{x + m * 5, y + 20}, {x + m * 15, y + 20}, {x + m * 15, y + 30}, {x + m * 5, y + 30}}, {34, 203, 197});
    polygon({{x + m * 5, y + 30}, {x + m * 15, y + 30}, {x + m * 15, y + 40}, {x + m * 5, y + 40}}, {41, 94, 135});

    polygon({{x + m * 5, y + 50}, {x + m * 15, y + 50}, {x + m * 15, y + 60}, {x + m * 5, y + 60}}, {34, 203, 197});
    polygon({{x + m * 5, y + 60}, {x + m * 15, y + 60}, {x + m * 15, y + 70}, {x + m * 5, y + 70}}, {41, 94, 135});

    polygon({{x + m * 5, y + 80}, {x + m * 15, y + 80}, {x + m * 15, y + 100}, {x + m * 5, y + 100}}, {28, 0, 149});

    polygon({{x + m * 5, y + 110}, {x + m * 15, y + 110}, {x + m * 15, y + 130}, {x + m * 5, y + 130}}, {28, 0, 149});

    polygon({{x + m * 5, y + 140}, {x + m * 15, y + 140}, {x + m * 15, y + 160}, {x + m * 5, y + 160}}, {28, 0, 149});

    polygon({{x + m * 5, y + 170}, {x + m * 15, y + 170}, {x + m * 15, y + 180}, {x + m * 5, y + 180}}, {34, 203, 197});
    polygon({{x + m * 5, y + 180}, {x + m * 15, y + 180}, {x + m * 15, y + 190}, {x + m * 5, y + 190}}, {41, 94, 135});

    polygon({{x + m * 5, y + 200}, {x + m * 15, y + 200}, {x + m * 15, y + 220}, {x + m * 5, y + 220}}, {28, 0, 149});

    polygon({{x + m * 5, y + 230}, {x + m * 15, y + 230}, {x + m * 15, y + 250}, {x + m * 5, y + 250}}, {28, 0, 149});

    // Pillar One
    polygon({{x + m * 15, y + 0}, {x + m * 25, y + 0}, {x + m * 25, y + 245}, {x + m * 15, y + 245}}, {135, 82, 214});

    polygon({{x + m * 25, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 245}, {x + m * 25, y + 245}}, {33, 72, 136});

    // Window Column Two
    polygon({{x + m * 30, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 10}, {x + m * 30, y + 10}}, {28, 0, 149});

    polygon({{x + m * 30, y + 20}, {x + m * 40, y + 20}, {x + m * 40, y + 30}, {x + m * 30, y + 30}}, {34, 203, 197});
    polygon({{x + m * 30, y + 30}, {x + m * 40, y + 30}, {x + m * 40, y + 40}, {x + m * 30, y + 40}}, {41, 94, 135});

    polygon({{x + m * 30, y + 50}, {x + m * 40, y + 50}, {x + m * 40, y + 60}, {x + m * 30, y + 60}}, {34, 203, 197});
    polygon({{x + m * 30, y + 60}, {x + m * 40, y + 60}, {x + m * 40, y + 70}, {x + m * 30, y + 70}}, {41, 94, 135});

    polygon({{x + m * 30, y + 80}, {x + m * 40, y + 80}, {x + m * 40, y + 100}, {x + m * 30, y + 100}}, {28, 0, 149});

    polygon({{x + m * 30, y + 110}, {x + m * 40, y + 110}, {x + m * 40, y + 130}, {x + m * 30, y + 130}}, {28, 0, 149});

    polygon({{x + m * 30, y + 140}, {x + m * 40, y + 140}, {x + m * 40, y + 160}, {x + m * 30, y + 160}}, {28, 0, 149});

    polygon({{x + m * 30, y + 170}, {x + m * 40, y + 170}, {x + m * 40, y + 180}, {x + m * 30, y + 180}}, {34, 203, 197});
    polygon({{x + m * 30, y + 180}, {x + m * 40, y + 180}, {x + m * 40, y + 190}, {x + m * 30, y + 190}}, {41, 94, 135});

    polygon({{x + m * 30, y + 200}, {x + m * 40, y + 200}, {x + m * 40, y + 220}, {x + m * 30, y + 220}}, {28, 0, 149});

    polygon({{x + m * 30, y + 230}, {x + m * 40, y + 230}, {x + m * 40, y + 250}, {x + m * 30, y + 250}}, {28, 0, 149});

    // Pillar Two
    polygon({{x + m * 40, y + 0}, {x + m * 50, y + 0}, {x + m * 50, y + 245}, {x + m * 40, y + 245}}, {135, 82, 214});

    polygon({{x + m * 50, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 245}, {x + m * 50, y + 245}}, {33, 72, 136});

    // Window Column Three
    polygon({{x + m * 55, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 10}, {x + m * 55, y + 10}}, {28, 0, 149});

    polygon({{x + m * 55, y + 20}, {x + m * 65, y + 20}, {x + m * 65, y + 30}, {x + m * 55, y + 30}}, {34, 203, 197});
    polygon({{x + m * 55, y + 30}, {x + m * 65, y + 30}, {x + m * 65, y + 40}, {x + m * 55, y + 40}}, {41, 94, 135});

    polygon({{x + m * 55, y + 50}, {x + m * 65, y + 50}, {x + m * 65, y + 60}, {x + m * 55, y + 60}}, {34, 203, 197});
    polygon({{x + m * 55, y + 60}, {x + m * 65, y + 60}, {x + m * 65, y + 70}, {x + m * 55, y + 70}}, {41, 94, 135});

    polygon({{x + m * 55, y + 80}, {x + m * 65, y + 80}, {x + m * 65, y + 100}, {x + m * 55, y + 100}}, {28, 0, 149});

    polygon({{x + m * 55, y + 110}, {x + m * 65, y + 110}, {x + m * 65, y + 130}, {x + m * 55, y + 130}}, {28, 0, 149});

    polygon({{x + m * 55, y + 140}, {x + m * 65, y + 140}, {x + m * 65, y + 160}, {x + m * 55, y + 160}}, {28, 0, 149});

    polygon({{x + m * 55, y + 170}, {x + m * 65, y + 170}, {x + m * 65, y + 180}, {x + m * 55, y + 180}}, {34, 203, 197});
    polygon({{x + m * 55, y + 180}, {x + m * 65, y + 180}, {x + m * 65, y + 190}, {x + m * 55, y + 190}}, {41, 94, 135});

    polygon({{x + m * 55, y + 200}, {x + m * 65, y + 200}, {x + m * 65, y + 220}, {x + m * 55, y + 220}}, {28, 0, 149});

    polygon({{x + m * 55, y + 230}, {x + m * 65, y + 230}, {x + m * 65, y + 250}, {x + m * 55, y + 250}}, {28, 0, 149});

    // Pillar Three
    polygon({{x + m * 65, y + 0}, {x + m * 75, y + 0}, {x + m * 75, y + 245}, {x + m * 65, y + 245}}, {135, 82, 214});

    // Terrace
    polygon({{x + m * 0, y + 245}, {x + m * 75, y + 245}, {x + m * 75, y + 250}, {x + m * 0, y + 250}}, {135, 82, 214});
    polygon({{x + m * 75, y + 245}, {x + m * 145, y + 245}, {x + m * 145, y + 250}, {x + m * 75, y + 250}}, {26, 46, 74});

    // Right Portion
    polygon({{x + m * 75, y + 0}, {x + m * 85, y + 0}, {x + m * 85, y + 245}, {x + m * 75, y + 245}}, {26, 46, 74});

    // Section One
    polygon({{x + m * 85, y + 0}, {x + m * 105, y + 0}, {x + m * 105, y + 245}, {x + m * 85, y + 245}}, {6, 23, 52});

    // Window Column Four
    polygon({{x + m * 85, y + 0}, {x + m * 98, y + 0}, {x + m * 98, y + 10}, {x + m * 85, y + 10}}, {28, 0, 149});

    polygon({{x + m * 85, y + 20}, {x + m * 98, y + 20}, {x + m * 98, y + 30}, {x + m * 85, y + 30}}, {34, 203, 197});
    polygon({{x + m * 85, y + 30}, {x + m * 98, y + 30}, {x + m * 98, y + 40}, {x + m * 85, y + 40}}, {41, 94, 135});

    polygon({{x + m * 85, y + 50}, {x + m * 98, y + 50}, {x + m * 98, y + 60}, {x + m * 85, y + 60}}, {34, 203, 197});
    polygon({{x + m * 85, y + 60}, {x + m * 98, y + 60}, {x + m * 98, y + 70}, {x + m * 85, y + 70}}, {41, 94, 135});

    polygon({{x + m * 85, y + 80}, {x + m * 98, y + 80}, {x + m * 98, y + 100}, {x + m * 85, y + 100}}, {28, 0, 149});

    polygon({{x + m * 85, y + 110}, {x + m * 98, y + 110}, {x + m * 98, y + 130}, {x + m * 85, y + 130}}, {28, 0, 149});

    polygon({{x + m * 85, y + 140}, {x + m * 98, y + 140}, {x + m * 98, y + 160}, {x + m * 85, y + 160}}, {28, 0, 149});

    polygon({{x + m * 85, y + 170}, {x + m * 98, y + 170}, {x + m * 98, y + 180}, {x + m * 85, y + 180}}, {34, 203, 197});
    polygon({{x + m * 85, y + 180}, {x + m * 98, y + 180}, {x + m * 98, y + 190}, {x + m * 85, y + 190}}, {41, 94, 135});

    polygon({{x + m * 85, y + 200}, {x + m * 98, y + 200}, {x + m * 98, y + 220}, {x + m * 85, y + 220}}, {28, 0, 149});

    polygon({{x + m * 85, y + 230}, {x + m * 98, y + 230}, {x + m * 98, y + 245}, {x + m * 85, y + 245}}, {28, 0, 149});

    // Pillar
    polygon({{x + m * 105, y + 0}, {x + m * 115, y + 0}, {x + m * 115, y + 245}, {x + m * 105, y + 245}}, {26, 46, 74});


    polygon({{x + m * 115, y + 0}, {x + m * 135, y + 0}, {x + m * 135, y + 245}, {x + m * 115, y + 245}}, {6, 23, 52});

    // Window Column Five
    polygon({{x + m * 115, y + 0}, {x + m * 130, y + 0}, {x + m * 130, y + 10}, {x + m * 115, y + 10}}, {28, 0, 149});

    polygon({{x + m * 115, y + 20}, {x + m * 130, y + 20}, {x + m * 130, y + 30}, {x + m * 115, y + 30}}, {34, 203, 197});
    polygon({{x + m * 115, y + 30}, {x + m * 130, y + 30}, {x + m * 130, y + 40}, {x + m * 115, y + 40}}, {41, 94, 135});

    polygon({{x + m * 115, y + 50}, {x + m * 130, y + 50}, {x + m * 130, y + 60}, {x + m * 115, y + 60}}, {34, 203, 197});
    polygon({{x + m * 115, y + 60}, {x + m * 130, y + 60}, {x + m * 130, y + 70}, {x + m * 115, y + 70}}, {41, 94, 135});

    polygon({{x + m * 115, y + 80}, {x + m * 130, y + 80}, {x + m * 130, y + 100}, {x + m * 115, y + 100}}, {28, 0, 149});

    polygon({{x + m * 115, y + 110}, {x + m * 130, y + 110}, {x + m * 130, y + 130}, {x + m * 115, y + 130}}, {28, 0, 149});

    polygon({{x + m * 115, y + 140}, {x + m * 130, y + 140}, {x + m * 130, y + 160}, {x + m * 115, y + 160}}, {28, 0, 149});

    polygon({{x + m * 115, y + 170}, {x + m * 130, y + 170}, {x + m * 130, y + 180}, {x + m * 115, y + 180}}, {34, 203, 197});
    polygon({{x + m * 115, y + 180}, {x + m * 130, y + 180}, {x + m * 130, y + 190}, {x + m * 115, y + 190}}, {41, 94, 135});

    polygon({{x + m * 115, y + 200}, {x + m * 130, y + 200}, {x + m * 130, y + 220}, {x + m * 115, y + 220}}, {28, 0, 149});

    polygon({{x + m * 115, y + 230}, {x + m * 130, y + 230}, {x + m * 130, y + 245}, {x + m * 115, y + 245}}, {28, 0, 149});

    polygon({{x + m * 135, y + 0}, {x + m * 145, y + 0}, {x + m * 145, y + 245}, {x + m * 135, y + 245}}, {26, 46, 74});
}

void Eight_Building(float x, float y, int m = 1, Color buildingWall = {49, 34, 192}, Color buildingWall2  = {137, 82, 214}, Color buildingWall3 = {35, 4, 46}, Color buildingWall4 = {27, 46, 75}){
    for (int i = 0; i < 120; ++i) {
        Color interpolatedColor = interpolateColor(buildingWall2, buildingWall, static_cast<float>(i) / 70.0f);
        polygon({{x + m * i, y + 0}, {x + m * (i + 1), y + 0}, {x + m * (i + 1), y + 245}, {x + m * i, y + 245}}, interpolatedColor);
    }


    polygon({{x + m * 100, y + 0}, {x + m * 200, y + 0}, {x + m * 200, y + 245}, {x + m * 100, y + 245}}, {13, 14, 183});
    polygon({{x + m * 100, y + 0}, {x + m * 111, y + 0}, {x + m * 111, y + 245}, {x + m * 100, y + 245}}, {26, 46, 74});

    polygon({{x + m * 0, y + 70}, {x + m * 200, y + 70}, {x + m * 200, y + 75}, {x + m * 0, y + 75}}, {0, 0, 0});
    polygon({{x + m * 0, y + 150}, {x + m * 200, y + 150}, {x + m * 200, y + 155}, {x + m * 0, y + 155}}, {0, 0, 0});

    polygon({{x + m * 40, y + 245}, {x + m * 160, y + 245}, {x + m * 160, y + 250}, {x + m * 40, y + 250}}, {0, 0, 0});
}

void Shadow_Building_One(float x, float y, int m = 1, Color shadow = {19, 23, 69}){
    polygon({{x + m * 0, y + 0}, {x + m * 60, y + 0}, {x + m * 60, y + 40}, {x + m * 0, y + 40}}, shadow);
    polygon({{x + m * 0, y + 40}, {x + m * 45, y + 40}, {x + m * 45, y + 60}, {x + m * 0, y + 60}}, shadow);
    polygon({{x + m * 0, y + 60}, {x + m * 30, y + 60}, {x + m * 30, y + 80}, {x + m * 0, y + 80}}, shadow);
    polygon({{x + m * 15, y + 80}, {x + m * 25, y + 80}, {x + m * 25, y + 95}, {x + m * 15, y + 95}}, shadow);

    polygon({{x + m * 70, y - 85}, {x + m * 80, y - 85}, {x + m * 80, y + 165}, {x + m * 70, y + 165}}, shadow);
}

void Shadow_Building_Two(float x, float y, int m = 1, Color shadow = {19, 23, 69}){
    polygon({{x + m * 0, y + 0}, {x + m * 60, y + 0}, {x + m * 60, y + 40}, {x + m * 0, y + 40}}, shadow);
}

void cloudLower(float Tx, float Ty, float s, Color color)
{
    //first
    circle(Tx + s * 2, Ty + s * 30, 60, 60, color);
    circle(Tx + s * 13, Ty + s * 22, 93, 93, color);
    circle(Tx + s * 24, Ty + s * 24, 83, 90, color);
    circle(Tx + s * 40, Ty + s * 32, 120, 120, color);
    circle(Tx + s * 54, Ty + s * 36, 77, 70, color);
    circle(Tx + s * 60, Ty + s * 30, 77, 70, color);
    circle(Tx + s * 66, Ty + s * 40, 77, 84, color);
    circle(Tx + s * 74, Ty + s * 40, 100, 100, color);
    circle(Tx + s * 85, Ty + s * 37, 77, 84, color);
    circle(Tx + s * 85, Ty + s * 32, 77, 84, color);
    circle(Tx + s * 95, Ty + s * 40, 107, 100, color);
    circle(Tx + s * 108, Ty + s * 34, 67, 60, color);
    circle(Tx + s * 122, Ty + s * 31, 100, 100, color);
    circle(Tx + s * 132, Ty + s * 25, 100, 100, color);
    circle(Tx + s * 144, Ty + s * 16, 60, 60, color);
    quad({{12, 18}, {146, 18}, {146, 11}, {11, 10}}, color, Tx, Ty, s);
    quad({{20, 32}, {138, 32}, {138, 17}, {20, 17}}, color, Tx, Ty, s);
    quad({{12, 18}, {146, 18}, {146, 11}, {11, 10}}, color, Tx, Ty, s);
    quad({{20, 32}, {138, 32}, {138, 17}, {20, 17}}, color, Tx, Ty, s);

    //last
    circle(Tx + s * 102, Ty + s * 30, 60, 60, color);
    circle(Tx + s * 113, Ty + s * 16, 93, 93, color);
    circle(Tx + s * 124, Ty + s * 24, 83, 90, color);
    circle(Tx + s * 140, Ty + s * 32, 120, 120, color);
    circle(Tx + s * 154, Ty + s * 36, 77, 70, color);
    circle(Tx + s * 160, Ty + s * 30, 77, 70, color);
    circle(Tx + s * 166, Ty + s * 40, 77, 84, color);
    circle(Tx + s * 174, Ty + s * 40, 100, 100, color);
    circle(Tx + s * 185, Ty + s * 37, 77, 84, color);
    circle(Tx + s * 185, Ty + s * 32, 77, 84, color);
    circle(Tx + s * 195, Ty + s * 40, 107, 100, color);
    circle(Tx + s * 208, Ty + s * 34, 67, 60, color);
    circle(Tx + s * 222, Ty + s * 31, 100, 100, color);
    circle(Tx + s * 232, Ty + s * 25, 100, 100, color);
    circle(Tx + s * 244, Ty + s * 16, 60, 60, color);
    quad({{112, 18}, {246, 18}, {246, 11}, {111, 10}}, color, Tx, Ty, s);
    quad({{120, 32}, {238, 32}, {238, 17}, {120, 17}}, color, Tx, Ty, s);
    quad({{112, 18}, {246, 18}, {246, 11}, {111, 10}}, color, Tx, Ty, s);
    quad({{120, 32}, {238, 32}, {238, 17}, {120, 17}}, color, Tx, Ty, s);

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

    // Cloud
    cloudLower(-250,480,10, {23, 13, 77});
    cloudLower(-100,285,10, {46, 35, 93});
    cloudLower(0,100,10, {115, 74, 218});

     // First Building
    Seventh_Building(0, 0);
    polygon({{0, 250}, {0, 255}, {140,255}, {140, 250}}, {0, 0, 0});
    Seventh_Building(0, 255);

    // Shadow Building One
    Shadow_Building_One(335, 85);

    // Third Building
    Third_Building(200, 0);

    // Second Building
    Second_Building(100, 0);

    // Fourth Building
    Tomb(320, 0);

    // Fifth Building
    Fifth_Building(420, 0);

    // Sixth Building
    Second_Building(520, 0);

    // Shadow Building Four
    polygon({{840, 0}, {840, 120}, {860, 120}, {860, 0}}, {0, 0, 0});
    polygon({{860, 0}, {860, 180}, {900, 180}, {900, 0}}, {0, 0, 0});

    // Seventh Building
    Seventh_Building(700, 0);

    // Eight Building
    Eight_Building(900, 0);
    Second_Building(930, 250);

    // Shadow Building Four
    polygon({{1080, 0}, {1080, 280}, {1200,280}, {1200, 0}}, {0, 0, 0});

    // Tenth Building
    glPushMatrix();
    glScalef(1.2,1.4,0.0);
    Second_Building(950, 0);
    glPopMatrix();

    // Ninth Building
    Tomb(1070, 0);

    // Twelfth Building
    Seventh_Building(1380, 0);

    // Eleventh Building
    Second_Building(1280, 0);

    // Thirteenth Building
    Seventh_Building(1500, 0);
    polygon({{1505, 250}, {1505, 255}, {1640,255}, {1640, 250}}, {0, 0, 0});
    Seventh_Building(1500, 255);

    // Fourteenth Building
    Third_Building(1700, 0);

    // Shadow Building One
    Shadow_Building_One(1845, 85);

    // Fourteenth Building
    Second_Building(1600, 0);

    // Sixteenth Building
    Tomb(1850, 0);

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
