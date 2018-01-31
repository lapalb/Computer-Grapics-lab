#include <Windows.h>
#include <GL\glut.h>
#include <bits/stdc++.h>


using namespace std;

void Draw() {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
                glColor3f(0.0, 0.502, 0.0);
                glVertex3f(0, 0, 0.0);
                glVertex3f(1.35, 0, 0.0);
                glVertex3f(1.35, 0.3, 0.0);
                glVertex3f(0, 0.3, 0.0);
                glColor3f(1.0, 1.0, 1.0);
                glVertex3f(0, 0.3, 0.0);
                glVertex3f(1.35, 0.3, 0.0);
                glVertex3f(1.35, 0.6, 0.0);
                glVertex3f(0, 0.6, 0.0);
                glColor3f(1.0, 0.502, 0.0);
                glVertex3f(0, 0.6, 0.0);
                glVertex3f(1.35, 0.6, 0.0);
                glVertex3f(1.35, 0.9, 0.0);
                glVertex3f(0, 0.9, 0.0);

        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(0.0, 0.0, 1.0);
        for(int ii = 0; ii < 100; ii++)
        {
                float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle

                float x = 0.15 * cosf(theta);//calculate the x component
                float y = 0.15 * sinf(theta);//calculate the y component

                glVertex3f(x + 0.625-0.15, y + 0.45,0.0);//output vertex

        }
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        for(int ii = 0; ii < 24; ii++)
        {
                float theta = 2.0f * 3.1415926f * float(ii) / float(24);//get the current angle

                float x = 0.15 * cosf(theta);//calculate the x component
                float y = 0.15 * sinf(theta);//calculate the y component


                float x1 = 0.15 * cosf(theta+3.1415926);//calculate the x component
                float y1 = 0.15 * sinf(theta+3.1415926);//calculate the y component

                glVertex3f(x+0.625-0.15, y+0.45,0.0);//output vertex
                glVertex3f(x1+0.625-0.15, y1+0.45,0.0);

        }
        glEnd();
        glFlush();
}

void Initialize() {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
        glutInit(&iArgc, cppArgv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(250, 250);
        glutInitWindowPosition(200, 200);
        glutCreateWindow("XoaX.net");
        Initialize();
        glutDisplayFunc(Draw);
        glutMainLoop();
        return 0;
}
