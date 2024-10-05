#include "spaceship.hpp"

Spaceship::Spaceship() 
{
    // load spaceship img texture
    image = LoadTexture("graphics/spaceshipGame.png");
    // init data members
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
    // Draw spaceship texture, with 0.3 scaling
    DrawTextureEx(image, position, 0, 0.3, WHITE);
}

void Spaceship::MoveRight()
{
    // move spaceship 5 pixels to the right
    this->position.x += 5;
    // if position is past the end of the screen, reset to end of screen
    if(this->position.x > 730)
    {
        this->position.x = 730;
    }
}

void Spaceship::MoveLeft()
{
    // move spaceship 5 pixels to the left
    this->position.x -= 5; 
    // if position is past left of the screen, reset to start
    if(this->position.x < 0)
    {
        this->position.x = 0;
    } 
}

void Spaceship::FireLaser()
{
    // If 250 miliseconds have passed, allow a new laser to be fired
    if(GetTime() - lastFireTime >= 0.25)
    {
        // Create new laser and push it into lasers vector
        lasers.push_back(Laser({this->position.x + 33, this->position.y}, -6));
        lastFireTime = GetTime();
    }

}