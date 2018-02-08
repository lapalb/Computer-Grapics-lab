#include< GL/glut.h > 
#include< iostream >
using namespace std;

float a, b;
void drawDot(GLint x, GLint y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void symmetricPixels(int x, int y) {
  drawDot(x, y);
  drawDot(-x, y);
  drawDot(x, -y);
  drawDot(-x, -y);
}
void ellipse(int a, int b);
void circle(int a) {
  ellipse(a, a);
  int z = a;
  while (z > 20) {
    z = z - 20;
    ellipse(a, z);
    ellipse(z, a);
  }
}
void display() {
    //ellipse(a,b);
    //ellipse(a-20,b);
    //ellipse(a-40,b);
    circle(a);
}
void ellipse(int a, int b)
{

int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;

  aSq = a*a;
  bSq = b*b;
  twoASq = 2*aSq;
  twoBSq = 2*bSq;
  d = bSq - b*aSq + aSq/4; //Decision parameter
  dx = 0;
  dy = twoASq*b;
  x = 0;
  y = b;
  symmetricPixels(x,y);
  while (dx < dy)
  { x++;
    dx += twoBSq;
    if (d >= 0)
    { y--;
      dy -= twoASq;
    }
    if (d < 0)
     d += bSq + dx;
    else
     d += bSq + dx - dy;
    symmetricPixels (x,y);
  }
  d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
                 aSq*bSq);
  while (y > 0)
  { y--;
    dy -= twoASq;
    if (d <= 0)
    { x++;
      dx += twoBSq;
    }
    if (d > 0)
         d += aSq - dy;
    else
         d += aSq -dy +dx;
    symmetricPixels(x,y);
  }
  glFlush();
}    
void init(void) {
  glPointSize(2);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.5, 0.5);
  gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv)
{
 cout<<"Enter a and b\n";
 cin>>a>>b;
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0,0);
 glutCreateWindow ("Ellipse : Mid point algorithm ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

