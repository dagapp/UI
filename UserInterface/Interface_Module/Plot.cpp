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
    
    Precision = prec;
    
    XInterval = xinter;
    YInterval = yinter;
    
    Position = pos;
    Size = size;
}

Plot::Plot(Function * func, int count, float prec, Vector xinter, Vector yinter, Vector size, Vector pos)
{
    FunctionsCount = count;
    
    Functions = new Function[FunctionsCount];
    for (int i = 0; i < FunctionsCount; i++)
    {
        Functions[i] = func[i];
    }
    
    Precision = prec;
    
    XInterval = xinter;
    YInterval = yinter;
    
    Position = pos;
    Size = size;
}

Plot::~Plot()
{
    delete Functions;
}


void Plot::Draw(RenderWindow & window)
{
    RectangleShape border(Size);
    border.SetPosition(Position);
    border.SetOutlineThickness(2);
    border.SetOutlineColor(Color::Black);
    window.Draw(border);
    
    
//    sf::Vertex grid[2][2] =
//    {
//        { Vertex(AbsPoint(XInterval.X, 0), Color::Black), Vertex(AbsPoint(XInterval.Y, 0), Color::Black) },
//        { Vertex(AbsPoint(0, YInterval.X), Color::Black), Vertex(AbsPoint(0, YInterval.Y), Color::Black) }
//    };
//    target.draw(grid[0], 2, sf::Lines, states);
//    target.draw(grid[1], 2, sf::Lines, states);
    
    Line axis[2] = { Line(AbsPoint(XInterval.X, 0), AbsPoint(XInterval.Y, 0)),
                     Line(AbsPoint(0, YInterval.X), AbsPoint(0, YInterval.Y)) };
    window.Draw(axis[0]);
    window.Draw(axis[1]);
    
    
    Function func;
    Color color;
    for (int i = 0; i < FunctionsCount; i++)
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
//            if (curr_y >= YInterval.X && curr_y <= YInterval.Y)
//            {
                line = Line(AbsPoint(Vector(prev_x, prev_y)), AbsPoint(Vector(curr_x, curr_y)), 2, color);
                
                window.Draw(line);
                
                prev_x = curr_x;
                curr_x += Precision;
                
                prev_y = curr_y;
                curr_y = func(curr_x);
//            }
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
    Vector result;
    
    float axis_x = XInterval.Y - XInterval.X;
    float axis_y = YInterval.Y - YInterval.X;
    
    float scale_x = Size.X / axis_x;
    float scale_y = Size.Y / axis_y;
    
    result.X = (std::abs(XInterval.X) + x) * scale_x + Position.X;
    result.Y = (std::abs(YInterval.Y) - y) * scale_y + Position.Y;
    
    return result;
}

Vector Plot::AbsPoint(Vector point) const
{
    return AbsPoint(point.X, point.Y);
}


void Plot::EventHandler(const Event & event)
{
    
}
