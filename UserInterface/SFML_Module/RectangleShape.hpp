//
//  RectangleShape.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef RectangleShape_hpp
#define RectangleShape_hpp

#include <SFML/Graphics.hpp>

#include "Vector.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"

class RectangleShape
{
    friend class RenderWindow;
    
    private:
        sf::RectangleShape Body;
    
    public:
        RectangleShape();
        RectangleShape(Vector size, Vector pos = Vector(0, 0));
        RectangleShape(unsigned int width, unsigned int height, unsigned int pos_x = 0, unsigned int pos_y = 0);
    
        void SetPosition(Vector pos);
        void SetSize(Vector size);
        void SetFillColor(Color color);
        void SetOutlineThickness(int thickness);
        void SetOutlineColor(Color color);

        Vector GetPosition() const;
        Vector GetSize() const;
        Color GetFillColor() const;
        float GetOutlineThickness() const;
        Color GetOutlineColor() const;
    
        Rectangle GetGlobalBounds() const;
    
        void Rotate(float angle);
};


#endif /* RectangleShape_hpp */
