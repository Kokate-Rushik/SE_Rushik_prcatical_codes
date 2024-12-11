//Code by Kokate Rushik
#include <graphics.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Shape {
	public:
	virtual void draw() = 0;
	virtual void scanline() = 0;
};

class ConcavePoly : public Shape {
	protected:
	vector<pair<int, int>> vertices;
	int fillColor;

	public:
	ConcavePoly(const vector<pair<int, int>>& verts, int color) {
		vertices = verts;
		fillColor = color;
	}
	
	void draw() override {
		for (size_t i = 0; i < vertices.size(); ++i) {
			size_t next = (i + 1) % vertices.size();
			line(vertices[i].first, vertices[i].second, vertices[next].first, vertices[next].second);
		}
	}
	
	void scanline() override {
		int ymin = 10000, ymax = -10000;
		for (const auto& vertex : vertices) {
			ymin = min(ymin, vertex.second);
			ymax = max(ymax, vertex.second);
		}

		for (int y = ymin; y <= ymax; y++) {
			vector<int> xIntersect;
			
			for (size_t i = 0; i < vertices.size(); i++) {
				size_t next = (i + 1) % vertices.size();
				int x1 = vertices[i].first;
				int y1 = vertices[i].second;
				int x2 = vertices[next].first;
				int y2 = vertices[next].second;
				
				if (y1 == y2) continue;
				
				if (y >= min(y1, y2) && y < max(y1, y2)) {
					int x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
					xIntersect.push_back(x);
				}
			}

			sort(xIntersect.begin(), xIntersect.end());
			
			for (size_t i = 0; i < xIntersect.size(); i += 2) {
				setcolor(fillColor);
				line(xIntersect[i], y, xIntersect[i + 1], y);
			}
		}
	}
};

ConcavePoly* Polygon;

void display() {
	cleardevice();
	Polygon->draw();
	Polygon->scanline();
}

int main() {
	vector<pair<int, int>> vertices = {{100, 100}, {400, 100}, {400, 500}, {300, 300}, {100, 400}};
	int color = RED; // Define a color using BGI color constants
	Polygon = new ConcavePoly(vertices, color);

	int gd = X11, gm = X11_1024x768;
    initgraph(&gd, &gm, (char*)"");
	display();
	
	getch(); // Wait for user input
	closegraph();
	delete Polygon;	
	return 0;
}

