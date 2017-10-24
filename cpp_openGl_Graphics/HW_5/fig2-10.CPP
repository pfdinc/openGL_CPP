
#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include "glut.h"
const int screenWidth = 640;	   // width of screen window in pixels 
const int screenHeight = 480;	   // height of screen window in pixels
GLdouble A, B, C, D;  // values used for scaling and shifting
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
 	  glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	  glMatrixMode(GL_PROJECTION); 	   // set "camera shape"
	  glLoadIdentity();
	  gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 500.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight /500.0;
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glBegin(GL_LINE_STRIP);	
	for(GLfloat x = 0; x <= 600; x += 3)
  {	
	GLfloat   func = 300 - 100 * cos(2 * 3.14159265 * x / 100) + 30 * cos(4 * 3.14159265 * x / 100) + 6*cos(6*3.14159265*x/100);
     glVertex2d(A * x + B, C * func + D);
 		}
	glEnd();	
	glFlush();		   // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
}
