//
// Created by bird on 10/07/25.
//

#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP
#include "PlayerSprite.hpp"
#include "Direction.hpp"
#include "MovingDirection.hpp"
#include "BoardManager.hpp"
#include "WallManager.hpp"
#include "Right.hpp"
#include "Left.hpp"
#include "Up.hpp"
#include "Down.hpp"
#include <SFML/Graphics/Sprite.hpp>

class MovementSystem {
    std::unique_ptr<MovingDirection> movingDirection;

  public:
    MovementSystem();
    BoardManager boardManager;
    WallManager wall;
    void changePosition(const Direction& direction, PlayerSprite& player, bool& newPage, int page);
    void reset();
    MovingDirection* getMovingDirection() const noexcept;
};
#endif //MOVEMENTSYSTEM_HPP
