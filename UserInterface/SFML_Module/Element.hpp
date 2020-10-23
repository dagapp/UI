//
//  Element.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 25/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

//#include "RenderWindow.hpp"
#include "Vector.hpp"
#include "Event.hpp"

class RenderWindow; // ???????????????????????????????????????????????????????????????????? //

typedef void(* Action)(void);

class Element
{
    friend class RenderWindow;
    
    protected:
        Vector Position;
        Vector Size;
    
        virtual void Draw(RenderWindow & window) = 0;
    
    public:
        void SetPosition(int x, int y);
        void SetPosition(Vector position);
        Vector GetPosition();
    
        void SetSize(int x, int y);
        void SetSize(Vector size);
        Vector GetSize();
    
        virtual void EventHandler(const Event & event) = 0;
};

#endif /* Element_hpp */
