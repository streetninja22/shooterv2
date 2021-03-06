#include "general/constructs.h"

double dot(Vector2 a, Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

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

Vector2& operator+=(Vector2& a, Vector2 b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

std::string toString(const Vector2& vector)
{
	return std::to_string(vector.x) + ", " + std::to_string(vector.y);
}

SDL_Rect* RectIntToSDLRect(RectInt a)
{
    SDL_Rect* b = new SDL_Rect;
    b->x = a.position.x;
    b->y = a.position.y;
    b->w = a.size.x;
    b->h = a.size.y;

	return b;
}
