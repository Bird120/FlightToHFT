//
// Created by bird on 16/09/25.
//

#ifndef HEIGHTUP_HPP
#define HEIGHTUP_HPP


constexpr float widthBoard = 400.f;



constexpr float Gravity = 2000.f;
constexpr float playerWalk = 40.f;
constexpr float playerNotWalk = 0.f;

constexpr float GroundY = 500.f;

struct MarginPlayer {
    static constexpr float LeftMargin = 80.0f;
    static constexpr float Player = 40.f;
    static constexpr float RightMarginOnBoardMinusPlayer = 105.f;
    //static constexpr float EndRightMarginMinusPlayer = 40.f;
    static constexpr float EndLeftMarginMinusPlayer = 80.f;

};





struct HeightUp {
    static constexpr float First   = -680.f;
    static constexpr float Second = -800.f;
    static constexpr float Third = -1000.f;
    static constexpr float Fourth = -1400.f;
    static constexpr float Five = -4400.f;

};


enum  class MovingType{DEFAULT, ACTION};


enum  class StateMoving{DEFAULT, ACTION};
#endif //HEIGHTUP_HPP
