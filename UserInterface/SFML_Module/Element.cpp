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
    Body.SetPosition(Vector(x, y));
}

void Element::SetPosition(Vector position)
{
    Body.SetPosition(position);
}

Vector Element::GetPosition()
{
    return Body.GetPosition();
}


void Element::SetSize(int x, int y)
{
    Body.SetSize(Vector(x, y));
}

void Element::SetSize(Vector size)
{
    Body.SetSize(size);
}

Vector Element::GetSize()
{
    return Body.GetSize();
}


