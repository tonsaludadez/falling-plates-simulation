#ifndef PLATE_H
#define PLATE_H

#include <vector>
#include "Shard.h"

using namespace std;

class Plate
{
    public:
        Plate();
        ~Plate();
        Plate(GLfloat, GLfloat, GLfloat);
        const static GLfloat gravity = 9.8f;
        vector<Shard> shards;
        GLfloat angle, cameraZ, height, tablePlateDistance, time;
        GLboolean dropped;
        void draw();
};

#endif // PLATE_H
