//
//  Text.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 10/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

#include <string.h>

#include <SFML/Graphics.hpp>

#include "Font.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "Rectangle.hpp"

class Text
{
    friend class RenderWindow;
    
    private:
        sf::Text Body;
    
    public:
        Text(std::string text = "");
    
        void SetString(std::string text);
        void SetFont(Font font);
        void SetFillColor(Color color);
        void SetPosition(Vector pos);
    
        std::string GetString();
        Font GetFont();
        Color GetFillColor();
        Vector GetPosition();
    
        Rectangle GetGlobalBounds();
};

#endif /* Text_hpp */
