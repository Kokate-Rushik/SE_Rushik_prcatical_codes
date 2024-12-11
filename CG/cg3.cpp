#include <graphics.h>
#include <cmath>

void drawDDALine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    float x = x1, y = y1;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

void drawBresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

int main() {
    int gd = X11, gm = X11_1024x768;
    initgraph(&gd, &gm, (char*)"");

    int xc = 320, yc = 240; // Center of the main circle
    int radius = 100; // Radius of the main circle

    // Draw outer circle using Bresenham's algorithm
    drawBresenhamCircle(xc, yc, radius);

    // Calculate vertices of the inscribed equilateral triangle
    int x1 = xc;
    int y1 = yc - radius;
    int x2 = xc + (int)(radius * sin(M_PI / 3));
    int y2 = yc + (int)(radius * 0.5);
    int x3 = xc - (int)(radius * sin(M_PI / 3));
    int y3 = yc + (int)(radius * 0.5);

    // Draw the triangle using DDA line drawing algorithm
    drawDDALine(x1, y1, x2, y2);
    drawDDALine(x2, y2, x3, y3);
    drawDDALine(x3, y3, x1, y1);

    // Draw inner circle using Bresenham's algorithm
    int innerRadius = radius / 2;
    drawBresenhamCircle(xc, yc, innerRadius);

    getch();
    closegraph();
    return 0;
}

