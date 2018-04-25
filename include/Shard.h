#ifndef SHARD_H
#define SHARD_H

#include <GL/glut.h>
#include "Vertex.h"

class Shard
{
    public:
        Shard();
        ~Shard();
        Shard(Vertex, Vertex, Vertex);
        Vertex getTop();
        Vertex getMiddle();
        Vertex getBottom();
        void setTop(Vertex);
        void setMiddle(Vertex);
        void setBottom(Vertex);
        void breakPart();
        void display_values();
    private:
        Vertex top, middle, bottom;
        GLboolean shatter;
};

#endif // SHARD_H
