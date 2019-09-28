// ------------------------------------------------------------------------
// This program is complementary material for the book:
//
// Frank Nielsen
//
// Visual Computing: Geometry, Graphics, and Vision
//
// ISBN: 1-58450-427-7
//
// Charles River Media, Inc.
//
//
// All programs are available at http://www.charlesriver.com/visualcomputing/
//
// You may use this program for ACADEMIC and PERSONAL purposes ONLY. 
//
//
// The use of this program in a commercial product requires EXPLICITLY
// written permission from the author. The author is NOT responsible or 
// liable for damage or loss that may be caused by the use of this program. 
//
// Copyright (c) 2005. Frank Nielsen. All rights reserved.
// ------------------------------------------------------------------------

#pragma once
//#include <RtlR0.h>
#include <stdlib.h>
//#include <TcMath.h>
#include <math.h>
using namespace std;

#define W 800
#define H 800
#define M_PI 3.14159265
#define toRad(x) ((x)*(M_PI/180.0))

class Point3D
{
public:
	double x, y, z;
};

class Quaternion {
public:
	double w;
	Point3D u;

	inline void Multiply(const Quaternion q);

	inline double Norm();


	inline void Normalize();
	inline void Conjugate();

	inline void Inverse();

	void ExportToMatrix(float matrix[16]);

	Quaternion(double xyzw[]) {
		u.x = xyzw[0];
		u.y = xyzw[1];
		u.z = xyzw[2]; 
		w = xyzw[3];
	}
	Quaternion() {

	}

};

class slerp {
public:
	inline double drand() { return rand() / (double)RAND_MAX; }

	Quaternion RotateAboutAxis(Point3D pt, double angle, Point3D axis);


	void Slerp(Quaternion q1, Quaternion q2, Quaternion &qr, double lambda);

	void Slerp1(Quaternion q1, Quaternion q2, Quaternion &qr, double lambda);


	Point3D p, q, Rp;

	double lambdaanim = 0.0;


	void MultiplyPointMatrix(float m[16], Point3D p, Point3D& rotp);
};
