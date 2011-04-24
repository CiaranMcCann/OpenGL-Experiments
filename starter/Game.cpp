#include "StdAfx.h"
#include "Game.h"
#include "opengl.h"


#include <string>
#include <sstream>
using namespace std;




Game::Game(void):mPlane(10,1,10)
{
   
}

Game::~Game(void)
{
}



bool Game::Init(void)
{
    
    glEnable(GL_DEPTH_TEST); // check for depth


    
    return true;
}

bool Game::Update(float gametime){
	///////////////////////////
	//main game logic goes here
	///////////////////////////

	if(GetKeyState(VK_ESCAPE)& 128)
	{
		return true;
	}


	cube.Update();
	return false; //return false if you want to continue game
}
bool Game::Draw(void)
{
	
	// Prepare to draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear buffers
	glMatrixMode(GL_MODELVIEW); // reset modelview matrix
	glLoadIdentity();
	   
	mCamera.update();

	////////////////////////////////
	///Game Drawing code goes here
	///////////////////////////////


	mPlane.draw();


	Vector t =  Vector::NormalVectorToPlane(Vector(-10,0,10), Vector(-10,0,-10), Vector(-10,10,-10));

	
	//side walls
	glBegin(GL_QUADS);

	glColor3f(1.0f,0.0f,0.0f);

	
	glVertex3d(-10, 0 , 10);
	glVertex3d(-10, 0 , -10);
	glVertex3d(-10, 10 , -10);	
	glVertex3d(-10, 10 , 10);


	glVertex3d(10, 0 , 10);
	glVertex3d(10, 0 , -10);
	glVertex3d(10, 10 , -10);	
	glVertex3d(10, 10 , 10);

	glColor3f(1.0f,1.0f,1.0f);

	glVertex3d(-10,0,10);
	glVertex3d(10, 0 ,10);
	glVertex3d(10, 10 , 10);
	glVertex3d(-10,10,10);

	glEnd();

	cube.Draw();


	/////////////////////////////////
	//display the scene on the screen
	/////////////////////////////////
    OpenGL::Swap();

    return true;
}

bool Game::Done(void)
{
    return true;
}
