//
//  Container.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 26/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include "SFMLModule.hpp"

class Container : public Element
{
    private:
        std::vector<Element *> Elements;
    
        virtual void Draw(RenderWindow & window) override;
        
    public:
        Container();
        Container(unsigned int width,
                  unsigned int height,
                  unsigned int pos_x = 0,
                  unsigned int pos_y = 0);
        Container(Vector size,
                  Vector pos = Vector(0, 0));
    
        void AddElement(Element * element);
    
        virtual void EventHandler(const Event & event) override;
};

#endif /* Container_hpp */
