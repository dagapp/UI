//
//  Paint.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 18/12/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Paint.hpp"

Paint::Paint(Color brush_color, int brush_thickness, Vector size, Vector pos)
{
    BrushColor = brush_color;
    BrushThickness = brush_thickness;
    
    IsClicked = false;
    
    Body.SetSize(size);
    Body.SetPosition(pos);
    
    Scene.create(size.X, size.Y);
    Texture.create(size.X, size.Y);
    
    for (int i = 0; i < size.X; i++)
    {
        for (int j = 0; j < size.Y; j++)
        {
            Scene.setPixel(i, j, sf::Color::White);
        }
    }
}

void Paint::DrawCircle(Vector point)
{
    for (int x = -BrushThickness; x < BrushThickness; x++)
    {
        for (int y = -BrushThickness; y < 2 * BrushThickness; y++)
        {
            if (x * x + y * y <= BrushThickness * BrushThickness)
            {
                Vector circle_point = Vector(point.X + x, point.Y + y);
                if (circle_point >= Vector(0, 0) && circle_point <= Body.GetSize())
                {
                    Scene.setPixel(circle_point.X, circle_point.Y, sf::Color(BrushColor.R(), BrushColor.G(), BrushColor.B()));
                }
            }
        }
    }
}

void Paint::DrawLine(Vector first_point, Vector second_point)
{
    Vector line = second_point - first_point;
    
    if(line.Y != 0)
    {
        float step = line.Y < 0 ? 1 : -1;
        float coeff = line.X / line.Y;

        for (int y = line.Y; y != 0; y += step)
        {
            DrawCircle(first_point + Vector(y * coeff, y));
        }
    }
    else
    {
        float step = line.X < 0 ? 1 : -1;
        for (int x = line.X; x != 0; x += step)
        {
            DrawCircle(first_point + Vector(x, 0));
        }
    }
}

void Paint::Draw(RenderWindow & window)
{
    Texture.update(Scene);
    Sprite.setTexture(Texture);
    
    window.Body.draw(Sprite);
}

void Paint::EventHandler(const Event & event)
{
    if (Body.GetGlobalBounds().Contains(Vector(event.Body.mouseButton.x, event.Body.mouseButton.y)))
    {
        if (event.Body.type == event.Body.MouseButtonPressed)
        {
            IsClicked = true;
            BrushPosition = Vector(event.Body.mouseButton.x, event.Body.mouseButton.y);
            DrawCircle(BrushPosition);
        }
        if(event.Body.type == event.Body.MouseButtonReleased)
        {
            IsClicked = false;
        }
    }

    if (Body.GetGlobalBounds().Contains(Vector(event.Body.mouseMove.x, event.Body.mouseMove.y)))
    {
        if (IsClicked && (event.Body.type == event.Body.MouseMoved))
        {
            DrawLine(BrushPosition, Vector(event.Body.mouseMove.x, event.Body.mouseMove.y));
            BrushPosition = Vector(event.Body.mouseMove.x, event.Body.mouseMove.y);
        }
    }
}
