//
//  Vertex.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Vertex.hpp"

Vertex::Vertex(Vector vector, class Color color)
{
    X = vector.X;
    Y = vector.Y;
    
    R(color.R());
    G(color.G());
    B(color.B());
    A(color.A());
}
