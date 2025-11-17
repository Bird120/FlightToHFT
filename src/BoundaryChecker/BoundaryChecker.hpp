//
// Created by bird on 11/07/25.
//

#ifndef BOUNDARYCHECKER_HPP
#define BOUNDARYCHECKER_HPP

#include "PlayerSprite.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

#include "MovementSystem.hpp"
#include "Direction.hpp"
#include "BackgroundManager.hpp"
#include "Upmoving.hpp"

class BoundaryChecker {

public:
  BoundaryChecker() = default;
  bool canMove(Direction direction, PlayerSprite& player, const sf::RenderWindow& window, BackgroundManager& manager);
  void screenLimit(auto x, auto y);

};



#endif //BOUNDARYCHECKER_HPP
