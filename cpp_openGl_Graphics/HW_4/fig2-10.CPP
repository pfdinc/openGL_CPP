
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
/*#include <iostream.h> */
#include "glut.h"
void Display();
void Init(void);
void drawPolyLine();
void drawPolygon();
void main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first attempt");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLine();
	drawPolygon();
   glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(0.0f,0.0f,0.0f);
   glPointSize(4.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(1.0,640.0,0.0,480.0);
}

void drawPolyLine(){
	glBegin(GL_LINE_STRIP);
	glVertex2i(50,100);
	glVertex2i(250,100);

	glVertex2i(250, 100);
	glVertex2i(50,350);

	glVertex2i(50,350);
	glVertex2i(250, 350);
	glEnd();
}

void drawPolygon(){
	glBegin(GL_LINE_LOOP);
	glVertex2i(350,100);
	glVertex2i(550,100);

	glVertex2i(550,100);
	glVertex2i(350,350);

	glVertex2i(350,350);
	glVertex2i(550,350);
	glEnd();
}