#include "StdAfx.h"
#include "Material.h"

Material * Material::pInstance = 0;

Material::Material(void)
{
	GLfloat tempGoldAmbient[] = {0.24725f, 0.1995f, 0.0745f, 1.0f};
	GLfloat tempGoldDiffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f};
	GLfloat tempGoldSpecular[] = {0.628281f, 0.555802f, 0.366065f, 1.0f};
	GLfloat tempGoldShininess[] = {51.2f};

	goldAmbient = tempGoldAmbient;
	goldDiffuse = tempGoldDiffuse;
	goldShininess = tempGoldShininess;
	goldSpecular = tempGoldSpecular;

}

Material * Material::getInstance()
{

	if(pInstance == 0)
	{
		pInstance = &Material();
	}

	return pInstance;
}

void Material::currentMaterialGold()
{

	GLfloat materialAmbDiff[] = {0.0f, 0.1f, 1.0f, 1.0f}; // create an array of RGBA values
	GLfloat tempGoldSpecular[] = {0.628281f, 0.555802f, 0.366065f, 1.0f};
	GLfloat tempGoldShininess[] = {90.2f};


	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff); 
	//glMaterialfv(GL_FRONT,GL_AMBIENT,goldAmbient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, tempGoldSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, tempGoldShininess);

}

void Material::currentMaterialChrome()
{

	GLfloat materialAmbDiff[] = {1.0f, 0.0f, 0.0f, 1.0f}; // create an array of RGBA values
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff); 

}