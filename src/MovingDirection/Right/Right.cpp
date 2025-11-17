//
// Created by bird on 02/11/25.
//

#include "Right.hpp"

void Right::initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page)
{
    if (!this->getMoving().upmoving)
        this->rightKeyboard(sprite, wall, page);
}

void Right::doTheMove(const float& dt, sf::Sprite& sprite)
{
    auto& moving = this->getMoving();
    const float SpriteX =  sprite.getPosition().x;
    const float SpriteY =  sprite.getPosition().y;
    const bool playerBelowGround = SpriteY >= moving.getGroundY();

    moving.velocityY += moving.gravity * dt;
    const auto speed = moving.velocityY * dt;
    sprite.move({playerNotWalk, speed});

    if (playerBelowGround){
        sprite.setPosition({SpriteX + (playerWalk * 2) , moving.getGroundY()});
        moving.upmoving = false;
    }
    return;
}




void Right::rightKeyboard(sf::Sprite& sprite, WallManager& wall, unsigned int page)
{
    auto& moving = this->getMoving();
    auto board = moving.currentboard_;

    const float SpriteX =  sprite.getPosition().x;
    const float SpriteY =  sprite.getPosition().y;

    const bool playerOffGround = (moving.getGroundY() != SpriteY);
    const bool playerOnGround = (SpriteY == moving.getGroundY());

    if (!board){
        if (playerOnGround)
            setToDefault(sprite, this->getMovingType(), wall, page);
        return;
    }
    const bool playerBeyondEdge = (SpriteX >= board->endX_ - MarginPlayer::Player);
    const bool playerOnBoard = (SpriteX <= board->endX_ - MarginPlayer::Player);

    if (playerBeyondEdge  && playerOffGround)
        setToAction(this->getMovingType());
    else if (playerOnGround|| playerOnBoard)
    {
        setToDefault(sprite, this->getMovingType(), wall, page);
    }
    return;
}
