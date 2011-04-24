#include "StdAfx.h"
#include "FunkyCube.h"

FunkyCube::FunkyCube(void):angle(0.0f),drawTriangle(true)
{
}

FunkyCube::~FunkyCube(void)
{
}


void FunkyCube::Update(){

	static float angle_inc=1.0f;

	if( GetKeyState(VK_SPACE)& 128){
		
	

		angle+=angle_inc; // increase angle of rotation
	}
	
	
}

void FunkyCube::Draw(void){
	glPushMatrix();
	
	glTranslated(0,2,0);
	glRotatef(angle,0,1,0);

	glColor3f(1.0f,1.0f,1.0f); // set current color to white
	glBegin(GL_LINES); // draw a box
		glVertex3f(1.0f,1.0f,1.0f); //specify a point
		glVertex3f(-1.0f,1.0f,1.0f); //specify a point
		
		glVertex3f(1.0f,1.0f,1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,1.0f); //specify a point
		
		glVertex3f(1.0f,1.0f,1.0f); //specify a point
		glVertex3f(1.0f,1.0f,-1.0f); //specify a point
		
		glVertex3f(-1.0f,-1.0f,-1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,-1.0f); //specify a point
		
		glVertex3f(-1.0f,-1.0f,-1.0f); //specify a point
		glVertex3f(-1.0f,1.0f,-1.0f); //specify a point
		
		glVertex3f(-1.0f,-1.0f,-1.0f); //specify a point
		glVertex3f(-1.0f,-1.0f,1.0f); //specify a point

		glVertex3f(1.0f,1.0f,-1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,-1.0f); //specify a point

		glVertex3f(1.0f,1.0f,-1.0f); //specify a point
		glVertex3f(-1.0f,1.0f,-1.0f); //specify a point

		glVertex3f(-1.0f,-1.0f,1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,1.0f); //specify a point

		glVertex3f(-1.0f,-1.0f,1.0f); //specify a point
		glVertex3f(-1.0f,1.0f,1.0f); //specify a point

		glVertex3f(-1.0f,-1.0f,1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,1.0f); //specify a point

		glVertex3f(-1.0f,1.0f,-1.0f); //specify a point
		glVertex3f(-1.0f,1.0f,1.0f); //specify a point

		glVertex3f(1.0f,-1.0f,-1.0f); //specify a point
		glVertex3f(1.0f,-1.0f,1.0f); //specify a point
		
	glEnd(); //Box finished

	if(drawTriangle==true){
	glBegin(GL_TRIANGLES); // draw a triangle
		glColor3f(1.0f,0.0f,0.0f); // set current color to red
		glVertex3f(0.0f,0.0f,0.0f); //specify a point
		
		glColor3f(0.0f,0.0f,1.0f); // set current color to blue
		glVertex3f(1.0f,1.0f,1.0f); //specify a point
		
		glColor3f(0.0f,1.0f,1.0f); // set current color to cyan
		glVertex3f(-1.0f,1.0f,1.0f); //specify a point
	glEnd(); //Trangle finished
	}
	glPopMatrix();
}
