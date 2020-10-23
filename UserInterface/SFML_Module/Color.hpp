//
//  Color.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 03/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <SFML/Graphics.hpp>

class Color
{
    private:
        sf::Color Value;
    
        Color(sf::Color color);
    
    public:
        Color(int r = 255, int g = 255, int b = 255, int a = 255);
    
        void Set(const Color & color);
        void Set(int r = 255, int g = 255, int b = 255, int a = 255);
    
        void R(int value);
        void G(int value);
        void B(int value);
        void A(int value);
    
        int R() const;
        int G() const;
        int B() const;
        int A() const;
    
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        static const Color Transparent;
};

#endif /* Color_hpp */
