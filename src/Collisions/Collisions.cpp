//
// Created by bird on 24/07/25.
//

#include "Collisions.hpp"

Collisions::Collisions()
{

}



int Collisions::getCoinCollision(std::vector<std::pair<std::unique_ptr<Coin>, int>>& coins, const sf::Sprite& playerSprite, int page, int& score)
{
    unsigned int iterator = 0;
    for (auto& [it, v] : coins)
    {
        if (v == page)
        {
            if (playerSprite.getGlobalBounds().findIntersection(it->getSprite().getGlobalBounds()))
            {
                score += 10;
                return static_cast<int>(iterator);
            }
        }
        iterator++;
    }
    return -1;
}

