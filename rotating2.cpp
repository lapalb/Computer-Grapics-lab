#include<iostream>
#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
using namespace std;

int r;

void myInit (void)
{
        glClearColor(0.0, 0.0, 0.0,1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
		
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-150, 150, -150, 150);
}


void TranslatedSquareAlgo()
{  float tx=-100.0,ty=-100.0;
        
	
            //convert theta in degrees to
	//original square

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(0, 0);     // Define vertices in counter-clockwise (CCW) order
      glVertex2f(100, 0);     //  so that the normal (front-face) is facing you
      glVertex2f(100, 100);
      glVertex2f(0, 100);
	 glEnd();
	   glFlush ();
	    
	 glBegin(GL_POLYGON);
	 glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0+tx,0+ty);
    glVertex2f(100.0+tx, 0.0+ty);
    glVertex2f(100.0+tx, 100.0+ty);
    glVertex2f(0.0+tx, 100.0+ty);
	 glEnd();

        }
void myDisplay(void)
{
        glClear (GL_COLOR_BUFFER_BIT);
        TranslatedSquareAlgo();
        glFlush ();
}

void main(int argc, char** argv)
{        
        
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (320, 320);
        glutInitWindowPosition (50, 50);
        glutCreateWindow ("Translated Square");
        myInit ();
        glutDisplayFunc(myDisplay);
        glutMainLoop();

}
