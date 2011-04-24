#include "StdAfx.h"
#include "Camera.h"

Camera::Camera(void):
	mViewReferencePiont(0,15,-25), 
	mCenterPiont(0,0,0),
	mUpVector(0,1,0),
	mDirection((mViewReferencePiont-mCenterPiont).normalize()),
	mViewPortHeight(0),
	mViewPortWidth(0)
{
}

void Camera::update()
{

	GLint p[4];
	glGetIntegerv(GL_VIEWPORT,p);
	mViewPortWidth = p[2];
	mViewPortHeight =p[3];

	if(GetKeyState('W')& 128)
	{
		mViewReferencePiont += mDirection*0.5;
	}

	if(GetKeyState('S')& 128)
	{
		mViewReferencePiont -= mDirection*0.5;
	}

	if(GetKeyState('A')& 128)
	{
		mCenterPiont.rotate(10);
		mViewReferencePiont.rotate(10);
	}

	if(GetKeyState('D')& 128)
	{
		mCenterPiont.rotate(-10);
		mViewReferencePiont.rotate(-10);
	}


	double thridOfScreenHeight = mViewPortHeight/3;
	double thridOfScreenWidth = mViewPortWidth/4;
	POINT cursorPos;
	GetCursorPos(&cursorPos);

	if(cursorPos.y > thridOfScreenHeight*2)
	{
		mCenterPiont.y -= 0.3;
		mDirection = (mViewReferencePiont-mCenterPiont).normalize();
	}
	else if(cursorPos.y < thridOfScreenHeight)
	{	
		mCenterPiont.y += 0.3;
		mDirection = (mViewReferencePiont-mCenterPiont).normalize();
	}

	
	/*
	if(cursorPos.x > thridOfScreenWidth*2)
	{
		mCenterPiont.x -= 0.9;
		mDirection = (mViewReferencePiont-mCenterPiont).normalize();
	}
	else if(cursorPos.x < thridOfScreenWidth)
	{
		mCenterPiont.x += 0.9;
		mDirection = (mViewReferencePiont-mCenterPiont).normalize();
	}
	*/
	

	Vector target = mViewReferencePiont + mDirection;
	gluLookAt(

		mViewReferencePiont.x,mViewReferencePiont.y,mViewReferencePiont.z,  //VRP = { 0,-15,0 }
		target.x,mCenterPiont.y,target.z,						//VPN = (VPR - {0,0,0}).normalize()
		mUpVector.x,mUpVector.y,mUpVector.z									//Up Vector = { 0, 1 , 0 }

		);
}
