#include <graphics.h>
#include <iostream>
using namespace std;

// Function to draw the Hilbert Curve
void hilbertCurve(int x, int y, int xi, int xj, int yi, int yj, int n) {
    if (n <= 0) {
        int x1 = x + (xi + yi) / 2;
        int y1 = y + (xj + yj) / 2;
        int x2 = x + (xi - yi) / 2;
        int y2 = y + (xj - yj) / 2;
        line(x1, y1, x2, y2);
    } else {
        hilbertCurve(x, y, yi / 2, yj / 2, xi / 2, xj / 2, n - 1);
        hilbertCurve(x + xi / 2, y + xj / 2, xi / 2, xj / 2, yi / 2, yj / 2, n - 1);
        hilbertCurve(x + xi / 2 + yi / 2, y + xj / 2 + yj / 2, xi / 2, xj / 2, yi / 2, yj / 2, n - 1);
        hilbertCurve(x + xi / 2 + yi, y + xj / 2 + yj, -yi / 2, -yj / 2, -xi / 2, -xj / 2, n - 1);
    }
}

int main() {
    int gd = X11, gm = X11_1024x768;
    initgraph(&gd, &gm, (char*)"");

    int n = 5; // Depth level of Hilbert curve
    int startX = 100, startY = 100;
    int length = 512;

    hilbertCurve(startX, startY, length, 0, 0, length, n);

    getch();
    closegraph();
    return 0;
}

