//
// Created by bird on 16/09/25.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "HeightUp.hpp"

struct Board
{
    unsigned int page_;
    float beginX_;
    float endX_;
    float height_;
    float groundY;
    float upmovingValue;
    float downmovingValue;

    float getHeightBoard();

    bool border(const float& value);
    Board(unsigned int page, float beginX, float height);
    Board(){};
    bool canBeOnTheBoard(const float& value);
    bool canGoLeftOnBoard(const float& value);
    bool canGoRightOnBoard(const float& value);
    void landOnTheGround(const float& ground);
    float getUpMovingFromHeight(float height);
    bool aroundBoard(float value, float valueY);
};

#endif //BOARD_HPP
