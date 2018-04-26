#include "Plate.h"

Plate::Plate()
{
    //ctor
}

Plate::~Plate()
{
    //dtor
}

Plate::Plate(GLfloat z, GLfloat tablePlateDistance, GLfloat angle)
{
    this->angle = angle;
    this->cameraZ = z;
    this->height = 0.0f;
    this->tablePlateDistance = tablePlateDistance;
    this->time = 0.0f;
    this->dropped = GL_FALSE;

    /// Middle Vertex for all Shards
    Vertex v1(0.0f, 0.0f, 0.0f);
    /// Shard 1
    Vertex v2(-1.0f, -1.0f, 0.0f);
    Vertex v3(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v2, v3, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 2
    Vertex v4(-1.5f, 0.0f, 0.0f);
    Vertex v5(-1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v4, v5, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 3
    Vertex v6(-1.0f, 1.0f, 0.0f);
    Vertex v7(-1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v6, v7, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 4
    Vertex v8(-1.0f, 1.0f, 0.0f);
    Vertex v9(0.0f, 1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v8, v9, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 5
    Vertex v10(1.0f, -1.0f, 0.0f);
    Vertex v11(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v10, v11, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 6
    Vertex v12(1.5f, 0.0f, 0.0f);
    Vertex v13(1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v12, v13, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 7
    Vertex v14(1.0f, 1.0f, 0.0f);
    Vertex v15(1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v14, v15, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));
    /// Shard 8
    Vertex v16(1.0f, 1.0f, 0.0f);
    Vertex v17(0.0f, 1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v16, v17, 0.0f, this->height, this->cameraZ, this->tablePlateDistance));

}

void Plate::draw()
{
    for(int i = 0; i < this->shards.size(); i++)
    {
        //cout<<this->time<<endl;
        glLoadIdentity();
        glTranslatef(this->shards.at(i).getShardX(), this->shards.at(i).getShardY(), this->shards.at(i).getShardZ());
        //glTranslatef(0.0f, this->height, this->cameraZ);
        glRotatef(this->angle, 1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glColor3f(0.9f, 0.9f, 0.9f);
        glVertex3f(this->shards.at(i).getMiddle().getX(), this->shards.at(i).getMiddle().getY(), this->shards.at(i).getMiddle().getZ());
        glVertex3f(this->shards.at(i).getTop().getX(), this->shards.at(i).getTop().getY(), this->shards.at(i).getTop().getZ());
        glVertex3f(this->shards.at(i).getBottom().getX(), this->shards.at(i).getBottom().getY(), this->shards.at(i).getBottom().getZ());
        glEnd();

        //this->shards.at(i).setShardX();
        this->shards.at(i).setShardY(this->height);
        //this->shards.at(i).setShardZ();
    }
    ///Reached the surface
    if(this->height < this->tablePlateDistance)
    {
        for(int i = 0; i < this->shards.size(); i++)
        {
            if(!this->shards.at(i).isBroken())
            {
                this->shards.at(i).breakPart();
                this->shards.at(i).plateTime = this->time;
                this->shards.at(i).rotateAngle = this->angle;
                cout<<"Shard rotate angle"<<i+1<<": "<<this->shards.at(i).rotateAngle<<endl;
                this->shards.at(i).displayValues();
                cout<<"Shard sx: "<<this->shards.at(i).getShardX()<<", sy: "<<this->shards.at(i).getShardY()<<", sz: "<<this->shards.at(i).getShardZ()<<endl<<endl;
            }
            else
            {
                if(this->shards.at(i).time < 0.2)
                {
                    this->shards.at(i).time += 0.1;
                    //if(this->shards.at(i))
                    this->shards.at(i).setShardX(this->shards.at(i).getShardX() + (this->shards.at(i).plateTime * i) * 0.001);
                    this->shards.at(i).setShardY(this->shards.at(i).getShardY() + (this->shards.at(i).plateTime * i) * 0.001);
                    this->shards.at(i).setShardZ(this->shards.at(i).getShardZ() + (this->shards.at(i).plateTime * i) * 0.001);
                }

            }
        }
    }
    ///Hasn't reached the surface
    else
    {
        if(this->angle > 360)
        {
            this->angle = 0.0;
        }
        else
        {
            this->angle += 2.0;
        }
        if(this->dropped)
        {
            this->time += 1;
            this->height -= 0.01 * (gravity*this->time);
        }
    }
}
