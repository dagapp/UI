//
//  Button.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Button.hpp"

Button::Button(Vector size, Vector pos, std::string text, Color display_color, Color click_color)
{
    DisplayColor = display_color;
    ClickColor = click_color;
    
    Body.SetSize(size);
    Body.SetPosition(pos);
    Body.SetFillColor(display_color);
    Body.SetOutlineThickness(2);
    Body.SetOutlineColor(Color::Black);
    
//    Font font;
//    font.LoadFromFile("sansation.ttf");
//    SetFont(font);

////    SetText(text);
//    Label.SetString(text);
//    Label.SetFillColor(Color::Black);
}


bool Button::GetState()
{
    return State;
}
    
Font Button::GetFont()
{
    return Label.GetFont();
}

void Button::SetFont(Font font)
{
    Label.SetFont(font);
}

std::string Button::GetText()
{
    return Label.GetString();
}

void Button::SetText(std::string text)
{
    Vector size = Body.GetSize();
    Vector pos  = Body.GetPosition();
    
    Label.SetString(text);
    Label.SetPosition(Vector(pos.X + (size.X - Label.GetGlobalBounds().GetSize().X) / 2, pos.Y + (size.Y - Label.GetGlobalBounds().GetSize().Y) / 2));
}

Color Button::GetDisplayColor()
{
    return GetDisplayColor();
}

void Button::SetDisplayColor(Color color)
{
    DisplayColor = color;
}

Color Button::GetClickColor()
{
    return ClickColor;
}

void Button::SetClickColor(Color color)
{
    ClickColor = color;
}


void Button::Animate()
{
    if (State)
    {
        Body.SetFillColor(ClickColor);
    }
    else
    {
        Body.SetFillColor(DisplayColor);
    }
}


void Button::Draw(RenderWindow & window)
{
    window.Draw(Body);
    window.Draw(Label);
}


void Button::ClickHandler()
{
    
}

void Button::EventHandler(const Event & event)
{
    if (Body.GetGlobalBounds().Contains(Vector(event.Body.mouseButton.x, event.Body.mouseButton.y)))
    {
        if (event.Body.type == event.Body.MouseButtonPressed)
        {
            ClickHandler();
            
            State = true;
        }
        else if (event.Body.type == event.Body.MouseButtonReleased)
        {
            State = false;
        }
        
        Animate();
    }
}
