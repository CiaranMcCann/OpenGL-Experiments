#pragma once
#include "Vector.h"
#include "Material.h"
#include "opengl.h"

class GLShape
{

private:
	static bool mDrawNormalVector;

	double mScaleX;
	double mScaleY;
	double mScaleZ;


public:
	GLShape(double mScaleX = 5, double mScaleY = 5, double mScaleZ = 5);	
	void draw();
};
