//
//  Button.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <string.h>

#include "SFMLModule.hpp"

class Button : public Element
{
    protected:
        bool State;
    
        Text Label;
    
        Color DisplayColor;
        Color ClickColor;
    
        void Animate();

        virtual void Draw(RenderWindow & window) override;
    
    public:
        Button(Vector size = Vector(0, 0),
               Vector pos  = Vector(0, 0),
               std::string text = "",
               Color display_color = Color::White,
               Color click_color = Color(128, 128, 128)
               );
        
        bool GetState();
        
        Font GetFont();
        void SetFont(Font font);
        std::string GetText();
        void SetText(std::string text);
    
        Color GetDisplayColor();
        void SetDisplayColor(Color color);
        Color GetClickColor();
        void SetClickColor(Color color);
    
        virtual void ClickHandler();
    
        virtual void EventHandler(const Event & event) override;
};

#endif /* Button_hpp */
