#include <iostream>
#include <glut.h>
#include <vector>
#include "Vector.h"
#include "Point.h"
#include"graphic.h"
#include "Distributor.h"
#define window 2
std::vector<Point> data;
Graphic engine(&data, window);
void idle()
{
	engine.update();
	glutPostRedisplay();
}
void display_molecules()
{
	engine.display_molecules();
	engine.draw_rect(0, 0, 0.1, 0.1, 1.0, 0, 0);
	engine.draw_rect(0.2, 0.2, 0.3, 0.3, 1.0, 1.0, 1.0);
	engine.draw_graphic();
	glutSwapBuffers();
}
int main(int argc, char ** argv) {
	Distributor d1(1);
	d1.set_num_of_directions(20);
	d1.fill(data, 10000);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(800*window, 800);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutCreateWindow("MY WINDOW");
	gluOrtho2D(0, 0, 100, 100);
	glutDisplayFunc(display_molecules);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}