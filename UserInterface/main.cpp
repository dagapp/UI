
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

void ButtonPressHandler()
{
    printf("%d\n", counter++);
}

void ColorIncrease(Color & color, int value = 1)
{
    if (color.B() >= 255)
    {
        color.B(0);
        if (color.G() >= 255)
        {
            color.G(0);
            if (color.R() >= 255)
            {
                color.R(0);
            }
            else
            {
                color.R(color.R() + value);
            }
        }
        else
        {
            color.G(color.G() + value);
        }
    }
    else
    {
        color.B(color.B() + value);
    }
}

int main()
{
    UI ui;
    ui.AddWindow(1500, 1000, "3D Sphere");

    
//    numbers = new float * [100];
//    for (int i = 0; i < 100; i++)
//    {
//        numbers[i] = new float[i + 1];
//        for (int j = 0; j < i; j++)
//        {
//            numbers[i][j] = rand();
//        }
//    }
//
//
//    Function funcs_bubble[] = {BubbleSwapCount, BubbleCompCount};
//    Function funcs_select[] = {SelectionSwapCount, SelectionCompCount};
//
//    Plot plot_bubble(funcs_bubble,
//                     2,
//                     1,
//                     sf::Vector2f(0, 100),
//                     sf::Vector2f(0, 100),
//                     sf::Vector2f(985, 985),
//                     sf::Vector2f(10, 10));
//    Plot plot_select(funcs_select,
//                     2,
//                     1,
//                     sf::Vector2f(0, 100),
//                     sf::Vector2f(0, 100),
//                     sf::Vector2f(985, 985),
//                     sf::Vector2f(1005, 10));

//    Button b1(ButtonPressHandler,
//              sf::Vector2f(505, 95),
//              sf::Vector2f(250, 1055),
//              "Hello how are you?");
//
//    Button b2(ButtonPressHandler,
//              sf::Vector2f(505, 95),
//              sf::Vector2f(1225, 1055),
//              "Okay, Dmitriy");
//
//
//    ui.GetWindow(0)->AddElement(&b1);
//    ui.GetWindow(0)->AddElement(&b2);
//    ui.GetWindow(0)->AddElement(&plot_bubble);
//    ui.GetWindow(0)->AddElement(&plot_select);
//
//    for (int i = 0; i < 100; i++)
//    {
//        delete [] numbers[i];
//    }
//    delete [] numbers;
    
    
    SphereScene sphere(Color::White, Color::White, Color::Black, 450, 15, Vector3(500, 500, 500), 1000, Vector(0, 0));
    
    Container s_color(Vector(480, 180), Vector(1010, 10));
    Container l_color(Vector(480, 180), Vector(1010, 210));
    Container l_pos(Vector(480, 180), Vector(1010, 410));
    
    SlideBar s_sb_r(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 10));
    SlideBar s_sb_g(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 70));
    SlideBar s_sb_b(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 130));
//    s_sb_r.SetValue(255);
//    s_sb_g.SetValue(255);
//    s_sb_b.SetValue(255);
    
    SlideBar l_sb_r(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 210));
    SlideBar l_sb_g(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 270));
    SlideBar l_sb_b(Vector(0, 255), 1, Vector(480, 50), Vector(1010, 330));
//    l_sb_r.SetValue(255);
//    l_sb_g.SetValue(255);
//    l_sb_b.SetValue(255);
    
    SlideBar l_sb_x(Vector(-500, 500), 1, Vector(480, 50), Vector(1010, 410));
    SlideBar l_sb_y(Vector(-500, 500), 1, Vector(480, 50), Vector(1010, 470));
    SlideBar l_sb_z(Vector(-1000, 1000), 1, Vector(480, 50), Vector(1010, 530));
    
    SlideBar s_sb_m(Vector(1, 100), 1, Vector(480, 50), Vector(1010, 610));
    
    s_color.AddElement(&s_sb_r);
    s_color.AddElement(&s_sb_g);
    s_color.AddElement(&s_sb_b);
    
    l_color.AddElement(&l_sb_r);
    l_color.AddElement(&l_sb_g);
    l_color.AddElement(&l_sb_b);
    
    l_pos.AddElement(&l_sb_x);
    l_pos.AddElement(&l_sb_y);
    l_pos.AddElement(&l_sb_z);
    
    ui.GetWindow(0)->AddElement(&sphere);
    ui.GetWindow(0)->AddElement(&s_color);
    ui.GetWindow(0)->AddElement(&l_color);
    ui.GetWindow(0)->AddElement(&l_pos);
    ui.GetWindow(0)->AddElement(&s_sb_m);
    
    Vector3 add;
    
    while(true)
    {
        ui.Display();
        
        sphere.Sphere = Color(s_sb_r.GetValue(), s_sb_g.GetValue(), s_sb_b.GetValue());
        sphere.Light  = Color(l_sb_r.GetValue(), l_sb_g.GetValue(), l_sb_b.GetValue());
        sphere.LightPosition = Vector3(l_sb_x.GetValue(), l_sb_y.GetValue(), l_sb_z.GetValue());
        sphere.Material = s_sb_m.GetValue();

//        sphere.Material++;
        
//        add = Vector3(-sphere.LightPosition.Z,
//                      0,
//                      sphere.LightPosition.X);
//        add = add.Normalize();
//
//        sphere.LightPosition = sphere.LightPosition + add * 50;
    }

    
//    RenderWindow rwin(800, 900, "Pipa");
//
//    Event event;
//    while (rwin.IsOpen())
//    {
//        while (rwin.PollEvent(event))
//        {
//            if (event.Body.type == sf::Event::Closed)
//            {
//                rwin.Close();
//            }
//
//            if (event.Body.type == sf::Event::KeyPressed && event.Body.key.code == sf::Keyboard::Escape)
//            {
//                rwin.Close();
//            }
//        }
//        rwin.Clear(Color::White);
//
//        rwin.Display();
//    }

    
    return EXIT_SUCCESS;
}
