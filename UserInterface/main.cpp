
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <iostream>
#include <math.h>

#include "SortingAlgorithms.hpp"

#include "InterfaceModule.hpp"

extern int swap_count;
extern int comp_count;

float ** numbers = nullptr;

int counter = 0;

float BubbleSwapCount(float n)
{
    swap_count = 0;
    
    if (n > 0)
    {
        BubbleSort(numbers[int(n) - 1], int(n));
    }
    
    return swap_count;
}

float BubbleCompCount(float n)
{
    comp_count = 0;
    
    if (n > 0)
    {
        BubbleSort(numbers[int(n) - 1], int(n));
    }
    
    return comp_count;
}

float SelectionSwapCount(float n)
{
    swap_count = 0;
    
    if (n > 0)
    {
        SelectionSort(numbers[int(n) - 1], int(n));
    }
    
    return swap_count;
}

float SelectionCompCount(float n)
{
    comp_count = 0;
    
    if (n > 0)
    {
        SelectionSort(numbers[int(n) - 1], int(n));
    }
    
    return comp_count;
}

float Parabola(float x)
{
    return x * x;
}

float CubeParabola(float x)
{
    return x * x * x;
}

int main()
{
    UI ui;
    ui.AddWindow(1000, 1200, "Plot");
    ui.AddWindow(1000, 1000, "Paint");

    numbers = new float * [100];
    for (int i = 0; i < 100; i++)
    {
        numbers[i] = new float[i + 1];
        for (int j = 0; j < i; j++)
        {
            numbers[i][j] = rand();
        }
    }

    Function funcs[] = {sin, cos, tan, Parabola};
    Plot plot(funcs,
              4,
              0.01,
              sf::Vector2f(-5, 5),
              sf::Vector2f(-5, 5),
              sf::Vector2f(980, 980),
              sf::Vector2f(10, 10));

    PlotButtonFunctionShow b_sin (&plot,
                                  0,
                                  sf::Vector2f(485, 90),
                                  sf::Vector2f(10, 1000),
                                  "Sin");
    PlotButtonFunctionShow b_cos (&plot,
                                  1,
                                  sf::Vector2f(485, 90),
                                  sf::Vector2f(505, 1000),
                                  "Cos");
    PlotButtonFunctionShow b_tan (&plot,
                                  2,
                                  sf::Vector2f(485, 90),
                                  sf::Vector2f(10, 1100),
                                  "Tan");
    PlotButtonFunctionShow b_par (&plot,
                                  3,
                                  sf::Vector2f(485, 90),
                                  sf::Vector2f(505, 1100),
                                  "Parabola");

    ui.GetWindow(0)->AddElement(&b_sin);
    ui.GetWindow(0)->AddElement(&b_cos);
    ui.GetWindow(0)->AddElement(&b_tan);
    ui.GetWindow(0)->AddElement(&b_par);
    
    ui.GetWindow(0)->AddElement(&plot);
    
    //---------------------------------
    
    Paint paint(Color::Black, 10, Vector(990, 990), Vector(5, 5));
    
    ui.GetWindow(1)->AddElement(&paint);
    
    while(true)
    {
        ui.Display();
    }

    for (int i = 0; i < 100; i++)
    {
        delete [] numbers[i];
    }
    delete [] numbers;
    
    return EXIT_SUCCESS;
}
