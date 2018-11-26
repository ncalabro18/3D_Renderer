#include "mat3.h"

Mat3::Mat3(double v[9])
{
	for (int i = 0; i < 9; i++) {
		values[i] = v[i];
	}
}

Mat3 Mat3::operator*(Mat3 a) {
	double matValues[9] = { 0 };

	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			for (int i = 0; i < 3; i++) 
				matValues[row * 3 + col] += values[row * 3 + i] * a.values[i * 3 + col];
	
	return Mat3(matValues);
}

Vec3 Mat3::transform(Vec3 vec) {
	return Vec3(
		vec.x * values[0] + vec.y * values[3] + vec.z * values[6],
		vec.x * values[1] + vec.y * values[4] + vec.z * values[7],
		vec.x * values[2] + vec.y * values[5] + vec.z * values[8]
	);
}
