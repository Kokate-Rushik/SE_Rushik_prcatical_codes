//Code by Kokate Rushik
#include<GL/freeglut.h>
#include<math.h>

class Shaper {
	public:
		void DDAline(int x1, int  y1, int  x2, int y2);
		void Bresenham_circle(int cx, int y, int r);
		
	private:
		void putpixel(int x, int y);
		void plotpixel(int cx, int cy, int x, int y);
};

void Shaper::DDAline(int x1, int  y1, int  x2, int y2) {
	int dx, dy, step;
	float xinc, yinc, x, y;
	
	dx = x2-x1;
	dy = y2-y1;
	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	
	xinc = dx/float(step);
	yinc = dy/float(step);
	x=x1;y=y1;
	
	while (x<=x2) {
		putpixel(x,y);
		x+=xinc;
		y+=yinc;
	}
}

void Shaper::Bresenham_circle(int cx, int cy, int r) {
	int x=0, y=r;
	int p=3-2*r;
	
	while (x<=y) {
		plotpixel(cx,cy,x,y);
		if (p<0) {
			p+= 2*x + 6;
		} else {
			p+= 2*(x-y) + 10;
			y--;
		}
		x++;
	}
}

void Shaper::putpixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void Shaper::plotpixel(int cx, int cy, int x, int y) {
	putpixel(cx+x,cy+y);
	putpixel(cx+x,cy-y);
	putpixel(cx-x,cy+y);
	putpixel(cx-x,cy-y);
	
	putpixel(cx+y,cy+x);
	putpixel(cx+y,cy-x);
	putpixel(cx-y,cy+x);
	putpixel(cx-y,cy-x);
}

Shaper Pattern;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//to draw
	glColor3f(1.0, 1.0, 1.0);
	Pattern.DDAline(-500,0,500,0);
	Pattern.DDAline(-500,0,0,900);
	Pattern.DDAline(0,900,500,0);
	
	Pattern.Bresenham_circle(0,300,300);
	Pattern.Bresenham_circle(0,300,600);	
	
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(200,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("CG_PQ2");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	
	glutMainLoop();
	return 0;
}
