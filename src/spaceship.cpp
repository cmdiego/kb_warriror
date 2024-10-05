#include "spaceship.hpp"

Spaceship::Spaceship() 
{
    image = LoadTexture("graphics/spaceshipGame.png");
    position.x = (GetScreenWidth() - image.width) / 2 + 70;
    position.y = (GetScreenHeight() - 60);
    lastFireTime = 0.0;
}

Spaceship::~Spaceship() 
{
    UnloadTexture(image);
}

void Spaceship::Draw() 
{
    DrawTextureEx(image, position, 0, 0.3, WHITE);
}

void Spaceship::MoveRight()
{
    this->position.x += 5;
    if(this->position.x > 730)
    {
        this->position.x = 730;
    }
}

void Spaceship::MoveLeft()
{
    this->position.x -= 5; 
    if(this->position.x < 0)
    {
        this->position.x = 0;
    } 
}

void Spaceship::FireLaser()
{
    if(GetTime() - lastFireTime >= 0.25)
    {
        // Create new laser and push it into lasers vector
        lasers.push_back(Laser({this->position.x + 33, this->position.y}, -6));
        lastFireTime = GetTime();
    }

}