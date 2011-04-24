#pragma once

class Vector
{

public: 
   
	double x,y,z;

	Vector(double=0.0,double=0.0, double = 0.0);

	void rotate(double angle);
	double dotProduct(Vector v);
	double length();

	/************************************************************************/
	/* Operator Overloads                                                                     */
	/************************************************************************/
	Vector operator*(double);
	Vector operator-(Vector & f);
	Vector operator+(Vector & f);
	Vector operator+=(Vector & f);
	Vector operator-=(Vector & f);


	Vector normalize();
	static Vector NormalVectorToPlane(Vector & vertexOne, Vector & vertexTwo, Vector & vertexThree);
	
};
