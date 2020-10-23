//
//  RenderWindow.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 05/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(unsigned int width, unsigned int height, std::string title)
{
    Create(width, height, title);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    Body.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void RenderWindow::Create(unsigned int width, unsigned int height, std::string title)
{
    Body.create(sf::VideoMode(width, height), title);
}
    
void RenderWindow::SetSize(Vector size)
{
    Body.setSize(sf::Vector2u(size.X, size.Y));
}

void RenderWindow::SetPosition(Vector pos)
{
    Body.setPosition(sf::Vector2i(pos.X, pos.Y));
}

Vector RenderWindow::GetSize()
{
    return Vector(Body.getSize());
}

Vector RenderWindow::GetPosition()
{
    return Vector(Body.getPosition());
}

bool RenderWindow::IsOpen()
{
    return Body.isOpen();
}

void RenderWindow::Close()
{
    Body.close();
}

void RenderWindow::Clear(const Color & color)
{
    Body.clear(sf::Color(color.R(), color.G(), color.B(), color.A()));
}

void RenderWindow::Draw(Element & element)
{
    element.Draw(* this);
}

void RenderWindow::Draw(RectangleShape & rect)
{
    Body.draw(rect.Body);
}

void RenderWindow::Draw(Line & line)
{
    Body.draw(line.Body.Body);
}

void RenderWindow::Draw(Text & text)
{
    Body.draw(text.Body);
}

void RenderWindow::Display()
{
    Body.display();
}

bool RenderWindow::PollEvent(Event & event)
{
    return Body.pollEvent(event.Body);
}
