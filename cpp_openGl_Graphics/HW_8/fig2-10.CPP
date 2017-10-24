
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <iostream>
#include "glut.h"

void Display();

void Init(void);

struct GLintPoint {
GLint x,y;};



class GLintPointArray{

	static const int MAX_NUM = 1000;
	public:
   	int num;
		GLintPoint pt[MAX_NUM];
};
void drawPolyLine(GLintPointArray, int);

void main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 960);
	glutInitWindowPosition(0,0);
	glutCreateWindow("my first attempt");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();
}

void Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);	
	GLintPointArray p;
	p.num = 11;

	p.pt[0].x = 200;
	p.pt[0].y = 250;

	p.pt[1].x = 240;
	p.pt[1].y = 330;

	p.pt[2].x = 280;
	p.pt[2].y = 250;

	p.pt[3].x = 350;
	p.pt[3].y = 250;

	p.pt[4].x = 290;
	p.pt[4].y = 210;

	p.pt[5].x = 340;
	p.pt[5].y = 140;

	p.pt[6].x = 240;
	p.pt[6].y = 180;

	p.pt[7].x = 140;
	p.pt[7].y = 140;

	p.pt[8].x = 190;
	p.pt[8].y = 210;

	p.pt[9].x = 130;
	p.pt[9].y = 250;

	p.pt[10].x = 200;
	p.pt[10].y = 250;		
	
		drawPolyLine(p, 0);
	

   glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(0.0f,0.0f,0.0f);
   glPointSize(1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(1.0,640.0,0.0,480.0);
}

void drawPolyLine(GLintPointArray poly, int closed)
{	
	if (closed){
	glBegin(GL_LINE_LOOP);
	}
glBegin(GL_LINE_STRIP);
for(int i = 0; i < poly.num; i++){
	
glVertex2i(poly.pt[i].x, poly.pt[i].y);
}

glEnd();
glFlush();


}