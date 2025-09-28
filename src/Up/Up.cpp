//
// Created by bird on 26/09/25.
//

#include "Up.hpp"



void Upp::initializeMoving(sf::Sprite& sprite, Board* board, bool availableBoard)
{
    this->upKeybord(sprite, *board, availableBoard);
    if (this->getMoving().upmoving) std::cout << "UP initializingMoving() moving in moment!" << std::endl;
}


void Upp::doTheMove(const float& dt, sf::Sprite& sprite)
{

    this->getMoving().velocityY += this->getMoving().gravity * dt;

    if (this->getMoving().upmoving){
        sprite.move({0.f, this->getMoving().velocityY });
        if (this->stateMoving_ == StateMoving::DEFAULT) {

            if (sprite.getPosition().y >= this->getMoving().getGroundY()){
                sprite.setPosition({sprite.getPosition().x, this->getMoving().groundY});
                this->getMoving().upmoving = false;
                this->getMoving().availableBoard = false;
            }
        }
        else if (this->stateMoving_ == StateMoving::ACTION) {

            if (sprite.getPosition().y <= this->getMoving().currentboard_->getHeightBoard()- moving.sizePlayer){
                sprite.setPosition({sprite.getPosition().x, this->getMoving().currentboard_->getHeightBoard()  - this->getMoving().sizePlayer});
                this->getMoving().upmoving = false;
                this->getMoving().availableBoard = false;
            }
        }
    }
}


void Upp::upKeybord(sf::Sprite& sprite, Board& board, bool availableBoard)
{
    //Later: better organization
    (void) availableBoard;
    if (this->getMoving().availableBoard == true){

        if (board.canGoLeftOnBoard(sprite.getPosition().x) || board.canGoRightOnBoard(sprite.getPosition().x))
        {
            this->stateMoving_= StateMoving::ACTION;
            this->getMoving().keyPressed(HeightUp::Fourth);
        }
    }
    else if (sprite.getPosition().y >= this->getMoving().getGroundY())
    {
        this->stateMoving_= StateMoving::DEFAULT;

        this->getMoving().setGroundY(sprite.getPosition().y);
        this->getMoving().currentboard_ = nullptr;
        this->getMoving().keyPressed(HeightUp::First);
    }
}
