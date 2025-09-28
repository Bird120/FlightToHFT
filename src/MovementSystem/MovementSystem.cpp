//
// Created by bird on 10/07/25.
//

#include "MovementSystem.hpp"


MovementSystem::MovementSystem()
{

}

void MovementSystem::changePosition(const Direction& direction, float MOVE, PlayerSprite& player)
{
switch(direction){
  case Direction::UP:
    {

      player.setYPosition(-MOVE);
      break;
    }
  case Direction::DOWN:
    {
      player.setYPosition(MOVE);
      break;
    }
  case Direction::LEFT:
    {
      player.setXPosition(-MOVE);
      break;
    }
  case Direction::RIGHT:
    {
      player.setXPosition(MOVE);
      break;
    }
  default:
    break;
  }
}

