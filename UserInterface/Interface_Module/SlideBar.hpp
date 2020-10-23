//
//  SlideBar.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 19/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef SlideBar_hpp
#define SlideBar_hpp

#include "SFMLModule.hpp"

class SlideBar : public Element
{
    private:
        float Value;
        
        Vector Interval;
        float Step;
    
        Line Axis;
        RectangleShape Body;
    
        bool IsClicked;
    
        Vector GetBodyPosition();
        void   SetBodyPosition();
    
        void Draw(RenderWindow & window) override;
    
    public:
        SlideBar(Vector inter,
                 float step = 1,
                 Vector size = Vector(0, 0),
                 Vector pos  = Vector(0, 0));
    
        void SetValue(float value);
    
        float GetValue();
                  
        void EventHandler(const Event & event) override;
};

#endif /* SlideBar_hpp */
