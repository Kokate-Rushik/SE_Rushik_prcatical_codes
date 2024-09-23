//Code by Kokate Rushik
#include<GL/freeglut.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Shape {
	public:
	virtual void draw() = 0;
	virtual void scanline() = 0;
};

class ConcavePoly : public Shape {
	protected:
	vector<pair<int, int>> vertices;
	float fillColor[3];
	
	public:
	ConcavePoly(const vector<pair<int, int>>& verts, const float color[3]) {
		vertices = verts;
		fillColor[0] = color[0];
		fillColor[1] = color[1];
		fillColor[2] = color[2];
	}
	
	void draw() override {
		glBegin(GL_LINE_LOOP);
		for (const auto& vertex : vertices) {
			glVertex2i(vertex.first, vertex.second);
		}
		glEnd();
		glFlush();
	}
	
	void scanline() override {
		int ymin = 10000, ymax = -10000;
		for (const auto& vertex : vertices) {
			ymin = min(ymin, vertex.second);
			ymax = max(ymax, vertex.second);
		}
		for (int y = ymin; y<=ymax; y++) {
			vector<int> xIntersect;
			
			for (size_t i=0; i<vertices.size(); i++) {
				size_t next = (i+1)%vertices.size();
				int x1=vertices[i].first;
				int y1=vertices[i].second;
				int x2=vertices[next].first;
				int y2=vertices[next].second;
				
				if (y1 == y2) continue;
				
				if (y>=min(y1,y2) && y<max(y1,y2)) {
					int x = x1 + (y-y1)*(x2-x1)/(y2-y1);
					xIntersect.push_back(x);
				}
			}
			sort(xIntersect.begin(),xIntersect.end());
			
			for (size_t i=0; i<xIntersect.size(); i+=2) {
				glColor3fv(fillColor);
				glBegin(GL_LINES);
				glVertex2i(xIntersect[i],y);
				glVertex2i(xIntersect[i+1],y);
				glEnd();
				glFlush();
			}
		}
	}
};

ConcavePoly* Polygon;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	Polygon->draw();
	Polygon->scanline();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,700,0,700);
}

int main(int argc, char** argv) {
	
	vector<pair<int, int>> vertices = {{100,100},{400,100},{400,500},{300,300},{100,400}};
	float color[3] = {1.0,0.0,0.0};
	Polygon = new ConcavePoly(vertices, color);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("CG_PQ1");
	
	init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	
	delete Polygon;	
	return 0;
}
