//
// Created by bird on 16/09/25.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "Utilities.hpp"
#include "HeightUp.hpp"

/*constexpr float LeftMargin = 80.0f;
constexpr float LeftMarginOnBoardMinusPlayer = 40.f;
constexpr float RightMarginOnBoardMinusPlayer = 105.f;
constexpr float EndRightMarginMinusPlayer = 40.f;
constexpr float EndLeftMarginMinusPlayer = 80.f;*/


struct Board
{
    unsigned int page_;
    float beginX_;
    float endX_;
    float height_;
    float groundY;
    float upmovingValue;
    float downmovingValue;
    bool leftside = false;
    bool rightside = false;

    float getHeightBoard();

    bool border(const float& value);
    Board(unsigned int page, float beginX, float endX, float height);
    Board(){};
    bool canBeOnTheBoard(const float& value);
    bool canGoLeftOnBoard(const float& value);
    bool canGoRightOnBoard(const float& value);
    void landOnTheGround(const float& ground);
    float getUpMovingFromHeight(float height);
    bool aroundBoard(float value, float valueY);
    unsigned int getPage();

};

#endif //BOARD_HPP
