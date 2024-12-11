#include <graphics.h>
#include <cmath>

const float PI = 3.14159;

class Shape {
protected:
    int points[4][2];
    int n; // Number of vertices

public:
    Shape(int pts[][2], int vertices) {
        n = vertices;
        for (int i = 0; i < n; ++i) {
            points[i][0] = pts[i][0];
            points[i][1] = pts[i][1];
        }
    }

    void draw() {
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            line(points[i][0], points[i][1], points[next][0], points[next][1]);
        }
    }

    Shape operator+(const int translation[2]) {
        Shape translated = *this;
        for (int i = 0; i < n; ++i) {
            translated.points[i][0] += translation[0];
            translated.points[i][1] += translation[1];
        }
        return translated;
    }

    Shape operator*(float scale) {
        Shape scaled = *this;
        int cx = points[0][0], cy = points[0][1];
        for (int i = 0; i < n; ++i) {
            scaled.points[i][0] = cx + (int)((points[i][0] - cx) * scale);
            scaled.points[i][1] = cy + (int)((points[i][1] - cy) * scale);
        }
        return scaled;
    }

    Shape operator^(float angle) {
        Shape rotated = *this;
        int cx = points[0][0], cy = points[0][1];
        angle = angle * PI / 180;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0] - cx;
            int y = points[i][1] - cy;
            rotated.points[i][0] = cx + (int)(x * cos(angle) - y * sin(angle));
            rotated.points[i][1] = cy + (int)(x * sin(angle) + y * cos(angle));
        }
        return rotated;
    }
};

int main() {
    int gd = X11, gm = X11_1024x768;
    initgraph(&gd, &gm, (char*)"");

    int trianglePoints[3][2] = {{300, 300}, {350, 400}, {250, 400}};
    int rhombusPoints[4][2] = {{500, 300}, {550, 350}, {500, 400}, {450, 350}};

    Shape triangle(trianglePoints, 3);
    Shape rhombus(rhombusPoints, 4);

    triangle.draw();
    rhombus.draw();

    // Apply transformations and draw
    int translation[2] = {50, 50};
    float scale = 1.5;
    float angle = 45;

    Shape translatedTriangle = triangle + translation;
    Shape scaledTriangle = triangle * scale;
    Shape rotatedTriangle = triangle ^ angle;

    Shape translatedRhombus = rhombus + translation;
    Shape scaledRhombus = rhombus * scale;
    Shape rotatedRhombus = rhombus ^ angle;

    setcolor(RED);
    translatedTriangle.draw();
    translatedRhombus.draw();

    setcolor(GREEN);
    scaledTriangle.draw();
    scaledRhombus.draw();

    setcolor(CYAN);
    rotatedTriangle.draw();
    rotatedRhombus.draw();

    getch();
    closegraph();
    return 0;
}

