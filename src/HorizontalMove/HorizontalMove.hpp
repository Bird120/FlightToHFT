//
// Created by bird on 02/11/25.
//

#ifndef HORIZONTALMOVE_HPP
#define HORIZONTALMOVE_HPP


#include "Upmoving.hpp"
#include "WallManager.hpp"

class HorizontalMove{
    Upmoving& moving_;
    float sign_;
public:
    HorizontalMove(Upmoving& moving, float sign);
    ~HorizontalMove() = default;
    void setToDefault(sf::Sprite& sprite, MovingType& movingType, WallManager& wall, unsigned int page) const;
    void setToAction(MovingType& movingType) const;
};


#endif //HORIZONTALMOVE_HPP
