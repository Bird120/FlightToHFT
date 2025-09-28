//
// Created by bird on 26/09/25.
//

#ifndef DOWN_HPP
#define DOWN_HPP


#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>

struct Down: public MovingDirection {
    Down(): MovingDirection(){};
    void initializeMoving(sf::Sprite& sprite, Board* board, bool availableBoard) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void downKeybord(sf::Sprite& sprite, Board& board, bool availableBoard);
    void downKeyboard();
};



#endif //DOWN_HPP
