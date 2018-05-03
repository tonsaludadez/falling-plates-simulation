#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <math.h>
#include <vector>
#include "Plate.h"

using namespace std;
char title[] = "Falling Plate Simulation";
char s[50];
GLfloat cameraZ = -10.0f;
GLfloat tablePlateDistance = cameraZ/5.0f;

int refreshMills = 15;
vector<Plate> plates;

void drawFloor()
{
    glLoadIdentity();
    glTranslatef(0.0f, tablePlateDistance-2.0, cameraZ);
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
    glVertex3f(10.0f, 1.0f, -5.0f);
    glVertex3f(10.0f, 1.0, 5.0f);
    glVertex3f(10.0f, -1.0, 5.0f);
    glVertex3f(10.0f, -1.0, -5.0f);

    //TOP
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

void keyboardNormal(unsigned char key, int x, int y)
{
    switch(key){
        case 27:    ///Escape
            exit(1);
        case 32:    ///Space
            for(int i = 0; i < plates.size(); i++)
            {
                if(!plates.at(i).dropped)
                {
                    plates.at(i).dropped = GL_TRUE;
                    plates.push_back(Plate(cameraZ, tablePlateDistance, plates.at(i).angle));
                    break;
                }
            }
            break;
        case 8:    ///Backspace
            while(plates.size() > 0)
            {
                plates.pop_back();
            }
            plates.push_back(Plate(cameraZ, tablePlateDistance, 0.0));
            break;
    }
}

void keyboardSpecial(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_UP :
		    if(cameraZ != -94)
            {
                cameraZ -= 1;
                tablePlateDistance = cameraZ/5.0f;
                for(int i = 0; i < plates.size(); i++)
                {
                    plates.at(i).setCameraZ(cameraZ);
                    if(plates.at(i).shards.at(0).isBroken() or plates.at(i).shards.at(0).isDropped())
                    {
                        plates.at(i).setHeight(tablePlateDistance);
                    }
                }
            }
			break;
		case GLUT_KEY_DOWN :
		    if(cameraZ != -10)
            {
                cameraZ += 1;
                tablePlateDistance = cameraZ/5.0f;
                for(int i = 0; i < plates.size(); i++)
                {
                    plates.at(i).setCameraZ(cameraZ);
                    if(plates.at(i).shards.at(0).isBroken() or plates.at(i).shards.at(0).isDropped())
                    {
                        plates.at(i).setHeight(tablePlateDistance);
                    }
                }
            }
			break;
	}
}

void initGL()
{
    //glClearColor(0.8f, 0.8f, 1.0f, 1.0f);   /// Blue sky
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   /// Black sky
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glutKeyboardFunc(keyboardNormal);
    glutSpecialFunc(keyboardSpecial);

    glutTimerFunc(0, timer, 0);

    /// Create 1st plate
    plates.push_back(Plate(cameraZ, tablePlateDistance, 0.0f));
    ///plates.push_back(Plate(cameraZ, tablePlateDistance, 90.0f));
    ///plates.push_back(Plate(cameraZ, tablePlateDistance, 240.0f));
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

   initGL();

   glutMainLoop();
   return 0;
}
