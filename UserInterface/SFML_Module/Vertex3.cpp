//
//  Vertex3.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Vertex3.hpp"

Vertex3::Vertex3(Vector3 vector, Color color)
{
    X = vector.X;
    Y = vector.Y;
    Z = vector.Z;
    
    R(color.R());
    G(color.G());
    B(color.B());
    A(color.A());
}
