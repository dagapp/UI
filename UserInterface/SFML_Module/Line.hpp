//
//  Line.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <math.h>

#include "RectangleShape.hpp"
#include "Color.hpp"
#include "Vector.hpp"

class Line
{
    friend class RenderWindow;
    
    private:
        RectangleShape Body;
    
    public:
        Line(Vector start = Vector(0, 0),
             Vector end =   Vector(0, 0),
             unsigned int thickness = 1,
             Color color = Color::Black);
};

#endif /* Line_hpp */
