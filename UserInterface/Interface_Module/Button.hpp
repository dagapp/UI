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
    private:
        bool State;
    
        Text Label;
        
        RectangleShape Body;
    
        Color DisplayColor;
        Color ClickColor;

        Action ClickHandler;
    
        void Animate();

        void Draw(RenderWindow & window) override;
    
    public:
        Button(Action click_handler,
               Vector size = Vector(0, 0),
               Vector pos  = Vector(0, 0),
               std::string text = "",
               Color display_color = Color::White,
               Color click_color = Color(128, 128, 128)
               );
        
        bool GetState();
        
        Font GetFont();
        void SetFont(const Font & font);
        std::string GetText();
        void SetText(std::string text);
    
        Color GetDisplayColor();
        void SetDisplayColor(Color color);
        Color GetClickColor();
        void SetClickColor(Color color);

        Action GetClickHandler();
        void SetClickHandler(Action action);
    
        void EventHandler(const Event & event) override;
};

#endif /* Button_hpp */
