//
//  Paint.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 18/12/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Paint_hpp
#define Paint_hpp

#include "SFMLModule.hpp"

class Paint : public Element
{
    private:
        Color BrushColor;
        int BrushThickness;
    
        Vector BrushPosition;
    
        bool IsClicked;
    
        sf::Image Scene;
        sf::Texture Texture;
        sf::Sprite Sprite;
    
        void DrawCircle(Vector point);
        void DrawLine(Vector first_point, Vector second_point);
    
        virtual void Draw(RenderWindow & window) override;
    
    public:
        Paint(Color brush_color, int brush_thickness, Vector size, Vector pos = Vector(0, 0));
    
        void SetBrushColor(Color brush_color);
        void SetThickness(int brush_thickness);
    
        virtual void EventHandler(const Event & event) override;
};

#endif /* Paint_hpp */
