//
// Created by bird on 02/11/25.
//

#ifndef LEFT_HPP
#define LEFT_HPP

#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>
#include "WallManager.hpp"
#include "HorizontalMove.hpp"


struct Left final: public MovingDirection, HorizontalMove {
    explicit Left(float Y): MovingDirection(Y), HorizontalMove(this->getMoving(), -1.0){};
    void initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void leftKeyboard(sf::Sprite& sprite, WallManager& wall, unsigned int page);


};


#endif //LEFT_HPP
