//
// Created by bird on 26/09/25.
//

#ifndef MOVINGDIRECTION_HPP
#define MOVINGDIRECTION_HPP



#include <SFML/Graphics.hpp>
#include "Upmoving.hpp"
#include "HeightUp.hpp"


#include "WallManager.hpp"

struct MovingDirection {
private:
    Upmoving moving_;

public:
    MovingDirection(float Y):moving_(Upmoving(375.f, Y)){}
    Upmoving& getMoving(){return moving_;};
    MovingType movingType_;
    bool inMove = false;
    MovingType& getMovingType() {return movingType_;}

    virtual void initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page) = 0;
    virtual void doTheMove(const float& dt, sf::Sprite& sprite) = 0;
    virtual ~MovingDirection() = default;
};






#endif //MOVINGDIRECTION_HPP
