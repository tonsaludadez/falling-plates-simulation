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

    /// INSIDE SHARDS
    /// Middle Vertex for all Shards
    Vertex v1(0.0f, 0.0f, 0.0f);
    /// Shard 1
    Vertex v2(-1.0f, -1.0f, 0.0f);
    Vertex v3(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v2, v3, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 2
    Vertex v4(-1.5f, 0.0f, 0.0f);
    Vertex v5(-1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v4, v5, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 3
    Vertex v6(-1.0f, 1.0f, 0.0f);
    Vertex v7(-1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v6, v7, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 4
    Vertex v8(-1.0f, 1.0f, 0.0f);
    Vertex v9(0.0f, 1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v8, v9, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 5
    Vertex v10(1.0f, -1.0f, 0.0f);
    Vertex v11(0.0f, -1.5f, 0.0f);
    this->shards.push_back(Shard(v1, v10, v11, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 6
    Vertex v12(1.5f, 0.0f, 0.0f);
    Vertex v13(1.0f, -1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v12, v13, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 7
    Vertex v14(1.0f, 1.0f, 0.0f);
    Vertex v15(1.5f, 0.0f, 0.0f);
    this->shards.push_back(Shard(v1, v14, v15, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 8
    Vertex v16(0.0f, 1.5f, 0.0f);
    Vertex v17(1.0f, 1.0f, 0.0f);
    this->shards.push_back(Shard(v1, v16, v17, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// OUTSIDE SHARDS
    /// Shard 9
    Vertex v18(-2.0f, -1.0f, 0.4f);
    Vertex v19(-1.0f, -2.0f, 0.4f);
    this->shards.push_back(Shard(v2, v18, v19, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 10
    Vertex v20(-2.0f, 1.0f, 0.4f);
    Vertex v21(-2.0f, -1.0f, 0.4f);
    this->shards.push_back(Shard(v4, v20, v21, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 11
    Vertex v22(-1.0f, 2.0f, 0.4f);
    Vertex v23(-2.0f, 1.0f, 0.4f);
    this->shards.push_back(Shard(v6, v22, v23, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 12
    Vertex v24(-1.0f, 2.0f, 0.4f);
    Vertex v25(1.0f, 2.0f, 0.4f);
    this->shards.push_back(Shard(v9, v24, v25, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 13
    Vertex v26(1.0f, 2.0f, 0.4f);
    Vertex v27(2.0f, 1.0f, 0.4f);
    this->shards.push_back(Shard(v14, v26, v27, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 14
    Vertex v28(2.0f, 1.0f, 0.4f);
    Vertex v29(2.0f, -1.0f, 0.4f);
    this->shards.push_back(Shard(v12, v28, v29, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 15
    Vertex v30(2.0f, -1.0f, 0.4f);
    Vertex v31(1.0f, -2.0f, 0.4f);
    this->shards.push_back(Shard(v10, v30, v31, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 16
    Vertex v32(-1.0f, -2.0f, 0.4f);
    Vertex v33(1.0f, -2.0f, 0.4f);
    this->shards.push_back(Shard(v3, v32, v33, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    ///INVERTED OUTSIDE SHARDS
    /// Shard 17
    this->shards.push_back(Shard(v18, v4, v2, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 18
    this->shards.push_back(Shard(v20, v6, v4, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 19
    this->shards.push_back(Shard(v22, v9, v6, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 20
    this->shards.push_back(Shard(v25, v14, v9, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 21
    this->shards.push_back(Shard(v27, v14, v12, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 22
    this->shards.push_back(Shard(v29, v12, v10, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 23
    this->shards.push_back(Shard(v33, v10, v3, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
    /// Shard 24
    this->shards.push_back(Shard(v32, v2, v3, 0.0f, this->height, this->cameraZ, this->tablePlateDistance, this->angle));
}

void Plate::setCameraZ(GLfloat cameraZ)
{
    this->cameraZ = cameraZ;
    this->tablePlateDistance = this->cameraZ/5.0f;
    for(int i=0; i < this->shards.size(); i++)
    {
        this->shards.at(i).setShardZ(this->cameraZ);
        this->shards.at(i).initialDistance = this->tablePlateDistance;
    }
}

void Plate::setHeight(GLfloat height)
{
    this->height = height;
    for(int i=0; i < this->shards.size(); i++)
    {
        this->shards.at(i).setShardY(this->height);
    }
}

void Plate::draw()
{
    for(int i = 0; i < this->shards.size(); i++)
    {
        if(this->shards.at(i).isDropped() or this->shards.at(i).isBroken())
        {
            ///DO NOTHING
            //cout<<this->angle<<endl;
        }
        else
        {
            this->shards.at(i).rotateAngle = this->angle;
        }
        glLoadIdentity();
        glTranslatef(this->shards.at(i).getShardX(), this->shards.at(i).getShardY(), this->shards.at(i).getShardZ());
        glRotatef(this->shards.at(i).rotateAngle, 1.0f, 0.0f, 0.0f);
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
    if(this->height <= this->tablePlateDistance+0.2 && this->tablePlateDistance <= -10)
    {
        for(int i = 0; i < this->shards.size(); i++)
        {
            if(!this->shards.at(i).isDropped())
            {

                if(!this->shards.at(i).isBroken())
                {
                    this->shards.at(i).breakPart();
                    this->shards.at(i).plateTime = this->time;
                }
                else
                {
                    if(this->shards.at(i).time < 0.2)
                    {
                        this->shards.at(i).time += 0.1;
                        //if(this->shards.at(i))
                        if(i%2==0)
                        {
                            this->shards.at(i).setShardX(this->shards.at(i).getShardX() - (this->shards.at(i).plateTime * i) * 0.003);
                            this->shards.at(i).setShardY(this->shards.at(i).getShardY() - (this->shards.at(i).plateTime * i) * 0.003);
                            this->shards.at(i).setShardZ(this->shards.at(i).getShardZ() - (this->shards.at(i).plateTime * i) * 0.003);
                        }
                        else
                        {
                            this->shards.at(i).setShardX(this->shards.at(i).getShardX() + (this->shards.at(i).plateTime * i) * 0.003);
                            this->shards.at(i).setShardY(this->shards.at(i).getShardY() + (this->shards.at(i).plateTime * i) * 0.003);
                            this->shards.at(i).setShardZ(this->shards.at(i).getShardZ() + (this->shards.at(i).plateTime * i) * 0.003);
                        }
                    }
                    else
                    {
                        ///Make the shards flat
                        this->shards.at(i).setShardY(this->tablePlateDistance);
                        this->shards.at(i).rotateAngle = 90;
                    }
                }
            }
        }
    }
    ///If distance is less than 10
    else if(this->height <= this->tablePlateDistance+0.2 && this->tablePlateDistance > -10)
    {
        for(int i = 0; i < this->shards.size(); i++)
        {
            if(!this->shards.at(i).isDropped())
            {
                this->shards.at(i).dropped();
                this->shards.at(i).plateTime = this->time;
            }
            else
            {
                ///Make the shards flat
                this->shards.at(i).setShardY(this->tablePlateDistance);
                if(this->angle > 30 && this->angle < 180)
                {
                    this->shards.at(i).rotateAngle = 90;
                }
                else
                {
                    this->shards.at(i).rotateAngle = 240;
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
