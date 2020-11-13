//
//  Vertex3.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Vertex3_hpp
#define Vertex3_hpp

#include "Vector3.hpp"
#include "Color.hpp"

struct Vertex3 : public Vector3, public Color
{
    Vertex3(Vector3 vector, Color color = Color::White);
};

#endif /* Vertex3_hpp */
