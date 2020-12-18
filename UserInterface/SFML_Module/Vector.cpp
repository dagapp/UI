//
//  Vector.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Vector.hpp"

Vector::Vector(float x, float y)
{
    X = x;
    Y = y;
}

Vector::Vector(sf::Vector2f vector)
{
    X = vector.x;
    Y = vector.y;
}
Vector::Vector(sf::Vector2u vector)
{
    X = vector.x;
    Y = vector.y;
}
Vector::Vector(sf::Vector2i vector)
{
    X = vector.x;
    Y = vector.y;
}


float Vector::Length()
{
    return sqrt(X * X + Y * Y);
}

float Vector::Angle()
{
    return atan(Y / X);
}

Vector Vector::Normalize()
{
    return (* this) / Length();
}


Vector Vector::operator - ()
{
    return Vector(-X, -Y);
}


Vector Vector::operator + (Vector vector)
{
    return Vector(X + vector.X, Y + vector.Y);
}

Vector Vector::operator - (Vector vector)
{
    return Vector(X - vector.X, Y - vector.Y);
}


Vector Vector::operator * (float number)
{
    return Vector(X * number, Y * number);
}

float Vector::operator ^ (Vector vector)
{
    return X * vector.X + Y * vector.Y;
}


Vector Vector::operator / (float number)
{
    return Vector(X / number, Y / number);
}


bool Vector::operator < (Vector vector)
{
    return (X < vector.X && Y < vector.Y);
}

bool Vector::operator > (Vector vector)
{
    return (X > vector.X && Y > vector.Y);
}

bool Vector::operator <= (Vector vector)
{
    return (X <= vector.X && Y <= vector.Y);
}

bool Vector::operator >= (Vector vector)
{
    return (X >= vector.X && Y >= vector.Y);
}
