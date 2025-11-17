//
// Created by bird on 02/11/25.
//

#ifndef WALLMANAGER_HPP
#define WALLMANAGER_HPP

#include "Wall.hpp"
#include <vector>

class WallManager
{
private:
    std::vector<Wall> walls;

public:
    WallManager();
    ~WallManager();
    bool detectWall(float spriteX, float spriteY, unsigned int page);

};


#endif //WALLMANAGER_HPP
