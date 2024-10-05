#pragma once
#include <vector>
#include "raylib.h"
#include "laser.hpp"

class Spaceship {
    public:
        // constructor
        Spaceship();
        // destructor
        ~Spaceship();
        void Draw();
        void MoveRight();
        void MoveLeft();
        void FireLaser();
        // Vector to store Laser objects created/fired
        std::vector<Laser> lasers;


    private:
        // stores spaceship image
        Texture2D image;
        // stores x and y coordinates of spaceship
        Vector2 position;
        // stores time of last fired laser
        double lastFireTime;
};