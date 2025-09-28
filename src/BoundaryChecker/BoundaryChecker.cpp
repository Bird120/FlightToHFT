//
// Created by bird on 11/07/25.
//

#include "BoundaryChecker.hpp"

#include "Direction.hpp"


BoundaryChecker::BoundaryChecker() : up(Upmoving(375.f, 500.f)) {}


void BoundaryChecker::screenLimit(auto x, auto y)
{
}


bool BoundaryChecker::canMove(Direction direction, PlayerSprite& player, float MOVE, const sf::RenderWindow& window, BackgroundManager& manager)
{
  auto borders = player.getSprite().getGlobalBounds();
  auto windowSize = window.getSize();

  switch(direction){
    case Direction::UP:
      {
        if (borders.position.y - MOVE > 0)
        {
          return true;
        }
        else return false;

      }
  case Direction::DOWN:
    {
    if (borders.position.y + MOVE < windowSize.y) return true;
    else return false;
    }
  case Direction::LEFT:
      {
        if ((borders.position.x - MOVE > -180) &&(borders.position.x - MOVE < 890))
          return true;
        else
          return false;
      }
  case Direction::RIGHT:
      {
        if (borders.position.x + MOVE < 700.0)
          return true;
        else
        {
          manager.changeBackground_(true);
          player.setXPosition(-200);
          return true;
        }
    }
  default:
    break;
  }
  return false;
}
