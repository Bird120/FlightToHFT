//
// Created by bird on 24/07/25.
//

#ifndef COIN_HPP
#define COIN_HPP
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Utilities.hpp"

class Coin
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    Coin();
    void draw(sf::RenderWindow& window) const;
    sf::Sprite& getSprite();
    void setScale(float x, float y);
    void setPosition(float x, float y);

};
#endif //COIN_HPP
