//
// Created by bird on 26/09/25.
//

#ifndef UP_HPP
#define UP_HPP


#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


struct Upp: public MovingDirection {
    static float  stable;
    //float seuil = -1.0;
    Upp(): MovingDirection(){}
    void initializeMoving(sf::Sprite& sprite, Board* board, bool availableBoard) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void upKeybord(sf::Sprite& sprite, Board& board, bool availableBoard);

};


#endif //UP_HPP
