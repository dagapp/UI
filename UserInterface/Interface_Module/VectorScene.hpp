//
//  VectorScene.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 30/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef VectorScene_hpp
#define VectorScene_hpp

#include "SFMLModule.hpp"

class VectorScene : public Element
{
    private:
        std::vector<Vector> Vectors;
    
        float length;
        float width;
    
        Vector ToScreen(Vector vector);
    
        void Draw(RenderWindow & window) override;
    
    public:
        VectorScene(std::vector<Vector> vectors, float length, float width, Vector size, Vector pos = Vector(0, 0));
};

#endif /* VectorScene_hpp */
