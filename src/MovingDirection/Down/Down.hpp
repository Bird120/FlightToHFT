//
// Created by bird on 26/09/25.
//

#ifndef DOWN_HPP
#define DOWN_HPP


#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>
#include "WallManager.hpp"

struct Down final: public MovingDirection {
    explicit Down(float Y): MovingDirection(Y){};
    void initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void downKeyboard(sf::Sprite& sprite);
};


#endif //DOWN_HPP
