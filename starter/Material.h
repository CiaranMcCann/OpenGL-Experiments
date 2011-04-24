#pragma once
#include "opengl.h"

/**
 * This class is a singleton and allows the programmer to set the current material properties 
 * in OpenGL to a pre-defined set. Each a gold. It sets the material properties
 * ambient, diffuse, specular, shininess
 *
 * @author Ciarán McCann
 */
class Material
{

private:
	GLfloat * goldAmbient;
	GLfloat * goldDiffuse;
	GLfloat * goldSpecular;
	GLfloat * goldShininess;

	Material(void);
	static Material * pInstance;

public:
	
	static Material * getInstance();

	//Sets current material type to gold
	void currentMaterialGold();
};
