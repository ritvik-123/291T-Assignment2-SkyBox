#include "_2Dplyer.h"

_2Dplyer::_2Dplyer()
{
    //ctor
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;

    pos.x = 0;
    pos.y = 0;
    pos.z = -8;

    vertx[0].x = -0.5; vertx[0].y = -0.5; vertx[0].z = -1.0;
    vertx[1].x =  0.5; vertx[1].y = -0.5; vertx[1].z = -1.0;
    vertx[2].x =  0.5; vertx[2].y =  0.5; vertx[2].z = -1.0;
    vertx[3].x = -0.5; vertx[3].y =  0.5; vertx[3].z = -1.0;

    actiontrigger = 0;
}

_2Dplyer::~_2Dplyer()
{
    //dtor
}
void _2Dplyer::ply2DInit(char* fileName,int x, int y)
{
    myTex->loadImage(fileName);
    frames.x = x;
    frames.y = y;

}

void _2Dplyer::drawPly2D()
{
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    myTex->textureBinder();

    glBegin(GL_QUADS);

    if (actiontrigger == WALKLEFT)
    {
        // Flip the texture when moving left, just flips xMax with xMin
        glTexCoord2f(xMax, yMax);
        glVertex3f(vertx[0].x, vertx[0].y, vertx[0].z);

        glTexCoord2f(xMin, yMax);
        glVertex3f(vertx[1].x, vertx[1].y, vertx[1].z);

        glTexCoord2f(xMin, yMin);
        glVertex3f(vertx[2].x, vertx[2].y, vertx[2].z);

        glTexCoord2f(xMax, yMin);
        glVertex3f(vertx[3].x, vertx[3].y, vertx[3].z);
    }
    else
    {
        // Normal texture mapping for other actions (e.g., WALKRIGHT)
        glTexCoord2f(xMin, yMax);
        glVertex3f(vertx[0].x, vertx[0].y, vertx[0].z);

        glTexCoord2f(xMax, yMax);
        glVertex3f(vertx[1].x, vertx[1].y, vertx[1].z);

        glTexCoord2f(xMax, yMin);
        glVertex3f(vertx[2].x, vertx[2].y, vertx[2].z);

        glTexCoord2f(xMin, yMin);
        glVertex3f(vertx[3].x, vertx[3].y, vertx[3].z);
    }

    glEnd();
    glPopMatrix();
}

void _2Dplyer::ply2DAction()
{
    switch(actiontrigger)
    {
        case STAND:
            if (facingDirection == 1) { // If last movement was right, using one stand function, if
                xMin = 0;
                xMax = 1.0 / frames.x;
                yMin = 0;
                yMax = 1.0 / frames.y;
            } else { // If last movement was left
                xMin = 1.0 / frames.x;
                xMax = 0;
                yMin = 0;
                yMax = 1.0 / frames.y;
            }
            break;

        case WALKLEFT:
            facingDirection = -1; // Face left
            if(myTime->getTicks() > 60)
            {
                if (xMax >= 1.0)
                {
                    // If last frame in X is reached, reset to first column
                    xMin = 0;
                    xMax = 1.0 / frames.x;
                    yMin += 1.0 / frames.y;  // Move to next row
                    yMax += 1.0 / frames.y;
                }
                else
                {
                    // Move to next frame in the row
                    xMin += 1.0 / frames.x;
                    xMax += 1.0 / frames.x;
                }
                myTime->reset();
            }
            break;

        case WALKRIGHT:
            facingDirection = 1; // Face right
            if(myTime->getTicks() > 60)
            {
                if (xMax >= 1.0)
                {
                    xMin = 0;
                    xMax = 1.0 / frames.x;
                    yMin += 1.0 / frames.y;
                    yMax += 1.0 / frames.y;
                }
                else
                {
                    xMin += 1.0 / frames.x;
                    xMax += 1.0 / frames.x;
                }
                myTime->reset();
            }
            break;
    }
}

