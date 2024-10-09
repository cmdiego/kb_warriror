#include "../inc/alien.hpp"

Alien::Alien(int type, Vector2 position)
{
    this->type = type;
    this->position = position;
    // Load the correct image depending on alien type
    switch(type)
    {
        case 1:
            image = LoadTexture("graphics/alien_1.png");
            break;
        case 2:
            image = LoadTexture("graphics/alien_2.png");
            break;
        case 3:
            image = LoadTexture("graphics/alien_3.png");
            break;
        default:
            image = LoadTexture("graphics/alien_1.png");
            break;
    }
}

int Alien::GetType()
{
    return type;
}

void Alien::Draw()
{
    DrawTextureV(image, position, WHITE);
}

