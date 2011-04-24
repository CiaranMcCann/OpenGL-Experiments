#pragma once
#include "Vector.h"

class GLSurface
{
	static bool mDrawNormalVector;

	double mScaleX;
	double mScaleY;
	double mScaleZ;

	Vector a,b,c,d;

public:
	GLSurface(double mScaleX = 5, double mScaleY = 5, double mScaleZ = 5);
	void draw();
};
