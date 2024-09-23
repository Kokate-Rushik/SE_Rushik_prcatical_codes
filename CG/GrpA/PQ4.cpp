//Code by Kokate Rushik
#include<GL/freeglut.h>

class Pixel {
	protected:
		int x1, y1;
		float size;
	
	public:
		Pixel(float x0=0, float y0=0, float Size=1.0) : x1(x0), y1(0), size(Size) {}
		virtual void draw() {
			glPointSize(size);
			glBegin(GL_POINTS);
			glVertex2i(x1,y1);
			glEnd();
		}
};

class Line : public Pixel {
	private:
		int x2, y2, dx,dy;
		int style;

	public:
		Line(int X1, int Y1, int X2, int Y2, int Style=0) : Pixel(X1,Y1), x2(X2), y2(Y2), style(Style) {
			dx=x2-x1;
			dy=y2-y1;
			draw();
		}
		
		void drawSolid();
		void drawDotted();
		void drawDashed();
		void drawDashDot();
		void drawThick();
		
		void draw () override {
			switch (style) {
				case 0: drawSolid(); break;
				case 1: drawDotted(); break;
				case 2: drawDashed(); break;
				case 3: drawDashDot(); break;
				case 4: drawThick(); break;
				default: drawSolid(); break;
			}
		}
};

void Line::drawSolid() {
	int dx, dy, p,x ,y;
	p=2*dy-dx;
	x=x1;y=y1;
	while (x1<=x2) {
		Pixel(x,y).draw();
		if (p<0) {
			p += 2*dy;
		} else {
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
	}
}

void Line::drawDotted() {
	int dx, dy, p,x ,y, count;
	p=2*dy-dx;
	x=x1;y=y1;
	count=0;
	while (x1<=x2) {
		if (count%2==0) {
			Pixel(x,y).draw();
		}
		if (p<0) {
			p += 2*dy;
		} else {
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
		count++;
	}
}

void Line::drawDashed() {
	int dx, dy, p,x ,y, count;
	p=2*dy-dx;
	x=x1;y=y1;
	count=0;
	while (x1<=x2) {
		if (count%5<3) {
			Pixel(x,y).draw();
		}
		if (p<0) {
			p += 2*dy;
		} else {
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
		count++;
	}
}

void Line::drawDashDot() {
	int dx, dy, p,x ,y, count;
	p=2*dy-dx;
	x=x1;y=y1;
	count=0;
	while (x1<=x2) {
		if (count%7<3 || count%7==5) {
			Pixel(x,y).draw();
		}
		if (p<0) {
			p += 2*dy;
		} else {
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
		count++;
	}
}

void Line::drawThick() {
	int dx, dy, p,x ,y;
	p=2*dy-dx;
	x=x1;y=y1;
	while (x<=x2) {
		Pixel(x,y,3).draw();
		if (p<0) {
			p += 2*dy;
		} else {
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	Line SolidLine(-8,8,8,8,0);
	Line DottedLine(-8,6,8,6,1);
	Line DashedLine(-8,4,8,4,2);
	Line DashDotLine(-8,2,8,2,3);
	Line ThickLine(-8,0,8,0,4);
	
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
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
	glutCreateWindow("CG_PQ4");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	
	glutMainLoop();
	return 0;
}
