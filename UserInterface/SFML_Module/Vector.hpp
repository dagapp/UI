//
//  Vector.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <math.h>

#include <SFML/Graphics.hpp>

struct Vector
{
    float X;
    float Y;
    
    Vector(float x = 0, float y = 0);
    Vector(sf::Vector2f vector);
    Vector(sf::Vector2u vector);
    Vector(sf::Vector2i vector);
    
    float Length();
    float Angle();
    
    Vector Normalize();
    
    Vector operator - ();
    
    Vector operator + (Vector vector);
    Vector operator - (Vector vector);
    
    Vector operator * (float number);
    
    float  operator ^ (Vector vector);
    
    Vector operator / (float number);
    
    bool   operator < (Vector vector);
    bool   operator > (Vector vector);
};

#endif /* Vector_hpp */
