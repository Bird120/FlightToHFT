//
// Created by bird on 02/11/25.
//

#include "Wall.hpp"

Wall::Wall(float x, float y, unsigned int page)
    : x_(x), y_(y),page_(page)
{

}

bool Wall::detectWall(float spriteX, float spriteY)
{
    if ((spriteX  >= x_ - 40.f && spriteX <= x_+ 40.f) && y_ == spriteY)
    {
        return true;
    }
    return false;
}

unsigned int Wall::getPage() const noexcept
{
    return page_;
}