#include "Shard.h"

Shard::Shard()
{
    //ctor
}

Shard::~Shard()
{
    //dtor
}

Shard::Shard(Vertex top, Vertex middle, Vertex bottom)
{
    this->setTop(top);
    this->setMiddle(middle);
    this->setBottom(bottom);
    this->shatter = GL_FALSE;
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

void Shard::display_values()
{
    cout<<"TOP: ";
    this->getTop().display_values();
    cout<<"MIDDLE: ";
    this->getMiddle().display_values();
    cout<<"BOTTOM: ";
    this->getBottom().display_values();
}
