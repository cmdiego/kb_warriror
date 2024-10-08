#include "../inc/block.hpp"

Block::Block(Vector2 position)
{
    this->position = position;
}

void Block::Draw()
{
    DrawRectangle(this->position.x, this->position.y, 3, 3, {243, 216, 63, 255});
}