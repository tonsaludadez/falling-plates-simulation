#include "Vertex.h"

Vertex::Vertex()
{
    //ctor
}

Vertex::~Vertex()
{
    //dtor
}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

GLfloat Vertex::getX()
{
    return this->x;
}

GLfloat Vertex::getY()
{
    return this->y;
}

GLfloat Vertex::getZ()
{
    return this->z;
}

void Vertex::setX(GLfloat x)
{
    this->x = x;
}

void Vertex::setY(GLfloat y)
{
    this->y = y;
}

void Vertex::setZ(GLfloat z)
{
    this->z = z;
}

void Vertex::displayValues()
{
    cout<<"x: "<<this->getX()<<" , y: "<<this->getY()<<" , z: "<<this->getZ()<<endl;
}
