//
// Created by bird on 26/09/25.
//

#include "Up.hpp"


void Up::initializeMoving(sf::Sprite& sprite, WallManager& wall, unsigned int page)
{
  (void)page;
  (void)wall;
      this->upKeyboard(sprite);
}

void Up::moveDefault(sf::Sprite& sprite)
{
  auto SpriteX = sprite.getPosition().x;
  auto SpriteY = sprite.getPosition().y;
  auto& moving = this->getMoving();

  if (SpriteY >= moving.getGroundY()){
    sprite.setPosition({SpriteX, moving.groundY});
    moving.upmoving = false;
  }
}

void Up::moveAction(sf::Sprite& sprite)
{
  const auto SpriteY = sprite.getPosition().y;
  auto& moving = this->getMoving();
  auto* board = moving.currentboard_;

  const bool leftside = (board->leftside);
  const bool rightside = (board->rightside);

  if (SpriteY <= board->getHeightBoard() - moving.sizePlayer){
    if (leftside)
      sprite.setPosition({board->beginX_  +  MarginPlayer::Player, board->getHeightBoard()  - moving.sizePlayer});
    else if (rightside)
      sprite.setPosition({board->endX_ -  MarginPlayer::Player, board->getHeightBoard()  - moving.sizePlayer});
    moving.upmoving = false;
    board->rightside = false;
    board->leftside = false;
  }
}

void Up::doTheMove(const float& dt, sf::Sprite& sprite)
{
    auto& moving = this->getMoving();
    moving.setVelocity(moving.getGravity() * dt);

        sprite.move({0.f, moving.getVelocity() * dt});
        if (this->movingType_ == MovingType::DEFAULT) {

          moveDefault(sprite);
        }
        else if (this->movingType_ == MovingType::ACTION) {
          moveAction(sprite);
   }
}

void Up::setToDefault(sf::Sprite& sprite)
{
  const auto SpriteY = sprite.getPosition().y;
  auto& moving = this->getMoving();


    this->movingType_= MovingType::DEFAULT;

    moving.setGroundY(SpriteY);
    moving.currentboard_ = nullptr;
    moving.keyPressed(HeightUp::First);

}

void Up::upKeyboard(sf::Sprite& sprite)
{
  const auto SpriteX = sprite.getPosition().x;
  const auto SpriteY = sprite.getPosition().y;
  auto& moving = this->getMoving();
  auto* board = moving.currentboard_;

  auto availableBoard = moving.getAvailableBoard();
    if (availableBoard)
     {
        const bool playerEdgeOnGround = (board->canGoLeftOnBoard(SpriteX ) || board->canGoRightOnBoard(SpriteX));
        if (playerEdgeOnGround){
            this->movingType_= MovingType::ACTION;
            moving.keyPressed(HeightUp::Fourth);
        }
        else
          setToDefault(sprite);
     }
    else if (SpriteY >= moving.getGroundY())
      setToDefault(sprite);
}
