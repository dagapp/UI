//
//  SlideBar.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 19/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "SlideBar.hpp"

#include "SlideBar.hpp"

SlideBar::SlideBar(Vector inter, float step, Vector size, Vector pos)
{
    Size = size;
    Position = pos;
    
    Interval = inter;
    Step = step;
    
    Value = Interval.X;
    
    Position = pos;
    Size = size;
    
    IsClicked = false;
    
    Axis = Line(Vector(Position.X, Position.Y + Size.Y / 2), Vector(Position.X + Size.X, Position.Y + Size.Y / 2) , Size.Y / 3, Color(128, 128, 128));
    
//    Axis.setSize(Vector(Size.x, Size.y / 3));
//    Axis.setPosition(Vector(Position.x, Position.y + Size.y / 3));
//    Axis.setFillColor(sf::Color(128, 128, 128));
    
    Body = RectangleShape(Vector(20, Size.Y), GetBodyPosition());
    Body.SetFillColor(Color::White);
    Body.SetOutlineThickness(2);
    Body.SetOutlineColor(Color::Black);
    
//    Scroll.setRadius(Size.y / 2);
//    Scroll.setPosition(Vector(Position.x + (Value - Interval.y) / (Interval.y - Interval.x), Position.y));
//    Scroll.setFillColor(sf::Color::White);
//    Scroll.setOutlineThickness(2);
//    Scroll.setOutlineColor(sf::Color::Black);
}

Vector SlideBar::GetBodyPosition()
{
    return Vector(Position.X + (Value - Interval.Y) / (Interval.Y - Interval.X), Position.Y);
}

void SlideBar::SetBodyPosition()
{
    Body.SetPosition(Vector(Value / (Interval.Y - Interval.X) * Size.X + Position.X, Body.GetPosition().Y));
}

void SlideBar::SetValue(float value)
{
    Value = value;
    SetBodyPosition();
}

float SlideBar::GetValue()
{
    return Value;
}

void SlideBar::Draw(RenderWindow & window)
{
    window.Draw(Axis);
    window.Draw(Body);
}

void SlideBar::EventHandler(const Event & event)
{
    if (Rectangle(Size, Position).Contains(Vector(event.Body.mouseButton.x, event.Body.mouseButton.y)))
    {
        if (event.Body.type == event.Body.MouseButtonPressed)
        {
            IsClicked = true;
        }
        if(event.Body.type == event.Body.MouseButtonReleased)
        {
            IsClicked = false;
        }
    }
    
    if (Rectangle(Size, Position).Contains(Vector(event.Body.mouseMove.x, event.Body.mouseMove.y)))
    {
        if (IsClicked && (event.Body.type == event.Body.MouseMoved))
        {
            Body.SetPosition(Vector(event.Body.mouseMove.x - Body.GetSize().X / 2, Body.GetPosition().Y));
            
            Value = (Body.GetPosition().X - Position.X) / Size.X * (Interval.Y - Interval.X);
        }
    }
}

