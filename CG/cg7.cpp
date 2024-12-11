#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define ScreenWidth 1024
#define ScreenHeight 768
#define GroundY (ScreenHeight * 0.75)

int ldisp = 0;

// Function to draw a man with an umbrella
void DrawManAndUmbrella(Display *display, Window win, GC gc, int x, int ldisp) {
    // Draw head (circle)
    XFillArc(display, win, gc, x - 10, GroundY - 100, 20, 20, 0, 360 * 64); // Circle

    // Draw body (line)
    XDrawLine(display, win, gc, x, GroundY - 80, x, GroundY - 30);

    // Draw arms (lines)
    XDrawLine(display, win, gc, x, GroundY - 70, x + 10, GroundY - 60);
    XDrawLine(display, win, gc, x, GroundY - 65, x + 10, GroundY - 55);
    XDrawLine(display, win, gc, x + 10, GroundY - 60, x + 20, GroundY - 70);
    XDrawLine(display, win, gc, x + 10, GroundY - 55, x + 20, GroundY - 70);

    // Draw legs (lines)
    XDrawLine(display, win, gc, x, GroundY - 30, x + ldisp, GroundY);
    XDrawLine(display, win, gc, x, GroundY - 30, x - ldisp, GroundY);

    // Draw umbrella (pieslice equivalent)
    XFillArc(display, win, gc, x + 10, GroundY - 120, 40, 40, 0, 180 * 64); // Umbrella
    XDrawLine(display, win, gc, x + 20, GroundY - 120, x + 20, GroundY - 70); // Umbrella stick
}

// Function to simulate rain
void Rain(Display *display, Window win, GC gc, int x) {
    int i, rx, ry;
    for (i = 0; i < 400; i++) {
        rx = rand() % ScreenWidth;
        ry = rand() % ScreenHeight;
        if (ry < GroundY - 4) {
            if (ry < GroundY - 120 || (ry > GroundY - 120 && (rx < x - 20 || rx > x + 60))) {
                XDrawLine(display, win, gc, rx, ry, rx + 1, ry + 4);
            }
        }
    }
}

// Driver code
int main() {
    int x = ScreenWidth / 5;

    // Initialize graphics window
    Display* display;
    int screen;
    Window win;
    XEvent report;
    display = XOpenDisplay(NULL);
    screen = DefaultScreen(display);

    win = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, ScreenWidth, ScreenHeight, 0, 0, 0);
    XSelectInput(display, win, ExposureMask | KeyPressMask);
    XMapWindow(display, win);

    // Create Graphics Context (GC)
    GC gc = XCreateGC(display, win, 0, NULL);
    XSetForeground(display, gc, WhitePixel(display, screen));

    // Execute until any key is pressed
    while (1) {
        // Clear the screen
        XClearWindow(display, win);

        // Draw ground
        XDrawLine(display, win, gc, 0, GroundY, ScreenWidth, GroundY);

        // Simulate rain
        Rain(display, win, gc, x);

        // Update the man's umbrella position
        ldisp = (ldisp + 2) % 20;
        DrawManAndUmbrella(display, win, gc, x, ldisp);

        // Check if a key is pressed
        if (XPending(display) > 0) {
            XNextEvent(display, &report);
            if (report.type == KeyPress) {
                break; // Exit the loop if a key is pressed
            }
        }

        // Update x for animation
        x = (x + 2) % ScreenWidth;

        // Delay to control animation speed
        usleep(20000);  // Sleep for 20 milliseconds
    }

    // Close the display connection
    XCloseDisplay(display);

    return 0;
}

