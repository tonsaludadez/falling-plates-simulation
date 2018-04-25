#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Plate.h"

using namespace std;
char title[] = "Falling Plate Simulation";
GLfloat camera_z = -25.0f;
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

    plates.push_back(Plate(camera_z));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

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
        case 27:    //Escape
            cout<<"Pressed ESC"<<endl;
            exit(1);
        case 32:    //Space
            cout<<"Pressed Space"<<endl;
            for(int i = 0; i < plates.size(); i++)
            {
                if(!plates.at(i).dropped)
                {
                    cout<<"NOT DROPPED YET. DROPPING"<<endl;
                    plates.at(i).dropped = GL_TRUE;
                    break;
                }
                else
                {
                    cout<<"ALREADY DROPPED"<<endl;
                }
            }
            plates.push_back(Plate(camera_z));
            cout<<plates.size()<<endl;
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
   initGL();
   glutTimerFunc(0, timer, 0);
   glutMainLoop();
   return 0;
}
