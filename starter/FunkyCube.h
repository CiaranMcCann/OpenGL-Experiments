#pragma once
#include "opengl.h"

class FunkyCube
{
	float angle;
	bool drawTriangle;

public:
	FunkyCube();
	void Update();
	void Draw();
public:
	~FunkyCube(void);
};
