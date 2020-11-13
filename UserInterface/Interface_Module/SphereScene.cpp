//
//  SphereScene.cpp
//  UserInterface
//
//  Created by Danila Agapitov on 16/10/2020.
//  Copyright © 2020 Danila Agapitov. All rights reserved.
//

#include "SphereScene.hpp"

SphereScene::SphereScene(Color sphere, std::vector<Vertex3> lights, Color ambient, int radius, int material, int size, Vector pos)
{
    IsClicked = false;
    
    Sphere = sphere;
    Ambient = ambient;
    
    Radius = radius;
    Material = material;
    
//    for (int i = 0; i < light_count; i++)
//    {
//        Lights.push_back(lights[i]);
//    }
    Lights = lights;
    
    Size = Vector(size, size);
    Position = pos;
    
    Camera = Vector3(0, 0, size / 2);
}

SphereScene::~SphereScene()
{
    
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

Vector3 SphereScene::Light(Vector3 point, int light_index)
{
    Vector3 sphere_col = Vector3(Sphere.R(), Sphere.G(), Sphere.B()) / 255;
    
    Vector3 light_col = Vector3(Lights.at(light_index).R(), Lights.at(light_index).G(), Lights.at(light_index).B()) / 255;
    Vector3 light_pos = Vector3(Lights.at(light_index).X,   Lights.at(light_index).Y,   Lights.at(light_index).Z);
    
    Vector3 point_normal;
    Vector3 light_normal;
    
    float light_cos;
    float light_coeff;
    
    Vector3 light_reflection;
    
    Vector3 flare_aim;
    
    float flare_angle_cos;
    float flare_coeff;
    
    Vector3 color;
    
    point_normal = point.Normalize();
    light_normal = (light_pos - point).Normalize();

    light_cos   = point_normal ^ light_normal;
    light_coeff = light_cos > 0 ? light_cos : 0;

    light_reflection = light_col * (Lights.at(light_index).A() / 255);

    flare_aim = (light_normal + (point_normal * (light_normal ^ point_normal) - light_normal) * 2).Normalize();
    flare_angle_cos = flare_aim ^ Camera.Normalize();
    flare_coeff = flare_angle_cos > 0 ? pow(flare_angle_cos, Material) : 0;

    color = light_col * sphere_col * light_coeff +
            light_col * flare_coeff;             

    if (color.X > 1) color.X = 1;
    if (color.Y > 1) color.Y = 1;
    if (color.Z > 1) color.Z = 1;
    
    return color * 255;
}

void SphereScene::Draw(RenderWindow & window)
{
    sf::Image scene;
    scene.create(Size.X, Size.Y);
    sf::Texture texture;
    texture.create(Size.X, Size.Y);
    sf::Sprite sprite;
    
    Vector3 curr_color;
    
    Vector3 point;
    
    for (int i = 0; i < (int)Size.Y; i++)
    {
        for (int j = 0; j < (int)Size.X; j++)
        {
            point = ToScene(Vector(i, j));

            if (point.X * point.X + point.Y * point.Y <= Radius * Radius)
            {
                point.Z = sqrt(Radius * Radius - point.X * point.X - point.Y * point.Y);
                
                for (int n = 0; n < Lights.size(); n++)
                {
                    curr_color = curr_color + Light(point, n);
                }
                
                if (curr_color.X > 255) curr_color.X = 255;
                if (curr_color.Y > 255) curr_color.Y = 255;
                if (curr_color.Z > 255) curr_color.Z = 255;
            }
            else
            {
                curr_color = Vector3(Ambient.R(), Ambient.G(), Ambient.B());
            }
            
            scene.setPixel(i, j, sf::Color(curr_color.X, curr_color.Y, curr_color.Z));
            
            curr_color = Vector3(0, 0, 0);
        }
    }
    
    texture.update(scene);
    sprite.setTexture(texture);
    
    window.Body.draw(sprite);
}

void SphereScene::AddLight(Vertex3 vertex)
{
    Lights.push_back(vertex);
}

void SphereScene::RemoveLight(int index)
{
    //Lights.
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
    
//    if (Rectangle(Size, Position).Contains(Vector(event.Body.mouseMove.x, event.Body.mouseMove.y)))
//    {
//        if (IsClicked && event.Body.type == event.Body.MouseMoved)
//        {
//            LightPosition = Vector3(event.Body.mouseMove.x - (int)Size.X / 2, event.Body.mouseMove.y - (int)Size.Y / 2, LightPosition.Z);
//        }
//    }
}
