//
//  Container.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Container.hpp"

Container::Container()
{
    Size.X = 0;
    Size.Y = 0;
    
    Position.X = 0;
    Position.Y = 0;
}

Container::Container(unsigned int width, unsigned int height, unsigned int pos_x, unsigned int pos_y)
{
    Size.X = width;
    Size.Y = height;
    
    Position.X = pos_x;
    Position.Y = pos_y;
}

Container::Container(Vector size, Vector pos)
{
    Size = size;
    Position = pos;
}

void Container::Draw(RenderWindow & window)
{
    for (Element * element : Elements)
    {
        window.Draw(* element);
    }
}

void Container::AddElement(Element * element)
{
    Elements.push_back(element);
}

void Container::EventHandler(const Event & event)
{
    for (Element * element : Elements)
    {
        element->EventHandler(event);
    }
}
