#include< GL/glut.h > 
#include< iostream >
using namespace std;
float x,y,x2,y2,x3,y3,x4,y4,m,c;

void init(void) {
  glPointSize(5);
  glClearColor(1,1,1,0.5);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  gluOrtho2D(-100, 100, -100, 100);
}
void display()
{
	float d;
	//Calculating The reflected point x2,y2
	d= (x + (y - c)*m)/(1 + m*m);
	x2 = 2*d - x;
	y2 = 2*d*m - y + 2*c;
	//Axes
	glBegin(GL_LINES);
	glVertex2i(100,0);
	glVertex2i(-100,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(0,100);
	glVertex2i(0,-100);
	glEnd();
	//Axes End

	//Line Start. Line end point is the parameter that is given in Ortho2D(one is 100 and other is -100 and we calculate the y coordinate
	x3=100.0;
	x4=-100.0;
	y3=m*x3 + c;
	y4=m*x4 +c;
	cout<<x3<<y3;
	glBegin(GL_LINES);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
	glEnd();
	glFlush();
	//line End

	//Original Point
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
	//End of original Point

	//Reflected Point Plot
	glBegin(GL_POINTS);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();

}

int main(int argc, char** argv)
{
	  
	  cout<<"Enter a and b\n";
	 cin>>x>>y;
	 cout<<"Enter slope and intercept\n";
	 cin>>m>>c;
	 glutInit(&argc, argv);
	 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowSize (500, 500);
	 glutInitWindowPosition (0,0);
	 glutCreateWindow ("Reflection");
	 init ();
	 glutDisplayFunc(display);
	 glutMainLoop();
	 return 0;
}

