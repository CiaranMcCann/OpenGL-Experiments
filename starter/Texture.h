#pragma once
#include "opengl.h"



class Texture
{
	unsigned char transred,transgreen,transblue;
public:
	Texture();

	
	GLuint texture_id;
public:
	~Texture(void);

	unsigned char*  LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);

	void Enable();
	void Disable();
	void Load(char* ,unsigned char r=0,unsigned char g=0,unsigned char b=0);
	



	
};
