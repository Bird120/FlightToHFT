//
// Created by bird on 16/09/25.
//

#include "Board.hpp"


Board::Board(unsigned int page, float beginX, float height)
    : page_(page), beginX_(beginX), endX_(beginX_ + widthBoard), height_(getUpMovingFromHeight(height)), groundY(GroundY)
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
    if ((valueX >= beginX_ - 40.f && valueX < endX_ - 105.f))
    {
        if (valueY <= groundY - upmovingValue)
        {

            return true;
            //an else for case the borser is smaller than the player
        }
        else
            return false;
    }
    //jump to a left side of an board
    else if (valueX >= beginX_ - 80.f && valueX <= beginX_)
    {
        return true;

    }
    else if (valueX >= endX_ - 80.f && valueX <= endX_ + 40.f)
    {
        return true;
    }
    return false;
}


bool Board::canGoLeftOnBoard(const float& value)
{
    if (value >= beginX_ - 80.f && beginX_ >= value)
    {
        return true;
    }
    return false;
}

bool Board::canBeOnTheBoard(const float& value)
{
    if (value <= beginX_ || value >= beginX_ - 40)
    {
        return true;
    }
    else if (value >= endX_ || value <= endX_ + 40)
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
    if (value >= endX_ - 80.f  && value <= endX_ + 40.f)
    {
        return true;
    }
    return false;
}