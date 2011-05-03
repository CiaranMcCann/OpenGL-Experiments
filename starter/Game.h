#pragma once
#include"opengl.h"
#include "time.h"
#include "GLSurface.h"
#include "Camera.h"
#include "Material.h"
#include "GLShape.h"
#include "Terrain.h";


class Game
{
    int height,width;

	GLShape mShape;
	GLSurface mPlane;
	Camera mCamera;
	Terrain mTerrain;

public:
    BYTE keys[256];
    Game(void);

    ~Game(void);
    bool Init(void);
    bool Draw();
	bool Update(float);
    bool Done(void);
};
