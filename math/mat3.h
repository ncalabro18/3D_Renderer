#pragma once
#include <math.h>
#include "vec3.h"


class Mat3
{
public:
	double values[9];
public:
	Mat3(double values[9]);
	Mat3 operator*( Mat3 a);
	Vec3 transform(Vec3 vec);
};

