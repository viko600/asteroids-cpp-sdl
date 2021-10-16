#pragma once



class Vector2D
{
public:
    Vector2D();
    Vector2D(float x, float y, double a) : x{x}, y{y} {};

    Vector2D& operator+(const Vector2D&& other);
    Vector2D& operator-(const Vector2D&& other);
    Vector2D& operator*(const Vector2D&& other);
    Vector2D& operator/(const Vector2D&& other);

    float x;
    float y;
};