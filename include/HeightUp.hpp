//
// Created by bird on 16/09/25.
//

#ifndef HEIGHTUP_HPP
#define HEIGHTUP_HPP


constexpr float widthBoard = 400.f;


constexpr float GroundY = 500.f;

struct HeightUp {
    static constexpr float First   = -680.f;
    static constexpr float Second = -800.f;
    static constexpr float Third = -1000.f;
    static constexpr float Fourth = -1400.f;
    static constexpr float Five = -4400.f;

};




enum  class StateMoving{DEFAULT, ACTION};
#endif //HEIGHTUP_HPP
