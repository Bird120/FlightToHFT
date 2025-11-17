//
// Created by bird on 26/09/25.
//

#ifndef UP_HPP
#define UP_HPP




#include "MovingDirection.hpp"
#include "Board.hpp"
#include <iostream>
#include "WallManager.hpp"


struct Up final: public MovingDirection {
    explicit Up(float Y): MovingDirection(Y){};
    void initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page) override;
    void doTheMove(const float& dt, sf::Sprite& sprite) override;
    void upKeyboard(sf::Sprite& sprite);
    void moveDefault(sf::Sprite& sprite);
    void moveAction(sf::Sprite& sprite);
    void setToDefault(sf::Sprite& sprite);

};




#endif //UP_HPP
