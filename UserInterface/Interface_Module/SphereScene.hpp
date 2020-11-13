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
    
        Vector3 Light(Vector3 point, int light_index);
    
        void Draw(RenderWindow & window) override;
        
    public:
        Color Sphere;
        Color Ambient;
    
        int Radius;
        int Material;
    
        std::vector<Vertex3> Lights;
    
        SphereScene(Color sphere,
                    std::vector<Vertex3> lights,
                    Color ambient,
                    int radius,
                    int material,
                    int size,
                    Vector pos = Vector(0, 0));
        
        ~SphereScene();
    
        void AddLight(Vertex3 vertex);
        void RemoveLight(int index);
        
        void EventHandler(const Event & event) override;
};

#endif /* SphereScene_hpp */
