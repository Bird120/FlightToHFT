//
// Created by bird on 02/11/25.
//

#include "WallManager.hpp"

WallManager::WallManager()
{
    walls = {/*Wall(150.f, 480.f, 2), Wall(330.f, 480.f, 2),*/
        Wall(630.f, 480.f, 2), Wall(810.f, 480.f, 2),
        Wall(340.f, 460.f, 3), Wall(440.f, 460.f, 3),
        Wall(770.f, 460.f, 3), Wall(890.f, 460.f, 3)};
}

WallManager::~WallManager()
{}

bool WallManager::detectWall(float spriteX, float spriteY, unsigned int page)
{
    for(auto& wall : walls )
    {
        if (page == wall.getPage())
        {
            if (wall.detectWall(spriteX, spriteY))
                return true;
        }
    }
    return false;
}