#include "_inputs.h"

_inputs::_inputs()
{
    //ctor

    mouse_translate = false;
    mouse_rotate = false;
}

_inputs::~_inputs()
{
    //dtor
}
void _inputs::keyPressed(_model* mdl)
{
    switch(wParam)
    {
        case VK_LEFT:
              mdl->rot.y +=1.0;
             break;
        case VK_RIGHT:
              mdl->rot.y -=1.0;
             break;
        case VK_UP:
              mdl->rot.x +=1.0;
             break;
        case VK_DOWN:
              mdl->rot.x -=1.0;
             break;
    }

}
void _inputs::keyPressed(_2Dplyer* ply)
{
    switch(wParam)
    {
        case VK_LEFT:
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
            {
                ply->actiontrigger = ply->WALKRIGHT;  // Shift + Left moves right
            }
            else
            {
                ply->actiontrigger = ply->WALKLEFT;   // Normal Left moves left
            }
            break;

        case VK_RIGHT:
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
            {
                ply->actiontrigger = ply->WALKLEFT;   // Shift + Right moves left
            }
            else
            {
                ply->actiontrigger = ply->WALKRIGHT;  // Normal Right moves right
            }
            break;
    }
}

void _inputs::keyPressed(_parallax* prlx)
{
    switch(wParam)
    {
        case VK_LEFT:
            //  prlx->xMin -=0.005;
            //  prlx->xMax -=0.005;
             prlx->prlxScrollAuto("left",0.005);
             break;
        case VK_RIGHT:
             break;
        case VK_UP:
             break;
        case VK_DOWN:
             break;
    }

}
void _inputs::keyPressed(_skyBox* sky)
{
     switch(wParam)
    {
        case VK_LEFT:
             sky->rot.y -=1.0;

             break;
        case VK_RIGHT:
             sky->rot.y +=1.0;
             break;
        case VK_UP:

             sky->rot.x -=1.0;
             break;
        case VK_DOWN:
             sky->rot.x +=1.0;
             break;

        case VK_F2:
            sky->pos.z +=1.0;
            break;

        case VK_F3:
            sky->pos.z -=1.0;
            break;
    }

}


void _inputs::keyUp(_2Dplyer* ply)
{
   switch(wParam)
   {
        default:
        cout<<"come here";
        break;
        case VK_LEFT:
             //ply->actiontrigger=ply->STANDLEFT;
             break;
        case VK_RIGHT:
             //ply->actiontrigger=ply->STANDRIGHT;
             break;
   }
}

void _inputs::mouseEventDown(_model* mdl, double x, double y)
{
       switch(wParam)
       {
       case MK_LBUTTON:
              mouse_rotate = true;
             break;
       case MK_RBUTTON:
               mouse_translate =true;
             break;
       case MK_MBUTTON:
             break;
       }
       prev_mouseX = x;
       prev_mousey = y;
}

void _inputs::mouseEventUp()
{
     mouse_rotate = false;
     mouse_translate = false;
}

void _inputs::mouseWheel(_model* mdl, double delta)
{
     mdl->pos.z +=delta/100.0;
}

void _inputs::mouseMove(_model* mdl, double x, double y)
{
    if(mouse_rotate)
    {
        mdl->rot.y += (x-prev_mouseX)/3.0;
        mdl->rot.x += (y-prev_mousey)/3.0;
    }
    if(mouse_translate)
    {
       mdl->pos.x += (x-prev_mouseX)/100.0;
       mdl->pos.y -= (y-prev_mousey)/100.0;
    }
    prev_mouseX =x;
    prev_mousey =y;
}
void _inputs::mouseSceneMove(_skyBox* sky, _model* mdl, double x, double y)
{
    if(mouse_rotate)
    {
        sky->rot.y += (x-prev_mouseX)/3.0;
        sky->rot.x += (y-prev_mousey)/3.0;
        mdl->rot.y += (x-prev_mouseX)/3.0;
        mdl->rot.x += (y-prev_mousey)/3.0;
    }
    if(mouse_translate)
    {
       sky->pos.x += (x-prev_mouseX)/100.0;
       sky->pos.y -= (y-prev_mousey)/100.0;
       mdl->pos.x += (x-prev_mouseX)/100.0;
       mdl->pos.y -= (y-prev_mousey)/100.0;
    }
    prev_mouseX =x;
    prev_mousey =y;
}
