#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <SDL2/SDL.h>
#include <string>
#include <stdint>

typedef Uint32_t ticks_t;

//Multiplier used on time-dependant operations to convert milliseconds to seconds
const double G_MS_TO_S_MULTIPLIER = 0.001;

struct Vector2
{
    double x;
    double y;
};

struct Vector2Int
{
    int x;
    int y;
};


typedef Vector2 Point_t;

Vector2 operator+(Vector2, Vector2);
Vector2 operator-(Vector2, Vector2);
Vector2 operator*(Vector2, Vector2);
Vector2 operator/(Vector2, Vector2);
Vector2 operator*(Vector2, double);

Vector2& operator+=(Vector2&, Vector2);

std::string toString(const Vector2& vector);


struct Rect
{
    Point_t position;
    Vector2 size;
};

struct RectInt
{
    Vector2Int position;
    Vector2Int size;
};


SDL_Rect* RectIntToSDLRect(RectInt a);


#endif
