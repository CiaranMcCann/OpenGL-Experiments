#include "StdAfx.h"
#include "Texture.h"
#include <stdio.h>
#define BITMAP_ID 0x4D42		// the universal bitmap ID

void Texture::Load(char *filename,unsigned char r  ,unsigned char g,unsigned char b)
{
	transred=r,transgreen=g, transblue=b;
	BITMAPINFOHEADER	bitmapInfoHeader;	// bitmap info header
	unsigned char*		bitmapData;			// the texture data
	bitmapData=NULL;
	bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
	
    glEnable(GL_TEXTURE_2D);	
	if(!bitmapData)
		MessageBox(GetWindow(NULL,NULL),L"Bitmap reading error",L"Error",MB_OK);


	
	GLuint textures[1];
	glGenTextures(1, textures);// generate texture object names
	texture_id=textures[0];
	

	
	
	glBindTexture(GL_TEXTURE_2D, texture_id);       // enable our texture object to be 2D

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);



     // generate the texture image
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfoHeader.biWidth,
				 bitmapInfoHeader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmapData);
	//glError();
	delete [] bitmapData;
}

Texture::~Texture(void)
{
}

Texture::Texture(void)
{
	transred=transgreen=transblue=0;
}

// LoadBitmapFile
// desc: Returns a pointer to the bitmap image of the bitmap specified
//       by filename. Also returns the bitmap header information.
//		 No support for 8-bit bitmaps.
unsigned char* Texture::LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr;							// the file pointer
	BITMAPFILEHEADER	bitmapFileHeader;		// bitmap file header
	unsigned char		*bitmapImage;			// bitmap image data
	unsigned char		*bitmapAlphaImage;			// bitmap image data
	int					imageIdx = 0;		// image index counter
	//unsigned char		tempRGB;				// swap variable

	// open filename in "read binary" mode

	//TCHAR szDirectory[MAX_PATH];

	//if(!::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory))

	fopen_s(&filePtr,filename, "rb");
	if (filePtr == NULL)
		return NULL;

	// read the bitmap file header
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	
	// verify that this is a bitmap by checking for the universal bitmap id
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr);
		return NULL;
	}

	// read the bitmap information header
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	// move file pointer to beginning of bitmap data
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	// allocate enough memory for the bitmap image data
	int num_bytes=bitmapInfoHeader->biWidth*bitmapInfoHeader->biHeight*bitmapInfoHeader->biBitCount/8;
	int num_alpha_bytes=bitmapInfoHeader->biWidth*bitmapInfoHeader->biHeight*4;
	bitmapImage = new unsigned char[num_bytes];
	bitmapAlphaImage = new unsigned char[num_alpha_bytes];

	// verify memory allocation
	if (!bitmapImage)
	{
		delete [] bitmapImage;
		fclose(filePtr);
		return NULL;
	}

	// read in the bitmap image data
	fread(bitmapImage, 1, num_bytes, filePtr);
	
	// make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(filePtr);	
		return NULL;
	}

	// swap the R and B values to get RGB since the bitmap color format is in BGR
	int alphaidx=0;
	for (imageIdx = 0; imageIdx < num_bytes; imageIdx+=3)
	{
		/*tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;*/
		bitmapAlphaImage[alphaidx++]=bitmapImage[imageIdx + 2];//red
		bitmapAlphaImage[alphaidx++]=bitmapImage[imageIdx + 1];//green
		bitmapAlphaImage[alphaidx++]=bitmapImage[imageIdx];//blue
		if(bitmapImage[imageIdx + 2]==transred &&  bitmapImage[imageIdx + 1]==transgreen && bitmapImage[imageIdx]==transblue)
			bitmapAlphaImage[alphaidx++]=0;
		else
			bitmapAlphaImage[alphaidx++]=255;

	}

	// close the file and return the bitmap image data
	fclose(filePtr);

	delete [] bitmapImage;
	return bitmapAlphaImage;
}

void Texture::Enable(){
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)	;	
	glEnable(GL_BLEND);	
	glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, texture_id); // select current texture
}

void Texture::Disable(){
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)	;	
	glDisable(GL_BLEND);	
	glDisable(GL_TEXTURE_2D);	
	//glBindTexture(GL_TEXTURE_2D, texture_id); // select current texture
}

