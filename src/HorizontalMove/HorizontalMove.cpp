//
// Created by bird on 02/11/25.
//

#include "HorizontalMove.hpp"


HorizontalMove::HorizontalMove(Upmoving& moving, float sign) :moving_(moving), sign_(sign)
{}

void HorizontalMove::setToAction(MovingType& movingType) const
{

    movingType= MovingType::ACTION;
    moving_.setGravity(Gravity);
    moving_.keyPressed(moving_.getGravity());
}



void HorizontalMove::setToDefault(sf::Sprite& sprite, MovingType& movingType, WallManager& wall, unsigned int page) const
{
    const float SpriteX =  sprite.getPosition().x;
    const float SpriteY =  sprite.getPosition().y;

    movingType= MovingType::DEFAULT;
    moving_.setGroundY(SpriteY);

    if (!wall.detectWall(SpriteX + (playerWalk * sign_), SpriteY, page)){
        sprite.move({(playerWalk * sign_), playerNotWalk});
    }
}
