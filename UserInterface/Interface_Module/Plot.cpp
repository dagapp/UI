//
//  Plot.cpp
//  SFML_Plot
//
//  Created by Danila Agapitov on 20/09/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "Plot.hpp"

Plot::Plot(Function func, float prec, Vector xinter, Vector yinter, Vector size, Vector pos)
{
    FunctionsCount = 1;
    
    Functions = new Function[FunctionsCount];
    Functions[0] = func;
    
    VisibleFunctions = new bool[FunctionsCount];
    for (int i = 0; i < FunctionsCount; i++)
    {
        VisibleFunctions[i] = false;
    }
    
    Precision = prec;
    
    XInterval = xinter;
    YInterval = yinter;
    
    IsClicked = false;
    
    Body.SetPosition(pos);
    Body.SetSize(size);
}

Plot::Plot(Function * func, int count, float prec, Vector xinter, Vector yinter, Vector size, Vector pos)
{
    FunctionsCount = count;
    
    Functions = new Function[FunctionsCount];
    VisibleFunctions = new bool[FunctionsCount];
    for (int i = 0; i < FunctionsCount; i++)
    {
        Functions[i] = func[i];
        VisibleFunctions[i] = false;
    }
    
    Precision = prec;
    
    XInterval = xinter;
    YInterval = yinter;
    
    IsClicked = false;
    
    Body.SetPosition(pos);
    Body.SetSize(size);
}

Plot::~Plot()
{
    delete Functions;
    delete VisibleFunctions;
}


void Plot::Draw(RenderWindow & window)
{
    RectangleShape border(Body.GetSize());
    border.SetPosition(Body.GetPosition());
    border.SetOutlineThickness(2);
    border.SetOutlineColor(Color::Black);
    window.Draw(border);
    
    
    Line axis[2] = { Line(AbsPoint(XInterval.X, 0), AbsPoint(XInterval.Y, 0), 3),
                     Line(AbsPoint(0, YInterval.X), AbsPoint(0, YInterval.Y), 3) };
    window.Draw(axis[0]);
    window.Draw(axis[1]);
    
    
    float grid_step_x = (XInterval.Y - XInterval.X) / 8;
    float grid_step_y = (YInterval.Y - YInterval.X) / 8;
    
    float grid_curr_val = XInterval.X;
    
    Line grid[2][7];
    
    for (int i = 0; i < 7; i++)
    {
        grid_curr_val += grid_step_x;
        
        grid[0][i] = Line(AbsPoint(grid_curr_val, YInterval.X), AbsPoint(grid_curr_val, YInterval.Y));
    }
    
    grid_curr_val = YInterval.X;
    
    for (int i = 0; i < 7; i++)
    {
        grid_curr_val += grid_step_y;
        
        grid[1][i] = Line(AbsPoint(XInterval.X, grid_curr_val), AbsPoint(XInterval.Y, grid_curr_val));
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            window.Draw(grid[i][j]);
        }
    }
    
    
    Function func;
    Color color;
    for (int i = 0; i < FunctionsCount; i++)
    {
        if (VisibleFunctions[i])
        {
            func  = Functions[i];
            color = FunctionsColors[i % FunctionsColorsCount];
            
            float prev_x = XInterval.X;
            float curr_x = prev_x + Precision;
            
            float prev_y = func(prev_x);
            float curr_y = func(curr_x);
            
            Line line;
            
            while (curr_x < XInterval.Y)
            {
                if ((curr_y > YInterval.X && curr_y < YInterval.Y) && (prev_y > YInterval.X && prev_y < YInterval.Y))
                {
                    line = Line(AbsPoint(Vector(prev_x, prev_y)), AbsPoint(Vector(curr_x, curr_y)), 5, color);
                    
                    window.Draw(line);
                }
                
                prev_x = curr_x;
                curr_x += Precision;
                
                prev_y = curr_y;
                curr_y = func(curr_x);
            }
        }
    }
}


void Plot::SetXInterval(float start, float end)
{
    XInterval.X = start;
    XInterval.Y = end;
}

void Plot::SetXInterval(Vector interval)
{
    XInterval = interval;
}

Vector Plot::GetXInterval()
{
    return XInterval;
}


void Plot::SetYInterval(float start, float end)
{
    YInterval.X = start;
    YInterval.Y = end;
}

void Plot::SetYInterval(Vector interval)
{
    YInterval = interval;
}

Vector Plot::GetYInterval()
{
    return YInterval;
}


void Plot::SetPrecision(float precision)
{
    Precision = precision;
}

float Plot::GetPrecision()
{
    return Precision;
}


void Plot::SetFunctions(Function * funcs, int count)
{
    FunctionsCount = count;
    Functions = funcs;
}

void Plot::AddFunction(Function func)
{
    FunctionsCount++;
    
    Function * temp = Functions;
    Functions = new Function[FunctionsCount];
    for (int i = 0; i < FunctionsCount - 1; i++)
    {
        Functions[i] = temp[i];
    }
    Functions[FunctionsCount - 1] = func;
}

void Plot::AddFunctions(Function * funcs, int count)
{
    FunctionsCount += count;
    
    Function * temp = Functions;
    Functions = new Function[FunctionsCount];
    for (int i = 0; i < FunctionsCount - count; i++)
    {
        Functions[i] = temp[i];
    }
    for (int i = FunctionsCount - count; i < FunctionsCount; i++)
    {
        Functions[i] = funcs[i - (FunctionsCount - count)];
    }
}

Function * Plot::GetFunctions()
{
    return Functions;
}

int Plot::GetFunctionsCount()
{
    return FunctionsCount;
}


Vector Plot::AbsPoint(float x, float y) const
{
    Vector size = Body.GetSize();
    Vector pos  = Body.GetPosition();
    
    Vector result;
    
    float axis_x = XInterval.Y - XInterval.X;
    float axis_y = YInterval.Y - YInterval.X;
    
    float scale_x = size.X / axis_x;
    float scale_y = size.Y / axis_y;
    
    result.X = (std::abs(XInterval.X) + x) * scale_x + pos.X;
    result.Y = (std::abs(YInterval.Y) - y) * scale_y + pos.Y;
    
    return result;
}

Vector Plot::AbsPoint(Vector point) const
{
    return AbsPoint(point.X, point.Y);
}


void Plot::ShowFunction(int index)
{
    VisibleFunctions[index] = true;
}

void Plot::ShowFunctions(int * indeces, int count)
{
    for (int i = 0; i < count; i++)
    {
        VisibleFunctions[indeces[i]] = true;
    }
}

void Plot::ShowFunctionsAll()
{
    for (int i = 0; i < FunctionsCount; i++)
    {
        VisibleFunctions[i] = true;
    }
}

void Plot::HideFunction(int index)
{
    VisibleFunctions[index] = false;
}

void Plot::HideFunctions(int * indeces, int count)
{
    for (int i = 0; i < count; i++)
    {
        VisibleFunctions[indeces[i]] = false;
    }
}

void Plot::HideFunctionsAll()
{
    for (int i = 0; i < FunctionsCount; i++)
    {
        VisibleFunctions[i] = false;
    }
}


void Plot::EventHandler(const Event & event)
{
    if (Body.GetGlobalBounds().Contains(Vector(event.Body.mouseButton.x, event.Body.mouseButton.y)))
    {
        if (event.Body.type == event.Body.MouseButtonPressed)
        {
            IsClicked = true;
        }
        else if (event.Body.type == event.Body.MouseButtonReleased)
        {
            IsClicked = false;
        }
    }
    
    if (Body.GetGlobalBounds().Contains(Vector(event.Body.mouseMove.x, event.Body.mouseMove.y)))
    {
        if (IsClicked && (event.Body.type == event.Body.MouseMoved))
        {
//            printf("%f %f\n", event.Body.mouseMove.x, event.Body.mouseMove.y);
        }
    }
}




PlotButtonFunctionShow::PlotButtonFunctionShow(Plot * plot, int function_number, Vector size, Vector pos, std::string text, Color display_color, Color click_color) : Button(size, pos, text, display_color, click_color)
{
    CurrentPlot = plot;
    FunctionNumber = function_number;
}

void PlotButtonFunctionShow::ClickHandler()
{
    CurrentPlot->HideFunctionsAll();
    CurrentPlot->ShowFunction(FunctionNumber);
}
