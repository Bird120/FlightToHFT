//
// Created by bird on 26/09/25.
//

#ifndef MOVINGDIRECTION_HPP
#define MOVINGDIRECTION_HPP



#include <SFML/Graphics.hpp>
#include "Upmoving.hpp"
#include "HeightUp.hpp"


struct MovingDirection {
    MovingDirection():moving(Upmoving(375.f, 480.f)){}
    Upmoving moving;
    Upmoving& getMoving(){return moving;};
    StateMoving stateMoving_;
    virtual void initializeMoving(sf::Sprite& sprite, Board* board, bool availableBoard) = 0;
    virtual void doTheMove(const float& dt, sf::Sprite& sprite) = 0;
    virtual ~MovingDirection() = default;
};





#endif //MOVINGDIRECTION_HPP
