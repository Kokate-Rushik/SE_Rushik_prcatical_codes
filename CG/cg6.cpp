#include <graphics.h>
#include <cmath>
#include <iostream>
#include <unistd.h> // Include for sleep function

using namespace std;

struct Point3D {
    float x, y, z;
};

Point3D cube[8]; // Original points of the cube
Point3D transformedCube[8]; // Transformed points of the cube

void initializeCube(float side) {
    float halfSide = side / 2;
    cube[0] = { -halfSide, -halfSide, -halfSide };
    cube[1] = { halfSide, -halfSide, -halfSide };
    cube[2] = { halfSide, halfSide, -halfSide };
    cube[3] = { -halfSide, halfSide, -halfSide };
    cube[4] = { -halfSide, -halfSide, halfSide };
    cube[5] = { halfSide, -halfSide, halfSide };
    cube[6] = { halfSide, halfSide, halfSide };
    cube[7] = { -halfSide, halfSide, halfSide };
}

void projectCube() {
    for (int i = 0; i < 8; i++) {
        transformedCube[i].x = cube[i].x + 320;
        transformedCube[i].y = cube[i].y + 240;
    }
}

void drawCube() {
    for (int i = 0; i < 4; i++) {
        line(transformedCube[i].x, transformedCube[i].y, transformedCube[(i + 1) % 4].x, transformedCube[(i + 1) % 4].y);
        line(transformedCube[i + 4].x, transformedCube[i + 4].y, transformedCube[(i + 1) % 4 + 4].x, transformedCube[(i + 1) % 4 + 4].y);
        line(transformedCube[i].x, transformedCube[i].y, transformedCube[i + 4].x, transformedCube[i + 4].y);
    }
}

void scaleCube(float scaleX, float scaleY, float scaleZ) {
    for (int i = 0; i < 8; i++) {
        cube[i].x *= scaleX;
        cube[i].y *= scaleY;
        cube[i].z *= scaleZ;
    }
}

void translateCube(float tx, float ty, float tz) {
    for (int i = 0; i < 8; i++) {
        cube[i].x += tx;
        cube[i].y += ty;
        cube[i].z += tz;
    }
}

void rotateCubeX(float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        float y = cube[i].y;
        float z = cube[i].z;
        cube[i].y = y * cos(rad) - z * sin(rad);
        cube[i].z = y * sin(rad) + z * cos(rad);
    }
}

void rotateCubeY(float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        float x = cube[i].x;
        float z = cube[i].z;
        cube[i].x = x * cos(rad) + z * sin(rad);
        cube[i].z = -x * sin(rad) + z * cos(rad);
    }
}

void rotateCubeZ(float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        float x = cube[i].x;
        float y = cube[i].y;
        cube[i].x = x * cos(rad) - y * sin(rad);
        cube[i].y = x * sin(rad) + y * cos(rad);
    }
}

int main() {
    int gd = X11, gm = X11_1024x768;
    initgraph(&gd, &gm, (char*)"");

    initializeCube(100); // Initialize a cube with side length 100
    projectCube();
    drawCube();
    sleep(1); // Replace delay(1000) with sleep(1) for 1-second pause

    cleardevice();
    scaleCube(1.5, 1.5, 1.5); // Scale the cube
    projectCube();
    drawCube();
    sleep(1);

    cleardevice();
    translateCube(50, 50, 0); // Translate the cube
    projectCube();
    drawCube();
    sleep(1);

    cleardevice();
    rotateCubeX(45); // Rotate around X-axis
    projectCube();
    drawCube();
    sleep(1);

    cleardevice();
    rotateCubeY(45); // Rotate around Y-axis
    projectCube();
    drawCube();
    sleep(1);

    cleardevice();
    rotateCubeZ(45); // Rotate around Z-axis
    projectCube();
    drawCube();
    sleep(1);

    getch();
    closegraph();
    return 0;
}

