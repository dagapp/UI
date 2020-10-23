//
//  Color.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Color.hpp"



const Color Color::Black       = sf::Color::Black;
const Color Color::White       = sf::Color::White;
const Color Color::Red         = sf::Color::Red;
const Color Color::Green       = sf::Color::Green;
const Color Color::Blue        = sf::Color::Blue;
const Color Color::Yellow      = sf::Color::Yellow;
const Color Color::Magenta     = sf::Color::Magenta;
const Color Color::Cyan        = sf::Color::Cyan;
const Color Color::Transparent = sf::Color::Transparent;



Color::Color(sf::Color color)
{
    Value = color;
}

Color::Color(int r, int g, int b, int a)
{
    Set(r, g, b, a);
}


void Color::Set(const Color & color)
{
    Value = color.Value;
}

void Color::Set(int r, int g, int b, int a)
{
    Value = sf::Color(r, g, b, a);
}


void Color::R(int value)
{
    Value.r = value;
}

void Color::G(int value)
{
    Value.g = value;
}

void Color::B(int value)
{
    Value.b = value;
}

void Color::A(int value)
{
    Value.a = value;
}


int Color::R() const
{
    return Value.r;
}

int Color::G() const
{
    return Value.g;
}

int Color::B() const
{
    return Value.b;
}

int Color::A() const
{
    return Value.a;
}
