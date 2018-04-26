#include "Shard.h"

Shard::Shard()
{
    //ctor
}

Shard::~Shard()
{
    //dtor
}

Shard::Shard(Vertex top, Vertex middle, Vertex bottom, GLfloat shardX, GLfloat shardY, GLfloat shardZ, GLfloat initialDistance, GLfloat rotateAngle)
{
    this->setTop(top);
    this->setMiddle(middle);
    this->setBottom(bottom);
    this->shatter = GL_FALSE;
    this->setShardX(shardX);
    this->setShardY(shardY);
    this->setShardZ(shardZ);
    this->initialDistance = initialDistance;
    this->plateTime = 0.0f;
    this->time = 0.0f;
    this->rotateAngle = rotateAngle;
}

Vertex Shard::getTop()
{
    return this->top;
}

Vertex Shard::getMiddle()
{
    return this->middle;
}

Vertex Shard::getBottom()
{
    return this->bottom;
}

void Shard::setTop(Vertex top)
{
    this->top = top;
}

void Shard::setMiddle(Vertex middle)
{
    this->middle = middle;
}

void Shard::setBottom(Vertex bottom)
{
    this->bottom = bottom;
}

void Shard::breakPart()
{
    this->shatter = GL_TRUE;
}

void Shard::displayValues()
{
    cout<<"TOP: ";
    this->getTop().displayValues();
    cout<<"MIDDLE: ";
    this->getMiddle().displayValues();
    cout<<"BOTTOM: ";
    this->getBottom().displayValues();
}

GLboolean Shard::isBroken()
{
    return this->shatter;
}

GLfloat Shard::getShardX()
{
    return this->shardX;
}

GLfloat Shard::getShardY()
{
    return this->shardY;
}

GLfloat Shard::getShardZ()
{
    return this->shardZ;
}

void Shard::setShardX(GLfloat shardX)
{
    this->shardX = shardX;
}

void Shard::setShardY(GLfloat shardY)
{
    this->shardY = shardY;
}

void Shard::setShardZ(GLfloat shardZ)
{
    this->shardZ = shardZ;
}
