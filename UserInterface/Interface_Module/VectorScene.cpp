//
//  VectorScene.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "VectorScene.hpp"

VectorScene::VectorScene(std::vector<Vector> vectors, float length, float width, Vector size, Vector pos)
{
    Vectors = vectors;
    
    Size = size;
    Position = pos;
}

Vector VectorScene::ToScreen(Vector vector)
{
    return Vector( vector.X + Size.X / 2,
                  -vector.Y + Size.Y / 2);
}

void VectorScene::Draw(RenderWindow & window)
{
    Vector arrow[2];
    
    for (Vector vector : Vectors)
    {
        //arrow[0] = 
    }
}
