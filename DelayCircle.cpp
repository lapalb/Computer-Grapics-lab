#include<iostream>
#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
using namespace std;

int r;

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0,1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150, 150, -150, 150);
}


void midPointCircleAlgo()
{
	for(int i=0;i<100;i+=10)
		{
			if(i==50){
				glFlush ();
				Sleep(3000);
				glClear(GL_COLOR_BUFFER_BIT);
			}
	int x = 0;
	int y = r+i;
	float decision = 5/4 - r;
	glVertex2i(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, y);
		glVertex2i(-x, -y);
		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, -x);
		glEnd();
		}
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	midPointCircleAlgo();
	glFlush ();
}

void main(int argc, char** argv)
{	
	//usleep();
	cout << "\nEnter radius : "; cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Circle centered at center");
	myInit ();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}
