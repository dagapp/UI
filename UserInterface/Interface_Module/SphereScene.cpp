//
//  SphereScene.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "SphereScene.hpp"

SphereScene::SphereScene(Color sphere, Color light, Color ambient, int radius, int material, Vector3 light_pos, int size, Vector pos)
{
    IsClicked = false;
    
    Sphere = sphere;
    Light = light;
    Ambient = ambient;
    
    Radius = radius;
    Material = material;
    
    LightPosition = light_pos;
    
    Size = Vector(size, size);
    Position = pos;
    
    Camera = Vector3(0, 0, size / 2);
}

Vector3 SphereScene::ToScene(Vector point)
{
    float x = point.X - (int)Size.X / 2;
    float y = point.Y - (int)Size.Y / 2;
    return Vector3(x, y, 0);
}

Vector SphereScene::ToDisplay(Vector3 point)
{
    return Vector(point.X + (int)Size.X / 2,
                  point.Y + (int)Size.Y / 2);
}

void SphereScene::Draw(RenderWindow & window)
{
    sf::Image scene;
    scene.create(Size.X, Size.Y);
    sf::Texture texture;
    texture.create(Size.X, Size.Y);
    sf::Sprite sprite;
    
    Vector3 sphere  = Vector3(Sphere.R() , Sphere.G() , Sphere.B() ) / 255;
    Vector3 light   = Vector3(Light.R()  , Light.G()  , Light.B()  ) / 255;
    Vector3 ambient = Vector3(Ambient.R(), Ambient.G(), Ambient.B()) / 255;
    
    sf::Color curr_color;
    
    Vector3 point;
    
    Vector3 point_normal;
    Vector3 light_normal;
    
    Vector3 light_reflection;
    Vector3 ambient_reflection;
    
    Vector3 flare_aim;
    float flare_angle_cos;
    float flare_coeff;
    
    float product;
    float light_coeff;
    
    Vector3 color;
    
    for (int i = 0; i < (int)Size.Y; i++)
    {
        for (int j = 0; j < (int)Size.X; j++)
        {
            point = ToScene(Vector(i, j));

            if (point.X * point.X + point.Y * point.Y <= Radius * Radius)
            {
                point.Z = sqrt(Radius * Radius - point.X * point.X - point.Y * point.Y);
                
                point_normal = point.Normalize();
                light_normal = (LightPosition - point).Normalize();
                
                product = point_normal ^ light_normal;
                light_coeff = product > 0 ? product : 0;
                
                light_reflection   = light   * (Light.A()   / 255);
                ambient_reflection = ambient * (Ambient.A() / 255);
                
                flare_aim = (LightPosition + (point_normal * (LightPosition ^ point_normal) - LightPosition) * 2).Normalize();
//                flare_aim = LightPosition - (point * 2) * ((LightPosition - point) ^ point / (point ^ point));
//                flare_aim = point_normal * 2 * light_coeff - light_normal;
                flare_angle_cos = flare_aim ^ Camera.Normalize();
                flare_coeff = flare_angle_cos > 0 ? pow(flare_angle_cos, Material) : 0;
                
                color = light * sphere * light_coeff +
                        light * flare_coeff +
                        light * ambient;
                
                if (color.X > 1) color.X = 1;
                if (color.Y > 1) color.Y = 1;
                if (color.Z > 1) color.Z = 1;
                
                color = color * 255;
                
                curr_color = sf::Color(color.X, color.Y, color.Z, Sphere.A());
            }
            else
            {
                curr_color = sf::Color(Ambient.R(), Ambient.G(), Ambient.B(), Ambient.A());
            }
            
            scene.setPixel(i, j, curr_color);
        }
    }
    
    texture.update(scene);
    sprite.setTexture(texture);
    
    window.Body.draw(sprite);
}

void SphereScene::EventHandler(const Event & event)
{
    if (Rectangle(Size, Position).Contains(Vector(event.Body.mouseButton.x, event.Body.mouseButton.y)))
    {
        if (event.Body.type == event.Body.MouseButtonPressed)
        {
            IsClicked = true;
        }
        if(event.Body.type == event.Body.MouseButtonReleased)
        {
            IsClicked = false;
        }
    }
    
    if (Rectangle(Size, Position).Contains(Vector(event.Body.mouseMove.x, event.Body.mouseMove.y)))
    {
        if (IsClicked && event.Body.type == event.Body.MouseMoved)
        {
            LightPosition = Vector3(event.Body.mouseMove.x - (int)Size.X / 2, event.Body.mouseMove.y - (int)Size.Y / 2, LightPosition.Z);
        }
    }
}
