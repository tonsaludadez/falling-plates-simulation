#include "Plate.h"

Plate::Plate()
{
    //ctor
}

Plate::~Plate()
{
    //dtor
}

Plate::Plate(GLfloat z)
{
    /// Middle Vertex for all Shards
    Vertex v1(0.0f, 0.0f, 0.0f);
    /// Shard 1
    Vertex v2(-1.0f, -1.0f, 0.0f);
    Vertex v3(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v2, v3));
    /// Shard 2
    Vertex v4(-1.5f, 0.0f, 0.0f);
    Vertex v5(-1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v4, v5));
    /// Shard 3
    Vertex v6(-1.0f, 1.0f, 0.0f);
    Vertex v7(-1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v6, v7));
    /// Shard 4
    Vertex v8(-1.0f, 1.0f, 0.0f);
    Vertex v9(0.0f, 1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v8, v9));
    /// Shard 5
    Vertex v10(1.0f, -1.0f, 0.0f);
    Vertex v11(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v10, v11));
    /// Shard 6
    Vertex v12(1.5f, 0.0f, 0.0f);
    Vertex v13(1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v12, v13));
    /// Shard 7
    Vertex v14(1.0f, 1.0f, 0.0f);
    Vertex v15(1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v14, v15));
    /// Shard 8
    Vertex v16(1.0f, 1.0f, 0.0f);
    Vertex v17(0.0f, 1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v16, v17));

    this->angle = 0.0f;
    this->camera_z = z;
    this->height = 0.0f;
    this->time = 0.0f;
    this->dropped = GL_FALSE;
}

void Plate::draw()
{
    for(int i = 0; i < this->shards.size(); i++)
    {
        //cout<<this->time<<endl;
        glLoadIdentity();
        glTranslatef(0.0f, this->height, this->camera_z);
        glRotatef(this->angle, 1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(this->shards.at(i).getMiddle().getX(), this->shards.at(i).getMiddle().getY(), this->shards.at(i).getMiddle().getZ());
        glVertex3f(this->shards.at(i).getTop().getX(), this->shards.at(i).getTop().getY(), this->shards.at(i).getTop().getZ());
        glVertex3f(this->shards.at(i).getBottom().getX(), this->shards.at(i).getBottom().getY(), this->shards.at(i).getBottom().getZ());
        glEnd();
    }
    this->angle -= 2.0;
    if(this->dropped)
    {
        this->time += 1;
        //int velocity = (0.05*this->gravity)*(this->time*this->time); ///m/s^2
        this->height -= 0.01 * (gravity*this->time);
        cout<<gravity*this->time<<endl;
        //this->height -= 0.01;
    }
}
