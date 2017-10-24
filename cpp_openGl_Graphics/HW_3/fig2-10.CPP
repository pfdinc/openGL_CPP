
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
/*#include <iostream.h> */
#include "glut.h"
void Display();
void Init(void);
void drawLine(GLint, GLint, GLint, GLint);

void main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Drawing tick-tac-toe");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
			glVertex2i(100, 400);
			glVertex2i(100, 200);

			glVertex2i(150, 400);
			glVertex2i(150, 200);

			glVertex2i(50, 325);
			glVertex2i(200, 325);

			glVertex2i(50, 275);
			glVertex2i(200, 275);

			
   glEnd();
   glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(0.0f,0.0f,0.0f);
   glPointSize(50.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(1.0,640.0,0.0,480.0);
}

void drawLine(GLint x1, GLint x2, GLint y1, GLint y2){
glBegin (GL_LINES);
glVertex2i(x1,y1);
glEnd();

}
