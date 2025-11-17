//
// Created by bird on 24/07/25.
//

#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <map>
#include "Coin.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Collisions
{
  public:
    Collisions();
    int getCoinCollision(std::vector<std::pair<std::unique_ptr<Coin>, int>>& coins, const sf::Sprite& playerSprite, int page, int& score);
};
#endif //COLLISIONS_HPP
