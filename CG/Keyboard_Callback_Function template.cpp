//Code by Kokate Rushik
#include<GL/freeglut.h>
#define ESCAPE 27

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//to draw
	
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-650,650,-650,650);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void myKeyboard(unsigned char key, int mouseX, int mouseY) {
	switch (key) {
		case 'i':
			glBegin(GL_LINES);
			glVertex2i(100,250);
			glVertex2i(300,250);
			glEnd();
			break;
		case 'r':
			glRecti(350,250,550,100);
			break;
		case 't':
			glBegin(GL_TRIANGLES);
			glVertex2i(100,300);
			glVertex2i(300,300);
			glVertex2i(200,500);
			glEnd();
			break;
		case 'p':
			glBegin(GL_LINE_LOOP);
			glVertex2i(100,175);
			glVertex2i(150,100);
			glVertex2i(250,100);
			glVertex2i(300,175);
			glVertex2i(200,250);
			glEnd();
			break;
		case 'f':
			glBegin(GL_POLYGON);
			glColor3f(1,0,0);glVertex3i(100,500,0);
			glColor3f(0,1,0);glVertex3i(300,500,0);
			glColor3f(0,0,1);glVertex3i(200,625,0);
			glEnd();
			break;
		case ESCAPE:
			exit(0);
	}
	glFlush();
}	
		

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(200,100);
	glutInitWindowSize(650,650);
	glutCreateWindow("Keyboard Callback Function");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(reshape);
	init();
	
	glutMainLoop();
	return 0;
}
