//
// Created by bird on 02/11/25.
//

#include "Left.hpp"

void Left::initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page)
{
    this->leftKeyboard(sprite, wall, page);
}

void Left::doTheMove(const float& dt, sf::Sprite& sprite)
{
    auto& moving = this->getMoving();

    if (moving.upmoving){
        moving.velocityY += moving.gravity * dt;

        if (movingType_ == MovingType::ACTION){
            sprite.move({0.f, this->getMoving().velocityY * dt});

            if (sprite.getPosition().y >= moving.getGroundY()){
                sprite.setPosition({sprite.getPosition().x - MarginPlayer::Player , moving.getGroundY()});
                moving.upmoving = false;
                moving.availableBoard = false;
            }
        }
    }
}





void Left::leftKeyboard(sf::Sprite& sprite, WallManager& wall, unsigned int page)
{
    auto& moving = this->getMoving();

    auto board = moving.currentboard_;
    const float SpriteX =  sprite.getPosition().x;
    const float SpriteY =  sprite.getPosition().y;

    const bool playerOffGround = (SpriteY != moving.getGroundY());
    const bool playerOnGround = (SpriteY == moving.getGroundY());

    if (!board){
        if (playerOnGround)
            setToDefault(sprite, this->getMovingType(), wall, page);
        return;
    }

    const bool playerOnEdges = (SpriteX - MarginPlayer::Player <=  board->beginX_);
    const bool playerOnBoard = (SpriteX >= board->beginX_);

    if (playerOffGround && playerOnEdges)
        setToAction(this->getMovingType());

    else if (playerOnGround || playerOnBoard)
        setToDefault(sprite, this->getMovingType(), wall, page);
}