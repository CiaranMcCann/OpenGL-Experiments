#include "StdAfx.h"
#include "Game.h"
#include "opengl.h"


#include <string>
#include <sstream>
using namespace std;




Game::Game(void):mPlane(10,0,10),mShape(2,2,2)
{
   
}

Game::~Game(void)
{
}



bool Game::Init(void)
{
    
    glEnable(GL_DEPTH_TEST); // check for depth
	glEnable(GL_NORMALIZE);	// automatically convert normals to unit normals
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	GLfloat lightColor[] = {1.0, 1.0, 1.0, 1.0};
	
	//GLfloat lightPosition[] = {-10.0, 5.0, 0.0, 0.0};

	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
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


	return false; //return false if you want to continue game
}
bool Game::Draw(void)
{
	
	// Prepare to draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear buffers
	glMatrixMode(GL_MODELVIEW); // reset modelview matrix
	glLoadIdentity();

	//GLfloat lightPositionl[] = {-10.0, 5.0, 0.0, 0.0};
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPositionl);

	static float angle = 0;
	angle += 0.5;
	   
	mCamera.update();

	GLShape light = GLShape(0.5,0.5,0.5);

	static float theX = 10.0f;
	static float theY = 5.0f;

	////////////////////////////////
	///Game Drawing code goes here
	///////////////////////////////
	Material::getInstance()->currentMaterialGold();

	GLfloat lightPosition[] = {theX, theY, 0.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glPushMatrix();
	glTranslated(theX, theY, 0.0);

	if(GetKeyState('L')& 128)
	{
		theX -= 0.5;		
		//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	}

	if(GetKeyState('O')& 128)
	{
		theY += 0.5;		
		//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	}

	
	light.draw();
	glPopMatrix();
	
	
	glPushMatrix();
		glTranslated(0,2,0);
		glRotated(angle,0,1,0);
		//mShape.draw();	
	glPopMatrix();

	

	Material::getInstance()->currentMaterialChrome();

		mTerrain.draw();
	
	//mPlane.draw();

	glBegin(GL_QUADS);

	glColor3f(1.0f,0.0f,0.0f);	
	glNormal3d(-1,0,0);
	glVertex3d(-10, 0 , 10);
	glVertex3d(-10, 0 , -10);
	glVertex3d(-10, 10 , -10);	
	glVertex3d(-10, 10 , 10);


	glNormal3d(1,0,0);
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

	//cube.Draw();


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
