//
//  Font.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Font.hpp"

bool Font::LoadFromFile(std::string path)
{
    return Body.loadFromFile(path);
}
