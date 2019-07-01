#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

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



#endif
