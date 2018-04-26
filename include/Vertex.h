#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glut.h>
#include <iostream>

using namespace std;

class Vertex
{
    public:
        Vertex();
        ~Vertex();
        Vertex(GLfloat, GLfloat, GLfloat);
        GLfloat getX();                         ///Get x value
        GLfloat getY();                         ///Get y value
        GLfloat getZ();                         ///Get z value
        void setX(GLfloat);                     ///Set x value
        void setY(GLfloat);                     ///Set y value
        void setZ(GLfloat);                     ///Set z value
        void displayValues();                   ///Display x, y, and z values
    private:
        GLfloat x, y, z;
};

#endif // VERTEX_H
