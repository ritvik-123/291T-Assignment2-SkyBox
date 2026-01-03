#ifndef _SCENE_H
#define _SCENE_H

#include<_common.h>

class _scene
{
    public:
        _scene();
        virtual ~_scene();

        GLvoid resizeWindow(GLsizei width, GLsizei height);// resizing window
        GLint IniGL();                                    //initialization
        GLvoid renderScene();                              // Draw Scene

        int winMsg(HWND	hWnd,			// Handle For This Window
                   UINT	uMsg,			// Message For This Window
                   WPARAM wParam,			// Additional Message Information
                   LPARAM	lParam);

         vec2 dim;
         vec3 pos;//position the model;
         vec3 rot;//angels for rotate the model;
         vec3 scale;//to scale the model

    protected:

    private:
};

#endif // _SCENE_H
