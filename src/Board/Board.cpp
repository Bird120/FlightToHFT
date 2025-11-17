//
// Created by bird on 16/09/25.
//

#include "Board.hpp"



Board::Board(unsigned int page, float beginX,  float endX, float height)
    : page_(page), beginX_(beginX), endX_(endX), height_(getUpMovingFromHeight(height)), groundY(GroundY)
{}
float Board::getUpMovingFromHeight(float height)
{
    upmovingValue = height;
    downmovingValue = height;

    if (height == 260.f){
        height_ = HeightUp::Fourth;
    }
    return height_;
}

float Board::getHeightBoard()
{
  return upmovingValue;
}




bool Board::aroundBoard(float valueX, float valueY)
{
  const bool HorizontalBoardBounds = (valueX >= beginX_ - MarginPlayer::Player && valueX <= endX_  - MarginPlayer::Player);
  const bool OnBoard = (valueY < groundY);
   // for right and left move on board

    if (HorizontalBoardBounds && OnBoard)
	  return true;

   //jump to a left side of a board : va romgroundcanJumpOnBoard
    const bool fromGroundUptoBoard = (valueX >= beginX_ - MarginPlayer::LeftMargin && valueX <= beginX_);
    if (fromGroundUptoBoard)
      {
      leftside = true;
      rightside = false;
      return true;
	}
     //Right side jump/down to the ground
   const bool fromBoardDowntoGround = (valueX >= endX_ - MarginPlayer::Player && valueX <= endX_ + MarginPlayer::Player);
    if (fromBoardDowntoGround)
      {
      	leftside = false;
      	rightside = true;
        return true;
	  }
    return false;
}


bool Board::canGoLeftOnBoard(const float& value)
{
    if (value >= beginX_ - MarginPlayer::Player  && beginX_ + MarginPlayer::Player  >= value)
    {
        return true;
    }
    return false;
}

bool Board::canBeOnTheBoard(const float& value)
{
    if (value <= beginX_ || value >= beginX_ - MarginPlayer::Player)
    {
        return true;
    }
    else if (value >= endX_ || value <= endX_ + MarginPlayer::Player)
        return true;
    else
        return false;
}


bool Board::border(const float& value)
{
    if (endX_ >= value && beginX_ <= value)
        return true;
    return false;
}

bool Board::canGoRightOnBoard(const float& value)
{
    if (value >= endX_ - 40.f  && value <= endX_ + MarginPlayer::Player)
    {
        return true;
    }
    return false;
}

unsigned int Board::getPage()
{
  return page_;
}