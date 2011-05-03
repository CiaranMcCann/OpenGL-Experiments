#include "StdAfx.h"
#include "Terrain.h"

/**
 * Terrain object which manages the heightmap
 *
 * @author Ciarán McCann
 */
Terrain::Terrain(Vector position)
{	
		int randomInt = 0;

	//Terrain generation
	for (int z = 0; z < MAP_Y; z++)
	{
		/* initialize random seed: */
		srand ( time(NULL) );

		for (int x = 0; x < MAP_X; x++ )
		{

			/* generate secret number: */
			randomInt = rand() % 10 + 1;

			mTerrain[x][z].x = x*MAP_SCALER;
			mTerrain[x][z].y = z*randomInt;
			mTerrain[x][z].z = -z*MAP_SCALER;
		}
	}
}

Terrain::~Terrain(void)
{
}


void Terrain::draw()
{
	glColor3f(0.0f,1.0f,0.0f);
	for (int z = 0; z < MAP_Y; z++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (int x = 0; x < MAP_X; x++ )
		{
			glColor3f(mTerrain[z][x].x/255.0f,mTerrain[z][x].y/255.0f, mTerrain[z][x].z/255.0f);
			glVertex3f(mTerrain[z][x].x,mTerrain[z][x].y, mTerrain[z][x].z);//Verrtix 0

			glColor3f(mTerrain[z][x+1].x/255.0f,mTerrain[z][x+1].y/255.0f, mTerrain[z][x+1].z/255.0f);
			glVertex3f(mTerrain[z][x+1].x,mTerrain[z][x+1].y, mTerrain[z][x+1].z); //Vertix 1

			glColor3f(mTerrain[z+1][x].x/255.0f,mTerrain[z+1][x].y/255.0f, mTerrain[z+1][x].z/255.0f);
			glVertex3f(mTerrain[z+1][x].x,mTerrain[z+1][x].y, mTerrain[z+1][x].z); 

			glColor3f(mTerrain[z+1][x+1].x/255.0f,mTerrain[z+1][x+1].y/255.0f, mTerrain[z+1][x+1].z/255.0f);
			glVertex3f(mTerrain[z+1][x+1].x,mTerrain[z+1][x+1].y, mTerrain[z+1][x+1].z);

		}
		glEnd();
	}

}
 