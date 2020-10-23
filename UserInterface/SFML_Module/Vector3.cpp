//
//  Vector3.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 19/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Vector3.hpp"

Vector3::Vector3(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector3::Vector3(sf::Vector3f vector)
{
    X = vector.x;
    Y = vector.y;
    Z = vector.z;
}

Vector3::Vector3(sf::Vector3i vector)
{
    X = vector.x;
    Y = vector.y;
    Z = vector.z;
}


float Vector3::Length()
{
    return sqrt(X * X + Y * Y + Z * Z);
}


Vector3 Vector3::Normalize()
{
    return (* this) / Length();
}


Vector3 Vector3::operator - ()
{
    return Vector3(-X, -Y, -Z);
}


Vector3 Vector3::operator + (Vector3 vector)
{
    return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
}

Vector3 Vector3::operator - (Vector3 vector)
{
    return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
}


Vector3 Vector3::operator * (float number)
{
    return Vector3(X * number, Y * number, Z * number);
}

Vector3 Vector3::operator * (Vector3 vector)
{
    return Vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
}

float Vector3::operator ^ (Vector3 vector)
{
    return X * vector.X + Y * vector.Y + Z * vector.Z;
}


Vector3 Vector3::operator / (float number)
{
    return Vector3(X / number, Y / number, Z / number);
}


bool Vector3::operator < (Vector3 vector)
{
    return (X < vector.X && Y < vector.Y && Z < vector.Z);
}

bool Vector3::operator > (Vector3 vector)
{
    return (X > vector.X && Y > vector.Y && Z > vector.Z);
}
