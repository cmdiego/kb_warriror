#include "game.hpp"

Game::Game()
{
    obstacles = CreateObstacles();
}

Game::~Game()
{

}

void Game::Update()
{
    // Go through all lasers and update their position
    for(auto& laser : spaceship.lasers)
    {
        laser.Update();
    }

    // Check for inactive lasers and delete them
    DeleteInactiveLasers();
}

void Game::Draw()
{
    // Draw spaceship into screen
    spaceship.Draw();
    // Go through all lasers and draw them into screen 
    for(auto& laser : spaceship.lasers)
    {
        laser.Draw();
    }

    for(auto& obstacle : obstacles)
    {
        obstacle.Draw();
    }
}

void Game::HandleInput()
{   // Move spaceship left when left arrow key is pressed
    if(IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    }
    // Move spaceship right when right arrow key is pressed
    else if (IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }
    // Shoot laser from spaceship when spacebar is pressed
    else if(IsKeyDown(KEY_SPACE))
    {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLasers() 
{
    // Loop through all lasers and find inactive ones
   for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
   {
        // if laser is inactive, erase from lasers vector
        if(it->active == false)
        {
            it = spaceship.lasers.erase(it);
        }
        // if laser is still active, just move on to next laser on vector
        else
        {
            it++;
        }
   }     
}

std::vector<Obstacle> Game::CreateObstacles()
{
    // Calculate the width of each obstacle using # of columns times 3(number of pixels for each col)
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    // Calculate gap between each obstacle. There are 4 obstacles and 5 gaps
    float gap = (GetScreenWidth() - (obstacleWidth*4))/5;

    for(int i = 0; i < 4; i++)
    {
        // Calculate position of each obstacle. (i+1 times gap size) + (i times obs width)
        float offsetX = (i + 1) * gap + (i * obstacleWidth);
        // Push the new created obstacle into obstacles vector
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 130)}));
    }
    return obstacles;
}
