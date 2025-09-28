//
// Created by bird on 17/09/25.
//

#include "BoardManager.hpp"

void BoardManager::checkIfBoard(float posX, float posY, Upmoving& up)
{
    auto res  = checkboard(posX,posY, up);
    valueBoard(res, up);

}

Board* BoardManager::checkboard(float value, float valueY, Upmoving& up) {
    for (auto& board : boards) {
        if (board.aroundBoard(value, valueY))
        {
            up.availableBoard = true;
            return &board;
        }
    }
    up.availableBoard = false;
    return nullptr;
}


void  BoardManager::valueBoard(Board* board, Upmoving& upmoving)
{
    if(board != nullptr)
    {
        upmoving.currentboard_ = board;
    }
}