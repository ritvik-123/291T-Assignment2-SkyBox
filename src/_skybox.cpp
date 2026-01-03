#include "_skybox.h"

_skyBox::_skyBox()
{
    //ctor
}

_skyBox::~_skyBox()
{
    //dtor
}
void _skyBox::skyBoxInit()
{
    glGenTextures(6,tex);

    tex[0] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    tex[1] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    tex[2] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    tex[3] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    tex[4] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    tex[5] = textures->loadImages("D:/My Work/MS/3rd Sem/CSCI 291T/Assignment2_SkyBoxPly/images/SB7.jpg");
    xMin = 0;
    yMin = 0.33;
    xMax = 0.25;
    yMax = 0.66;

    rot.x= rot.y = rot.z = 0.0;
    pos.x= pos.y = 0.0;
    pos.z = -9;
    boxSize.x = boxSize.z =30.0;
    boxSize.y = 10.0;

}

void _skyBox::drawSkyBox()
{
    float xMinh = 0.33;
    float yMinh = 0.25;
    float xMaxh = 0.66;
    float yMaxh = 0.50;
   glPushMatrix();
     // handling translation and scaling
     glColor3f(1.0,1.0,1.0);
     glScalef(boxSize.x,boxSize.y,boxSize.z);
  //   glTranslatef(pos.x,pos.y, pos.z);
     //handling rotations
     glRotatef(rot.x,1,0,0);
     glRotatef(rot.y,0,1,0);
     glRotatef(rot.z,0,0,1);

   //Front Wall
     glBindTexture(GL_TEXTURE_2D,tex[0]);
     glBegin(GL_QUADS);
      glTexCoord2f(xMin,yMin); glVertex3f(-1.0,1.0,1.0);
      glTexCoord2f(xMax,yMin); glVertex3f( 1.0,1.0,1.0);
      glTexCoord2f(xMax,yMax); glVertex3f( 1.0,-1.0,1.0);
      glTexCoord2f(xMin,yMax); glVertex3f(-1.0,-1.0,1.0);
     glEnd();

   //back Wall
     glBindTexture(GL_TEXTURE_2D,tex[1]);
     glBegin(GL_QUADS);
      glTexCoord2f(xMax*2,yMax); glVertex3f(1.0, -1.0,-1.0);
      glTexCoord2f(xMax*3,yMax); glVertex3f(-1.0,-1.0,-1.0);
      glTexCoord2f(xMax*3,yMin); glVertex3f(-1.0, 1.0,-1.0);
      glTexCoord2f(xMax*2,yMin); glVertex3f( 1.0, 1.0,-1.0);
     glEnd();

    //top wall
     glBindTexture(GL_TEXTURE_2D,tex[2]);
     glBegin(GL_QUADS);
      glTexCoord2f(0,0); glVertex3f( 1.0,1.0,-1.0);
      glTexCoord2f(0,0.33); glVertex3f( 1.0,1.0,1.0);
      glTexCoord2f(1.0,0.33); glVertex3f( -1.0,1.0,1.0);
      glTexCoord2f(1.0,0); glVertex3f(-1.0,1.0,-1.0);
     glEnd();

      //bottom wall
     glBindTexture(GL_TEXTURE_2D,tex[3]);
     glBegin(GL_QUADS);
      glTexCoord2f(0,1); glVertex3f(-1.0,-1.0, 1.0);
      glTexCoord2f(0,0.66); glVertex3f( 1.0,-1.0, 1.0);
      glTexCoord2f(0.4,0.66); glVertex3f( 1.0,-1.0,-1.0);
      glTexCoord2f(0.4,1); glVertex3f(-1.0,-1.0,-1.0);
     glEnd();

     //left Wall
     glBindTexture(GL_TEXTURE_2D,tex[4]);
     glBegin(GL_QUADS);
      glTexCoord2f(xMax*3,yMin); glVertex3f(-1.0,1.0,-1.0);
      glTexCoord2f(xMax*4,yMin); glVertex3f(-1.0,1.0,1.0);
      glTexCoord2f(xMax*4,yMax); glVertex3f(-1.0,-1.0,1.0);
      glTexCoord2f(xMax*3,yMax); glVertex3f(-1.0,-1.0,-1.0);
     glEnd();

     //right wall
     glBindTexture(GL_TEXTURE_2D,tex[5]);
     glBegin(GL_QUADS);
      glTexCoord2f(xMax*2,yMin); glVertex3f( 1.0,1.0,-1.0);
      glTexCoord2f(xMax*2,yMax); glVertex3f( 1.0,-1.0,-1.0);
      glTexCoord2f(xMax,yMax); glVertex3f( 1.0,-1.0,1.0);
      glTexCoord2f(xMax,yMin); glVertex3f( 1.0,1.0,1.0);
     glEnd();

   glPopMatrix();


}
