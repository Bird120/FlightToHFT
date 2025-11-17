//
// Created by bird on 11/07/25.
//

#include "BoundaryChecker.hpp"

#include "Direction.hpp"




void BoundaryChecker::screenLimit(auto x, auto y)
{
}


bool BoundaryChecker::canMove(Direction direction, PlayerSprite& player, const sf::RenderWindow& window, BackgroundManager& manager)
{
  auto borders = player.getSprite().getGlobalBounds();
  auto windowSize = window.getSize();

  switch(direction){
    case Direction::UP:
      {
        if (borders.position.y  > 0)
        {
          return true;
        }
        else return false;

      }
  case Direction::DOWN:
    {
    if (borders.position.y  < windowSize.y) return true;
    else return false;
    }
  case Direction::LEFT:
      {
        if ((borders.position.x >= 30.f) &&(borders.position.x <= 1200))
          return true;
        else
          return false;
      }
  case Direction::RIGHT:
      {
        if (borders.position.x >= 10.f && borders.position.x <= 1100.f)
        {
          return true;
        }
        else
        {

          if (!manager.changeBackground_(true))
            return false;
          if (manager.getPage() == 2)
          {
            player.getSprite().setPosition({10.f, 480.f});

            manager.setNewPage(true);

          }
          else if (manager.getPage() == 3)
          {
            player.getSprite().setPosition({10.f, 460.f});

            manager.setNewPage(true);


          }
          else if (manager.getPage() == 1)
          {
            player.getSprite().setPosition({10.f, 500.f});

            manager.setNewPage(true);

          }
          return true;
        }
    }
  default:
    break;
  }
  return false;
}
