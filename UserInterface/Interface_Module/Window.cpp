//
//  Window.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, std::string title) : Body(width, height, title), Root(width, height)
{
    //Body.Create(width, height, title);
    //Root = Container(width, height);
}

void Window::AddElement(Element * element)
{
    Root.AddElement(element);
}

void Window::Display()
{
    Event event;
    
    if (Body.IsOpen())
    {
        if (Body.PollEvent(event))
        {
            if (event.Body.type == sf::Event::Closed)
            {
                Body.Close();
            }

            if (event.Body.type == sf::Event::KeyPressed && event.Body.key.code == sf::Keyboard::Escape)
            {
                Body.Close();
            }
            
            Root.EventHandler(event);
        }
        Body.Clear(Color::White);
        
        Body.Draw(Root);
        
        Body.Display();
    }
}

void Window::Close()
{
    //TODO
}
