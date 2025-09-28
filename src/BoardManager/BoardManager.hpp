//
// Created by bird on 17/09/25.
//

#ifndef BOARDMANAGER_HPP
#define BOARDMANAGER_HPP
#include "Upmoving.hpp"
#include "Board.hpp"


#include "Board.hpp"
#include <iostream>
#include "Upmoving.hpp"

struct BoardManager
{
    std::array<Board, 1> boards;
    //Board accurrentBoard;
    bool currentBoard;
    void checkIfBoard(float posX, float posY, Upmoving& up);
    void valueBoard(Board* board, Upmoving& upmoving);
    Board* checkboard(float value, float valueY, Upmoving& up);

    BoardManager(): currentBoard(false){
        boards = {Board(1, 400.f, 260.f)};
    }

};



#endif //BOARDMANAGER_HPP
