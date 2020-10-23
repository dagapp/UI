//
//  Element.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Element.hpp"

void Element::SetPosition(int x, int y)
{
    Position.X = x;
    Position.Y = y;
}

void Element::SetPosition(Vector position)
{
    Position = position;
}

Vector Element::GetPosition()
{
    return Position;
}


void Element::SetSize(int x, int y)
{
    Size.X = x;
    Size.Y = y;
}

void Element::SetSize(Vector size)
{
    Size = size;
}

Vector Element::GetSize()
{
    return Size;
}


