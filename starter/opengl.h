#ifndef __OPENGL__
#define __OPENGL__
#pragma comment(lib,"opengl32")
#pragma comment(lib,"glu32")
//#pragma comment(lib,"glaux")
#include <gl/gl.h> //Standard OpenGL Header
#include <gl/glu.h> //OpenGL utilities




class OpenGL
{
	
   
	static HDC g_hdc; 	// global handle to device context
    static HGLRC g_hrc; 	// global handle to rendering context
	static const int font_list_base_2d=2000;
public:
    static void SetupPixelFormat(HDC);
    static void GLResize(int ,int );

    static void Dispose();
    static void Disable2D();
    static void Enable2D();
    static void glError();
	


public:
    static int Init(HDC);
public:
    static void Swap(void);
};

#endif __OPENGL__
