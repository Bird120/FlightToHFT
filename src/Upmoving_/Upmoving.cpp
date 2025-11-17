#include "Upmoving.hpp"



bool Upmoving::getMoving() const
{
    return upmoving;
}

void Upmoving::setGroundY(float value)
{
    groundY = value;
}

void  Upmoving::setVelocity(float value)
{
    //std::cout <<" Dans Upmoving::setVelocity( value ) recu --->: " << value << std::endl;
    velocityY += value;
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



bool Upmoving::getAvailableBoard()
{
    return availableBoard;
}
