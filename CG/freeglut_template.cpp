//Code by Kokate Rushik
#include<GL/freeglut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//to draw
	
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
	glutCreateWindow("CG_PQ2");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	
	glutMainLoop();
	return 0;
}
