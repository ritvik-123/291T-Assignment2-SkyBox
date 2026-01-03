#include "_scene.h"
#include <_lighting.h>
#include <_model.h>
#include <_inputs.h>
#include <_parallax.h>
#include <_skybox.h>
#include <_2Dplyer.h>

_2Dplyer *ply2D = new _2Dplyer();
_lighting *myLight = new _lighting();
_model *myModel = new _model();
_inputs *myKbMs = new _inputs();
_parallax *prlx = new _parallax();
_skyBox *sky = new _skyBox();

_scene::_scene()
{
    //ctor
    rot.x=rot.y=rot.z=0;      //init rotation
    scale.x=scale.y=scale.z=1;
    pos.x=pos.y =0; pos.z = -10.0;
}

_scene::~_scene()
{
    //dtor
}
GLvoid _scene::resizeWindow(GLsizei width, GLsizei height)
{
    GLfloat Ratio = (GLfloat)width/(GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,Ratio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    dim.x = GetSystemMetrics(SM_CXSCREEN);
    dim.y = GetSystemMetrics(SM_CYSCREEN);
}

GLint _scene::IniGL()
{
    glClearColor(0.0,0.0,1.0,1.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    myLight->setupLight(GL_LIGHT0);
    myModel->initModel("images/skin-3.jpg");
    prlx->parallaxInit("images/prlx-2.jpg");
    ply2D->ply2DInit("images/Player1.png",6,4);

    dim.x = GetSystemMetrics(SM_CXSCREEN);
    dim.y = GetSystemMetrics(SM_CYSCREEN);

    sky->skyBoxInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Cut off the background, required for homework

    return true;
}

GLvoid _scene::renderScene()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   gluLookAt(0, 0, 10,
              0,0, 0,
              0, 1, 0);

    //myModel->drawModel();

    glPushMatrix();
    glScalef(4.33,4.33,1);
    glDisable(GL_LIGHTING);
 //   prlx->drawBkgrnd(dim.x,dim.y);
 //   prlx->prlxScrollAuto("left",0.005);

    sky->drawSkyBox();

    ply2D->ply2DAction();
    ply2D->drawPly2D();

    glEnable(GL_LIGHTING);
    glPopMatrix();
}

int _scene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_KEYDOWN:
          myKbMs->wParam = wParam;
          myKbMs->keyPressed(myModel);
          myKbMs->keyPressed(prlx);
          myKbMs->keyPressed(sky);
          myKbMs->keyPressed(ply2D);
        break;

    case WM_KEYUP:
        ply2D->actiontrigger=0;
        break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
        myKbMs->wParam= wParam;
        myKbMs->mouseEventDown(myModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        myKbMs->mouseEventUp();
        break;

   case WM_MOUSEMOVE:
        //myKbMs->mouseMove(myModel,LOWORD(lParam),HIWORD(lParam));
        myKbMs->mouseSceneMove(sky,myModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        myKbMs->mouseWheel(myModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }
}

