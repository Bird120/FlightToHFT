//
// Created by bird on 10/07/25.
//

#include "MovementSystem.hpp"


MovementSystem::MovementSystem()
{

}



void MovementSystem::reset()
{
  movingDirection.reset();
  //movingDirection = nullptr;
}

MovingDirection* MovementSystem::getMovingDirection() const noexcept { return movingDirection.get(); }


void MovementSystem::changePosition(const Direction& direction, PlayerSprite& sprite, bool& newPage, int page)
{
  if (movingDirection)
    return;

switch(direction){
  case Direction::UP:
    {

      if (!newPage && page == 1 )
        movingDirection = std::make_unique<Up>(500.f);
      else if (!newPage && page == 3)
        movingDirection = std::make_unique<Up>(460.f);
      else{
        movingDirection = std::make_unique<Up>(480.f);
        auto& upmoving = movingDirection->getMoving();
        upmoving.setGroundY(480.0);
        newPage = false;
      }
      boardManager.checkIfBoard(sprite.getXPosition(), sprite.getYPosition(),movingDirection->getMoving(), page);
      movingDirection->initializeMoving(sprite.getSprite(), wall, static_cast<unsigned int>(page));

      break;
    }
  case Direction::DOWN:
    {
      if (!newPage && page == 1 )
        movingDirection = std::make_unique<Down>(500.f);
      else if (!newPage && page == 3)
        movingDirection = std::make_unique<Down>(460.f);
      else{
        movingDirection = std::make_unique<Down>(480.f);
        auto& upmoving = movingDirection->getMoving();
        upmoving.setGroundY(480.0);
        newPage = false;
      }
      boardManager.checkIfBoard(sprite.getXPosition(), sprite.getYPosition(),movingDirection->getMoving(), page);
      movingDirection->initializeMoving(sprite.getSprite(), wall, static_cast<unsigned int>(page));

      break;
    }
  case Direction::LEFT:
    {
      if (!newPage && page == 1 )
        movingDirection = std::make_unique<Left>(500.f);
      else if (!newPage && page == 3)
        movingDirection = std::make_unique<Left>(460.f);
      else{
        movingDirection = std::make_unique<Left>(480.f);
        auto& upmoving = movingDirection->getMoving();
        upmoving.setGroundY(480.0);
        newPage = false;
      }
        boardManager.checkIfBoard(sprite.getXPosition(), sprite.getYPosition(),movingDirection->getMoving(), page);
        movingDirection->initializeMoving(sprite.getSprite(), wall, static_cast<unsigned int>(page));

      break;
    }
  case Direction::RIGHT:
    {
        if (!newPage && page == 1 )
          movingDirection = std::make_unique<Right>(500.f);
      else if (!newPage && page == 3)
        movingDirection = std::make_unique<Right>(460.f);
        else{
          movingDirection = std::make_unique<Right>(480.f);
            auto& upmoving = movingDirection->getMoving();
            upmoving.setGroundY(480.0);
            newPage = false;
        }
        boardManager.checkIfBoard(sprite.getXPosition(), sprite.getYPosition(),movingDirection->getMoving(), page);
        movingDirection->initializeMoving(sprite.getSprite(), wall, static_cast<unsigned int>(page));
      break;
    }
  default:
    break;
  }
}

