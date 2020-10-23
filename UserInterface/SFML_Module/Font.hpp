//
//  Font.hpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Font_hpp
#define Font_hpp

#include <string.h>

#include <SFML/Graphics.hpp>

class Font
{
    public:
        sf::Font Body;
        
    //public:
        bool LoadFromFile(std::string path);
};

#endif /* Font_hpp */
