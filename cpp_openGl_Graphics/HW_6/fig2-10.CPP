
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
/*#include <iostream.h> */
#include "glut.h"
void Display();
void Init(void);
void hardwiredHouse();
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
	
			hardwiredHouse();
   
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



void hardwiredHouse(void)
{
	int scale = 3;
	glBegin(GL_LINE_LOOP);
		glVertex2i(40*scale, 40*scale);	// draw the shell of house 
		glVertex2i(40*scale, 80*scale);
		glVertex2i(70*scale, 110*scale);
		glVertex2i(100*scale, 80*scale);
		glVertex2i(100*scale, 40*scale);
	glEnd();
	glBegin(GL_LINE_STRIP); 
		glVertex2i(50*scale, 90*scale);	// draw the chimney 
		glVertex2i(50*scale, 110*scale);
		glVertex2i(60*scale, 110*scale);
		glVertex2i(60*scale, 100*scale);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(50*scale,40*scale);
	glVertex2i(50*scale,60*scale);
	glVertex2i(60*scale,60*scale);
	glVertex2i(60*scale, 40*scale);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(80*scale,55*scale);
	glVertex2i(80*scale,65*scale);

	glVertex2i(90*scale,65*scale);
	glVertex2i(90*scale, 55*scale);
	
	glEnd();

		// draw the door 
		// draw the window 
}
