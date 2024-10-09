#include "game.hpp"

Game::Game()
{
    obstacles = CreateObstacles();
    aliens = CreateAliens();
    aliensDirection = 1;
}

Game::~Game()
{
    Alien::UnloadImages();
}

void Game::Update()
{
    // Go through all lasers and update their position
    for(auto& laser : spaceship.lasers)
    {
        laser.Update();
    }

    MoveAliens();

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
    // Draw all obstacles into screen
    for(auto& obstacle : obstacles)
    {
        obstacle.Draw();
    }
    // Draw all aliens into screen
    for(auto& alien : aliens)
    {
        alien.Draw();
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

std::vector<Alien> Game::CreateAliens()
{
    // Create aliens temp vector
    std::vector<Alien> aliens;
    // Create cell size for each alien
    int cellSize = 55;
    // Stores alien type
    int alienType;
    // Create a grid of alien objects and put them into aliens vector
    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 11; col++)
        {
            // if alien on first row, make it type 3, and so on
            if(row == 0)
            {
                alienType = 3;
            } else if (row == 1 || row == 2)
            {
                alienType = 2;
            } else
            {
                alienType = 1;
            }
            
            // 75 and 110 are offsets to center the alien grid
            float x = 100 + col * cellSize;
            float y = 110 + row * cellSize;
            aliens.push_back(Alien(alienType,{x,y}));
        }
    }
    return aliens;
}

void Game::MoveAliens()
{
    for(auto& alien : aliens)
    {
        if(alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth())
        {
            aliensDirection = -1;
            MoveDownAliens(4);
        }
        if(alien.position.x < 0)
        {
            aliensDirection = 1;
            MoveDownAliens(4);
        }
        alien.Update(aliensDirection);
    }
}

void Game::MoveDownAliens(int distance)
{
    for(auto& alien : aliens)
    {
        alien.position.y += distance;
    }
}
