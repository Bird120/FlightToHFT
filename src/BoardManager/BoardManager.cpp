//
// Created by bird on 17/09/25.
//

#include "BoardManager.hpp"



BoardManager::BoardManager(): currentBoard(false){
    boards = {Board(2, 130.f, 380.f, 310.f), Board(2, 610.f, 860.f, 490.f),
                Board(3, 290.f, 560.f, 492.f),Board(3, 730.f, 940.f, 500.f)};
}


void BoardManager::checkIfBoard(float posX, float posY, Upmoving& up, unsigned int page)
{
    auto res  = checkboard(posX,posY, up, page);
    valueBoard(res, up);

}




Board* BoardManager::checkboard(float value, float valueY, Upmoving& up, unsigned int page) {
    for (auto& board : boards) {
        if (board.getPage() == page) {
            if (board.aroundBoard(value, valueY))
            {
                up.availableBoard = true;
                return &board;
            }
        }
    }
    up.currentboard_ = nullptr;
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