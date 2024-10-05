#pragma once
#include "spaceship.hpp"

class Game 
{
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void Update();
    private:
        Spaceship spaceship;
};