#include "stdafx.h"
#include "opengl.h"
#include "stdio.h"
HDC OpenGL::g_hdc=NULL;
HGLRC OpenGL::g_hrc=NULL;


void OpenGL::SetupPixelFormat(HDC hdc){
	int nPixelFormat;

	  // set the pixel format we want
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),	// size of structure
		1,                              // default version
		PFD_DRAW_TO_WINDOW |            // window drawing support
		PFD_SUPPORT_OPENGL |            // OpenGL support
		PFD_DOUBLEBUFFER,               // double buffering support
		PFD_TYPE_RGBA,                  // RGBA color mode
		32,                           // 32 bit color mode
		0, 0, 0, 0, 0, 0,               // ignore color bits, non-palettized mode
		0,                              // no alpha buffer
		0,                              // ignore shift bit
		0,                              // no accumulation buffer
		0, 0, 0, 0,                     // ignore accumulation bits
		16,                             // 16 bit z-buffer size
		0,                              // no stencil buffer
		0,                              // no auxiliary buffer
		PFD_MAIN_PLANE,                 // main drawing plane
		0,                              // reserved
		0, 0, 0 };                      // layer masks ignored

	// choose best matching pixelformat
	nPixelFormat=ChoosePixelFormat(hdc, &pfd);

	if (nPixelFormat == 0) {
		MessageBox(NULL, L"ChoosePixelFormat() failed:  "
		   L"Cannot find a suitable pixel format.", L"Error", MB_OK); 
		return ;
    } 
 
	//set pixel format to device context
    if (SetPixelFormat(hdc,nPixelFormat,&pfd)== FALSE) {
		MessageBox(NULL, L"SetPixelFormat() failed:  "
		   L"Cannot set format specified.", L"Error", MB_OK);
		return ;
    } 

	
}

void OpenGL::GLResize(int width,int height){

			if(height==0){height=1;} // prevent divide by zero

			glViewport(0,0,width,height);  // set new viewport size

			glMatrixMode(GL_PROJECTION); // reset projection matrix
			glLoadIdentity();

			//calculate new prespective and aspect ratio
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);

			glMatrixMode(GL_MODELVIEW); // reset modelview matrix
			glLoadIdentity();
}



void OpenGL::Dispose(){
    wglMakeCurrent(g_hdc,NULL);
    wglDeleteContext(g_hrc);

}

int OpenGL::Init(HDC hdc)
{
    g_hdc=hdc;
    SetupPixelFormat(g_hdc); //

	g_hrc=wglCreateContext(g_hdc); // create a rendering context
	wglMakeCurrent(g_hdc,g_hrc);// make it current

		// create a font
	//font_list_base_2d=2000; // set the start of the display lists for the 2d font
	HFONT font = CreateFont(40, 0, 0, 0,
                           FW_NORMAL, FALSE, FALSE, FALSE,
                            ANSI_CHARSET, 0,
							0,0,0,L"Times New Roman"); // can only use true type fonts 
												// 	this one is 40 points in size
	
	SelectObject(g_hdc, font);
	wglUseFontBitmaps(g_hdc,0,127,font_list_base_2d); // create a display list for each character (0-127)
	glListBase(font_list_base_2d); //start of our font display list numbers 

	// start numbering the display lists at font_list_base_2d



    return 0;
}

void OpenGL::Swap(void){
    SwapBuffers(g_hdc);

}

void OpenGL::Enable2D()
{
	int vPort[4];

   glGetIntegerv(GL_VIEWPORT, vPort);

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();

   glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
}

void OpenGL::Disable2D()
{
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();   
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();	
}

void OpenGL::glError() { 
        GLenum err = glGetError(); 
        while (err != GL_NO_ERROR) { 
                fprintf( stderr,"glError: %s caught at %s:%u\n", (char *)gluErrorString(err), __FILE__, __LINE__); 
                //err = glGetError(); 
        } 

	}