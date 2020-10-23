//
//  Rectangle.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(Vector size, Vector pos)
{
    Size = size;
    Position = pos;
}

Vector Rectangle::GetSize()
{
    return Size;
}

Vector Rectangle::GetPosition()
{
    return Position;
}

bool Rectangle::Contains(Vector point)
{
    return (Position < point && point < Position + Size);
}
