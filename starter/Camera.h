#pragma once
#include "opengl.h"
#include "Vector.h"

class Camera
{

	Vector mViewReferencePiont;
	Vector mCenterPiont;
	Vector mUpVector;
	Vector mDirection;
	int mViewPortWidth;
	int mViewPortHeight;

public:
	Camera(void);
	void update();
	
};
