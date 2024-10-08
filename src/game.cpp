#include "game.hpp"

Game::Game()
{

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