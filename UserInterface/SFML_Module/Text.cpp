//
//  Text.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 10/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Text.hpp"

Text::Text(std::string text)
{
    Body.setString(text);
}


void Text::SetString(std::string text)
{
    Body.setString(text);
}

void Text::SetFont(Font font)
{
    Body.setFont(font.Body);
}

void Text::SetFillColor(Color color)
{
    Body.setFillColor(sf::Color(color.R(), color.G(), color.B(), color.A()));
}

void Text::SetPosition(Vector pos)
{
    Body.setPosition(sf::Vector2f(pos.X, pos.Y));
}


std::string Text::GetString()
{
    return Body.getString();
}

Font Text::GetFont()
{
//    Font result;
//    result.Body = Body.getFont();
//    return result;
}

Color Text::GetFillColor()
{
    sf::Color result = Body.getFillColor();;
    return Color(result.r, result.g, result.b, result.a);
}

Vector Text::GetPosition()
{
    return Body.getPosition();
}


Rectangle Text::GetGlobalBounds()
{
    sf::FloatRect result = Body.getGlobalBounds();
    return Rectangle(Vector(result.width, result.height), Body.getPosition());
}
