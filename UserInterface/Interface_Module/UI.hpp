//
//  UI.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef UI_hpp
#define UI_hpp

#include "Window.hpp"

class UI
{
    private:
        std::vector<Window *> Windows;
    
    public:
        void AddWindow(Window * window);
        void AddWindow(unsigned int width, unsigned int height, std::string title = "");
    
        void RemoveWindow(int index);
    
        Window * GetWindow(int index);
        
        void OpenWindow(int index);
        void CloseWindow(int index);
    
        void Display();
};

#endif /* UI_hpp */
