#include "StdAfx.h"
#include "Material.h"

Material * Material::pInstance = 0;

Material::Material(void)
{
	GLfloat tempGoldAmbient[] = {0.24725, 0.1995, 0.0745, 1.0};
	GLfloat tempGoldDiffuse[] = { 0.75164, 0.60648, 0.22648, 1.0 };
	GLfloat tempGoldSpecular[] = {0.628281, 0.555802, 0.366065, 1.0};
	GLfloat tempGoldShininess[] = {51.2};

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

	glMaterialfv(GL_FRONT,GL_AMBIENT,goldAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, goldShininess);

}