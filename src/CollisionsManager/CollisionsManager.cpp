//
// Created by bird on 24/07/25.
//

#include "CollisionsManager.hpp"


int CollisionsManager::checkIfDetect(std::vector<std::pair<std::unique_ptr<Coin>, int>>& coins, const sf::Sprite& playerSprite, int page, int& score)
{
    const auto return_value = collisions.getCoinCollision(coins, playerSprite, page, score);
    return return_value;
}


