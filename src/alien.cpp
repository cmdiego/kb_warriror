#include "../inc/alien.hpp"
#include "alien.hpp"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
    this->type = type;
    this->position = position;

    // Check if the texture for this alien has been loaded before, if not, go into switch to load
    if(alienImages[type - 1].id == 0) 
    {
        // Load the correct image depending on alien type
        switch(type)
        {
            case 1:
                alienImages[0] = LoadTexture("graphics/alien_1.png");
                break;
            case 2:
                alienImages[1] = LoadTexture("graphics/alien_2.png");
                break;
            case 3:
                alienImages[2] = LoadTexture("graphics/alien_3.png");
                break;
            default:
                alienImages[0] = LoadTexture("graphics/alien_1.png");
                break;
        }
    }
}

int Alien::GetType()
{
    return type;
}

void Alien::Draw()
{
    DrawTextureV(alienImages[type - 1], position, WHITE);
}

void Alien::Update(int direction)
{
    this->position.x += direction;
}

void Alien::UnloadImages()
{
    for(int i = 0; i < 3; i++)
    {
        UnloadTexture(alienImages[i]);
    }
}

