#include "../inc/laser.hpp"

Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Laser::Draw()
{
    // If laser is on screen, draw new laser (rectangle)
    if(active)
        DrawRectangle(this->position.x, this->position.y, 4, 15, {243,216,63,255});
}

void Laser::Update() 
{
    // update laser's y position to move
    this->position.y += speed;
    if(active)
    {
        // if laser is out of the screen, set active to false
        if(position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
        }
    }
}