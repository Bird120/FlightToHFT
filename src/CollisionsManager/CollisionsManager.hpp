//
// Created by bird on 24/07/25.
//

#ifndef COLLISIONSMANAGER_HPP
#define COLLISIONSMANAGER_HPP
#include <Coin.hpp>
#include <memory>
#include "Collisions.hpp"

class CollisionsManager
{

  private:
  Collisions collisions;

  public:
  CollisionsManager() = default;
  int checkIfDetect(std::vector<std::pair<std::unique_ptr<Coin>, int>>& coins, const sf::Sprite& playerSprite, int page, int& score);
  int eraseThisCoin(unsigned int iterator);

};
#endif //COLLISIONSMANAGER_HPP
