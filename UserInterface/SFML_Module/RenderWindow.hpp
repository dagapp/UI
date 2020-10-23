//
//  RenderWindow.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 05/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef RenderWindow_hpp
#define RenderWindow_hpp

#include <stdio.h>
#include <string.h>

#include <SFML/Graphics.hpp>

#include "Color.hpp"
#include "Element.hpp"
#include "Event.hpp"
#include "RectangleShape.hpp"
#include "Line.hpp"
#include "Text.hpp"

class RenderWindow
{
    public:
        sf::RenderWindow Body;
        
//    public:
        RenderWindow(unsigned int width, unsigned int height, std::string title = "");
    
        void Create(unsigned int width, unsigned int height, std::string title = "");
    
        void SetSize(Vector size);
        void SetPosition(Vector pos);
        
        Vector GetSize();
        Vector GetPosition();
        
        bool IsOpen();
    
        void Close();
    
        void Clear(const Color & color);
    
        void Draw(Element & element);
        void Draw(RectangleShape & rect);
        void Draw(Line & line);
        void Draw(Text & text);
    
        void Display();
    
        bool PollEvent(Event & event);
};

#endif /* RenderWindow_hpp */
