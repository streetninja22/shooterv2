#include "general/constructs.h"

Vector2 operator+(Vector2 a, Vector2 b)
{
	return Vector2{a.x + b.x, a.y + b.y};
}

Vector2 operator-(Vector2 a, Vector2 b)
{
	return Vector2{a.x - b.x, a.y - b.y};
}

Vector2 operator*(Vector2 a, Vector2 b)
{
	return Vector2{a.x * b.x, a.y * b.y};
}

Vector2 operator/(Vector2 a, Vector2 b)
{
	return Vector2{a.x / b.x, a.y / b.y};
}

Vector2 operator*(Vector2 a, double b)
{
	return Vector2{a.x * b, a.y * b};
}
