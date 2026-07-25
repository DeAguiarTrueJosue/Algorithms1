#pragma once
#include <array>

struct Vector2
{
	union
	{
		struct
		{
			float x;
			float y;
		};
		std::array<float, 2> v;
	};

	Vector2() : x(0), y(0) {}
	Vector2(float f) : x(f), y(f) {}
	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 operator-() const { return { -x, -y }; }
	Vector2 operator+(const Vector2& rhs) const { return { x + rhs.x, y + rhs.y }; }
	Vector2 operator-(const Vector2& rhs) const { return { x - rhs.x, y - rhs.y }; }
	Vector2 operator*(const float s) const { return{ x * s, y * s }; }
	Vector2 operator/(const float s) const { return{ x / s, y / s }; }

	Vector2& operator+=(const Vector2& rhs) { x += rhs.x, y += rhs.y; return *this; }
	Vector2& operator-=(const Vector2& rhs) { x -= rhs.x, y -= rhs.y; return *this; }
	Vector2& operator*=(const float s) { x *= s, y *= s; return *this; }
	Vector2& operator/=(const float s) { x /= s, y /= s; return *this; }

	float MagnitudeSquared() const { return (x * x) + (y * y); }
	float Magnitude() const { return sqrtf(MagnitudeSquared()); }

	float DistanceSquared(const Vector2& rhs) const { return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y); }
	float Distance(const Vector2& rhs) const { return sqrtf(DistanceSquared(rhs)); }
};