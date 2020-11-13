//
//  Vertex.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include "Vector.hpp"
#include "Color.hpp"

struct Vertex : public Vector, public Color
{
    Vertex(Vector vector, class Color color = Color::Black);
};

#endif /* Vertex_hpp */
