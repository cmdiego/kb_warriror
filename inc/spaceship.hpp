#pragma once
#include <vector>
#include "raylib.h"
#include "laser.hpp"

class Spaceship {
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveRight();
        void MoveLeft();
        void FireLaser();
        std::vector<Laser> lasers;


    private:
        Texture2D image;
        Vector2 position;
        double lastFireTime;
};