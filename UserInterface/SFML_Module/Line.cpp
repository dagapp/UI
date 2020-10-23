//
//  Line.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Line.hpp"

Line::Line(Vector start, Vector end, unsigned int thickness, Color color)
{
    Vector line = end - start;
    
    float angle = line.Angle();
    
    Vector pos = start + (Vector(sin(angle), -cos(angle)) * (thickness / 2));
    Vector size = Vector(line.Length(), thickness);
    
    Body.SetPosition(pos);
    Body.SetSize(size);
    Body.SetFillColor(color);
    Body.Rotate(180 / M_PI * angle);
}
