#pragma once
#include"opengl.h"
#include "time.h"
#include "FunkyCube.h"
#include "GLSurface.h"
#include "Camera.h"
#include "Material.h"


class Game
{
    int height,width;

	FunkyCube cube;
	GLSurface mPlane;
	Camera mCamera;

public:
    BYTE keys[256];
    Game(void);

    ~Game(void);
    bool Init(void);
    bool Draw();
	bool Update(float);
    bool Done(void);
};
