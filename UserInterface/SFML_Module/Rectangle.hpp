//
//  Rectangle.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <SFML/Graphics.hpp>

#include "Vector.hpp"

class Rectangle
{
    private:
        Vector Size;
        Vector Position;
        
    public:
        Rectangle(Vector size, Vector pos = Vector(0, 0));
    
        Vector GetSize();
        Vector GetPosition();
    
        bool Contains(Vector point);
};

#endif /* Rectangle_hpp */
