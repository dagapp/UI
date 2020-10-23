//
//  SphereScene.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef SphereScene_hpp
#define SphereScene_hpp

#include <math.h>

#include "SFMLModule.hpp"

class SphereScene : public Element
{
    private:
        Vector3 Camera;
    
        bool IsClicked;
    
        Vector3 ToScene(Vector point);
        Vector  ToDisplay(Vector3 point);
    
        void Draw(RenderWindow & window) override;
        
    public:
        Color Sphere;
        Color Light;
        Color Ambient;
    
        int Radius;
        int Material;
    
        Vector3 LightPosition;
    
        SphereScene(Color sphere,
                    Color light,
                    Color ambient,
                    int radius,
                    int material,
                    Vector3 light_pos,
                    int size,
                    Vector pos = Vector(0, 0));
        
        void EventHandler(const Event & event) override;
};

#endif /* SphereScene_hpp */
