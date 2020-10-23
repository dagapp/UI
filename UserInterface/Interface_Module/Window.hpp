//
//  Window.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "SFMLModule.hpp"

#include "Container.hpp"

class Window
{
    private:
        RenderWindow Body;
        Container Root;
        
    public:
        Window(unsigned int width, unsigned int height, std::string title = "");
        
        void Display();
        void Close();
    
        void AddElement(Element * element);
};

#endif /* Window_hpp */
