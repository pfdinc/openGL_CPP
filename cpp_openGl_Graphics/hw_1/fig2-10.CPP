#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
/*#include <iostream.h> */
#include "glut.h"
void Display();
void Init(void);
void Sierpinski();
void drawDot(GLint, GLint);

struct GLintPoint{
GLfloat x, y;
};

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
	glBegin(GL_POINTS);
			Sierpinski();
   glEnd();
   glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(0.0f,0.0f,0.0f);
   glPointSize(2.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(1.0,640.0,0.0,480.0);
}


void Sierpinski(void) 
{
	GLintPoint T[3]= {{10,10},{300,30},{200, 300}};
	
	int index = rand() % 3;         // 0, 1, or 2 equally likely 
	GLintPoint point = T[index]; 	 // initial point 
	drawDot(point.x, point.y);     // draw initial point 
	for(int i = 0; i < 100000; i++)  // draw 1000 dots
	{
		 index = rand()%3; 	
		 point.x = (point.x + T[index].x) / 2;
		 point.y = (point.y + T[index].y) / 2;
		 drawDot(point.x,point.y);  
	} 
	glFlush(); 	
}

void drawDot(GLint x, GLint y){
	glBegin(GL_POINTS);
		glVertex2i( x, y);
	glEnd();


}