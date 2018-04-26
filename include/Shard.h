#ifndef SHARD_H
#define SHARD_H

#include <GL/glut.h>
#include "Vertex.h"

class Shard
{
    public:
        Shard();
        ~Shard();
        Shard(Vertex, Vertex, Vertex, GLfloat, GLfloat, GLfloat, GLfloat);
        Vertex getTop();                                                            ///Get top vertex values
        Vertex getMiddle();                                                         ///Get middle vertex values
        Vertex getBottom();                                                         ///Get bottom vertex values
        void setTop(Vertex);                                                        ///Set top vertex values
        void setMiddle(Vertex);                                                     ///Set middle vertex values
        void setBottom(Vertex);                                                     ///Set bottom vertex values
        void breakPart();                                                           ///Set shatter to true
        void displayValues();                                                       ///Display the values for top, middle, and bottom vertices
        GLboolean isBroken();                                                       ///Checks if shatter is true
        GLfloat getShardX();                                                        ///Get x plane position for translation
        GLfloat getShardY();                                                        ///Get y plane position for translation
        GLfloat getShardZ();                                                        ///Get z plane position for translation
        void setShardX(GLfloat);                                                    ///Set x plane position for translation
        void setShardY(GLfloat);                                                    ///Set y plane position for translation
        void setShardZ(GLfloat);                                                    ///Set z plane position for translation
        GLfloat initialDistance, rotateAngle, plateTime, time;
    private:
        Vertex top, middle, bottom;
        GLboolean shatter;
        GLfloat shardX, shardY, shardZ;
};

#endif // SHARD_H
