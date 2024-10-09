#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"

class Game 
{
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void Update();
    private:
        void DeleteInactiveLasers();
        std::vector<Obstacle> CreateObstacles();
        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
};