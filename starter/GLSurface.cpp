#include "StdAfx.h"
#include "GLSurface.h"
#include "opengl.h"

bool GLSurface::mDrawNormalVector = true;


GLSurface::GLSurface(double mScaleX, double mScaleY, double mScaleZ):
	a(1,1,-1),
	b(1,1,1),
	c(-1,1,1),
	d(-1,1,-1)
{
	this->mScaleX = mScaleX;
	this->mScaleY = mScaleY;
	this->mScaleZ = mScaleZ;
}

void GLSurface::draw()
{
	glPushMatrix();
	glScaled(mScaleX, mScaleY, mScaleZ);
	Vector t = Vector::NormalVectorToPlane(a,d,c);
	Vector direction = t.normalize();

	glNormal3d(direction.x, direction.y, direction.z);
	glBegin(GL_QUADS);

		glVertex3d(a.x, a.y, a.z);		// A 
		glVertex3d(b.x, b.y, b.z);		// B
		glVertex3d(c.x, c.y, c.z);		// C
		glVertex3d(d.x, d.y, d.z);		// D

	glEnd();
		
		
	glPushAttrib(GL_COLOR_MATERIAL);
	Material::getInstance()->currentMaterialChrome();
	


	glBegin(GL_LINES);
	
	glColor3f(1.0f,0.0f,0.0f);		
	glVertex3d(t.x , t.y , t.z);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3d(direction.x,direction.y,direction.z);

	glEnd();
	glPopAttrib();

	

	glPopMatrix();
}