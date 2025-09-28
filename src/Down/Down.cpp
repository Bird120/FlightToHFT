//
// Created by bird on 26/09/25.
//

#include "Down.hpp"

void Down::initializeMoving(sf::Sprite& sprite, Board* board, bool availableBoard)
{
    this->downKeybord(sprite, *board, availableBoard);
}

void Down::doTheMove(const float& dt, sf::Sprite& sprite)
{
    this->getMoving().velocityY += this->getMoving().gravity * dt;
    if (this->getMoving().upmoving){

        if (stateMoving_ == StateMoving::ACTION){
            sprite.move({0.f, this->getMoving().velocityY * dt});

            if (sprite.getPosition().y >= getMoving().getGroundY()){
                sprite.setPosition({sprite.getPosition().x, this->getMoving().getGroundY()});
                this->getMoving().upmoving = false;
                this->getMoving().availableBoard = false;
            }
        }
    }
}

void Down::downKeybord(sf::Sprite& sprite, Board& board, bool availableBoard)
{
    //Later: when I will create a board
    (void)availableBoard;
    if (this->getMoving().availableBoard == true)
    {
        if (board.canGoLeftOnBoard(sprite.getPosition().x) || board.canGoRightOnBoard(sprite.getPosition().x))
        {
            this->stateMoving_= StateMoving::ACTION;
            this->getMoving().setGravity(2000.f);
            this->getMoving().keyPressed(this->getMoving().getGravity());
        }
    }
    else if (sprite.getPosition().y >= moving.getGroundY())
    {
        this->stateMoving_= StateMoving::DEFAULT;
        this->getMoving().setGroundY( sprite.getPosition().y);

        this->getMoving().currentboard_ = nullptr;
        this->getMoving().keyPressed(HeightUp::First);

    }
}



