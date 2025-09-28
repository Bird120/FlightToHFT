#include "Upmoving.hpp"


bool Upmoving::getMoving() const
{
    return upmoving;
}

void Upmoving::setGroundY(float value)
{
    groundY = value;
}



float Upmoving::getVelocity() const
{
    return velocityY;
}

void Upmoving::setGravity(float value)
{
    gravity = value;
}

Board* Upmoving::getBoard()
{
    if (currentboard_ == nullptr)
        return nullptr;
    return currentboard_;
}


void Upmoving::keyPressed(const float& value){
    if (!upmoving)
    {
        upmoving = true;
        velocityY = value;
    }
}



bool Upmoving::getAvailableBoard() const
{
    return availableBoard;
}
