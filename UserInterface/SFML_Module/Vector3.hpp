//
//  Vector3.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 19/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <math.h>

#include <SFML/Graphics.hpp>

struct Vector3
{
    float X;
    float Y;
    float Z;
    
    Vector3(float x = 0, float y = 0, float z = 0);
    Vector3(sf::Vector3f vector);
    Vector3(sf::Vector3i vector);
    
    float Length();
    
    Vector3 Normalize();
    
    Vector3 operator - ();
    
    Vector3 operator + (Vector3 vector);
    Vector3 operator - (Vector3 vector);
    
    Vector3 operator * (float number);
    Vector3 operator * (Vector3 vector);
    
    float   operator ^ (Vector3 vector);
    
    Vector3 operator / (float number);
    
    bool    operator < (Vector3 vector);
    bool    operator > (Vector3 vector);
};

#endif /* Vector3_hpp */
