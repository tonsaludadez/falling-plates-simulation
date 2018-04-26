#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <typeinfo>
#include <math.h>
#include <vector>
#include "Plate.h"

using namespace std;
char title[] = "Falling Plate Simulation";
GLfloat cameraZ = -25.0f;
GLfloat tablePlateDistance = cameraZ/5.0f;

int refreshMills = 15;
vector<Plate> plates;

void initGL()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    plates.push_back(Plate(cameraZ, tablePlateDistance, 0.0f));
}

void drawFloor()
{
    glLoadIdentity();
    glTranslatef(0.0f, tablePlateDistance-2.0f, cameraZ);
    glBegin(GL_QUADS);

    //FRONT
    glColor3f(0.3f,0.0f,0.0f);
    glVertex3f(10.0f, 1.0f, 5.0f);
    glVertex3f(-10.0f, 1.0f, 5.0f);
    glVertex3f(-10.0f, -1.0f, 5.0f);
    glVertex3f(10.0f, -1.0f, 5.0f);

    //LEFT
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-10.0f, 1.0f, 5.0f);
    glVertex3f(-10.0f, 1.0f, -5.0f);
    glVertex3f(-10.0f, -1.0f, -5.0f);
    glVertex3f(-10.0f, -1.0f, 5.0f);

    //RIGHT
    //glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(10.0f, 1.0f, -5.0f);
    glVertex3f(10.0f, 1.0, 5.0f);
    glVertex3f(10.0f, -1.0, 5.0f);
    glVertex3f(10.0f, -1.0, -5.0f);

    //TOP
    //glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(10.0f, 1.0f, -5.0f);
    glVertex3f(-10.0f, 1.0f, -5.0f);
    glVertex3f(-10.0f, 1.0f, 5.0f);
    glVertex3f(10.0f, 1.0f, 5.0f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    drawFloor();

    for(int i = 0; i < plates.size(); i++)
    {
        plates.at(i).draw();
    }

    glutSwapBuffers();
}

void timer(int value)
{
   glutPostRedisplay();
   glutTimerFunc(refreshMills, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void onclick(int button, int state, int x, int y)
{
    cout<<"Button: "<<button<< " | State: "<<state<<" | X,Y: "<<x<<","<<y<<endl;
}

void onpress(unsigned char key, int x, int y)
{
    switch(key){
        case 27:    ///Escape
            cout<<"Pressed ESC"<<endl;
            exit(1);
        case 32:    ///Space
            cout<<"Pressed SPACE"<<endl;
            for(int i = 0; i < plates.size(); i++)
            {
                if(!plates.at(i).dropped)
                {
                    //cout<<"NOT DROPPED YET. DROPPING"<<endl;
                    plates.at(i).dropped = GL_TRUE;
                    plates.push_back(Plate(cameraZ, tablePlateDistance, plates.at(i).angle));
                    break;
                }
                else
                {
                    //cout<<"ALREADY DROPPED"<<endl;
                }
            }

            cout<<plates.size()<<endl;
            break;
    }
}

void onpressSpecial(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT :
		    cout<<"Pressed LEFT"<<endl;
			break;
		case GLUT_KEY_RIGHT :
		    cout<<"Pressed RIGHT"<<endl;
			break;
		case GLUT_KEY_UP :
		    cout<<"Pressed UP"<<endl;
			break;
		case GLUT_KEY_DOWN :
		    cout<<"Pressed DOWN"<<endl;
			break;
	}
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(1500, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow(title);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(onclick);
   glutKeyboardFunc(onpress);
   glutSpecialFunc(onpressSpecial);
   initGL();
   glutTimerFunc(0, timer, 0);
   glutMainLoop();
   return 0;
}
