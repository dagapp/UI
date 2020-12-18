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
    Body.SetSize(Vector(0, 0));
    Body.SetPosition(Vector(0, 0));
}

Container::Container(unsigned int width, unsigned int height, unsigned int pos_x, unsigned int pos_y)
{
    Body.SetSize(Vector(width, height));
    Body.SetPosition(Vector(pos_x, pos_y));
}

Container::Container(Vector size, Vector pos)
{
    Body.SetSize(size);
    Body.SetPosition(pos);
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
