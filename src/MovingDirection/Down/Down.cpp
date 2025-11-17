//
// Created by bird on 26/09/25.
//

#include "Down.hpp"

void Down::initializeMoving(sf::Sprite& sprite,  WallManager& wall, unsigned int page)
{
    (void)wall;
    (void)page;
    if (!this->inMove)
        this->downKeyboard(sprite);
}

void Down::doTheMove(const float& dt, sf::Sprite& sprite)
{
    this->getMoving().velocityY += this->getMoving().gravity * dt;
    if (this->getMoving().upmoving){

        if (this->movingType_ == MovingType::ACTION){
            sprite.move({0.f, this->getMoving().velocityY * dt});

            if (sprite.getPosition().y >= getMoving().getGroundY()){
                sprite.setPosition({sprite.getPosition().x, this->getMoving().getGroundY()});
                this->getMoving().upmoving = false;
                this->getMoving().availableBoard = false;
                this->inMove = false;

            }
        }
    }
}

void Down::downKeyboard(sf::Sprite& sprite)
{
    auto& moving = this->getMoving();

    auto board = moving.currentboard_;
    auto availableBoard = moving.getAvailableBoard();

    if (availableBoard)
    {
        if (board->canGoLeftOnBoard(sprite.getPosition().x) || board->canGoRightOnBoard(sprite.getPosition().x))
        {
            this->inMove = true;


            this->movingType_= MovingType::ACTION;
            moving.setGravity(2000.f);
            moving.keyPressed(this->getMoving().getGravity());
        }
    }
    else if (sprite.getPosition().y >= moving.getGroundY())
    {
        return;
    }
}



