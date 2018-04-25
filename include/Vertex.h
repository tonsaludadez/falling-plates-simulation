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
        GLfloat getX();
        GLfloat getY();
        GLfloat getZ();
        void setX(GLfloat);
        void setY(GLfloat);
        void setZ(GLfloat);
        void display_values();
    private:
        GLfloat x, y, z;
};

#endif // VERTEX_H
