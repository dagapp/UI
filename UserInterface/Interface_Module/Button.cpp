//
//  Button.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Button.hpp"

Button::Button(Action click_handler, Vector size, Vector pos, std::string text, Color display_color, Color click_color)
{
    ClickHandler = click_handler;
    
    Position = pos;
    Size = size;
    
    DisplayColor = display_color;
    ClickColor = click_color;
    
    Body.SetSize(Size);
    Body.SetPosition(Position);
    Body.SetFillColor(display_color);
    Body.SetOutlineThickness(2);
    Body.SetOutlineColor(Color::Black);
    
    Font font;
    font.LoadFromFile("sansation.ttf");
    SetFont(font);
    
    SetText(text);
    Label.SetFillColor(Color::Black);
}


bool Button::GetState()
{
    return State;
}
    
Font Button::GetFont()
{
    return Label.GetFont();
}

void Button::SetFont(const Font & font)
{
    Label.SetFont(font);
}

std::string Button::GetText()
{
    return Label.GetString();
}

void Button::SetText(std::string text)
{
    Label.SetString(text);
    Label.SetPosition(Vector(Position.X + (Size.X - Label.GetGlobalBounds().GetSize().X) / 2, Position.Y + (Size.Y - Label.GetGlobalBounds().GetSize().Y) / 2));
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

Action Button::GetClickHandler()
{
    return ClickHandler;
}

void Button::SetClickHandler(Action action)
{
    ClickHandler = action;
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
