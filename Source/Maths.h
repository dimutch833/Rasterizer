#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

/*
 * Utility class, mostly utility math function
 */

#define PI 3.14159265359f

namespace Maths
{
	float Radians(float degrees);
	float Degrees(float rad);
	float Clamp(float min, float max, float v);
	
	Vector2f Min(const Vector2f& v, const Vector2f& w);
	Vector2f Max(const Vector2f& v, const Vector2f& w); //lower case conflicts name

	//Selection Sort on y value, because only 3 vertices
	void Sort(Vector3f* vertices, int size);
	
}	