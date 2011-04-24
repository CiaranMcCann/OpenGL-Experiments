#include "StdAfx.h"
#include "GLShape.h"

GLShape::GLShape(double mScaleX, double mScaleY, double mScaleZ)
{
	this->mScaleX = mScaleX;
	this->mScaleY = mScaleY;
	this->mScaleZ = mScaleZ;
}

void GLShape::draw()
{
	glPushMatrix();
	glScaled(mScaleX, mScaleY, mScaleZ);
	
	static GLfloat normal[] = {0,0,0};
	static GLfloat vertices [][3] = {
		
		//backface
		{1.0f,1.0f,1.0f}, 
		{-1.0f,1.0f,1.0f}, 
		{-1.0f,-1.0f,1.0f}, 
		{1.0f,-1.0f,1.0f},

		//frontface
		{1.0f,1.0f,-1.0f}, 
		{-1.0f,1.0f,-1.0f}, 
		{-1.0f,-1.0f,-1.0f}, 
		{1.0f,-1.0f,-1.0f}, 


		//topface
		{1.0f,1.0f,1.0f}, 
		{-1.0f,1.0f,1.0f}, 
		{-1.0f,1.0f,-1.0f}, 	
		{1.0f,1.0f,-1.0f},

		//bottomface
		{1.0f,-1.0f,1.0f}, 
		{-1.0f,-1.0f,1.0f}, 
		{-1.0f,-1.0f,-1.0f}, 	
		{1.0f,-1.0f,-1.0f},

		//leftFace
		{1.0f,-1.0f,1.0f}, 
		{1.0f,-1.0f,-1.0f}, 
		{1.0f,1.0f,-1.0f}, 
		{1.0f,1.0f,1.0f},

		//rightFace
		{-1.0f,-1.0f,1.0f}, 
		{-1.0f,-1.0f,-1.0f}, 
		{-1.0f,1.0f,-1.0f}, 
		{-1.0f,1.0f,1.0f},

	};

	
	glBegin(GL_QUADS); // draw a box

	Vector::NormalVectorToPlane(vertices[0],vertices[1],vertices[2],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[0]); glVertex3fv(vertices[1]); glVertex3fv(vertices[2]); glVertex3fv(vertices[3]);

	//front
	Vector::NormalVectorToPlane(vertices[0],vertices[3],vertices[7],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[0]); glVertex3fv(vertices[3]); glVertex3fv(vertices[7]); glVertex3fv(vertices[4]);

	//back
	Vector::NormalVectorToPlane(vertices[1],vertices[5],vertices[6],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[1]); glVertex3fv(vertices[5]); glVertex3fv(vertices[6]); glVertex3fv(vertices[2]);

	//left
	Vector::NormalVectorToPlane(vertices[3],vertices[2],vertices[6],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[3]); glVertex3fv(vertices[2]); glVertex3fv(vertices[6]); glVertex3fv(vertices[7]);

	//right
	Vector::NormalVectorToPlane(vertices[1],vertices[0],vertices[4],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[1]); glVertex3fv(vertices[0]); glVertex3fv(vertices[4]); glVertex3fv(vertices[5]);

	//bottom
	Vector::NormalVectorToPlane(vertices[4],vertices[7],vertices[6],normal);
	glNormal3fv(normal);
	glVertex3fv(vertices[4]); glVertex3fv(vertices[7]); glVertex3fv(vertices[6]); glVertex3fv(vertices[5]);

	glEnd();

	/*
	glPushAttrib(GL_COLOR_MATERIAL);
	Material::getInstance()->currentMaterialChrome();


	glBegin(GL_LINES);

	glColor3f(1.0f,0.0f,0.0f);		
	glVertex3d(t.x , t.y , t.z);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3d(direction.x,direction.y,direction.z);

	glEnd();
	glPopAttrib();

*/

	glPopMatrix();
}
