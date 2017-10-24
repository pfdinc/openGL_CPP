
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
/*#include <iostream.h> */
#include "glut.h"
void Display();

void Init(void);

struct GLintPoint {
GLint x,y;};

void parameterizedHouse(GLintPoint,GLint,GLint);
class GLintPointArray{

	static const int MAX_NUM = 1000;
	public:
   	int num;
		GLintPoint pt[MAX_NUM];
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
	
	GLintPoint p;
	p.x = 320;
	p.y = 240;
	parameterizedHouse(p,200,200);
	
			
   
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



void parameterizedHouse(GLintPoint peak, GLint width, GLint height)
 // the top of house is at the peak; the size of house is given
 //  by height and width
{
	glBegin(GL_LINE_LOOP);
	  glVertex2i(peak.x,             peak.y);  // draw shell of house 
	  glVertex2i(peak.x + width / 2, peak.y - 3 * height /8);
	  glVertex2i(peak.x + width / 2,  peak.y -     height);
	  glVertex2i(peak.x - width / 2, peak.y -     height);
	  glVertex2i(peak.x - width / 2, peak.y - 3 * height /8);	
	glEnd();
	 
	glBegin(GL_LINE_STRIP); //draw the Chimney
	glVertex2i(peak.x - width / 3, peak.y - 3 * height /12);
	glVertex2i(peak.x - width / 3, (peak.y - 3 * height /12) + height/3);
	glVertex2i((peak.x - width / 3) + width /8, (peak.y - 3 * height /12) + height/3);
	glVertex2i((peak.x - width / 3) + width /8, (peak.y - 3 * height /12) + height/10);
	glEnd();

glBegin(GL_LINE_STRIP); //draw the door
	
	glVertex2i(peak.x - width / 3, peak.y - 3 * height/3);
	glVertex2i(peak.x - width / 3, peak.y - 3 * height/4);
	glVertex2i(peak.x - width / 5, peak.y - 3 * height/4);
	glVertex2i(peak.x - width / 5, peak.y - 3 * height/3);

glEnd();
		
glBegin(GL_LINE_LOOP); //Window
	
	glVertex2i(peak.x + width / 5, peak.y - 3 * height/4.5);
	glVertex2i(peak.x + width / 5, peak.y - 3 * height/6);
	glVertex2i(peak.x + width / 3, peak.y - 3 * height/6);
	glVertex2i(peak.x + width / 3, peak.y - 3 * height/4.5);

	

glEnd();



	

	
}
