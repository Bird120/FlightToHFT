//
// Created by bird on 17/09/25.
//

#ifndef BOARDMANAGER_HPP
#define BOARDMANAGER_HPP

#include "Board.hpp"
#include <iostream>
#include "Upmoving.hpp"
#include "MovingDirection.hpp"

struct BoardManager
{
    BoardManager();
    std::array<Board, 4> boards;
    //Board accurrentBoard;
    bool currentBoard;
    void checkIfBoard(float posX, float posY, Upmoving& up, unsigned int page);
    void valueBoard(Board* board, Upmoving& upmoving);
    Board* checkboard(float value, float valueY, Upmoving& up, unsigned int page);


};


#endif //BOARDMANAGER_HPP
