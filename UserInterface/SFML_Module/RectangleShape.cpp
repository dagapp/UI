//
//  RectangleShape.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "RectangleShape.hpp"

RectangleShape::RectangleShape()
{
    Body.setSize(sf::Vector2f(0, 0));
    Body.setPosition(sf::Vector2f(0, 0));
}

RectangleShape::RectangleShape(Vector size, Vector pos)
{
    Body.setSize(sf::Vector2f(size.X, size.Y));
    Body.setPosition(sf::Vector2f(pos.X, pos.Y));
}

RectangleShape::RectangleShape(unsigned int width, unsigned int height, unsigned int pos_x, unsigned int pos_y)
{
    Body.setSize(sf::Vector2f(width, height));
    Body.setPosition(sf::Vector2f(pos_x, pos_y));
}



void RectangleShape::SetPosition(Vector pos)
{
    Body.setPosition(pos.X, pos.Y);
}

void RectangleShape::SetSize(Vector size)
{
    Body.setSize(sf::Vector2f(size.X, size.Y));
}

void RectangleShape::SetFillColor(Color color)
{
    Body.setFillColor(sf::Color(color.R(), color.G(), color.B(), color.A()));
}

void RectangleShape::SetOutlineThickness(int thickness)
{
    Body.setOutlineThickness(thickness);
}

void RectangleShape::SetOutlineColor(Color color)
{
    Body.setOutlineColor(sf::Color(color.R(), color.G(), color.B(), color.A()));
}



Vector RectangleShape::GetPosition() const
{
    sf::Vector2f pos = Body.getPosition();
    return Vector(pos.x, pos.y);
}

Vector RectangleShape::GetSize() const
{
    sf::Vector2f size = Body.getSize();
    return Vector(size.x, size.y);
}

Color RectangleShape::GetFillColor() const
{
    sf::Color color = Body.getFillColor();
    return Color(color.r, color.g, color.b, color.a);
}

float RectangleShape::GetOutlineThickness() const
{
    return Body.getOutlineThickness();
}

Color RectangleShape::GetOutlineColor() const
{
    sf::Color result = Body.getOutlineColor();
    return Color(result.r, result.g, result.b, result.a);
}



Rectangle RectangleShape::GetGlobalBounds() const
{
    return Rectangle(Body.getSize(), Body.getPosition());
}

void RectangleShape::Rotate(float angle)
{
    Body.rotate(angle);
}
