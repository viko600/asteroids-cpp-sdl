#include "Vector.h"


Vector2D::Vector2D(){
    x = 0;
    y = 0;
}

Vector2D& Vector2D::operator+(const Vector2D&& other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D& Vector2D::operator-(const Vector2D&& other){
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator*(const Vector2D&& other){
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vector2D& Vector2D::operator/(const Vector2D&& other){
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}