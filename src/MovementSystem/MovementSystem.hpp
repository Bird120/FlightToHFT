//
// Created by bird on 10/07/25.
//

#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP
#include "PlayerSprite.hpp"
#include "Direction.hpp"

class MovementSystem {

  public:
    MovementSystem();
    void changePosition(const Direction& direction, float MOVE, PlayerSprite& player);
};
#endif //MOVEMENTSYSTEM_HPP
