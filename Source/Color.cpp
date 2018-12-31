#include "Color.h"

#include <cassert>
#include <algorithm>
#include "IShader.h"

const float Color::MIN_VALUEF = 0.0f;
const float Color::MAX_VALUEF = 1.0f;

const int Color::MIN_VALUEI = 0;
const int Color::MAX_VALUEI = 255;


Color::Color(float r, float g, float b, float a)
	:r(ClampValue(r)),
	g(ClampValue(g)),
	b(ClampValue(b)),
	a(ClampValue(a))
{
}

Color& Color::operator*=(float f)
{
	r = ClampValue(r * f);
	g = ClampValue(g * f);
	b = ClampValue(b * f);
	return *this;
}

Color& Color::operator/=(float f)
{
	return *this *= (1.0f / f);
}

uint32_t Color::GetInt() const
{
	return ColorToInt(*this);
}

Color IntToColor(uint32_t c)
{
	float invMaxValue = 1.0f / 255.0f;
	return  Color
	(
		float(c >> 24) * invMaxValue,
		float(c >> 16) * invMaxValue,
		float(c >> 8) * invMaxValue,
		float(c) * invMaxValue
	);
}

uint32_t ColorToInt(const Color& c)
{
	float maxValue = 255.0f;
	return	
		(uint32_t(c.r * maxValue) << 24) |
		(uint32_t(c.g * maxValue) << 16) |
		(uint32_t(c.b * maxValue) << 8) |
		(uint32_t(c.a * maxValue) << 0);
}

Color operator*(const Color& c, const Color& d)
{
	return Color(c.r * d.r, c.g * d.g, c.b * d.b, c.a * d.a);
}

Color operator*(const Color& c, const Vector3f& v)
{
	return c * Vector4f(v, 1.0f);
}

Color operator*(const Color& c, const Vector4f& v)
{
	return Color(c.r * v.x, c.g * v.y, c.b * v.z, c.a * v.w);
}

Color operator*(const Vector3f& v, const Color& c)
{
	return c * v;
}

Color operator*(const Vector4f& v, const Color& c)
{
	return c * v;
}

Color operator+(const Color& c, const Color& d)
{
	return Color(c.r + d.r, c.g + d.g, c.b + d.b, c.a + d.a);
}

Color operator*(const Color& c, float f)
{
	return Color(c.r * f, c.g * f, c.b * f, c.a);
}

Color operator*(float f, const Color& c)
{
	return c * f;
}

Color operator/(const Color& c, float f)
{
	assert(abs(f) > 10e-5);
	return c * (1.0f / f);
}

float Color::ClampValue(float value)
{
	return Maths::Clamp(Color::MIN_VALUEF, Color::MAX_VALUEF, value);
}