//
// Created by bird on 02/11/25.
//

#ifndef RIGHT_HPP
#define RIGHT_HPP

#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>
#include "WallManager.hpp"
#include "HorizontalMove.hpp"



struct Right final: public MovingDirection, HorizontalMove {
    explicit Right(float Y): MovingDirection(Y), HorizontalMove(this->getMoving(), 1){};
    void initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void rightKeyboard(sf::Sprite& sprite, WallManager& wall, unsigned int page);

};



#endif //RIGHT_HPP
