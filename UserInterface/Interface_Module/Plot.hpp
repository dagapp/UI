//
//  Plot.hpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 20/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#ifndef Plot_hpp
#define Plot_hpp

#include <math.h>

#include "SFMLModule.hpp"

#include "Window.hpp"
#include "Button.hpp"

typedef float(* Function)(float);
const int FunctionsColorsCount = 6;

class Plot : public Element
{
    private:
        Vector XInterval;
        Vector YInterval;
    
        float Precision;
    
        Function * Functions;
        int FunctionsCount;
    
        Color FunctionsColors[FunctionsColorsCount] =
        {
            Color::Black,
            Color::Green,
            Color::Red,
            Color::Blue,
            Color::Magenta,
            Color::Cyan
        };
    
        bool IsClicked;
    
        virtual void Draw(RenderWindow & window) override;
        
    public:
        bool * VisibleFunctions;
    
        Plot(Function func,
             float prec = 0.1,
             Vector xinter = Vector(-10, 10),
             Vector yinter = Vector(-10, 10),
             Vector size   = Vector(0, 0),
             Vector pos    = Vector(0, 0));
        Plot(Function * funcs,
             int count,
             float prec = 0.1,
             Vector xinter = Vector(-10, 10),
             Vector yinter = Vector(-10, 10),
             Vector size   = Vector(0, 0),
             Vector pos    = Vector(0, 0));
        ~Plot();
    
        void SetXInterval(float start, float end);
        void SetXInterval(Vector interval);
        Vector GetXInterval();
    
        void SetYInterval(float start, float end);
        void SetYInterval(Vector interval);
        Vector GetYInterval();
        
        void  SetPrecision(float precision);
        float GetPrecision();
    
        void SetFunctions(Function * funcs, int count);
        void AddFunction(Function func);
        void AddFunctions(Function * funcs, int count);
        Function * GetFunctions();
        int GetFunctionsCount();
    
        void ShowFunction (int index);
        void ShowFunctions(int * indeces, int count);
        void ShowFunctionsAll();
    
        void HideFunction (int index);
        void HideFunctions(int * indeces, int count);
        void HideFunctionsAll();
        
        Vector AbsPoint(float x, float y) const;
        Vector AbsPoint(Vector point) const;
    
        virtual void EventHandler(const Event & event) override;
};

class PlotButtonFunctionShow : public Button
{
    private:
        Plot * CurrentPlot;
        int FunctionNumber;
    
    public:
        PlotButtonFunctionShow(Plot * plot,
                               int function_number,
                               Vector size = Vector(0, 0),
                               Vector pos  = Vector(0, 0),
                               std::string text = "",
                               Color display_color = Color::White,
                               Color click_color = Color(128, 128, 128)
                               );
    
        void ClickHandler() override;
};

#endif /* Plot_hpp */
