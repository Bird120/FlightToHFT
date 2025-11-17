//
// Created by bird on 02/11/25.
//

#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>

struct Wall
{
    float x_;
    float y_;
    unsigned int page_;
    Wall(float x, float y, unsigned int page);

    unsigned int getPage() const noexcept;

    bool detectWall(float spriteX, float spriteY);

};

#endif //WALL_HPP
