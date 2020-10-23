//
//  UI.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "UI.hpp"

void UI::AddWindow(Window * window)
{
    Windows.push_back(window);
}

void UI::AddWindow(unsigned int width, unsigned int height, std::string title)
{
    Windows.push_back(new Window(width, height, title));
}

void UI::RemoveWindow(int index)
{
    //TODO
}

Window * UI::GetWindow(int index)
{
    return Windows.at(index);
}

void UI::OpenWindow(int index)
{
    //Windows.at(index)->Open();
}

void UI::CloseWindow(int index)
{
    Windows.at(index)->Close();
}


void UI::Display()
{
    for (Window * win : Windows)
    {
        win->Display();
    }
}
