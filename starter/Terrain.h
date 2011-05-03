#pragma once
#include "Vector.h"
#include "opengl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_X 10
#define MAP_Y 10
#define MAP_SCALER 20.0f

class Terrain
{

private:
	Vector mTerrain[MAP_X][MAP_Y];

public:	
	Terrain(Vector position = Vector());	
	void draw();

	~Terrain(void);
};
