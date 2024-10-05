#pragma once
#include "raylib.h"

class Laser 
{
    public:
        Laser(Vector2 position, int speed);
        void Update();
        void Draw();
        // if laser is within screen, active is true
        bool active;
    private:
        // stores x and y position of laser
        Vector2 position;
        // speed of movement for laser
        int speed;
};