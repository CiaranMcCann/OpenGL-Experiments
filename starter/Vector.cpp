#include "StdAfx.h"
#include "Vector.h"
#include "math.h"


Vector::Vector(double a, double b, double c)
{
	this->x=a;
	this->y=b;
	this->z=c;
}


double Vector::dotProduct(Vector v){
	return x*v.x+y*v.y+z*v.z;
}


void Vector::rotate(double angle)
{// angle in degrees
angle=angle/360.0*2*3.141;// convert to radians

double a,b;

a= x*cos(angle)+y*sin(angle);
b= x*-sin(angle)+y*cos(angle);

x=a;
y=b;

}




double Vector::length(){
	return sqrt(x*x+y*y+z*z);
}

Vector Vector::normalize(){
	double lenght =length();

   lenght = 1.0f/lenght;

	return Vector((x*lenght),(y*lenght),(z*lenght));

}


Vector Vector::operator*(double f){
	return Vector(this->x*f,this->y*f,this->z*f);	
}


Vector Vector::operator-(Vector & f){
	return Vector(this->x-f.x,this->y-f.y,this->z-f.z);
}


Vector Vector::operator+(Vector & f){

	return Vector(this->x+f.x,this->x+f.x,this->x+f.x);
}



Vector Vector::operator+=(Vector & f)
{
	this->x += f.x;
	this->y += f.y;
	this->z += f.z;

	return *this;
}


Vector Vector::operator-=(Vector & f)
{
	this->x -= f.x;
	this->y -= f.y;
	this->z -= f.z;

	return *this;

}



Vector Vector::NormalVectorToPlane(Vector & vertexOne, Vector & vertexTwo, Vector & vertexThree)
{

	Vector v1 = vertexTwo-vertexOne;
	Vector v2 = vertexThree-vertexTwo;

	return Vector( 
		
		(v1.y*v2.z) - (v2.y*v1.z) ,
		(v1.z*v2.x) - (v2.z*v1.x) ,
		(v1.x*v2.y) - (v2.x*v1.y)
				
		);

}


void Vector::NormalVectorToPlane(float p1[3], float p2[3], float p3[3], float n[3])
{

	float v1[3],v2[3]; // two vectors

	//calculate two vectors lying on the surface
	// v1=p2-p1
	// v2=p3-p2

	for(int i=0;i<3;i++){
		v1[i]=p2[i]-p1[i];
		v2[i]=p3[i]-p2[i];
	}

	// calculate cross product of two vectors ( n= v1 x v2)
	n[0]=v1[1]*v2[2] - v2[1]*v1[2];
	n[1]=v1[2]*v2[0] - v2[2]*v1[0];
	n[2]=v1[0]*v2[1] - v2[0]*v1[1];

} //done
